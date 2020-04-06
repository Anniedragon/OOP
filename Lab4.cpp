//lab4.1
#include <iostream>
using namespace std;
float circarea(float radius);
int main() {
	double rad;
	setlocale(LC_ALL, "Russian");
	cout << "\nВведите радиус окружности: ";
	cin >> rad;
	cout << "S площадь равна " << circarea(rad) << endl;
	return 0;
}
float circarea(float r) {
	const float PI = 3.14159F;
	return r * r * PI;
}

//lab4.2
#include <iostream>
using namespace std;
double power(double n, int p = 2);
int main() {
	double number, answer;
	int pow;
	char yesorno;
	setlocale(LC_ALL, "Russian");
	cout << "\nВведите число: ";
	cin >> number;
	cout << "Будете вводить степень (y/n)? ";
	cin >> yesorno;
	if (yesorno == 'y') {
		cout << "Введите степень: ";
		cin >> pow;
		answer = power(number, pow);
}
	else answer = power(number);
	cout << "Ответ " << answer << endl;
	return 0;
}
double power(double n, int p) {
	double result = 1.0;
	for (int j = 0; j < p; j++)
		result *= n;
	return result;
}

//lab4.3
#include <iostream>
using namespace std;
int main()
{
	void zeroSmaller(int&, int&);
	setlocale(LC_ALL, "Russian");
	int а = 4, б = 7, в = 11, г = 9;
	zeroSmaller(а, б);
	zeroSmaller(в, г);
	cout << "\na == " << а << " б == " << б
		<< " в == " << в << " г == " << г;
	return 0;
}
void zeroSmaller(int& first, int& second)
{
	if (first < second)
		first = 0;
	else
		second = 0;
}

//lab4.4
#include <iostream>
using namespace std;
struct Distance 
{
	int feet;
	float inches;
};
Distance bigengl(Distance, Distance);
void engldisp(Distance);
int main() {
	setlocale(LC_ALL, "Russian");
	Distance d1, d2, d3;
	cout << "\nВведите число футов: "; cin >> d1.feet;
	cout << "Введите число дюймов: "; cin >> d1.inches;
	cout << "\nВведите число футов: "; cin >> d2.feet;
	cout << "Введите число дюймов: "; cin >> d2.inches;
	d3 = bigengl(d1, d2); 
	cout << "\nd1 = "; engldisp(d1);
	cout << "\nd2 = "; engldisp(d2);
	cout << "\nнаибольшее "; engldisp(d3); cout << endl;
	return 0;
}
Distance bigengl(Distance dd1, Distance dd2)
{
	if (dd1.feet > dd2.feet) 
		return dd1; 
	if (dd1.feet < dd2.feet)
		return dd2;
	if (dd1.inches > dd2.inches)
		return dd1; 
	else 
		return dd2;
}
void engldisp(Distance dd)
{
	cout << dd.feet << "\'-" << dd.inches << "\"";
}

//lab4.5
#include <iostream>
using namespace std;
struct time {
	int hours;
	int minutes;
	int seconds;
};
long hms_to_secs(int h, int m, int s);
int main() {
	time t;
	char points;
	cout << "Enter the time in 00:00:00 format." << endl;
	cin >> t.hours >> points >> t.minutes >> points >> t.seconds;
	cout << hms_to_secs(t.hours, t.minutes, t.seconds) << " sec." << endl;
	return 0;
}
long hms_to_secs(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}

//lab4.6
#include <iostream>
using namespace std;
struct time {
	int seconds;
	int minutes;
	int hours;
};
long time_to_secs(int h, int m, int s);
int secs_to_time(long ts);
int main() {
	setlocale(LC_ALL, "Russian");
	long totalsecsum;
	time t1, t2, t3;
	char points;
	float des_hours;
	int k = 10;
	cout << "Введите время1 в формате 00:00:00" << endl;
	cin >> t1.hours >> points >> t1.minutes >> points >> t1.seconds;
	cout << "Введите время2 в формате 00:00:00" << endl;
	cin >> t2.hours >> points >> t2.minutes >> points >> t2.seconds;
	totalsecsum = time_to_secs(t1.hours, t1.minutes, t1.seconds) + time_to_secs(t2.hours, t2.minutes, t2.seconds);
	t3.minutes = secs_to_time(totalsecsum);
	t3.hours = secs_to_time(totalsecsum) / 60;
	t3.seconds = (t3.hours * 3600 + t3.minutes * 60) - totalsecsum;
	while (t3.seconds >= 60) {
		t3.seconds /= 60;
		t3.minutes++;
	}
	while (t3.minutes >= 60) {
		t3.minutes = t3.minutes / 60;
		t3.hours++;
	}
	cout << t3.hours << " ч. " << t3.minutes << " мин. " << t3.seconds << " с.";
	return 0;
}
long time_to_secs(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}
int secs_to_time(long ts) {
	return ts / 60;
}

//lab4.7 
#include <iostream>
using namespace std;
struct znach {
	int zn1;
	long zn2;
	float zn3;
	char zn4;
};
double power1(int zn, int p);
double power2(long zn, int p);
double power3(float zn, int p);
double power4(char zn, int p);
int main() {
	setlocale(LC_ALL, "Russian");
	znach z;
	int st;
	cout << "Введите число: ";
	cin >> z.zn1;
	cout << "Введите большое число: ";
	cin >> z.zn2;
	cout << "Введите десятичную дробь: ";
	cin >> z.zn3;
	cout << "Введите символ: ";
	cin >> z.zn4;
	cout << "Введите степень: ";
	cin >> st;
	cout << "\n" << power1(z.zn1, st) << endl
		<< power2(z.zn2, st) << endl
		<< power3(z.zn3, st) << endl
		<< power4(z.zn4, st) << endl;
	return 0;
}
double power1(int zn, int p) {
	int result = 1;
	for (int i = 0; i < p; i++) {
		result *= zn;
	}
	return result;
}
double power2(long zn, int p) {
	long result = 1;
	for (int i = 0; i < p; i++) {
		result *= zn;
	}
	return result;
}
double power3(float zn, int p) {
	float result = 1.0;
	for (int i = 0; i < p; i++) {
		result *= zn;
	}
	return result;
}
double power4(char zn, int p) {
	char result = zn;
	for (int i = 0; i < p; i++) {
		result *= zn;
	}
	return result;
}


//lab4.8
#include <iostream>
#include <string>
using namespace std;
string swap(string arg1, string arg2);
int main() {
	setlocale(LC_ALL, "Russian");
	string a, b;
	cout << "Enter 1st number: ";
	cin >> a;
	cout << "Enter 2nd number: ";
	cin >> b;
	cout << swap(a, b);
	return 0;
}
string swap(string arg1, string arg2) {
	string temp = "0";
	string result;
	temp = arg1;
	arg1 = arg2;
	arg2 = temp;
	result = arg1 + " " + arg2;
	return result;
}

//lab4.9
#include <iostream>
#include <string>
using namespace std;
struct time {
	string hours;
	string minutes;
	string seconds;
};
string swap(string arg1, string arg2);
int main() {
	setlocale(LC_ALL, "Russian");
	time t1, t2;
	string time1, time2;
	cout << "Enter 1st time." << endl;
	cout << "Enter hours: ";
	cin >> t1.hours;
	cout << "Enter minutes: ";
	cin >> t1.minutes;
	cout << "Enter seconds: ";
	cin >> t1.seconds;
	cout << "Enter 2nd number." << endl;
	cout << "Enter hours: ";
	cin >> t2.hours;
	cout << "Enter minutes: ";
	cin >> t2.minutes;
	cout << "Enter seconds: ";
	cin >> t2.seconds;
	time1 = t1.hours + ":" + t1.minutes + ":" + t1.seconds;
	time2 = t2.hours + ":" + t2.minutes + ":" + t2.seconds;
	cout << "\n" << swap(time1, time2);
	return 0;
}
string swap(string arg1, string arg2) {
	string temp = "0";
	string result;
	temp = arg1;
	arg1 = arg2;
	arg2 = temp;
	result = arg1 + "   " + arg2;
	return result;
}

//lab4.10
#include <iostream>
using namespace std;
int function(int arg);
int main() {
	for (int i = 0; i < 11; i++) {
		cout << function(i) << endl;
	}
}
int function(int arg) {
	return arg;
}

//lab4.11
#include <iostream>
using namespace std;
struct sterling {
	int pounds;
	int shillings;
	int pence;
};
void ster_useless(sterling sum);
int ster_sum(int sum1, int sum2);
int ster_cout(int arg);
int main() {
	sterling st1, st2, stsum;
	cout << "Enter the first sum: ";
	cin >> st1.pounds >> st1.shillings >> st1.pence;
	cout << "Enter the second sum: ";
	cin >> st2.pounds >> st2.shillings >> st2.pence;
	stsum.pounds = ster_sum(st1.pounds, st2.pounds);
	stsum.shillings = ster_sum(st1.shillings, st2.shillings);
	stsum.pence = ster_sum(st1.pence, st2.pence);
	while (stsum.pence > 12) {
		stsum.shillings += stsum.pence / 12;
		stsum.pence -= 12;
	}
	while (stsum.shillings > 20) {
		stsum.pounds += stsum.shillings / 20;
		stsum.shillings -= 20;
	}
	cout << ster_cout(stsum.pounds) << " " << ster_cout(stsum.shillings) << " " << ster_cout(stsum.pence) << endl;
	return 0;
}
void ster_useless(sterling sum) {
}
int ster_sum(int sum1, int sum2) {
	return sum1 + sum2;
}
int ster_cout(int arg) {
	return arg;
}

//lab4.12
#include <iostream>
using namespace std;
struct fraction {
	int chisl;
	int znam;
	int resch;
	int reszn;
};
int fadd(int arg1, int arg2, int arg3, int arg4);
int fsub(int arg1, int arg2, int arg3, int arg4);
int fmul(int arg1, int arg2);
int fdiv(int arg1, int arg2);
int main() {
	setlocale(LC_ALL, "Russian");
	fraction fr, fr1, fr2;
	char flag = '+';
	char oper = '0';
	char slash;
	while (flag == '+') {
		cout << "Введите первую дробь в формате a/b: ";
		cin >> fr1.chisl >> slash >> fr1.znam;
		cout << "Введите первую дробь в формате c/d: ";
		cin >> fr2.chisl >> slash >> fr2.znam;
		cout << "Выберите действие: сложение(+), вычитание(-), умножение(*), деление(/)" << endl;
		cin >> oper;
		switch (oper) {
		case '+':
			fr.resch = fadd(fr1.chisl, fr2.znam, fr1.znam, fr2.chisl);
			fr.reszn = fr1.znam * fr2.znam;
			cout << fr.resch << "/" << fr.reszn << endl;
			cout << "Хотите продолжить? (+/-)" << endl;
			cin >> flag;
			break;
		case '-':
			fr.resch = fsub(fr1.chisl, fr2.znam, fr1.znam, fr2.chisl);
			fr.reszn = fr1.znam * fr2.znam;
			cout << fr.resch << "/" << fr.reszn << endl;
			cout << "Хотите продолжить? (+/-)" << endl;
			cin >> flag;
			break;
		case '*':
			fr.resch = fmul(fr1.chisl, fr2.chisl);
			fr.reszn = fr1.znam * fr2.znam;
			cout << fr.resch << "/" << fr.reszn << endl;
			cout << "Хотите продолжить? (+/-)" << endl;
			cin >> flag;
			break;
		case '/':
			fr.resch = fdiv(fr1.chisl, fr2.znam);
			fr.reszn = fr2.chisl * fr1.znam;
			cout << fr.resch << "/" << fr.reszn << endl;
			cout << "Хотите продолжить? (+/-)" << endl;
			cin >> flag;
			break;
		default:
			cout << "Такого дейтвия не существует." << endl;
			cout << "Хотите продолжить? (+/-)" << endl;
			cin >> flag;
			break;
		}
	}
	return 0;
}
int fadd(int arg1, int arg2, int arg3, int arg4) {
	return arg1 * arg2 + arg3 * arg4;
}
int fsub(int arg1, int arg2, int arg3, int arg4) {
	return arg1 * arg2 - arg3 * arg4;
}
int fmul(int arg1, int arg2) {
	return arg1 * arg2;
}
int fdiv(int arg1, int arg2) {
	return arg1 * arg2;
}
