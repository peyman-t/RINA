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

/* Author: Kewin Rausch (kewin.rausch@create-net.org) */

#include "PDUFTGPolicy.h"
#include "PDUFwdTabGenerator.h"

Define_Module(PDUFTGPolicy);

/*
 * Class constructor/destructors stuff.
 */

PDUFTGPolicy::PDUFTGPolicy()
{

}

PDUFTGPolicy::~PDUFTGPolicy()
{
    // Do nothing...
}

/*
 * Class procedures sorted by name.
 */

void PDUFTGPolicy::computeForwardingTable()
{
    // Do nothing...
}

std::list<FSUpdateInfo *> * PDUFTGPolicy::getNetworkState()
{
    return NULL;
}

unsigned int PDUFTGPolicy::getUpdateTimeout()
{
    return updateT;
}

void PDUFTGPolicy::handleMessage(cMessage *msg)
{
    // Do nothing...
}

void PDUFTGPolicy::initialize()
{
    fwdtg = ModuleAccess<PDUFwdTabGenerator>("pduFwdTabGenerator").get();

    // Display active policy name.
    cDisplayString& disp = getDisplayString();
    disp.setTagArg("t", 1, "t");
    disp.setTagArg("t", 0, getClassName());
}

void PDUFTGPolicy::insertNewFlow(Address addr, short unsigned int qos, RMTPort * port)
{
    // Do nothing...
}

void PDUFTGPolicy::mergeForwardingInfo(FSUpdateInfo * info)
{
    // Do nothing...
}

void PDUFTGPolicy::removeFlow(Address addr, unsigned short qos)
{
    // Do nothing...
}

void PDUFTGPolicy::setUpdateTimeout(unsigned int msec)
{
    updateT = msec;
}