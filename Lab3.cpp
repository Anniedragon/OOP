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
//lab3.7
//lab3.8
//lab3.9
//lab3.10
//lab3.11
//lab3.12
