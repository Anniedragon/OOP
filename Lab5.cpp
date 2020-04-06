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

//lab5.4 IN PROGRESS
#include <iostream>
using namespace std;
class employee {
public:
	int num;
	float allow;
	employee() : num(0), allow(0.0) {
	}
	employee(int n, float a) : num(n), allow(a) {
	}
	void display() const {
		cout << "Number: " << num << endl
			<< "Allowance: " << allow << endl;
	}
};
int main() {
	const employee em1(1, 67000);
	const employee em2(2, 120000);
	const employee em3(3, 45000);
	/*cout << "Enter the number and allowance of 1st employee" << endl;
	cin >> num;
	cin >> allow;*/
	cout << "1st employee" << endl;
	em1.display();
	cout << "\n2nd employee" << endl;
	em2.display();
	cout << "\n3d employee" << endl;
	em3.display();
	/*cout << "Enter the number and allowance of 2nd employee" << endl;
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
		<< "Allowance: " << em3.allowance << endl;*/
	return 0;
}

//lab5.5
//lab5.6
//lab5.7
//lab5.8
//lab5.9
//lab5.10
//lab5.11
//lab5.12
