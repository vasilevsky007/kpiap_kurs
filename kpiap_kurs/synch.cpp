#include "synch.h"
void synch::SaveToFile(vector<plane>& planes, vector<flight>& flights, vector<flight>& oldflights) {
    Book* book = xlCreateBook();
    Sheet* sheet1 = book->addSheet(L"Planes");
    if (sheet1)
    {
        sheet1->writeNum(1, 1, planes.size());
        for (int i = 0; i < planes.size(); i++) {
            planes[i].SavePlane(sheet1, i + 2);
        }
    }
    Sheet* sheet2 = book->addSheet(L"Flights");
    if (sheet2)
    {
        sheet2->writeNum(1, 1, flights.size());
        for (int i = 0; i < flights.size(); i++) {
            flights[i].SaveFlight(sheet2, i + 2);
        }
    }
    Sheet* sheet3 = book->addSheet(L"OldFlights");
    if (sheet3)
    {
        sheet3->writeNum(1, 1, oldflights.size());
        for (int i = 0; i < oldflights.size(); i++) {
            oldflights[i].SaveFlight(sheet3, i + 2);
        }
    }
    book->save(L"Data.xls");
    book->release();
    ;
}

void synch::LoadFromFile(vector<plane>& planes, vector<flight>& flights, vector<flight>& oldflights) {
    Book* book = xlCreateBook();
    book->load(L"Data.xls");
    plane pl;
    flight fl;
    Sheet* sheet1 = book->getSheet(0);
    if (sheet1) {
        double cap = sheet1->readNum(1, 1);
        for (int i = 0; i < cap; i++) {
            planes.push_back(pl);
            planes[i].LoadPlane(sheet1, i + 2);
        }
    }
    Sheet* sheet2 = book->getSheet(1);
    if (sheet2) {
        double cap = sheet2->readNum(1, 1);
        for (int i = 0; i < cap; i++) {
            flights.push_back(fl);
            flights[i].LoadFlight(sheet2, i + 2, planes, true);
        }
    }
    Sheet* sheet3 = book->getSheet(2);
    if (sheet3) {
        double cap2 = sheet3->readNum(1, 1);
        for (int i = 0; i < cap2; i++) {
            oldflights.push_back(fl);
            oldflights[i].LoadFlight(sheet3, i + 2, planes, false);
        }
    }
    book->release();
}

