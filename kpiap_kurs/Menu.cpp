#include "Menu.h"

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
            cout << "������� ������ �������� ��������!\n";
        }
    }
}

Menu::Menu() {
    system("CLS");
    wanttocontinue = true;
    data.LoadFromFile(planes, flights, oldflights);
    cout << "            ##~~~#~##~~##\n            ###~##~~####\n            ##~#~#~~~##\n            ##~~~#~~~##\n            ##~~~#~~~##\n\n            ~####~~##~~##~######~~####\n            ##~~##~##~~##~~~##~~~##~~##\n            ######~##~~##~~~##~~~######\n            ##~~##~~####~~~~##~~~##~~##\n            ##~~##~~~##~~~######~##~~##\n\n            ~####~~~####~~##~~~#~#####~~~####~~##~~##~##~~##\n            ##~~##~##~~##~###~##~##~~##~##~~##~###~##~~####\n            ##~~~~~##~~##~##~#~#~#####~~######~##~###~~~##\n            ##~~##~##~~##~##~~~#~##~~~~~##~~##~##~~##~~~##\n            ~####~~~####~~##~~~#~##~~~~~##~~##~##~~##~~~##" << endl;
    cout << "\n����\n1)�������� �������\n2)�������� ��� ��������\n3)�������� ������ � ��������\n4)������� �������\n5)�������� ����\n6)�������� �������� �����\n7)��������� ����\n8)�������� ����������� �����\n9)������������� ��������\n0)�����\n";
    k = inputint();
    switch (k) {
    case 1:
        cin >> newplane;
        planes.push_back(&newplane);
        break;
    case 2:
        cout << setw(15) << "�������������" << setw(15) << "������" << setw(15) << "�������� �" << setw(10) << "� �����" << setw(10) << "�� �������" << setw(40) << "���������������" << endl;
        for (int i = 0; i < planes.size(); i++) {
            cout << planes[i] << endl;
        }
        system("pause");
        break;
    case 3:
        cout << setw(15) << "�������������" << setw(15) << "������" << setw(15) << "�������� �" << setw(10) << "� �����" << setw(10) << "�� �������" << setw(40) << "���������������" << endl;
        for (int i = 0; i < planes.size(); i++) {
            cout << planes[i] << endl;
        }
    SearchFP:cout << "������� �������� � ��������" << endl;
        id = inputint();
        for (int i = 0; i < planes.size(); i++) {
            if (planes[i].GetBortNumber() == id) selected = &planes[i];
        }
        if (selected == nullptr) {
            cout << "�� ���� ������� �������� � ����� �������� �������" << endl;
            goto SearchFP;
        }
        cin >> *selected;
        break;
    case 4:
        n = -1;
        cout << setw(15) << "�������������" << setw(15) << "������" << setw(15) << "�������� �" << setw(10) << "� �����" << setw(10) << "�� �������" << setw(40) << "���������������" << endl;
        for (int i = 0; i < planes.size(); i++) {
            cout << planes[i] << endl;
        }
    SearchFp:cout << "������� �������� � ��������" << endl;
        id = inputint();
        for (int i = 0; i < planes.size(); i++) {
            if (planes[i].GetBortNumber() == id) n = i;
        }
        if (n == -1) {
            cout << "�� ���� ������� �������� � ����� �������� �������" << endl;
            goto SearchFp;
        }
        planes.erase(planes.begin() + n);
        break;
    case 5:
        cout << setw(15) << "�������������" << setw(15) << "������" << setw(15) << "�������� �" << setw(10) << "� �����" << setw(10) << "�� �������" << setw(40) << "���������������" << endl;
        for (int i = 0; i < planes.size(); i++) {
            cout << planes[i] << endl;
        }
    Searchfp:cout << "������� �������� � ��������" << endl;
        id = inputint();
        for (int i = 0; i < planes.size(); i++) {
            if (planes[i].GetBortNumber() == id) selected = &planes[i];
        }
        if (selected == nullptr) {
            cout << "�� ���� ������� �������� � ����� �������� �������" << endl;
            goto Searchfp;
        }
        if (selected->isinflight() == true) {
            cout << "������ ������� ���� ��������� � �����!" << endl;
            goto Searchfp;
        }
        if (selected->isinflight() == true) {
            cout << "������ ������� ��������� � �������!" << endl;
            goto Searchfp;
        }
        cout << "������� ��� ������ ����������" << endl;
        cin >> str;
        flights.push_back(newflight);//����� ��� �������� ������� ����������� ���������� ������� ��� �������� ��� ������ ��������� ����� 
        flights[flights.size() - 1].addflight(selected, str);
        break;
    case 6:
        cout << setw(15) << "� �����" << setw(15) << "�������� �" << setw(15) << "�����������" << setw(15) << "��������" << endl;
        for (int i = 0; i < flights.size(); i++) flights[i].showflight();
        system("pause");
        break;
    case 7:
        n = -1;
        cout << setw(15) << "� �����" << setw(15) << "�������� �" << setw(15) << "�����������" << setw(15) << "��������" << endl;
        for (int i = 0; i < flights.size(); i++) flights[i].showflight();
    SearchFF:cout << "������� � �����" << endl;
        id = inputint();
        for (int i = 0; i < flights.size(); i++) {
            if (flights[i].GetFlightNumber() == id) n = i;
        }
        if (n == -1) {
            cout << "��� ��������� ����� � ����� �������" << endl;
            goto SearchFF;
        }
        flights[n].endflight(oldflights);
        flights.erase(flights.begin() + n);
        break;
    case 8:
        cout << setw(15) << "� �����" << setw(15) << "�������� �" << setw(15) << "�����������" << setw(15) << "��������" << endl;
        for (int i = 0; i < oldflights.size(); i++) oldflights[i].showflight();
        system("pause");
        break;
    case 9:
        n = -1;
        while (n != 0) {
            cout << "����������\n1)�� ��������� ������\n2)�� ���������������\n0)�����" << endl;
            n = inputint();
            if (n == 1) { sort(planes.begin(), planes.end(), compbrtn); n = 0; }
            if (n == 2) { sort(planes.begin(), planes.end(), complocat); n = 0; }
        }
        break;
    case 0:
        wanttocontinue = false;
        break;
    }
}
Menu::~Menu() {
    data.SaveToFile(planes, flights, oldflights);
}
bool Menu::WantToContinue() {
    return wanttocontinue;
}