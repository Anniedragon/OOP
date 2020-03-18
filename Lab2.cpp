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
		s += "x";
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
//lab2.10
//lab2.11
//lab2.12
