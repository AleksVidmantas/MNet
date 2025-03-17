#pragma once
#include <vector>

#include "NetLayoutMap.h"

template<int PayloadSize>
class NetLayout
{
public:
    

    NetLayout()
    {
       
    }

    template <class LayoutID>
    static void AddPacketField(std::vector<int>* Layout)
    {
        Layout->push_back(NetLayoutMap::LayoutTypeMap.at(typeid(LayoutID)));
    };
    
   
    static bool IsValid(std::vector<int>* Layout)
    {
        int size = 0;
        for(int i = 0; i < Layout->size(); i++)
        {
            size+= Layout->operator[](i);
        }

        if(size > PayloadSize)
        {
            return false;
        }else
        {
            return true;
        }
    }
    static int GetBitfieldSize(std::vector<int>* Layout)
    {
        int size = 0;
        for(int i = 0; i < Layout->size(); i++)
        {
            size+=Layout->operator[](i);
        }
        return size;
    }

};


