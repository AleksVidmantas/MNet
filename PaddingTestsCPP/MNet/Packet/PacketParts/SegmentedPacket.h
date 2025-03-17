#pragma once
#include "../../MNet.h"
struct SegmentedPacket
{
    Net1b header;
    Net7b payload;
    
};