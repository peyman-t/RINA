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

#include "NeighborTable.h"

//Constants
const char*   ELEM_NEIGHTAB        = "NeighborTable";
const char*   ELEM_NEIGHBOR        = "Neighbor";

Define_Module(NeighborTable);

void NeighborTable::initialize()
{
    //Parse XML config
    parseConfig(par(PAR_CONFIGDATA).xmlValue());

    //Init watchers
    WATCH_LIST(NeiTable);
}

void NeighborTable::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
}

void NeighborTable::addNeighborEntry(const APN& apn) {
    NeiTable.push_back(NeighborTableEntry(apn));
}

NeighborTableEntry* NeighborTable::findNeighborEntryByApn(const APN& apn) {
    for (NeiEntryItem it = NeiTable.begin(); it != NeiTable.end(); ++it) {
        if (it->getApn() == apn)
            return &(*it);
    }
    return NULL;
}

const APNList* NeighborTable::findNeighborsByApn(const APN& apn) {
    NeighborTableEntry* entry = findNeighborEntryByApn(apn);
    return entry ? &(entry->getNeigbors()) : NULL;
}

void NeighborTable::addNewNeighbor(const APN& apn, const APN& neighbor) {
    findNeighborEntryByApn(apn)->addNeighbor(neighbor);
}

void NeighborTable::removeNeighborEntry(const APN& apn) {
    NeiTable.remove(*(findNeighborEntryByApn(apn)));
}

const APNList* NeighborTable::findApnsByNeighbor(const APN& neighbor) {
    APNList* apnlist = new APNList();
    for (NeiEntryCItem it = NeiTable.begin(); it != NeiTable.end(); ++it) {
        if (it->hasNeighbor(neighbor)) {
            apnlist->push_back(it->getApn());
        }
    }
    return apnlist;
}

void NeighborTable::parseConfig(cXMLElement* config) {
    cXMLElement* mainTag = NULL;
    if (config != NULL && config->hasChildren() && config->getFirstChildWithTag(ELEM_NEIGHTAB))
        mainTag = config->getFirstChildWithTag(ELEM_NEIGHTAB);
    else {
        EV << "configData parameter not initialized!" << endl;
        return;
    }

    cXMLElementList apnlist = mainTag->getChildrenByTagName(ELEM_APN);
    for (cXMLElementList::const_iterator it = apnlist.begin(); it != apnlist.end(); ++it) {
        cXMLElement* m = *it;

        if (!(m->getAttribute(ATTR_APN) && m->getFirstChildWithTag(ELEM_NEIGHBOR))) {
            EV << "\nError when parsing NeighborTable record" << endl;
            continue;
        }

        APN newapn = APN(m->getAttribute(ATTR_APN));

        addNeighborEntry(newapn);

        cXMLElementList neighborlist = m->getChildrenByTagName(ELEM_NEIGHBOR);
        for (cXMLElementList::const_iterator jt = neighborlist.begin(); jt != neighborlist.end(); ++jt) {
            cXMLElement* n = *jt;

            if (!(n->getAttribute(ATTR_APN))) {
                EV << "\nError when parsing Synonym record" << endl;
                continue;
            }

            addNewNeighbor(newapn, APN(n->getAttribute(ATTR_APN)));
        }
    }


}
