#pragma once
#include <map>
#include <typeindex>

class Layout8{Layout8();};
class  Layout7{Layout7();};
class  Layout6{Layout6();};
class  Layout5{Layout5();};
class  Layout4{Layout4();};
class  Layout3{Layout3();};
class  Layout2{Layout2();};
class  Layout1{Layout1();};

class NetLayoutMap 
{
    
public:
    static std::map<std::type_index, int> LayoutTypeMap;
    static void Init();
   
    
};