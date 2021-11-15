#include "plane.h"
plane::plane(manufacturer_ man,model_ mod) {
	manufacturer = man;
	model = mod;
	num++;
	bortnum += num;
	ISINFLIGHT = false;
	ISONREPAIR = false;
	location = "MSQ\0";
}
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
void flight::endflight() {
	if (planeadr != nullptr) {
	planeadr->ISINFLIGHT = false;
	planeadr->location = arrival;
}
}
