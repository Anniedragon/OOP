//lab3.1
#include <iostream>
using namespace std;
struct phone
{
	int area; 
	int exchange; 
	int number; 
};
int main()
{
	phone ph1 = { 212, 767, 8900 }; 
	phone ph2; 
	cout << "\nEnter your area code, exchange, and number";
	cout << "\n(Don't use leading zeros): ";
	cin >> ph2.area >> ph2.exchange >> ph2.number;
	cout << "\nMy number is " 
		<< '(' << ph1.area << ") "
		<< ph1.exchange << '-' << ph1.number;
	cout << "\nYour number is "
		<< '(' << ph2.area << ") "
		<< ph2.exchange << '-' << ph2.number << endl;
	return 0;
}

//lab3.2
#include <iostream>
using namespace std;
struct point
{
	int xCo; 
	int yCo; 
};
int main()
{
	point p1, p2, p3; 
	cout << "\nEnter coordinates for p1: "; 
	cin >> p1.xCo >> p1.yCo; 
	cout << "Enter coordinates for p2: ";
	cin >> p2.xCo >> p2.yCo;
	p3.xCo = p1.xCo + p2.xCo; 
	p3.yCo = p1.yCo + p2.yCo; 
	cout << "Coordinates of p1+p2 are: " 
		<< p3.xCo << ", " << p3.yCo << endl;
	return 0;
}

//lab3.3.1
#include <iostream>
using namespace std;
struct Distance
{
	int feet;
	float inches;
};
struct Volume
{
	Distance length;
	Distance width;
	Distance height;
};
int main()
{
	float l, w, h;
	Volume room1 = { { 16, 3.5 }, { 12, 6.25 }, { 8, 1.75 } };
	l = room1.length.feet + room1.length.inches / 12.0;
	w = room1.width.feet + room1.width.inches / 12.0;
	h = room1.height.feet + room1.height.inches / 12.0;
	cout << "Volume = " << l * w * h << " cubic feet\n";
	return 0;
}
//lab3.3.2
#include <iostream>
using namespace std;
struct Distance 
{
	int feet;
	float inches;
};
int main()
{
	Distance d1, d3; 
	Distance d2 = { 11, 6.25 }; 
	cout << "\nEnter feet: "; cin >> d1.feet;
	cout << "Enter inches: "; cin >> d1.inches;
	d3.inches = d1.inches + d2.inches; 
	d3.feet = 0; 
	if (d3.inches >= 12.0) {
		d3.inches -= 12.0; 
		d3.feet++; 
	}
	d3.feet += d1.feet + d2.feet; 
	cout << d1.feet << "\'-" << d1.inches << "\" + ";
	cout << d2.feet << "\'-" << d2.inches << "\" = ";
	cout << d3.feet << "\'-" << d3.inches << "\"\n";
	return 0;
}

//lab3.4
#include <iostream>
using namespace std;
struct employee {
	int number;
	float allowance;
};
int main() {
	employee em1, em2, em3;
	cout << "Enter the number and allowance of 1st employee" << endl;
	cin >> em1.number >> em1.allowance;
	cout << "Enter the number and allowance of 2nd employee" << endl;
	cin >> em2.number >> em2.allowance;
	cout << "Enter the number and allowance of 3d employee" << endl;
	cin >> em3.number >> em3.allowance;
	cout << "1st employee" << endl
		<< "Number: " << em1.number << endl
		<< "Allowance: " << em1.allowance << endl;
	cout << "2nd employee" << endl
		<< "Number: " << em2.number << endl
		<< "Allowance: " << em2.allowance << endl;
	cout << "3d employee" << endl
		<< "Number: " << em3.number << endl
		<< "Allowance: " << em3.allowance << endl;
	return 0;
}

//lab3.5
#include <iostream>
using namespace std;
struct date {
	int day;
	int month;
	int year;
};
int main() {
	date d;
	char slash;
	cout << "Enter a date in 00/00/0000 format" << endl;
	cin >> d.day >> slash >> d.month >> slash >> d.year;
	cout << "\nYour date is: " << d.day << "/" << d.month << "/" << d.year;
	return 0;
}

//lab3.6
#include <iostream>
using namespace std;
enum etype { laborer, secretary, manager, accountant, executive, researcher };
int main() {
	int x;
	char letter;
	cout << "Enter the 1st letter of the position: ";
	cin >> letter;
	switch (letter) {
	case 'l':
		x = 0;
		break;
	case 's':
		x = 1;
		break;
	case 'm':
		x = 2;
		break;
	case 'a':
		x = 3;
		break;
	case 'e':
		x = 4;
		break;
	case 'r':
		x = 5;
		break;
	default:
		cout << "Try again" << endl;
		x = -1;
		break;
	}
	switch (x) {
	case 0:
		cout << "The full title is: laborer";
		break;
	case 1:
		cout << "The full title is: secretary";
		break;
	case 2:
		cout << "The full title is: manager";
		break;
	case 3:
		cout << "The full title is: accountant";
		break;
	case 4:
		cout << "The full title is: executive";
		break;
	case 5:
		cout << "The full title is: researcher";
		break;
	default:
		cout << "Try again" << endl;
		break;
	}
	return 0;
}

//lab3.7
#include <iostream>
#include <string>
using namespace std;
struct employee {
	int number;
	float salary;
	string day;
	string month;
	int year;
	string work;
};
enum etype { laborer = 1, secretary, manager, accountant, executive, researcher };
int main() {
	int position1 = 0;
	int position2 = 0;
	int position3 = 0;
	char slash;
	employee em1, em2, em3;
	cout << "Enter the numbers for 3 employees" << endl
		<< "1st employee: ";
	cin >> em1.number;
	cout << "2nd employee: ";
	cin >> em2.number;
	cout << "3d employee: ";
	cin >> em3.number;
	cout << "\nEnter the salary for 3 employees" << endl
		<< "1st employee: ";
	cin >> em1.salary;
	cout << "2nd employee: ";
	cin >> em2.salary;
	cout << "3d employee: ";
	cin >> em3.salary;
	cout << "\nEnter, when each of emloyees has started to work in 00/00/0000 format" << endl
		<< "1st employee: ";
	cin >> em1.day >> slash >> em1.month >> slash >> em1.year;
	cout << "2nd employee: ";
	cin >> em2.day >> slash >> em2.month >> slash >> em2.year;
	cout << "3d employee: ";
	cin >> em3.day >> slash >> em3.month >> slash >> em3.year;
	cout << "\nEnter the position for 3 employees:" << endl
		<< "laborer - 1, secretary - 2, manager - 3, accountant - 4, executive - 5, researcher - 6" << endl
		<< "1st employee: ";
	cin >> position1;
	cout << "2nd employee: ";
	cin >> position2;
	cout << "3d employee: ";
	cin >> position3;
	switch (position1) {
	case laborer:
		em1.work = "laborer";
		break;
	case secretary:
		em1.work = "secretary";
		break;
	case manager:
		em1.work = "manager";
		break;
	case accountant:
		em1.work = "accountant";
		break;
	case executive:
		em1.work = "executive";
		break;
	case researcher:
		em1.work = "researcher";
		break;
	default:
		cout << "Your position is absent. Try again." << endl;
		break;
	}
	switch (position2) {
	case laborer:
		em2.work = "laborer";
		break;
	case secretary:
		em2.work = "secretary";
		break;
	case manager:
		em2.work = "manager";
		break;
	case accountant:
		em2.work = "accountant";
		break;
	case executive:
		em2.work = "executive";
		break;
	case researcher:
		em2.work = "researcher";
		break;
	default:
		cout << "Your position is absent. Try again." << endl;
		break;
	}
	switch (position3) {
	case laborer:
		em3.work = "laborer";
		break;
	case secretary:
		em3.work = "secretary";
		break;
	case manager:
		em3.work = "manager";
		break;
	case accountant:
		em3.work = "accountant";
		break;
	case executive:
		em3.work = "executive";
		break;
	case researcher:
		em3.work = "researcher";
		break;
	default:
		cout << "Your position is absent. Try again." << endl;
		break;
	}
	cout << "The full information about the 1st employee." << endl
		<< "Number: " << em1.number << endl
		<< "Salary: " << em1.salary << endl
		<< "Date: " << em1.day << "/" << em1.month << "/" << em1.year << endl
		<< "Position: " << em1.work << endl;
	cout << "\nThe full information about the 2nd employee." << endl
		<< "Number: " << em2.number << endl
		<< "Salary: " << em2.salary << endl
		<< "Date: " << em2.day << "/" << em2.month << "/" << em2.year << endl
		<< "Position: " << em2.work << endl;
	cout << "\nThe full information about the 3d employee." << endl
		<< "Number: " << em3.number << endl
		<< "Salary: " << em3.salary << endl
		<< "Date: " << em3.day << "/" << em3.month << "/" << em3.year << endl
		<< "Position: " << em3.work << endl;
	return 0;
}
//lab3.8
//lab3.9
//lab3.10
//lab3.11
//lab3.12
