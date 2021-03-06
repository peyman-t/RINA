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

#include <RMTSchedulingBase.h>

Define_Module(RMTSchedulingBase);

void RMTSchedulingBase::initialize()
{
    // display active policy name
    cDisplayString& disp = getDisplayString();
    disp.setTagArg("t", 1, "t");
    disp.setTagArg("t", 0, getClassName());

    onPolicyInit();
}

void RMTSchedulingBase::handleMessage(cMessage *msg)
{
}

void RMTSchedulingBase::onPolicyInit()
{

}

void RMTSchedulingBase::finalizeService(RMTPort* port, RMTQueueType direction)
{
    if (direction == RMTQueue::OUTPUT)
    {
        if (waitingOnOutput[port] > 0)
        {
            port->setBusy();
            waitingOnOutput[port] -= 1;
            processQueues(port, RMTQueue::OUTPUT);
        }
    }
    else
    {
        if (waitingOnInput[port] > 0)
        {
            waitingOnInput[port] -= 1;
            processQueues(port, RMTQueue::INPUT);
        }
    }
}

void RMTSchedulingBase::processQueues(RMTPort* port, RMTQueueType direction)
{
}
