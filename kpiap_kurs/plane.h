#pragma once //134
#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include<string>
#include <string.h>
#include <iomanip>
#include<vector>
#include <algorithm>
#include "libxl.h"
using namespace libxl;
using namespace std;

enum manufacturer_ { Airbus = 1, ATR, Saab, Туполев, Boeing, Bombardier, Embraer };
enum model_ { A220 = 1, A320, A350, A380, ATR42, ATR72, SAAB340, SAAB200, TY204, TY214, TY324, TY330, TY134, TY154, BOEING737, BOEING747, BOEING787, CRJ200, CRJ700, EMB121, ERJ135, ERJ140, ERJ145, E175, E195 };
class plane
{
private:
	manufacturer_ manufacturer;
	model_ model;
	static inline int num=0; //ne zabit izmenit nacalo otcheta pri zagruzke
	int bortnum = 100;
	bool ISINFLIGHT;
	bool ISONREPAIR;
	string location;
public:
	plane(manufacturer_,model_);
	plane(plane* existing);
	plane();
	void SavePlane(Sheet* sheet, int position);
	void LoadPlane(Sheet* sheet, int position);
	bool isinflight();
	int GetBortNumber();
	string GetLocation();
	friend ostream& operator<< (ostream& out, const plane& Plane);
	friend istream& operator>> (istream& in, plane& Plane);
	friend class flight;
};

bool complocat(plane a, plane b);
bool compbrtn(plane a, plane b);

class flight
{
private:
	static inline int numf=0;
	int flightnumber=1000;
	int planebortnum;
	plane* planeadr;
	string departure;
	string arrival;
public:
	friend class plane;
	void addflight(plane* selectedplane, string arriv);
	flight();
	void showflight();
	int GetFlightNumber();
	void endflight(vector<flight>& oldflights);
	void SaveFlight(Sheet* sheet, int position);
	void LoadFlight(Sheet* sheet, int position, vector<plane>& planes, bool isCurrent);

};

#endif