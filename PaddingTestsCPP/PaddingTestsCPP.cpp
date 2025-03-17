
#include <iostream>
#include <bitset>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <map>
#include <typeindex>
#include <vector>

#include "MNet/MNet.h"
#include "MNet/Packet/Net8Packet.h"


















void printBits(int64_t num) {
    std::bitset<64> bits(num);  // Convert int to bitset (32 bits)
    std::cout << "Raw bit represnetation: "<< bits << std::endl;
}

int main()
{
    NetLayoutMap::Init();
    std::vector<int> Layout;

    
    MNet8::AddPacketField<Layout1>(&Layout);//0
    

    
    int LayoutSize = MNet8::GetBitfieldSize(&Layout);
    std::cout << "Layout size: " << LayoutSize<<std::endl;
    
    
    
    Net8Packet packet = Net8Packet();
    packet.SetHeaderAsChar(0b1);
    packet.SetPayloadAsNumber(15);
    
   
   
    
    printBits(packet.GetRawPacket());
    
    std::cout << "Payload as number: " << packet.GetPayloadAsInt() << std::endl;
    std::cout << "Header as number: " << packet.GetHeaderAsInt() << std::endl;




    
    int8_t Field2 = packet.GetPayloadValAtLayout<int8_t>(&Layout, 2);
    std::cout << "Field value: " << Field2 << std::endl;
    std::bitset<64> bitset1;

    std::cout<<"Bitset size" << sizeof(bitset1) << std::endl;
    printBits(packet.GetRawPacket());
    std::cout<<packet.getBitset()<<std::endl;
    int Field3 = 0;
    


    
    packet.SetPayloadAsNumber(0);
    
    packet.ClearPayload();
    std::cout <<std::endl;
    
    packet.SetPayloadValAtLayout<Layout4>(&Layout, 2,14);
    std::cout <<std::endl;
    std::cout << "Test" << std::endl;
    packet.SetPayloadValAtLayout<Layout1>(&Layout, 0,0b1);
    std::cout <<std::endl;

    packet.SetPayloadValAtLayout<Layout8>(&Layout, 3,0b1101);
    std::cout <<std::endl;

    packet.SetPayloadAsNumber(255);
    int payloadInt = packet.GetPayloadAsInt();
    std::cout << payloadInt<<std::endl;
    std::cout<< "bitset: " << packet.getBitset()<<std::endl;



    packet.SetHeaderAsChar(0b1110000);
    std::bitset<8> header = packet.GetHeaderAsChar();
    std::cout << "Header: " << header << std::endl;
    std::cout<< "bitset: " << packet.getBitset()<<std::endl;
}