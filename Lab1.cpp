//lab1.1
#include <iostream>
using namespace std;
int main() {
	float gallons, cufeet;
	cout << "Enter quantity in gallons" << endl;
	cin >> gallons;
	cufeet = gallons / 7.481;
	cout << "Equivalent in cubic feet is " << cufeet << endl;
	return 0;
}

//lab1.2
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	cout << 1990 << setw(8) << 135 << endl
		<< 1991 << setw(8) << 7290 << endl
		<< 1992 << setw(8) << 11300 << endl
		<< 1993 << setw(8) << 16200 << endl;
	return 0;
}

//lab1.3
#include <iostream>
using namespace std;
int main() {
	int var = 10;
	cout << var << endl;
	var *= 2;
	cout << var-- << endl;
	cout << var << endl;
	return 0;
}

//lab1.4
//lab1.5
//lab1.6
//lab1.7
//lab1.8
//lab1.9
//lab1.10
//lab1.11
//lab1.12
