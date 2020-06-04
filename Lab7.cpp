//lab7.1
#include <iostream>
using namespace std;
class Distance {
private:
	int feet;
	float inches;
public: 
	Distance() : feet(0), inches(0.0)
	{ } 
	Distance(int ft, float in) : feet(ft), inches(in)
	{ }
	void getdist() {
		cout << "\nEnter feet: "; cin >> feet;
		cout << "Enter inches: "; cin >> inches;
	}
	void showdist()	{
		cout << feet << "\'-" << inches << '\"';
	}
	Distance operator + (Distance);
	Distance operator - (Distance); 
};
Distance Distance::operator + (Distance d2) {
	int f = feet + d2.feet;
	float i = inches + d2.inches;
	if (i >= 12.0) {
		i -= 12.0; 
		f++; 
	} 
	return Distance(f, i); 
}
Distance Distance::operator - (Distance d2) {
	int f = feet - d2.feet; 
	float i = inches - d2.inches; 
	if (i < 0) {
		i += 12.0; 
		f--; 
	} 
	return Distance(f, i); 
}
int main() {
	Distance dist1, dist3; 
	dist1.getdist(); 
	Distance dist2(3, 6.25); 
	dist3 = dist1 - dist2; 
	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
	cout << endl;
	return 0;
}

//lab7.2 DON'T WORKING!!!
#include <iostream>
#include <cstring> 
#include <string.h>
#include <process.h> 
using namespace std;
class String {
private:
	enum { SZ = 80 }; 
	char str[SZ];
public:
	String()
	{
		strcpy(str, "");
	}
	String(char s[]) 
	{
		strcpy(str, s);
	}
	void display() 
	{
		cout << str;
	}
	String operator += (String ss) { 
		if (strlen(str) + strlen(ss.str) >= SZ)
		{
			cout << "\nString overflow"; exit(1);
		}
		strcat(str, ss.str); 
		return String(str); 
	}
};
int main()
{
	String s1 = "Merry Christmas! "; 
	String s2 = "Happy new year!"; 
	String s3; 
	s3 = s1 += s2; 
	cout << "\ns1="; s1.display(); 
	cout << "\ns2="; s2.display(); 
	cout << "\ns3="; s3.display(); 
	cout << endl;
	return 0;
}

//lab7.3
#include <iostream>
using namespace std;
class time
{
private:
	int hrs, mins, secs;
public:
	time() : hrs(0), mins(0), secs(0)
	{ } 
	time(int h, int m, int s) : hrs(h), mins(m), secs(s)
	{ }
	void display()
	{
		cout << hrs << ":" << mins << ":" << secs;
	}
	time operator + (time t2)
	{
		int s = secs + t2.secs; 
		int m = mins + t2.mins; 
		int h = hrs + t2.hrs; 
		if (s > 59) 
		{
			s -= 60; m++;
		} 
		if (m > 59)
		{
			m -= 60; h++;
		} 
		return time(h, m, s); 
	}
};
int main()
{
	time time1(5, 59, 59);
	time time2(4, 30, 30);
	time time3;
	time3 = time1 + time2;
	cout << "\ntime3 = "; time3.display();
	cout << endl;
	return 0;
}

//lab7.4
#include <iostream>
#include <process.h>
using namespace std;
class Int {
private:
	int i;
public:
	Int() : i(0)
	{ }
	Int(int ii) : i(ii) 
	{ } 
	void putInt()
	{
		cout << i;
	}
	void getInt()
	{
		cin >> i;
	}
	operator int()
	{
		return i;
	} 
	Int operator + (Int i2)
	{
		return checkit(long double(i) + long double(i2));
	}
	Int operator - (Int i2)
	{
		return checkit(long double(i) - long double(i2));
	}
	Int operator * (Int i2)
	{
		return checkit(long double(i) * long double(i2));
	}
	Int operator / (Int i2) 
	{
		return checkit(long double(i) / long double(i2));
	}
	Int checkit(long double answer) 
	{
		if (answer > 2147483647.0L || answer < -2147483647.0L)
		{
			cout << "\nOverflow Error\n"; exit(1);
		}
		return Int(int(answer));
	}
};
int main()
{
	Int alpha = 20;
	Int beta = 7;
	Int delta, gamma;
	gamma = alpha + beta;
	cout << "\ngamma="; gamma.putInt();
	gamma = alpha - beta;
	cout << "\ngamma="; gamma.putInt();
	gamma = alpha * beta;
	cout << "\ngamma="; gamma.putInt();
	gamma = alpha / beta; 
	cout << "\ngamma="; gamma.putInt();
	delta = 2147483647;
	gamma = delta + alpha; 
	delta = -2147483647;
	gamma = delta - alpha;
	cout << endl;
	return 0;
}

//lab7.5
#include <iostream>
using namespace std;
class time
{
private:
	int hrs, mins, secs;
public:
	time() : hrs(0), mins(0), secs(0)
	{ }
	time(int h, int m, int s) : hrs(h), mins(m), secs(s)
	{ }
	void display()
	{
		cout << hrs << ":" << mins << ":" << secs << endl;
	}
	time operator + (time t2) {
		int s = secs + t2.secs;
		int m = mins + t2.mins;
		int h = hrs + t2.hrs;
		if (s > 59)
		{
			s -= 60; m++;
		}
		if (m > 59)
		{
			m -= 60; h++;
		}
		return time(h, m, s);
	}
	time operator++ () {
		int s = secs++;
		int m = mins;
		int h = hrs;
		if (s > 59) {
			s -= 60;
			m++;
		}
		if (m > 59) {
			m -= 60;
			h++;
		}
		return time(h, m, s);
	}
	time operator++ (int i) {
		int s = secs++;
		int m = mins;
		int h = hrs;
		if (s > 59) {
			s -= 60;
			m++;
		}
		if (m > 59) {
			m -= 60;
			h++;
		}
		return time(h, m, s);
	}
	time operator-- () {
		int s = secs--;
		int m = mins;
		int h = hrs;
		if (s < 0) {
			cout << "Time can't be less than zero!" << endl;
		}
		else return time(h, m, s);
	}
	time operator-- (int i) {
		int s = secs--;
		int m = mins;
		int h = hrs;
		if (s < 0) {
			cout << "Time can't be less than zero!" << endl;
		}
		else return time(h, m, s);
	}
};
int main()
{
	time time1(5, 20, 0);
	time1++;
	time1.display();
	++time1;
	time1.display();
	time1--;
	time1.display();
	--time1;
	time1.display();
	return 0;
}

//lab7.6
#include <iostream>
#include <cmath>
using namespace std;
class time
{
private:
	int hrs, mins, secs;
public:
	time() : hrs(0), mins(0), secs(0)
	{ }
	time(int h, int m, int s) : hrs(h), mins(m), secs(s)
	{ }
	void display()
	{
		cout << hrs << ":" << mins << ":" << secs << endl;
	}
	time operator + (time t2) {
		int s = secs + t2.secs;
		int m = mins + t2.mins;
		int h = hrs + t2.hrs;
		if (s > 59)
		{
			s -= 60; m++;
		}
		if (m > 59)
		{
			m -= 60; h++;
		}
		return time(h, m, s);
	}
	time operator - (time t2) {
		int s = abs(secs - t2.secs);
		int m = abs(mins - t2.mins);
		int h = abs(hrs - t2.hrs);
		if (s > 59)
		{
			s -= 60; m++;
		}
		if (m > 59)
		{
			m -= 60; h++;
		}
		return time(h, m, s);
	}
	time operator * (time t2) {
		int s = float(secs * t2.secs);
		int m = float(mins * t2.mins);
		int h = float(hrs * t2.hrs);
		if (s > 59)
		{
			s -= 60; m++;
		}
		if (m > 59)
		{
			m -= 60; h++;
		}
		return time(h, m, s);
	}
	time operator++ () {
		int s = secs++;
		int m = mins;
		int h = hrs;
		if (s > 59) {
			s -= 60;
			m++;
		}
		if (m > 59) {
			m -= 60;
			h++;
		}
		return time(h, m, s);
	}
	time operator++ (int i) {
		int s = secs++;
		int m = mins;
		int h = hrs;
		if (s > 59) {
			s -= 60;
			m++;
		}
		if (m > 59) {
			m -= 60;
			h++;
		}
		return time(h, m, s);
	}
	time operator-- () {
		int s = secs--;
		int m = mins;
		int h = hrs;
		if (s > 59) {
			s -= 60;
			m++;
		}
		if (m > 59) {
			m -= 60;
			h++;
		}
		return time(h, m, s);
	}
	time operator-- (int i) {
		int s = secs--;
		int m = mins;
		int h = hrs;
		if (s > 59) {
			s -= 60;
			m++;
		}
		if (m > 59) {
			m -= 60;
			h++;
		}
		return time(h, m, s);
	}
};
int main()
{
	time time1(5, 59, 59);
	time time2(4, 30, 30);
	time time3;
	time3 = time1 - time2;
	time3.display();
	time3 = time1 * time2;
	time3.display();
	return 0;
}

//lab7.7
#include <iostream>
#include <cmath>
using namespace std;
class fraction {
private:
	long chisl;
	long znam;
public:
	fraction(long ch, long zn) {
		chisl = ch;
		znam = zn;
	}
	void get_frac(long u_chisl, long u_znam) {
		chisl = u_chisl;
		znam = u_znam;
	}
	fraction operator + (fraction f2) {
		long ch = chisl * f2.znam + f2.chisl * znam;
		long zn = znam * f2.znam;
		return fraction(ch, zn);
	}
	fraction operator - (fraction f2) {
		long ch = chisl * f2.znam + f2.chisl * znam;
		long zn = znam * f2.znam;
		return fraction(ch, zn);
	}
	fraction operator * (fraction f2) {
		long ch = chisl * f2.chisl;
		long zn = znam * f2.znam;
		return fraction(ch, zn);
	}
	fraction operator / (fraction f2) {
		long ch = chisl * f2.znam;
		long zn = znam * f2.chisl;
		return fraction(ch, zn);
	}
	bool operator == (fraction f) {
		if ((chisl == f.chisl) && (znam == f.znam)) {
			return true;
		}
		else return false;
	}
	bool operator != (fraction f) {
		if ((chisl != f.chisl) && (znam != f.znam)) {
			return true;
		}
		else return false;
	}
	void lowterms() {
		long temp, result_chisl, result_znam, nod;
		result_chisl = labs(chisl);
		result_znam = labs(znam);
		if (result_znam == 0) {
			cout << "Forbidden znam";
			exit(1);
		}
		else if (result_chisl == 0) {
			chisl = 0;
			znam = 1;
		}
		while (result_chisl != 0) {
			if (result_chisl < result_znam) {
				temp = result_chisl;
				result_chisl = result_znam;
				result_znam = temp;
			}
			result_chisl = result_chisl - result_znam;
		}
		nod = result_znam;
		chisl = chisl / nod;
		znam = znam / nod;
	}
	void return_frac() {
		cout << chisl << "/" << znam << endl;
	}
};
int main() {
	fraction fr1 = { 0, 0 };
	fraction fr2 = { 0, 0 };
	fraction frres = { 0, 0 };
	fraction zero = { 0, 1 };
	char slash, oper;
	long chisl1, chisl2, znam1, znam2;
	while (true) {
		cout << "Enter 1st fraction like a/b: ";
		cin >> chisl1 >> slash >> znam1;
		fraction fr1(chisl1, znam1);
		if (fr1 == zero) {
			break;
		}
		cout << "Enter 2nd fraction like a/b: ";
		cin >> chisl2 >> slash >> znam2;
		fraction fr2(chisl2, znam2);
		if (fr2 == zero) {
			break;
		}
		cout << "Enter operation (+, -, *, /): ";
		cin >> oper;
		switch (oper) {
		case '+':
			frres = fr1 + fr2;
			frres.lowterms();
			frres.return_frac();
			break;
		case '-':
			frres = fr1 - fr2;
			frres.lowterms();
			frres.return_frac();
			break;
		case '*':
			frres = fr1 * fr2;
			frres.lowterms();
			frres.return_frac();
			break;
		case '/':
			frres = fr1 / fr2;
			frres.lowterms();
			frres.return_frac();
			break;
		default:
			cout << "You're operation is absent. Try again." << endl;
			break;
		}
	}
	return 0;
}

//lab7.8
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
class bMoney {
private:
	long double money;
	string sum;
public:
	bMoney() {
		money = 0;
	}
	bMoney(string u_sum) {
		money = mstold(u_sum);
	}
	bMoney(long double d) {
		money = d;
	}
	void getmoney() {
		string u_money;
		cout << "Enter a money string: ";
		cin >> u_money;
		money = mstold(u_money);
	}
	long double mstold(string u_sum) {	
		sum = u_sum;
		string s;
		int len;
		len = sum.size() - 3;
		for (int i = 0; i < len; i++) {
			if ((sum[i] != '$') && (sum[i] != ',')) {
				if ((sum[i] == '.') && (i + 2 == len - 1)) {
					s += sum[i];
				}
				else s += sum[i];
			}
		}
		len = s.size();
		long double pow = len - 1;
		long double result = 0;
		int temp = 0;
		for (int i = 0; i < len; i++) {
			switch (s[i]) {
			case '1':
				temp = 1;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			case '2':
				temp = temp * 2;
				for (int j = 0; j < pow; j++) {
					temp = temp * 10;
				}
				result += temp;
				temp = 1;
				break;
			case '3':
				temp = 3;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			case '4':
				temp = 4;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			case '5':
				temp = 5;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			case '6':
				temp = 6;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			case '7':
				temp = 7;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			case '8':
				temp = 8;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			case '9':
				temp = 9;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			default:
				break;
			}
			pow--;
		}
		long double result1 = 0;
		pow = 0.1;
		for (int i = s.size() - 2; i <= s.size() - 1; i++) {
			switch (s[i]) {
			case '1':
				temp = 1;
				result1 += temp * pow;
				temp = 1;
				break;
			case '2':
				temp = 2;
				result1 += temp * pow;
				temp = 1;
				break;
			case '3':
				temp = 3;
				result1 += temp * pow;
				temp = 1;
				break;
			case '4':
				temp = 4;
				result1 += temp * pow;
				temp = 1;
				break;
			case '5':
				temp = 5;
				result1 += temp * pow;
				temp = 1;
				break;
			case '6':
				temp = 6;
				result1 += temp * pow;
				temp = 1;
				break;
			case '7':
				temp = 7;
				result1 += temp * pow;
				temp = 1;
				break;
			case '8':
				temp = 8;
				result1 += temp * pow;
				temp = 1;
				break;
			case '9':
				temp = 9;
				result1 += temp * pow;
				temp = 1;
				break;
			}
			pow /= 10;
		}
		result += result1;
		money = result;
		return money;
	}
	void ldtoms(long double sum) {
		string ustring, sum_string;
		char temp;
		long double cel, drob;
		int ch = 0;
		drob = modf(sum, &cel);
		int sum1 = cel;
		int count = 0;
		while (sum1 != 0) {
			sum1 /= 10;
			count++;
		}
		int cel_int = int(cel);
		for (int i = 0; i < count; i++) {
			ch = cel_int % 10;
			switch (ch) {
			case 1:
				ustring += '1';
				break;
			case 2:
				ustring += '2';
				break;
			case 3:
				ustring += '3';
				break;
			case 4:
				ustring += '4';
				break;
			case 5:
				ustring += '5';
				break;
			case 6:
				ustring += '6';
				break;
			case 7:
				ustring += '7';
				break;
			case 8:
				ustring += '8';
				break;
			case 9:
				ustring += '9';
				break;
			case 0:
				ustring += '0';
				break;
			}
			cel_int /= 10;
		}
		for (int i = 0; i < count / 2; i++) {
			temp = ustring[i];
			ustring[i] = ustring[count - i - 1];
			ustring[count - i - 1] = temp;
		}
		ustring += '.';
		drob *= 10;
		long double drob_cel, drob_drob;
		drob_drob = modf(drob, &drob_cel);
		int drob_cel_int = int(drob_cel);
		drob_drob *= 10;
		int drob_drob_int = int(drob_drob);
		switch (drob_cel_int) {
		case 1:
			ustring += '1';
			break;
		case 2:
			ustring += '2';
			break;
		case 3:
			ustring += '3';
			break;
		case 4:
			ustring += '4';
			break;
		case 5:
			ustring += '5';
			break;
		case 6:
			ustring += '6';
			break;
		case 7:
			ustring += '7';
			break;
		case 8:
			ustring += '8';
			break;
		case 9:
			ustring += '9';
			break;
		case 0:
			ustring += '0';
			break;
		}
		switch (drob_drob_int) {
		case 1:
			ustring += '1';
			break;
		case 2:
			ustring += '2';
			break;
		case 3:
			ustring += '3';
			break;
		case 4:
			ustring += '4';
			break;
		case 5:
			ustring += '5';
			break;
		case 6:
			ustring += '6';
			break;
		case 7:
			ustring += '7';
			break;
		case 8:
			ustring += '8';
			break;
		case 9:
			ustring += '9';
			break;
		case 0:
			ustring += '0';
			break;
		}
		sum_string += '$';
		int k = 0;
		for (int i = 0; i < count + 3; i++) {
			if (ustring[i + 1] == '.') {
				sum_string += ustring[i];
				k = 0;
			}
			else sum_string += ustring[i];
			k++;
			if ((k == 3) && (ustring[i + 1] != '.') && (i < count)) {
				sum_string += ',';
				k = 0;
			}
		}
		sum_string[count + 5] = '\0';
		cout << sum_string << endl;
	}
	bMoney operator + (bMoney b2) {
		money = money + b2.money;
		return money;
	}
	bMoney operator - (bMoney b2) {
		money = abs(money - b2.money);
		return money;
	}
	bMoney operator * (long double b2) {
		money = money * b2;
		return money;
	}
	bMoney operator / (bMoney b2) {
		money = money / b2.money;
		return money;
	}
	bMoney operator / (long double b2) {
		money = money / b2;
		return money;
	}
	void putmoney() {
		cout << money << endl;
	}
};
int main() {
	bMoney m1, m2, m3;
	long double amount;
	m1.getmoney();
	m2.getmoney();
	cout << "Enter amount: ";
	cin >> amount;
	m3 = m1 + m2;
	m3.putmoney();
	m3 = m1 - m2;
	m3.putmoney();
	m3 = m1 * amount;
	m3.putmoney();
	m3 = m1 / m2;
	m3.putmoney();
	m3 = m1 / amount;
	m3.putmoney();
	return 0;
}

//lab7.9
#include <iostream>
#include <process.h>
using namespace std;
int LIMIT, bottom;
class safearay {
private:
	int arr[100];
public:
	int& operator [](int n) {
		if (n < 0 || n >= LIMIT) {
			cout << "\nIndex out of bounds"; 
			exit(1);
		}
		return arr[n];
	}
};
int main() {
	safearay sa1;
	cout << "Enter a bottom index and a top index: ";
	cin >> bottom >> LIMIT;
	for (int j = 0; j < LIMIT - bottom; j++)
		sa1[j] = j * 10; 
	for (int j = 0; j < LIMIT - bottom; j++) {
		int temp = sa1[j]; 
		cout << "Element " << j << " is " << temp << endl;
	}
	return 0;
}

//lab7.10
#include <iostream>
using namespace std;
class polar {
private:
	int x, y;
public: 
	polar(double r, double gr) {
		x = r * cos(gr);
		y = r * sin(gr);
	}
	void put_polar() {
		cout << "x = " << x << ", y = " << y << endl;
	}
	polar operator + (polar p2) {
		x = x + p2.x;
		y = y + p2.y;
		return polar(x, y);
	}
};
int main() {
	double r1, gr1, r2, gr2;
	cout << "Enter a radius and an angle of 1st point: ";
	cin >> r1 >> gr1;
	polar p1(r1, gr1);
	cout << "Enter a radius and an angle of 2nd point: ";
	cin >> r2 >> gr2;
	polar p2(r2, gr2);
	polar p3 = p1 + p2;
	p3.put_polar();
	return 0;
}

//lab7.11
#include <iostream>
using namespace std;
class sterling {
private:
	long pounds;
	int shillings;
	int pense;
	double d;
public:
	sterling() {
		pounds = 0;
		shillings = 0;
		pense = 0;
	}
	sterling(double d) {
		pounds = int(d);
		pense = d - (int)d; 
		shillings = pense * 20;
	}
	sterling(double po, int s, int pe) {
		pounds = po;
		shillings = s;
		pense = pe;
	}
	void getSterling() {
		char point;
		long po;
		int s, pe;
		cout << "Enter sum in pounds, shillings and pense: ";
		cin >> po >> point >> s >> point >> pe;
		pounds = po;
		shillings = s;
		pense = pe;
	}
	void putSterling() {
		cout << pounds << "." << shillings << "." << pense << endl;
	}
	void putDouble() {
		cout << d << endl;
	}
	sterling operator + (sterling s2) {
		pounds = pounds + s2.pounds;
		shillings = shillings + s2.shillings;
		pense = pense + s2.pense;
		while (pense >= 12) {
			pense -= 12;
			shillings++;
		}
		while (shillings >= 20) {
			shillings -= 20;
			pounds++;
		}
		return sterling(pounds, shillings, pense);
	}
	sterling operator - (sterling s2) {
		pounds = abs(pounds - s2.pounds);
		shillings = abs(shillings - s2.shillings);
		pense = abs(pense - s2.pense);
		while (pense >= 12) {
			pense -= 12;
			shillings++;
		}
		while (shillings >= 20) {
			shillings -= 20;
			pounds++;
		}
		return sterling(pounds, shillings, pense);
	}
	sterling operator * (double s2) {
		pounds = pounds * s2;
		shillings = shillings * s2;
		pense = pense * s2;
		while (pense >= 12) {
			pense -= 12;
			shillings++;
		}
		while (shillings >= 20) {
			shillings -= 20;
			pounds++;
		}
		return sterling(pounds, shillings, pense);
	}
	sterling operator / (sterling s2) {
		pounds = pounds / s2.pounds;
		shillings = shillings / s2.shillings;
		pense = pense / s2.pense;
		while (pense >= 12) {
			pense -= 12;
			shillings++;
		}
		while (shillings >= 20) {
			shillings -= 20;
			pounds++;
		}
		return sterling(pounds, shillings, pense);
	}
	sterling operator / (double d) {
		pounds = pounds / d;
		shillings = shillings / d;
		pense = pense / d;
		while (pense >= 12) {
			pense -= 12;
			shillings++;
		}
		while (shillings >= 20) {
			shillings -= 20;
			pounds++;
		}
		return sterling(pounds, shillings, pense);
	}
	void ster_to_double() {
		d = pounds + (pense / 12) / 20 + shillings / 20;
	}
};
int main() {
	sterling st1, st2, st3;
	double amount;
	st1.getSterling();
	st2.getSterling();
	cout << "Enter amount: ";
	cin >> amount;
	st3 = st1 + st2;
	st3.putSterling();
	st3 = st1 - st2;
	st3.putSterling();
	st3 = st1 * amount;
	st3.putSterling();
	st3 = st1 / st2;
	st3.putSterling();
	st3 = st1 / amount;
	st3.putSterling();
	st1.ster_to_double();
	st1.putDouble();
	return 0;
}

//lab7.12
#include <iostream>
using namespace std;
class bMoney {
private:
	long double money;
	string sum;
public:
	bMoney() {
		money = 0;
	}
	bMoney(string u_sum) {
		money = mstold(u_sum);
	}
	bMoney(long double d) {
		money = d;
	}
	void ster_to_bmoney(long po, int sh, int pe) {
		money = po * 50 + (50 / 20) * sh + 50 * 20 * 12 * pe;
	}
	void getmoney() {
		string u_money;
		cout << "Enter a money string: ";
		cin >> u_money;
		money = mstold(u_money);
	}
	long double mstold(string u_sum) {
		sum = u_sum;
		string s;
		int len;
		len = sum.size() - 3;
		for (int i = 0; i < len; i++) {
			if ((sum[i] != '$') && (sum[i] != ',')) {
				if ((sum[i] == '.') && (i + 2 == len - 1)) {
					s += sum[i];
				}
				else s += sum[i];
			}
		}
		len = s.size();
		long double pow = len - 1;
		long double result = 0;
		int temp = 0;
		for (int i = 0; i < len; i++) {
			switch (s[i]) {
			case '1':
				temp = 1;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			case '2':
				temp = temp * 2;
				for (int j = 0; j < pow; j++) {
					temp = temp * 10;
				}
				result += temp;
				temp = 1;
				break;
			case '3':
				temp = 3;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			case '4':
				temp = 4;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			case '5':
				temp = 5;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			case '6':
				temp = 6;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			case '7':
				temp = 7;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			case '8':
				temp = 8;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			case '9':
				temp = 9;
				for (int j = 0; j < pow; j++) {
					temp *= 10;
				}
				result += temp;
				temp = 1;
				break;
			default:
				break;
			}
			pow--;
		}
		long double result1 = 0;
		pow = 0.1;
		for (int i = s.size() - 2; i <= s.size() - 1; i++) {
			switch (s[i]) {
			case '1':
				temp = 1;
				result1 += temp * pow;
				temp = 1;
				break;
			case '2':
				temp = 2;
				result1 += temp * pow;
				temp = 1;
				break;
			case '3':
				temp = 3;
				result1 += temp * pow;
				temp = 1;
				break;
			case '4':
				temp = 4;
				result1 += temp * pow;
				temp = 1;
				break;
			case '5':
				temp = 5;
				result1 += temp * pow;
				temp = 1;
				break;
			case '6':
				temp = 6;
				result1 += temp * pow;
				temp = 1;
				break;
			case '7':
				temp = 7;
				result1 += temp * pow;
				temp = 1;
				break;
			case '8':
				temp = 8;
				result1 += temp * pow;
				temp = 1;
				break;
			case '9':
				temp = 9;
				result1 += temp * pow;
				temp = 1;
				break;
			}
			pow /= 10;
		}
		result += result1;
		money = result;
		return money;
	}
	void ldtoms(long double sum) {
		string ustring, sum_string;
		char temp;
		long double cel, drob;
		int ch = 0;
		drob = modf(sum, &cel);
		int sum1 = cel;
		int count = 0;
		while (sum1 != 0) {
			sum1 /= 10;
			count++;
		}
		int cel_int = int(cel);
		for (int i = 0; i < count; i++) {
			ch = cel_int % 10;
			switch (ch) {
			case 1:
				ustring += '1';
				break;
			case 2:
				ustring += '2';
				break;
			case 3:
				ustring += '3';
				break;
			case 4:
				ustring += '4';
				break;
			case 5:
				ustring += '5';
				break;
			case 6:
				ustring += '6';
				break;
			case 7:
				ustring += '7';
				break;
			case 8:
				ustring += '8';
				break;
			case 9:
				ustring += '9';
				break;
			case 0:
				ustring += '0';
				break;
			}
			cel_int /= 10;
		}
		for (int i = 0; i < count / 2; i++) {
			temp = ustring[i];
			ustring[i] = ustring[count - i - 1];
			ustring[count - i - 1] = temp;
		}
		ustring += '.';
		drob *= 10;
		long double drob_cel, drob_drob;
		drob_drob = modf(drob, &drob_cel);
		int drob_cel_int = int(drob_cel);
		drob_drob *= 10;
		int drob_drob_int = int(drob_drob);
		switch (drob_cel_int) {
		case 1:
			ustring += '1';
			break;
		case 2:
			ustring += '2';
			break;
		case 3:
			ustring += '3';
			break;
		case 4:
			ustring += '4';
			break;
		case 5:
			ustring += '5';
			break;
		case 6:
			ustring += '6';
			break;
		case 7:
			ustring += '7';
			break;
		case 8:
			ustring += '8';
			break;
		case 9:
			ustring += '9';
			break;
		case 0:
			ustring += '0';
			break;
		}
		switch (drob_drob_int) {
		case 1:
			ustring += '1';
			break;
		case 2:
			ustring += '2';
			break;
		case 3:
			ustring += '3';
			break;
		case 4:
			ustring += '4';
			break;
		case 5:
			ustring += '5';
			break;
		case 6:
			ustring += '6';
			break;
		case 7:
			ustring += '7';
			break;
		case 8:
			ustring += '8';
			break;
		case 9:
			ustring += '9';
			break;
		case 0:
			ustring += '0';
			break;
		}
		sum_string += '$';
		int k = 0;
		for (int i = 0; i < count + 3; i++) {
			if (ustring[i + 1] == '.') {
				sum_string += ustring[i];
				k = 0;
			}
			else sum_string += ustring[i];
			k++;
			if ((k == 3) && (ustring[i + 1] != '.') && (i < count)) {
				sum_string += ',';
				k = 0;
			}
		}
		sum_string[count + 5] = '\0';
		cout << sum_string << endl;
	}
	bMoney operator + (bMoney b2) {
		money = money + b2.money;
		return money;
	}
	bMoney operator - (bMoney b2) {
		money = abs(money - b2.money);
		return money;
	}
	bMoney operator * (long double b2) {
		money = money * b2;
		return money;
	}
	bMoney operator / (bMoney b2) {
		money = money / b2.money;
		return money;
	}
	bMoney operator / (long double b2) {
		money = money / b2;
		return money;
	}
	void putmoney() {
		cout << money << endl;
	}
	long double putmoney1() {
		return money;
	}
};
class sterling {
private:
	long pounds;
	int shillings;
	int pense;
	double d;
public:
	sterling() {
		pounds = 0;
		shillings = 0;
		pense = 0;
	}
	sterling(double d) {
		pounds = int(d);
		pense = d - (int)d;
		shillings = pense * 20;
	}
	sterling(double po, int s, int pe) {
		pounds = po;
		shillings = s;
		pense = pe;
	}
	long put_pound() {
		return pounds;
	}
	int put_shilling() {
		return shillings;
	}
	int put_pense() {
		return pense;
	}
	void bmoney_to_ster(bMoney& m) {
		long double d = m.putmoney1();
		int tr;
		tr = (d / 50) * 20 * 12;
		pounds = tr / (20 * 12);
		shillings = tr % (20 * 12) / 12;
		pense = tr % (20 * 12) % 12;
	}
	void getSterling() {
		char point;
		long po;
		int s, pe;
		cout << "Enter sum in pounds, shillings and pense: ";
		cin >> po >> point >> s >> point >> pe;
		pounds = po;
		shillings = s;
		pense = pe;
	}
	void putSterling() {
		cout << pounds << "." << shillings << "." << pense << endl;
	}
	void putDouble() {
		cout << d << endl;
	}
	sterling operator + (sterling s2) {
		pounds = pounds + s2.pounds;
		shillings = shillings + s2.shillings;
		pense = pense + s2.pense;
		while (pense >= 12) {
			pense -= 12;
			shillings++;
		}
		while (shillings >= 20) {
			shillings -= 20;
			pounds++;
		}
		return sterling(pounds, shillings, pense);
	}
	sterling operator - (sterling s2) {
		pounds = abs(pounds - s2.pounds);
		shillings = abs(shillings - s2.shillings);
		pense = abs(pense - s2.pense);
		while (pense >= 12) {
			pense -= 12;
			shillings++;
		}
		while (shillings >= 20) {
			shillings -= 20;
			pounds++;
		}
		return sterling(pounds, shillings, pense);
	}
	sterling operator * (double s2) {
		pounds = pounds * s2;
		shillings = shillings * s2;
		pense = pense * s2;
		while (pense >= 12) {
			pense -= 12;
			shillings++;
		}
		while (shillings >= 20) {
			shillings -= 20;
			pounds++;
		}
		return sterling(pounds, shillings, pense);
	}
	sterling operator / (sterling s2) {
		pounds = pounds / s2.pounds;
		shillings = shillings / s2.shillings;
		pense = pense / s2.pense;
		while (pense >= 12) {
			pense -= 12;
			shillings++;
		}
		while (shillings >= 20) {
			shillings -= 20;
			pounds++;
		}
		return sterling(pounds, shillings, pense);
	}
	sterling operator / (double d) {
		pounds = pounds / d;
		shillings = shillings / d;
		pense = pense / d;
		while (pense >= 12) {
			pense -= 12;
			shillings++;
		}
		while (shillings >= 20) {
			shillings -= 20;
			pounds++;
		}
		return sterling(pounds, shillings, pense);
	}
	void ster_to_double() {
		d = pounds + (pense / 12) / 20 + shillings / 20;
	}
};
int main() {
	bMoney m1("$123,456.32");
	bMoney m2;
	sterling s1, s2;
	s1.getSterling();
	s2.bmoney_to_ster(m1);
	s2.putSterling();
	m2.ster_to_bmoney(s1.put_pound(), s1.put_shilling(), s1.put_pense());
	m2.putmoney();
	return 0;
}
