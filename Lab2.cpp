//lab2.1
#include <iostream>
#include <iomanip> 
using namespace std;
int main()
{
	unsigned long n; 
	cout << "Enter a number: ";
	cin >> n; 
	for (int j = 1; j <= 200; j++) 
	{
		cout << setw(5) << j * n << " "; 
		if (j % 10 == 0) 
			cout << endl; 
	}
	return 0;
}

//lab2.2
#include <iostream>
using namespace std;
int main()
{
	int response;
	double temper;
	cout << "\nType 1 to convert fahrenheit to celsius,"
		<< "\n 2 to convert celsius to fahrenheit: ";
	cin >> response;
	if (response == 1)
	{
		cout << "Enter temperature in fahrenheit: ";
		cin >> temper;
		cout << "In celsius that's " << 5.0 / 9.0 * (temper - 32.0);
	}
	else
	{
		cout << "Enter temperature in celsius: ";
		cin >> temper;
		cout << "In fahrenheit that's " << 9.0 / 5.0 * temper + 32.0;
	}
	cout << endl;
	return 0;
}

//lab2.3
#include <iostream>
#include <conio.h> 
using namespace std;
int main()
{
	char ch;
	unsigned long total = 0; 
	cout << "\nEnter a number: ";
	while ((ch = _getche()) != '\r') 
		total = total * 10 + ch - '0'; 
	cout << "\nNumber is: " << total << endl;
	return 0;
}

//lab2.4
#include <iostream>
using namespace std;
int main()
{
	double n1, n2, ans;
	char oper, ch;
	do {
		cout << "\nEnter first number, operator, second number: ";
		cin >> n1 >> oper >> n2;
		switch (oper)
		{
		case '+': ans = n1 + n2; break;
		case '-': ans = n1 - n2; break;
		case '*': ans = n1 * n2; break;
		case '/': ans = n1 / n2; break;
		default: ans = 0;
		}
		cout << "Answer = " << ans;
		cout << "\nDo another (Enter 'y' or 'n')? ";
		cin >> ch;
	} while (ch != 'n');
	return 0;
}

//lab2.5
#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;
int main()
{
	int i;
	string s = "x";
	for (i = 0; i < 20; i++) {
		cout << setw(20) << s  << endl;
		s += "xх";
	}
	return 0;
}

//lab2.6
#include <iostream>
using namespace std;
int main()
{
	unsigned int numb;
	unsigned long fact = 1;
	int flag = 1;
	while (flag == 1) {
		cout << "Enter a number: ";
		cin >> numb;
		for (int j = numb; j > 0; j--)
			fact *= j;
		cout << "Factorial is " << fact << endl;
		cout << "Do you want to continue? Yes - 1, no - 0" << endl;
		cin >> flag;
		fact = 1;
	}
	return 0;
}

//lab2.7
#include <iostream>
using namespace std;
int main() {
	float sum, years, i, percents;
	cout << "Enter the sum: ";
	cin >> sum;
	cout << "Enter the amount of years: ";
	cin >> years;
	cout << "Enter percents(%): ";
	cin >> percents;
	for (i = 0; i < years; i++) {
		sum *= (1 + percents / 100);
	}
	cout << "Your sum after " << years << " years is: " << sum;
	return 0;
}

//lab2.8
#include <iostream>
using namespace std;
int main() {
	int pound1, shil1, pen1, pound2, shil2, pen2, s_pound, s_shil, s_pen;
	char flag = 'y';
	s_pound = 0;
	s_shil = 0;
	s_pen = 0;
	do {
		cout << "Enter the first sum: ";
		cin >> pound1 >> shil1 >> pen1;
		cout << "Enter the second sum: ";
		cin >> pound2 >> shil2 >> pen2;
		s_pen = pen1 + pen2; 
		while (s_pen > 12) {
			s_shil += s_pen / 12;
			s_pen -= 12;
		}
		s_shil += shil1 + shil2;
		while (s_shil > 20) {
			s_pound += s_shil / 20;
			s_shil -= 20;
		}
		s_pound += pound1 + pound2;
		cout << s_pound << " " << s_shil << " " << s_pen << endl;
		cout << "Do you want to continue? (y/n)" << endl;
		cin >> flag;
	} while (flag == 'y');
	return 0;
}

//lab2.9
#include <iostream>
using namespace std;
int main() {
	int guest, place, slch, i;
	slch = 1;
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество гостей: " << endl;
	cin >> guest;
	cout << "Введите количество мест, большее или равное числу гостей: " << endl;
	cin >> place;
	for (i = 0; i < place; i++) {
		slch *= guest;
		guest--;
	}
	cout << slch << endl;
	return 0;
}

//lab2.10
#include <iostream>
using namespace std;
int main() {
	float sum, sumk, i, percents;
	int year = 0;
	cout << "Enter the sum: ";
	cin >> sum;
	cout << "Enter the final sum: ";
	cin >> sumk;
	cout << "Enter percents(%): ";
	cin >> percents;
	while (sum <= sumk) {
		sum *= (1 + percents / 100);
		year++;
	}
	cout << year;
	return 0;
}

//lab2.11
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	char flag = '+';
	char oper = '0';
	int pound1, pound2, shil1, shil2, pen1, pen2, f_pound, f_shil, f_pen, x;
	while (flag == '+') {
		f_pen = 0;
		f_shil = 0;
		f_pound = 0;
		cout << "Введите первую сумму: ";
		cin >> pound1 >> shil1 >> pen1;
		cout << "Выберите действие: сложение(+), вычитание(-), умножение на число(*)" << endl;
		cin >> oper;
		switch (oper) {
		case '+':
			cout << "Введите вторую сумму: ";
			cin >> pound2 >> shil2 >> pen2;
			f_pen = pen1 + pen2;
			while (f_pen > 12) {
				f_shil += f_pen / 12;
				f_pen -= 12;
			}
			f_shil += shil1 + shil2;
			while (f_shil > 20) {
				f_pound += f_shil / 20;
				f_shil -= 20;
			}
			f_pound += pound1 + pound2;
			cout << f_pound << " " << f_shil << " " << f_pen << endl;
			cout << "Хотите продолжить? (+/-)" << endl;
			cin >> flag;
			break;
		case '-':
			cout << "Введите вторую сумму: ";
			cin >> pound2 >> shil2 >> pen2;
			f_pen = abs(pen1 - pen2);
			f_shil = abs(shil1 - shil2);
			f_pound = abs(pound1 - pound2);
			cout << f_pound << " " << f_shil << " " << f_pen << endl;
			cout << "Хотите продолжить? (+/-)" << endl;
			cin >> flag;
			break;
		case '*':
			cout << "Введите число, на которое хотите умножить: ";
			cin >> x;
			f_pen = pen1 * x;
			while (f_pen > 12) {
				f_shil += f_pen / 12;
				f_pen -= 12;
			}
			f_shil += shil1 * x;
			while (f_shil > 20) {
				f_pound += f_shil / 20;
				f_shil -= 20;
			}
			f_pound += pound1 * x;
			cout << f_pound << " " << f_shil << " " << f_pen << endl;
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

//lab2.12
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	char flag = '+';
	char oper = '0';
	char slash;
	int a, b, c, d, resch, reszn;
	cout << "Введите первую дробь в формате a/b: ";
	cin >> a >> slash >> b;
	cout << "Введите первую дробь в формате c/d: ";
	cin >> c >> slash >> d;
	while (flag == '+') {
		cout << "Выберите действие: сложение(+), вычитание(-), умножение(*), деление(/)" << endl;
		cin >> oper;
		switch (oper) {
		case '+':
			resch = a * d + b * c;
			reszn = b * d;
			cout << resch << "/" << reszn << endl;
			cout << "Хотите продолжить? (+/-)" << endl;
			cin >> flag;
			break;
		case '-':
			resch = a * d - b * c;
			reszn = b * d;
			cout << resch << "/" << reszn << endl;
			cout << "Хотите продолжить? (+/-)" << endl;
			cin >> flag;
			break;
		case '*':		
			resch = a * c;
			reszn = b * d;
			cout << resch << "/" << reszn << endl;
			cout << "Хотите продолжить? (+/-)" << endl;
			cin >> flag;
			break;
		case '/':
			resch = a * d;
			reszn = b * c;
			cout << resch << "/" << reszn << endl;
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
