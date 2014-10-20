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

/*
 * @file DTCPState.cc
 * @author Marcel Marek (imarek@fit.vutbr.cz)
 * @date May 3, 2014
 * @brief
 * @detail
 */

#include <DTCPState.h>

DTCPState::DTCPState()
{
  // TODO Auto-generated constructor stub

  //TODO B! Fix
//  rtt = 10;

}



bool DTCPState::isImmediate() const
{
  return immediate;
}

void DTCPState::setImmediate(bool immediate)
{
  this->immediate = immediate;
}

unsigned int DTCPState::getRcvrRightWinEdgeSent() const
{
  return rcvRightWinEdgeSent;
}

void DTCPState::setRcvrRightWinEdgeSent(unsigned int rcvRightWinEdgeSent)
{
  this->rcvRightWinEdgeSent = rcvRightWinEdgeSent;
}

unsigned int DTCPState::getSenderRightWinEdge() const
{
  return sndRightWinEdge;
}

void DTCPState::setSenderRightWinEdge(unsigned int senderRightWinEdge)
{
  this->sndRightWinEdge = senderRightWinEdge;
}

//bool DTCPState::isSetDrfFlag() const
//{
//  return setDRFFlag;
//}
//
//void DTCPState::setSetDrfFlag(bool setDrfFlag)
//{
//  setDRFFlag = setDrfFlag;
//}

//unsigned int DTCPState::getRtt() const
//{
//  //TODO B1 RTT estimator policy
//  return rtt;
//}

//void DTCPState::setRtt(unsigned int rtt)
//{
//  this->rtt = rtt;
//}

DTCPState::~DTCPState()
{
  // TODO Auto-generated destructor stub
}

