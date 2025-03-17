#pragma once

struct PacketNumbers
{
    
public:
    char Context;
private:
    char fill1;
    char fill2;
    char fill3;
public:
    void clearPayload()
    {
        
        fill1=0b0;
        fill2=0b0;
        fill3=0b0;
        PayloadAsNum=0b0;
    }
    void clearHeader()
    {
        Context=0b0;
    }
    int PayloadAsNum;
};