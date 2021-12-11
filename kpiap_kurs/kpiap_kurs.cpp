#include "plane.h"
int inputint() {
    int a;
    while (true) {

        cin >> a;
        if (!(cin.fail())) {
            cin.ignore(10000, '\n');
            return a;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "введите верное числовое значение!\n";
        }
    }
}

void SaveToFile(vector<plane>& planes, vector<flight>& flights, vector<flight>& oldflights) {
    Book* book = xlCreateBook();
    Sheet* sheet1 = book->addSheet(L"Planes");
    if (sheet1)
    {
        sheet1->writeNum(1, 1, planes.size());
        for (int i = 0; i < planes.size(); i++) {
            planes[i].SavePlane(sheet1, i+2);
        }
    }
    Sheet* sheet2 = book->addSheet(L"Flights");
    if (sheet2)
    {
        sheet2->writeNum(1, 1, flights.size());
        for (int i = 0; i < flights.size(); i++) {
            flights[i].SaveFlight(sheet2, i+2);
        }        
    }
    Sheet* sheet3 = book->addSheet(L"OldFlights");
    if (sheet3)
    {
        sheet3->writeNum(1, 1, oldflights.size());
        for (int i = 0; i < oldflights.size(); i++) {
            oldflights[i].SaveFlight(sheet3, i+2);
        }
    }
    book->save(L"Data.xls");
    book->release();
    ;
}

void LoadFromFile(vector<plane>& planes, vector<flight>& flights, vector<flight>& oldflights) {
    Book* book = xlCreateBook();
    book->load(L"Data.xls");
    plane pl;
    flight fl;
    Sheet* sheet1 = book->getSheet(0);
    if (sheet1){
        double cap = sheet1->readNum(1, 1);
        for (int i = 0; i < cap; i++) {
            planes.push_back(pl);
            planes[i].LoadPlane(sheet1, i+2);
        }
    }
    Sheet* sheet2 = book->getSheet(1);
    if (sheet2) {
        double cap = sheet2->readNum(1, 1);
        for (int i = 0; i < cap; i++) {
            flights.push_back(fl);
            flights[i].LoadFlight(sheet2, i + 2,planes,true);
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


int main()
{
	setlocale(LC_ALL, "russian");
	bool flag=true;
	while (flag) {
        vector<plane> planes;
        vector<flight> flights;
        vector<flight> oldflights;
        system("CLS");
        LoadFromFile(planes, flights, oldflights);
        cout << "\nМЕНЮ\n1)добавить самолет\n2)показать все самолеты\n3)изменить данные о самолете\n4) удалить самолет\n5)Добавить рейс\n6)Показать активные рейсы\n7)Завершить рейс\n8)Показать завершенные рейсы\n9)отсортировать самолеты\n0)выход\n";
            int k = inputint();
            plane newplane, *selected=nullptr;
            flight newflight;
            int id,n;
            string str;
            switch (k) {
            case 1:
                cin >> newplane;
                planes.push_back(&newplane);
                break;
            case 2:
                cout << setw(15) << "Производитель" <<setw(15) << "Модель" <<setw(15) << "Бортовой №" << setw(10) << "В полёте" << setw(10) << "На ремонте" <<setw(40)<<"Местонахождение"<< endl;
                for (int i = 0; i < planes.size(); i++) {
                    cout << planes[i]<<endl;
                }
                system("pause");
                break;
            case 3:
                cout << setw(15) << "Производитель" << setw(15) << "Модель" << setw(15) << "Бортовой №" << setw(10) << "В полёте" << setw(10) << "На ремонте" << setw(40) << "Местонахождение" << endl;
                for (int i = 0; i < planes.size(); i++) {
                    cout << planes[i] << endl;
                }
                SearchFP:cout << "Введите Бортовой № самолета"<<endl;
                id = inputint();
                for (int i = 0; i < planes.size(); i++) {
                    if (planes[i].GetBortNumber() == id) selected = &planes[i];
                }
                if (selected == nullptr) {
                    cout << "Не было найдено самолета с таким бортовым номером" << endl;
                    goto SearchFP;
                }
                cin >> *selected;
                break;
            case 4:
                n = -1;
                cout << setw(15) << "Производитель" << setw(15) << "Модель" << setw(15) << "Бортовой №" << setw(10) << "В полёте" << setw(10) << "На ремонте" << setw(40) << "Местонахождение" << endl;
                for (int i = 0; i < planes.size(); i++) {
                    cout << planes[i] << endl;
                }
            SearchFp:cout << "Введите Бортовой № самолета" << endl;
                id = inputint();
                for (int i = 0; i < planes.size(); i++) {
                    if (planes[i].GetBortNumber() == id) n = i;
                }
                if (n == -1) {
                    cout << "Не было найдено самолета с таким бортовым номером" << endl;
                    goto SearchFp;
                }
                planes.erase(planes.begin() + n);
                break;
            case 5:
                cout << setw(15) << "Производитель" << setw(15) << "Модель" << setw(15) << "Бортовой №" << setw(10) << "В полёте" << setw(10) << "На ремонте" << setw(40) << "Местонахождение" << endl;
                for (int i = 0; i < planes.size(); i++) {
                    cout << planes[i] << endl;
                }
                Searchfp:cout << "Введите Бортовой № самолета" << endl;
                id = inputint();
                for (int i = 0; i < planes.size(); i++) {
                    if (planes[i].GetBortNumber() == id) selected = &planes[i];
                }
                if (selected == nullptr) {
                    cout << "Не было найдено самолета с таким бортовым номером" << endl;
                    goto Searchfp;
                }
                if (selected->isinflight() == true) {
                    cout << "Данный самолет итак находится в полёте!" << endl;
                    goto Searchfp;
                }
                cout << "Введите код пункта назначения" << endl;
                cin >> str;
                flights.push_back(newflight);//здесь при реаллоке вектора срабатывает деструктор поэтому для удаления был создан отдельный метод 
                flights[flights.size()-1].addflight(selected,str);
                break;
            case 6:
                cout << setw(15) << "№ Рейса" <<setw(15) << "Бортовой №" <<  setw(15) << "Отправление" << setw(15) << "Прибытие" << endl;
                for (int i = 0; i < flights.size(); i++) flights[i].showflight();
                system("pause");
                break;
            case 7:
                n = -1;
                cout << setw(15) << "№ Рейса" << setw(15) << "Бортовой №" << setw(15) << "Отправление" << setw(15) << "Прибытие" << endl;
                for (int i = 0; i < flights.size(); i++) flights[i].showflight();
                SearchFF:cout << "Введите № рейса" << endl;
                id = inputint();
                for (int i = 0; i < flights.size(); i++) {
                    if (flights[i].GetFlightNumber() == id) n = i;
                }
                if (n == -1) {
                    cout << "Нет активного полёта с таким номером" << endl;
                    goto SearchFF;
                }
                flights[n].endflight(oldflights);
                flights.erase(flights.begin() + n);
                break;
            case 8:
                cout << setw(15) << "№ Рейса" << setw(15) << "Бортовой №" << setw(15) << "Отправление" << setw(15) << "Прибытие" << endl;
                for (int i = 0; i < oldflights.size(); i++) oldflights[i].showflight();
                system("pause");
                break;
            case 9:
                n = -1;
                while (n != 0) {
                    cout << "сортировка\n1)по бортовому номеру\n2)по местонахождению\n0)выход" << endl;
                    n = inputint();
                    if (n == 1) { sort(planes.begin(), planes.end(),compbrtn); n = 0; }
                    if (n == 2) { sort(planes.begin(), planes.end(), complocat); n = 0; }
                }
                break;
            case 0:
                flag = false;
                break;
            }

            SaveToFile(planes,flights,oldflights);
}
    return 0;
}