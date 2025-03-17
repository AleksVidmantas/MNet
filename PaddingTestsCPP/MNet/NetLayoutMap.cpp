#include "NetLayoutMap.h"
std::map<std::type_index, int> NetLayoutMap::LayoutTypeMap;
void NetLayoutMap::Init()
{ 
        
    NetLayoutMap::LayoutTypeMap.emplace(typeid(Layout8),8);
    NetLayoutMap::LayoutTypeMap.emplace(typeid(Layout7),7);
    NetLayoutMap::LayoutTypeMap.emplace(typeid(Layout6),6);
    NetLayoutMap::LayoutTypeMap.emplace(typeid(Layout5),5);
    NetLayoutMap::LayoutTypeMap.emplace(typeid(Layout4),4);
    NetLayoutMap::LayoutTypeMap.emplace(typeid(Layout3),3);
    NetLayoutMap::LayoutTypeMap.emplace(typeid(Layout2),2);
    NetLayoutMap::LayoutTypeMap.emplace(typeid(Layout1),1);

    
}
