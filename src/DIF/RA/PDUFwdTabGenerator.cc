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

/**
 * @file PDUFwdTabGenerator.cc
 * @author Tomas Hykel (xhykel01@stud.fit.vutbr.cz)
 * @brief PDU forwarding (routing) table generator.
 * @detail Responds to various events happening inside the IPC process
 *         by adding, removing and editing entries in the forwarding table.
 */

#include "PDUFwdTabGenerator.h"

Define_Module(PDUFwdTabGenerator);


void PDUFwdTabGenerator::initialize()
{
    fwTable = check_and_cast<PDUForwardingTable*>
        (getModuleByPath("^.pduForwardingTable"));
}

void PDUFwdTabGenerator::handleMessage(cMessage *msg)
{
}

