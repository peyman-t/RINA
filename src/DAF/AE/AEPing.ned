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

package rina.DAF.AE;

simple AEPing extends AE like IAE
{
    parameters:
        @class(AEPing);
        string dstApName = default("AppErr");
        string dstApInstance = default("0");
        string dstAeName = default("AeErr");
        string dstAeInstance = default("0");
        
        int startAt @unit(s) = default(0s);
        int stopAt  @unit(s) = default(0s);
        int pingAt  @unit(s) = default(0s);
        int rate 			 = default(1);    
        
        int size    @unit(B) = default(512B);
        
}
