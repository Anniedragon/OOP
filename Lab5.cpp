//lab5.1
#include <iostream>
using namespace std;
class Int {
private:
	int i;
public:
	Int() {
		i = 0;
	}
	Int(int ii) {
		i = ii;
	}
	void add(Int i2, Int i3) {
		i = i2.i + i3.i;
	}
	void display() {
		cout << i;
	}
};
int main() {
	Int Int1(7); 
	Int Int2(11); 
	Int Int3; 
	Int3.add(Int1, Int2); 
	cout << "\nInt3 = "; Int3.display(); 
	cout << endl;
	return 0;
}

//lab5.2
#include <iostream>
#include <conio.h>
using namespace std;
const char ESC = 27;
const double TOLL = 0.5;
class tollBooth
{

private:
	unsigned int totalCars; 
	double totalCash; 
public: 
	tollBooth() : totalCars(0), totalCash(0.0){
	}
	void payingCar() 
	{
		totalCars++; totalCash += TOLL;
	}
	void nopayCar() 
	{
		totalCars++;
	}
	void display()const 
	{
		cout << "\n" << "Машины: " << totalCars
			<< " Деньги: " << totalCash
			<< endl;
	}
};
int main()
{
	tollBooth booth1; 
	char ch;
	setlocale(LC_ALL, "Russian");
	cout << "\nНажмите 0 для машины без оплаты,"
		<< "\n 1 для каждой оплачивающей машины,"
		<< "\n Esc для выхода.\n ";
	do {
		ch = _getche(); 
		if (ch == '0') 
			booth1.nopayCar();
		if (ch == '1') 
			booth1.payingCar();
	} while (ch != ESC); 
	booth1.display(); 
	return 0;
}

//lab5.3
#include <iostream>
using namespace std;
class time {
private:
	int hrs, mins, secs;
public:
	time() :hrs(0), mins(0), secs(0) {
	}
	time(int h, int m, int s) :hrs(h), mins(m), secs(s) {
	}
	void display()const {
		cout << hrs << ":" << mins << ":" << secs;
	}
	void add_time(time t1, time t2) {
		secs = t1.secs + t2.secs; 
		if (secs > 59) 
		{
			secs -= 60; mins++;
		} 
		mins += t1.mins + t2.mins; 
		if (mins > 59)
		{
			mins -= 60; hrs++;
		} 
		hrs += t1.hrs + t2.hrs; 
	}
};
int main() {
	const time time1(5, 59, 59); 
	const time time2(4, 30, 30); 
	time time3;
	time3.add_time(time1, time2); 
	cout << "time3 = "; time3.display();
	cout << endl;
	return 0;
}

//lab5.4
#include <iostream>
using namespace std;
class employee {
private:
	int number;
	float salary;
public:
	void get_number(int em_number) {
		number = em_number;
	}
	int return_number() {
		return number;
	}
	void get_salary(float em_salary) {
		salary = em_salary;
	}
	float return_salary() {
		return salary;
	}
};
int main() {
	employee em1, em2, em3;
	int number;
	float salary;
	cout << "Enter the information about the 1st employee." << endl
		<< "Enter number: ";
	cin >> number;
	cout << "Enter salary: ";
	cin >> salary;
	em1.get_number(number);
	em1.get_salary(salary);
	cout << "\nEnter the information about the 2nd employee." << endl
		<< "Enter number: ";
	cin >> number;
	cout << "Enter salary: ";
	cin >> salary;
	em2.get_number(number);
	em2.get_salary(salary);
	cout << "\nEnter the information about the 3d employee." << endl
		<< "Enter number: ";
	cin >> number;
	cout << "Enter salary: ";
	cin >> salary;
	em3.get_number(number);
	em3.get_salary(salary);
	cout << "\nThe information about the 1st employee." << endl
		<< "Number: " << em1.return_number() << endl
		<< "Salary: " << em1.return_salary() << endl
		<< "\nThe information about the 2nd employee." << endl
		<< "Number: " << em2.return_number() << endl
		<< "Salary: " << em2.return_salary() << endl
		<< "\nThe information about the 3d employee." << endl
		<< "Number: " << em3.return_number() << endl
		<< "Salary: " << em3.return_salary() << endl;
	return 0;
}

//lab5.5
#include <iostream>
using namespace std;
struct date {
	int day;
	int month;
	int year;
};
class Date {
private:
	date d;
public:
	void get_date(date today_d) {
		d = today_d;
	}
	void showdate(date d) {
		cout << "\nToday is " << d.day << "/" << d.month << "/" << d.year << ".";
	}
};
int main() {
	Date to_day;
	date today;
	char slash;
	cout << "What's the date today? Enter in 00/00/00 format." << endl;
	cin >> today.day >> slash >> today.month >> slash >> today.year;
	to_day.get_date(today);
	to_day.showdate(today);
	return 0;
}

//lab5.6
//lab5.7
//lab5.8
//lab5.9
//lab5.10
//lab5.11
//lab5.12
