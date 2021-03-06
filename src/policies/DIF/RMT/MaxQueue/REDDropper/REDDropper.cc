//
// Copyright © 2014 PRISTINE Consortium (http://ict-pristine.eu)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "REDDropper.h"

Define_Module(REDDropper);

void REDDropper::onPolicyInit()
{
    monitor = dynamic_cast<REDMonitor*>(qMonPolicy);
    if (monitor == NULL)
    {
        EV << "!!! REDDropper has to be used in conjecture with REDMonitor!" << endl;
    }
}

/**
 * Either drops or marks the last PDU in given queue (depending on the NED setting).
 *
 * @param queue target queue
 * @return true for PDU drop, false for PDU mark
 */
bool REDDropper::dropOrMark(RMTQueue* queue)
{
    if (par("marking").boolValue() == true)
    {
        EV << "REDDropper: Marking the last message in " << queue->getFullName()
           << " with an ECN bit." << endl;
        queue->markCongestionOnLast();
        return false;
    }
    else
    {
        EV << "REDDropper: executing tail drop in " << queue->getFullName() << endl;
        return true;
    }
}

/**
 * Decides whether to mark/drop last incoming packet in a queue.
 *
 * @param queue target queue
 * @return true for PDU drop, false for PDU mark
 */
bool REDDropper::run(RMTQueue* queue)
{
    if (monitor == NULL)
    {
        return false;
    }

    // gather some variables from the queue, the monitoring policy and the NED module
    const char* qname = queue->getFullName();
    int length = queue->getLength();
    int minThresh = queue->getThreshLength();
    int maxThresh = queue->getMaxLength();
    double avr = monitor->qAvgLengths[queue];
    int count = monitor->qCounters[queue];
    double maxP = par("dropProbability").doubleValue();

    bool dropped = false;

    if (minThresh <= avr && avr < maxThresh)
    {
        monitor->qCounters[queue] += 1;
        const double pb = maxP * (avr - minThresh) / (maxThresh - minThresh);
        const double pa = pb / (1 - count * pb);
        const double rand = dblrand();

        if (rand < pa)
        {
            EV << "REDDropper: rand < pa (" << rand << " < " << pa << ")" << endl;
            monitor->qCounters[queue] = 0;
            dropped = dropOrMark(queue);
        }
    }
    else if (avr >= maxThresh)
    {
        EV << "REDDropper: Average queue length in " << qname << " exceeds the maximum threshold." << endl;
        monitor->qCounters[queue] = 0;
        dropped = dropOrMark(queue);
    }
    else if (length >= maxThresh)
    {
        EV << "REDDropper: Queue length in " << qname << " exceeds the maximum threshold." << endl;
        monitor->qCounters[queue] = 0;
        dropped = dropOrMark(queue);
    }
    else
    {
        monitor->qCounters[queue] = -1;
    }

    return dropped;
}
