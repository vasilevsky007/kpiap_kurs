#pragma once
#ifndef MENU_H
#define MENU_H
#include "plane.h"
#include "synch.h"
class Menu
{
private:
    vector<plane> planes;
    vector<flight> flights;
    vector<flight> oldflights;
    synch data;
    plane newplane, * selected = nullptr;
    flight newflight;
    int k, id, n;
    string str;
    bool wanttocontinue;
public:
    Menu();
    ~Menu();
    bool WantToContinue();
};
int inputint();
#endif