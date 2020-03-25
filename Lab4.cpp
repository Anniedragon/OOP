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
	bool pr = false;
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
int power1(int zn, int p);
long power2(long zn, int p);
float power3(float zn, int p);
char power4(char zn, int p);
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
int power1(int zn, int p) {
	int result = 1;
	for (int i = 0; i < p; i++) {
		result *= zn;
	}
	return result;
}
long power2(long zn, int p) {
	long result = 1;
	for (int i = 0; i < p; i++) {
		result *= zn;
	}
	return result;
}
float power3(float zn, int p) {
	float result = 1.0;
	for (int i = 0; i < p; i++) {
		result *= zn;
	}
	return result;
}
char power4(char zn, int p) {
	char result = zn;
	for (int i = 0; i < p; i++) {
		result *= zn;
	}
	return result;
}

//lab4.8
//lab4.9
//lab4.10
//lab4.11
//lab4.12
