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
//lab4.5
//lab4.6
//lab4.7
//lab4.8
//lab4.9
//lab4.10
//lab4.11
//lab4.12
