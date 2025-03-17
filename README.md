To use, include:
#include "MNet/MNet.h"
#include "MNet/Packet/Net8Packet.h"

Call MNet::Init(); somewhere early before you use it.



Add a packet field:

std::vector<int> Layout;
MNet8::AddPacketField<Layout1>(&Layout);

Layout1 is 1 bit, Layout2 is 2 bits, etc.

Create a packet:
Net8Packet packet = Net8Packet();

// Doesn't require layout.
Set headers and payloads by chars and numbers:
packet.SetHeaderAsChar(0b1);
packet.SetPayloadAsNumber(15);


Set payload at the bit-level:
packet.SetPayloadValAtLayout<Layout4>(&Layout, 2,14);
2 is the index, 14 is the value.


