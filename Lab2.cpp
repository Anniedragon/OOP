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
//lab2.4
//lab2.5
//lab2.6
//lab2.7
//lab2.8
//lab2.9
//lab2.10
//lab2.11
//lab2.12
