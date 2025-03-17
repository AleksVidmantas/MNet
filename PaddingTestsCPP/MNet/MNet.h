#pragma once
#define Net8PayloadSize static_cast<int>(7)
#define Net8HeaderBitSize static_cast<int>(1)
#include "NetLayout.h"


typedef char Net7b[7];
typedef char Net8[8];
typedef char Net1b;



class MNet {
public:
    
    
    

    static void Init()
    {
        NetLayoutMap::Init();
    }
   
};


class MNet8
{
public:
    template <class LayoutID>
 static void AddPacketField(std::vector<int>* Layout)
    {
        NetLayout<Net8PayloadSize>::AddPacketField<LayoutID>(Layout);
    };


    static int GetBitfieldSize(std::vector<int>* Layout)
    {
        return NetLayout<Net8PayloadSize>::GetBitfieldSize(Layout);
    }

   
};


