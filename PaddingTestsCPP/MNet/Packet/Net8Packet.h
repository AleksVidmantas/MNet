#pragma once
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>

#include "PacketParts/PacketNumbers.h"
#include "PacketParts/SegmentedPacket.h"

#include "../NetLayout.h"
struct Net8Packet {
private:
    union
    {
        std::bitset<64> bitset;
        SegmentedPacket SegPacket;
        PacketNumbers NumberPacket;
        int64_t PacketAsBits;
    };
    
public:

    void ClearPayload()
    {
        NumberPacket.clearPayload();
    }
    Net8Packet()
    {
        
    }
    std::bitset<64> getBitset()
    {
        return bitset;
    }
    int64_t GetRawPacket()
    {
        return PacketAsBits;
    }
    char GetHeaderAsChar()
    {
        return NumberPacket.Context;  
    }
    int GetHeaderAsInt()
    {
        return static_cast<int>(NumberPacket.Context);
    }
    
    void SetHeaderAsChar(char c){
        NumberPacket.Context = c;  
    }
    
    int GetPayloadAsInt(){
        
        return NumberPacket.PayloadAsNum;  
    }
    template<typename Type>
    Type GetPayloadValAtLayout(std::vector<int>* Layout, int index)
    {
        
        Type f = 0;
        //std::cout << "val: " << f << std::endl;
        return f;
    }
    
    template<class Type>
    void SetPayloadValAtLayout(std::vector<int>* Layout, int index, unsigned long value)
    {
        std::cout <<"test" << index<<std::endl;
        std::cout << Layout->size()<<std::endl;
        int bitStart = 0;
        if (!(index < Layout->size())) {
            std::cerr << "Assertion failed: Passed index exceeds layout length\n";
            assert(false); // Ensures the program halts
        }
        for(int i = 0; i < index; i++)
        {
            if(i == index)
            {
                break;
            }
            
            bitStart += Layout->at(i);
            
        }
        
        std::bitset<sizeof(Type)*8> val_as_bitset;
        val_as_bitset = value;

        // starting index
        int trueValAsBitsetSize = NetLayoutMap::LayoutTypeMap.at(typeid(Type));
        int valAsBitsetIndex = val_as_bitset.size()-trueValAsBitsetSize;
        
       std::cout<<"Value as bitset: " << val_as_bitset << ". Start index: " << valAsBitsetIndex << ". true size: " << trueValAsBitsetSize << std::endl;
      //  std::cout<<"bsetting: " << bitset <<std::endl;
        std::bitset<64> prior = bitset;
        for(int i = 0; i < trueValAsBitsetSize; i++)
        {
            std::cout<<"modified index: " << (64-i-bitStart) << "valasbitset acces: " << (i+bitStart) << "Val: " << val_as_bitset[i]<<std::endl;
            std::cout<<" val: " << val_as_bitset[valAsBitsetIndex+i]<< std::endl;

            bitset[63-i-bitStart] = val_as_bitset[i];
        }

    };
    
    void SetPayloadAsNumber(int val){
       NumberPacket.PayloadAsNum = val;
    }

    void SetPayloadAsLayout(Net7b layout)
    {
        std::memcpy(&SegPacket.payload, layout, 7);
 
    };
    
};
