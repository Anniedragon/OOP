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
//lab7.11
//lab7.12
