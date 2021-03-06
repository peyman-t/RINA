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
/**
 * @file FlowAllocator.h
 * @author Marcel Marek (imarek@fit.vutbr.cz)
 * @date Apr 29, 2014
 * @brief
 * @detail
 */

#ifndef FA_H_
#define FA_H_

//Standard libraries
#include <omnetpp.h>
#include <string>
//RINASim libraries
#include "FABase.h"
#include "FAListeners.h"
#include "FAI.h"
#include "Flow.h"
#include "FAITable.h"
#include "RINASignals.h"
#include "ModuleAccess.h"
#include "EFCP.h"
#include "ExternConsts.h"
#include "RABase.h"
#include "DA.h"

//Constants

extern const int RANDOM_NUMBER_GENERATOR;
extern const int MAX_PORTID;
extern const int MAX_CEPID;

class FA : public FABase
{
  public:
    FA();
    virtual ~FA();

    virtual bool receiveAllocateRequest(Flow* flow);
    virtual void receiveCreateFlowPositive(Flow* flow);
    virtual void receiveCreateResponseFlowPositiveFromRibd(Flow* flow);
    virtual bool receiveDeallocateRequest(Flow* flow);
    virtual bool receiveCreateFlowRequestFromRibd(Flow* flow);

    virtual void deinstantiateFai(Flow* flow);

    virtual bool setOriginalAddresses(Flow* flow);
    virtual bool setNeighborAddresses(Flow* flow);


    bool invokeNewFlowRequestPolicy(Flow* flow);

    //Signals
    //simsignal_t sigFAIAllocReq;
    //simsignal_t sigFAAllocResNega;
    //simsignal_t sigFAAllocResPosi;
    simsignal_t sigFACreReqFwd;
    simsignal_t sigFACreResNega;
    //simsignal_t sigFACreResPosi;
    simsignal_t sigFACreResPosiFwd;

    //Listeners
    LisFAAllocReq*      lisAllocReq;
    LisFACreFloPosi*    lisCreFloPosi;
    LisFADeallocReq*    lisDeallocReq;
    LisFACreReq*        lisCreReq;
    LisFACreRes*        lisCreResFloPosi;

  protected:
    //SimpleModule overloads
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    void initPointers();


  private:
    EFCP* Efcp;
    RABase* ResourceAllocator;
    DA* DifAllocator;

    bool isMalformedFlow(Flow* flow);
    FAI* createFAI(Flow* flow);

    void initSignalsAndListeners();

    //void signalizeAllocateResponseNegative(Flow* flow);
    void signalizeCreateFlowRequestForward(Flow* flow);
    void signalizeCreateFlowResponseNegative(Flow* flow);
    void signalizeCreateFlowResponsePositiveForward(Flow* flow);

    const Address getAddressFromDa(const APN& apn, bool useNeighbor);

    bool changeDstAddresses(Flow* flow, bool useNeighbor);
    bool changeSrcAddress(Flow* flow, bool useNeighbor);

};

#endif /* FLOWALLOCATOR_H_ */
