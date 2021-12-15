#pragma once 
#ifndef SYNCH_H
#define SYNCH_H
#include "plane.h"

class synch
{
public:
    void SaveToFile(vector<plane>& planes, vector<flight>& flights, vector<flight>& oldflights); 
    void LoadFromFile(vector<plane>& planes, vector<flight>& flights, vector<flight>& oldflights); 
};

#endif