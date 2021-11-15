// kpiap_kurs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
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



int main()
{
	setlocale(LC_ALL, "russian");
    vector<plane> planes;
    vector<flight> flights;
	int k;
	bool flag=true;
	while (flag) {
        system("CLS");
        cout << "\nМЕНЮ\n1)добавить самолет\n2)показать все самолеты\n3)изменить данные о самолете\n4) удалить самолет\n5)Добавить полет\n6)Показать активные полёты\n7)Завершить полёт\n8)отсортировать самолеты\n0)выход\n";
            k = inputint();
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
                    cout << "Не было найдено самолета с таким бортовым номером" << endl;
                    goto SearchFF;
                }
                flights[n].endflight();
                flights.erase(flights.begin() + n);
                break;
            case 8:
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
	}

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
