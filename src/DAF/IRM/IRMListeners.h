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

#ifndef IRMLISTENERS_H_
#define IRMLISTENERS_H_

//Standard libraries
#include <omnetpp.h>
//RINASim libraries
#include "IRM.h"

class IRM;
class IRMListeners : public cListener {
  public:
    IRMListeners(IRM* nirm);
    virtual ~IRMListeners();

    virtual void receiveSignal(cComponent *src, simsignal_t id, bool b) {
        EV << "Signal to IRM initiated by " << src->getFullPath() << endl;
    }
  protected:
      IRM* irm;
};

class LisIRMAllocReq : public IRMListeners {
  public:
    LisIRMAllocReq(IRM* nirm) : IRMListeners(nirm){};
    void virtual receiveSignal(cComponent *src, simsignal_t id, cObject *obj);
};

class LisIRMDeallocReq : public IRMListeners {
  public:
    LisIRMDeallocReq(IRM* nirm) : IRMListeners(nirm){};
    void virtual receiveSignal(cComponent *src, simsignal_t id, cObject *obj);
};


#endif /* IRMLISTENERS_H_ */
