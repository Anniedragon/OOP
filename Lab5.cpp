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
#include <iostream>
#include <string>
using namespace std;
class Date {
private:
	int day;
	int month;
	int year;
public:
	void get_date(int em_day, int em_month, int em_year) {
		day = em_day;
		month = em_month;
		year = em_year;
	}
	void showdate() {
		cout << "Start date: " << day << "/" << month << "/" << year << "." << endl;
	}
};
enum etype { laborer = 1, secretary, manager, accountant, executive, researcher };
class employee {
private:
	int number;
	float salary;
	Date data;
	etype profession;
public:
	void getemployee(int em_number, float em_salary, int em_day, int em_month, int em_year, etype em_prof) {
		number = em_number;
		salary = em_salary;
		data.get_date(em_day, em_month, em_year);
		profession = em_prof;
	}

	void putemployee() {
		cout << "\nNumber: " << number << endl
			<< "Salary: " << salary << endl;
		data.showdate();
		cout << "Profession: ";
		switch (profession) {
		case 1:
			cout << "laborer" << endl;
			break;
		case 2:
			cout << "secretary" << endl;
			break;
		case 3:
			cout << "manager" << endl;
			break;
		case 4:
			cout << "accountant" << endl;
			break;
		case 5:
			cout << "executive" << endl;
			break;
		case 6:
			cout << "researcher" << endl;
			break;
		default:
			cout << "Your position is absent. Try again." << endl;
			break;
		}
	}
};
int main() {
	employee em1, em2, em3;
	int number, day, month, year;
	float salary;
	etype profession;
	char slash, letter;
	cout << "Enter information about the 1st employee." << endl
		<< "Enter number: ";
	cin >> number;
	cout << "Enter salary: ";
	cin >> salary;
	cout << "Enter the start date in 00/00/0000 format: ";
	cin >> day >> slash >> month >> slash >> year;
	cout << "Enter th 1st letter of the profession (laborer, secretary, manager, accountant, executive, researcher): ";
	cin >> letter;
	switch (letter) {
	case 'l':
		profession = laborer;
		break;
	case 's':
		profession = secretary;
		break;
	case 'm':
		profession = manager;
		break;
	case 'a':
		profession = accountant;
		break;
	case 'e':
		profession = executive;
		break;
	case 'r':
		profession = researcher;
		break;
	default:
		cout << "Try again" << endl;
		break;
	}
	em1.getemployee(number, salary, day, month, year, profession);
	em1.putemployee();
	cout << "\nEnter information about the 2nd employee." << endl
		<< "Enter number: ";
	cin >> number;
	cout << "Enter salary: ";
	cin >> salary;
	cout << "Enter the start date in 00/00/0000 format: ";
	cin >> day >> slash >> month >> slash >> year;
	cout << "Enter th 1st letter of the profession (laborer, secretary, manager, accountant, executive, researcher): ";
	cin >> letter;
	switch (letter) {
	case 'l':
		profession = laborer;
		break;
	case 's':
		profession = secretary;
		break;
	case 'm':
		profession = manager;
		break;
	case 'a':
		profession = accountant;
		break;
	case 'e':
		profession = executive;
		break;
	case 'r':
		profession = researcher;
		break;
	default:
		cout << "Try again" << endl;
		break;
	}
	em2.getemployee(number, salary, day, month, year, profession);
	em2.putemployee();
	cout << "\nEnter information about the 3d employee." << endl
		<< "Enter number: ";
	cin >> number;
	cout << "Enter salary: ";
	cin >> salary;
	cout << "Enter the start date in 00/00/0000 format: ";
	cin >> day >> slash >> month >> slash >> year;
	cout << "Enter th 1st letter of the profession (laborer, secretary, manager, accountant, executive, researcher): ";
	cin >> letter;
	switch (letter) {
	case 'l':
		profession = laborer;
		break;
	case 's':
		profession = secretary;
		break;
	case 'm':
		profession = manager;
		break;
	case 'a':
		profession = accountant;
		break;
	case 'e':
		profession = executive;
		break;
	case 'r':
		profession = researcher;
		break;
	default:
		cout << "Try again" << endl;
		break;
	}
	em3.getemployee(number, salary, day, month, year, profession);
	em3.putemployee();
	return 0;
}

//lab5.7
//lab5.8
//lab5.9
#include <iostream>
#include <string>
using namespace std;
struct fraction {
	int chisl;
	int znam;
};
class Fraction {
private:
	fraction fr1, fr2, frsum;
public:
	void get_frac(fraction u_fr1, fraction u_fr2) {
		fr1 = u_fr1;
		fr2 = u_fr2;
	}
	void frac_sum() {
		frsum.chisl = fr1.chisl * fr2.znam + fr2.chisl * fr1.znam;
		frsum.znam = fr1.znam * fr2.znam;
	}
	void return_frac() {
		cout << frsum.chisl << "/" << frsum.znam << endl;
	}
};
int main() {
	Fraction frac;
	fraction fr1, fr2;
	char slash, flag;
	while (true) {
		cout << "Enter the 1st fraction in a/b format" << endl;
		cin >> fr1.chisl >> slash >> fr1.znam;
		cout << "Enter the 2nd fraction in c/d format" << endl;
		cin >> fr2.chisl >> slash >> fr2.znam;
		frac.get_frac(fr1, fr2);
		frac.frac_sum();
		frac.return_frac();
		cout << "Do you want to continue? Write y/n: ";
		cin >> flag;
		if (flag == 'n') {
			break;
		}
	}
	return 0;
}

//lab5.10
//lab5.11 CLASS METHOD "LOWTERMS" DOESN'T WORK
#include <iostream>
#include <cmath>
using namespace std;
struct fraction {
	long chisl;
	long znam;
};
class Fraction {
private:
	fraction fr1, fr2, fr, frres;
public:
	void get_frac(fraction u_fr1, fraction u_fr2) {
		fr1 = u_fr1;
		fr2 = u_fr2;
	}
	void frac_sum() {
		fr.chisl = fr1.chisl * fr2.znam + fr2.chisl * fr1.znam;
		fr.znam = fr1.znam * fr2.znam;
	}
	void frac_sub() {
		fr.chisl = fr1.chisl * fr2.znam - fr2.chisl * fr1.znam;
		fr.znam = fr1.znam * fr2.znam;
	}
	void frac_mul() {
		fr.chisl = fr1.chisl * fr2.chisl;
		fr.znam = fr1.znam * fr2.znam;
	}
	void frac_div() {
		fr.chisl = fr1.chisl * fr2.znam;
		fr.znam = fr1.znam * fr2.chisl;
	}
	void lowterms() {
		frres.chisl = labs(fr.chisl);
		frres.znam = labs(fr.znam); 
		if (frres.znam == 0) {
			cout << "Forbidden znam";
			exit(1);
		}
		else if (frres.chisl == 0) {
			fr.chisl = 0;
			fr.znam = 1;
		}
	}
	void return_frac() {
		cout << frres.chisl << "/" << frres.znam << endl;
	}
};
int main() {
	Fraction frac;
	fraction fr1, fr2;
	char slash, flag, oper;
	while (true) {
		cout << "Enter the 1st fraction in a/b format: ";
		cin >> fr1.chisl >> slash >> fr1.znam;
		cout << "Enter the 2nd fraction in c/d format: ";
		cin >> fr2.chisl >> slash >> fr2.znam;
		cout << "Enter what you want to do (+, -, *, /): ";
		cin >> oper;
		switch (oper) {
		case '+':
			frac.get_frac(fr1, fr2);
			frac.frac_sum();
			frac.lowterms();
			frac.return_frac();
			cout << "Do you want to continue? Write y/n: ";
			cin >> flag;
			if (flag == 'n') {
				break;
			}
			break;
		case '-':
			frac.get_frac(fr1, fr2);
			frac.frac_sub();
			frac.lowterms();
			frac.return_frac();
			cout << "Do you want to continue? Write y/n: ";
			cin >> flag;
			if (flag == 'n') {
				break;
			}
			break;
		case '*':
			frac.get_frac(fr1, fr2);
			frac.frac_mul();
			frac.lowterms();
			frac.return_frac();
			cout << "Do you want to continue? Write y/n: ";
			cin >> flag;
			if (flag == 'n') {
				break;
			}
			break;
		case '/':
			frac.get_frac(fr1, fr2);
			frac.frac_div();
			frac.lowterms();
			frac.return_frac();
			cout << "Do you want to continue? Write y/n: ";
			cin >> flag;
			if (flag == 'n') {
				break;
			}
			break;
		default:
			cout << "This operation is absent. Try again.";
			cout << "Do you want to continue? Write y/n: ";
			cin >> flag;
			if (flag == 'n') {
				break;
			}
			break;
		}
	}
	return 0;
}
