#include "plane.h"
#pragma warning(disable:4996)
plane::plane(plane* existing) {
	manufacturer = existing->manufacturer;
	model = existing->model;
	ISONREPAIR = false;
	ISINFLIGHT = false;
	num++;
	bortnum += num;
	location = "MSQ\0";
}	
plane::plane() {
	/*num++;
	bortnum += num;
	location = "MSQ";*/
}

bool plane::isinflight() {
	return this->ISINFLIGHT;
}

int plane::GetBortNumber() {
	return bortnum;
}
string plane::GetLocation() {
	return location;
}
ostream& operator<< (ostream& out, const plane& Plane) //перегрузка вывода. добавить новые поля при необходимости.
{
	string manuf;
	switch (Plane.manufacturer) {
	case Airbus: manuf = "Airbus"; break;
	case ATR: manuf = "ATR"; break;
	case Saab: manuf = "Saab"; break;
	case Туполев: manuf = "Туполев"; break;
	case Boeing: manuf = "Boeing"; break;
	case Bombardier: manuf = "Bombardier"; break;
	case Embraer: manuf = "Embraer"; break;
	}
	string mode;
	switch (Plane.model) {
	case A220: mode = "A220"; break;
	case A320: mode = "A320"; break;
	case A350: mode = "A350"; break;
	case A380: mode = "A380"; break;
	case ATR42: mode = "ATR42"; break;
	case ATR72: mode = "ATR72"; break;
	case SAAB340: mode = "SAAB340"; break;
	case SAAB200: mode = "SAAB200"; break;
	case TY204: mode = "TY204"; break;
	case TY214: mode = "TY214"; break;
	case TY324: mode = "TY324"; break;
	case TY330: mode = "TY330"; break;
	case TY134: mode = "TY134"; break;
	case TY154: mode = "TY154"; break;
	case BOEING737: mode = "BOEING737"; break;
	case BOEING747: mode = "BOEING747"; break;
	case BOEING787: mode = "BOEING787"; break;
	case CRJ200: mode = "CRJ200"; break;
	case CRJ700: mode = "CRJ700"; break;
	case EMB121: mode = "EMB121"; break;
	case ERJ135: mode = "ERJ135"; break;
	case ERJ140: mode = "ERJ140"; break;
	case ERJ145: mode = "ERJ145"; break;
	case E175: mode = "E175"; break;
	case E195: mode = "E195"; break;
	}
	out << setw(15) << manuf << setw(15) << mode << setw(12) << "MC-" << Plane.bortnum;
	if (Plane.ISINFLIGHT) out << setw(10) << "Да";
	else out << setw(10) << "Нет";
	if (Plane.ISONREPAIR) out << setw(10) << "Да";
	else out << setw(10) << "Нет"<<setw(40)<<Plane.location;
	return out;
}
istream& operator>> (istream& in, plane& Plane) //перегрузка ввода.добавить ноыве поля при необходимости
{
	Manufsel:cout << "Выберите производителя:\n1)Airbus\n2)ATR\n3)Saab\n4)Туполев\n5)Boeing\n6)Bombardier\n7)Embraer\n";
	int input,input2;
	in >> input;
	if (input > 7 || input < 1 || in.fail()) {
		in.clear();
		in.ignore(10000, '\n');
		goto Manufsel;
	}
	Plane.manufacturer = static_cast<manufacturer_>(input);
	in.ignore(10000, '\n');
	Modelsel:cout << "Выберите модель:\n";
	switch (Plane.manufacturer) {
	case Airbus:
		cout << "1)A220\n2)A320\n3)A350\n4)A380\n";
		in >> input2;
		if (input2 > 4 || input2 < 1 || in.fail()) {
			in.clear();
			in.ignore(10000, '\n');
			goto Modelsel;
		}
		Plane.model = static_cast<model_>(input2);
		break;
	case ATR: 
		cout << "1)ATR42\n2)ATR72\n";
		in >> input2;
		if (input2 > 2 || input2 < 1 || in.fail()) {
			in.clear();
			in.ignore(10000, '\n');
			goto Modelsel;
		}
		Plane.model = static_cast<model_>(input2+4);
		break;
	case Saab: 
		cout << "1)SAAB340\n2)SAAB200\n";
		in >> input2;
		if (input2 > 2 || input2 < 1 || in.fail()) {
			in.clear();
			in.ignore(10000, '\n');
			goto Modelsel;
		}
		Plane.model = static_cast<model_>(input2 + 6);
		break;
	case Туполев:
		cout << "1)TY204\n2)TY214\n3)TY324\n4)TY330\n5)TY134\n6)TY154\n";
		in >> input2;
		if (input2 > 6 || input2 < 1 || in.fail()) {
			in.clear();
			in.ignore(10000, '\n');
			goto Modelsel;
		}
		Plane.model = static_cast<model_>(input2+8);
		break;
	case Boeing: 
		cout << "1)BOEING737\n2)BOEING747\n3)BOEING787\n";
		in >> input2;
		if (input2 > 3 || input2 < 1 || in.fail()) {
			in.clear();
			in.ignore(10000, '\n');
			goto Modelsel;
		}
		Plane.model = static_cast<model_>(input2+14);
		break;
	case Bombardier: 
		cout << "1)CRJ200\n2)CRJ700\n";
		in >> input2;
		if (input2 > 2 || input2 < 1 || in.fail()) {
			in.clear();
			in.ignore(10000, '\n');
			goto Modelsel;
		}
		Plane.model = static_cast<model_>(input2 + 17);
		break;
	case Embraer:
		cout << "1)EMB121\n2)ERJ135\n3)ERJ140\n4)ERJ145\n5)E175\n6)E195\n";
		in >> input2;
		if (input2 > 6 || input2 < 1 || in.fail()) {
			in.clear();
			in.ignore(10000, '\n');
			goto Modelsel;
		}
		Plane.model = static_cast<model_>(input2 + 19);
		break;
	}
	in.ignore(10000, '\n');
	Plane.ISINFLIGHT = false;
	Plane.ISONREPAIR = false;
	return in;
}
bool compbrtn(plane a, plane b) {
	return (a.GetBortNumber() < b.GetBortNumber());
}
bool complocat(plane a, plane b) {
	return (a.GetLocation() > b.GetLocation());
}

void plane::SavePlane(Sheet* sheet, int position) {
	switch (manufacturer) {
	case Airbus: sheet->writeStr(position, 1,L"Airbus"); break;
	case ATR: sheet->writeStr(position, 1, L"ATR"); break;
	case Saab:sheet->writeStr(position, 1, L"Saab"); break;
	case Туполев:sheet->writeStr(position, 1, L"Туполев"); break;
	case Boeing: sheet->writeStr(position, 1, L"Boeing"); break;
	case Bombardier:sheet->writeStr(position, 1, L"Bombardier"); break;
	case Embraer: sheet->writeStr(position, 1, L"Embraer"); break;
	}
	switch (model) {
	case A220: sheet->writeStr(position, 2, L"A220"); break;
	case A320: sheet->writeStr(position, 2, L"A320"); break;
	case A350: sheet->writeStr(position, 2, L"A350"); break;
	case A380: sheet->writeStr(position, 2, L"A380"); break;
	case ATR42: sheet->writeStr(position, 2, L"ATR42"); break;
	case ATR72: sheet->writeStr(position, 2, L"ATR72"); break;
	case SAAB340: sheet->writeStr(position, 2, L"SAAB340"); break;
	case SAAB200: sheet->writeStr(position, 2, L"SAAB200"); break;
	case TY204: sheet->writeStr(position, 2, L"TY204"); break;
	case TY214: sheet->writeStr(position, 2, L"TY214"); break;
	case TY324: sheet->writeStr(position, 2, L"TY324"); break;
	case TY330: sheet->writeStr(position, 2, L"TY330"); break;
	case TY134: sheet->writeStr(position, 2, L"TY134"); break;
	case TY154: sheet->writeStr(position, 2, L"TY154"); break;
	case BOEING737: sheet->writeStr(position, 2, L"BOEING737"); break;
	case BOEING747: sheet->writeStr(position, 2, L"BOEING747"); break;
	case BOEING787: sheet->writeStr(position, 2, L"BOEING787"); break;
	case CRJ200: sheet->writeStr(position, 2, L"CRJ200"); break;
	case CRJ700: sheet->writeStr(position, 2, L"CRJ700"); break;
	case EMB121: sheet->writeStr(position, 2, L"EMB121"); break;
	case ERJ135: sheet->writeStr(position, 2, L"ERJ135"); break;
	case ERJ140: sheet->writeStr(position, 2, L"ERJ140"); break;
	case ERJ145: sheet->writeStr(position, 2, L"ERJ145"); break;
	case E175: sheet->writeStr(position, 2, L"E175"); break;
	case E195: sheet->writeStr(position, 2, L"E195"); break;
	}
	sheet->writeNum(position, 3, bortnum);
	sheet->writeNum(1, 3, num);
	sheet->writeBool(position, 4, ISINFLIGHT);
	sheet->writeBool(position, 5, ISONREPAIR);
	string str = location;

	auto get_wchar = [](const char* c)->const wchar_t*
	{
		const size_t cSize = strlen(c) + 1;
		wchar_t* wc = new wchar_t[cSize];
		mbstowcs(wc, c, cSize);
		return wc;
	};
	const wchar_t* str_wchar = get_wchar(str.c_str());

	sheet->writeStr(position, 6, str_wchar);
	delete[] str_wchar;
	
}
void plane::LoadPlane(Sheet* sheet, int position) {
	const wchar_t* wc = sheet->readStr(position, 1);
	wstring ws = wc;
	if(ws== L"Airbus") manufacturer=Airbus;
	if (ws == L"ATR") manufacturer = ATR;
	if (ws == L"Saab") manufacturer = Saab;
	if (ws == L"Туполев") manufacturer = Туполев;
	if (ws == L"Boeing") manufacturer = Boeing;
	if (ws == L"Bombardier") manufacturer = Bombardier;
	if (ws == L"Embraer") manufacturer = Embraer;
	ws.clear();
	const wchar_t* wc1 = sheet->readStr(position, 2);
	ws = wc1;
	if (ws == L"A220") model = A220;
	if (ws == L"A320") model = A320;
	if (ws == L"A350") model = A350;
	if (ws == L"A380") model = A380;
	if (ws == L"ATR42") model = ATR42;
	if (ws == L"ATR72") model = ATR72;
	if (ws == L"SAAB340") model = SAAB340;
	if (ws == L"SAAB200") model = SAAB200;
	if (ws == L"TY204") model = TY204;
	if (ws == L"TY214") model = TY214;
	if (ws == L"TY324") model = TY324;
	if (ws == L"TY330") model = TY330;
	if (ws == L"TY134") model = TY134;
	if (ws == L"TY154") model = TY154;
	if (ws == L"BOEING737") model = BOEING737;
	if (ws == L"BOEING747") model = BOEING747;
	if (ws == L"BOEING787") model = BOEING787;
	if (ws == L"CRJ200") model = CRJ200;
	if (ws == L"CRJ700") model = CRJ700;
	if (ws == L"EMB121") model = EMB121;
	if (ws == L"ERJ135") model = ERJ135;
	if (ws == L"ERJ140") model = ERJ140;
	if (ws == L"ERJ145") model = ERJ145;
	if (ws == L"E175") model = E175;
	if (ws == L"E195") model = E195;
	ws.clear();
	num = sheet->readNum(1, 3);
	bortnum = sheet->readNum(position, 3);
	ISINFLIGHT = sheet->readBool(position, 4);
	ISONREPAIR = sheet->readBool(position, 5);
	wc = sheet->readStr(position, 6);
	auto get_char = [](const wchar_t* wc)->const char*
	{
		const size_t cSize = wcslen(wc) + 1;
		char* c = new char[cSize];
		wcstombs(c, wc, cSize);
		return c;
	};
	const char* str_char = get_char(wc);
	location = str_char;
}
void flight::addflight(plane* selectedplane, string arriv) {
	departure = selectedplane->location;
	arrival = arriv;
	numf++;
	flightnumber += numf;
	planebortnum = selectedplane->bortnum;
	string flstr; flstr = to_string(flightnumber);
	planeadr = selectedplane;
	selectedplane->ISINFLIGHT = true;
	selectedplane->location = "В рейсе МС-" + flstr + " " + departure + " - " + arrival;

}

void flight::showflight() {
	cout << setw(12) << "МС-" << flightnumber << setw(12) << "МС-" << planebortnum << setw(15) << departure << setw(15) << arrival<<endl;
}

flight::flight() {
	planeadr = nullptr;
}
int flight::GetFlightNumber() {
	return flightnumber;
}

void flight::endflight(vector<flight>& oldflights) {
	oldflights.push_back(*this);
	oldflights[oldflights.size() - 1].planeadr = nullptr;
	if (planeadr != nullptr) {
	planeadr->ISINFLIGHT = false;
	planeadr->location = arrival;
}

}
void flight::LoadFlight(Sheet* sheet, int position, vector<plane>& planes, bool isCurrent) {
	numf = sheet->readNum(1, 3);
	flightnumber = sheet->readNum(position,1);
	planebortnum = sheet->readNum(position, 2);
	if (isCurrent)for (int i = 0; i < planes.size(); i++) {
		if (planes[i].GetBortNumber() == planebortnum) planeadr = &(planes[i]);
	}
	else planeadr = nullptr;
	const wchar_t* wc = sheet->readStr(position, 3);
	auto get_char = [](const wchar_t* wc)->const char*
	{
		const size_t cSize = wcslen(wc) + 1;
		char* c = new char[cSize];
		wcstombs(c, wc, cSize);
		return c;
	};
	const char* str_char = get_char(wc);
	departure = str_char;
	const wchar_t* wc1 = sheet->readStr(position, 4);
	const char* str_char1 = get_char(wc1);
	arrival = str_char1;

}
void flight::SaveFlight(Sheet* sheet, int position) {
	sheet->writeNum(position, 1, flightnumber);
	sheet->writeNum(position, 2, planebortnum);
	sheet->writeNum(1, 3, numf);
	string str = departure;
	auto get_wchar = [](const char* c)->const wchar_t*
	{
		const size_t cSize = strlen(c) + 1;
		wchar_t* wc = new wchar_t[cSize];
		mbstowcs(wc, c, cSize);
		return wc;
	};
	const wchar_t* str_wchar = get_wchar(str.c_str());
	sheet->writeStr(position, 3, str_wchar);
	str = arrival;
	str_wchar = get_wchar(str.c_str());
	sheet->writeStr(position, 4, str_wchar);
}