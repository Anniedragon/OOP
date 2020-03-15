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
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Ночевала тучка золотая \n";
	cout << "На груди утёса - великана \n";
	cout << "Утром в путь она умчалась рано \n";
	cout << "По лазури весело играя \n";
	cout << "\n";
	cout << "Но остался влажный след в морщине \n";
	cout << "Старого утёса.Одиноко \n";
	cout << "Он стоит, задумался глубоко, \n";
	cout << "И тихонько плачет он в пустыне." << endl;
	return 0;
}

//lab1.5
#include <iostream>
#include <ctype.h>
using namespace std;
int main() {
	char letter;
	setlocale(LC_ALL, "Russian");
	cout << "Введите строчную или заглавную букву" << endl;
	cin >> letter;
	cout << islower(letter) << endl;
	return 0;
}

//lab1.6
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	float dollar, funt, frank, nm, yen;
	cout << "Введите сумму в долларах" << endl;
	cin >> dollar;
	funt = 0.672 * dollar;
	frank = 5.814 * dollar;
	nm = 1.512 * dollar;
	yen = 104.712 * dollar;
	cout << funt << " funts" << endl;
	cout << frank << " franks" << endl;
	cout << nm << " nms" << endl;
	cout << yen << " yens" << endl;
}

//lab1.7
//lab1.8
//lab1.9
//lab1.10
//lab1.11
//lab1.12
