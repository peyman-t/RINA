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

package rina.DIF.RIB;

import rina.DAF.CDAP.CommonDistributedApplicationProtocol;

module RIBDaemon
{
    parameters:
        @display("i=block/control;bgb=271,228");

    gates:
        inout rmtIo;
    submodules:
        commonDistributedApplicationProtocol: CommonDistributedApplicationProtocol {
            parameters:
                @display("p=135,148");
            gates:
                southIo[1];
        }
        ribd: RIBd {
            parameters:
                @display("p=135,52");
        }
    connections allowunconnected:
}
