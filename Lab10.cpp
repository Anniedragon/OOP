//lab10.1
#include <iostream>
#include <string>
using namespace std;
class publication {
private:
	string title;
	float price;
public:
	virtual void getdata() {
		cout << "\nEnter title: "; 
		cin >> title;
		cout << "Enter price: "; 
		cin >> price;
	}
	virtual void putdata() {
		cout << "\nTitle: " << title;
		cout << "\nPrice: " << price << endl;
	}
};
class book : public publication {
private:
	int pages;
public:
	void getdata() {
		publication::getdata();
		cout << "Enter number of pages: "; cin >> pages;
	}
	void putdata() {
		publication::putdata();
		cout << "\nPages: " << pages;
	}
};
class tape : public publication {
private:
	float time;
public:
	void getdata() {
		publication::getdata();
		cout << "Enter playing time: "; cin >> time;
	}
	void putdata() {
		publication::putdata();
		cout << "\nPlaying time: " << time;
	}
};
int main() {
	publication* pubarr[100]; 
	int n = 0; 
	char choice;
	do {
		cout << "\nEnter data for book or tape (b/t)? ";
		cin >> choice;
		if (choice == 'b') 
			pubarr[n] = new book;
		else 
			pubarr[n] = new tape; 
		pubarr[n++]->getdata(); 
		cout << " Enter another (y/n)? ";
		cin >> choice;
	}
	while (choice == 'y'); 
	for (int j = 0; j < n; j++) 
		pubarr[j]->putdata(); 
	cout << endl;
	return 0;
}

//lab10.2
#include <iostream>
#include <string>
using namespace std;
class publication {
private:
	string title;
	float price;
public:
	virtual void getdata() {
		cout << "\nEnter title: "; 
		cin >> title;
		cout << "Enter price: "; 
		cin >> price;
	}
	virtual void putdata() {
		cout << "\nTitle: " << title;
		cout << "\nPrice: " << price << endl;
	}
};
class book : public publication {
private:
	int pages;
public:
	void getdata() {
		publication::getdata();
		cout << "Enter number of pages: "; cin >> pages;
	}
	void putdata() {
		publication::putdata();
		cout << "\nPages: " << pages;
	}
};
class tape : public publication {
private:
	float time;
public:
	void getdata() {
		publication::getdata();
		cout << "Enter playing time: "; cin >> time;
	}
	void putdata() {
		publication::putdata();
		cout << "\nPlaying time: " << time;
	}
};
int main() {
	publication* pubarr[100]; 
	int n = 0; 
	char choice;
	do {
		cout << "\nEnter data for book or tape (b/t)? ";
		cin >> choice;
		if (choice == 'b') 
			pubarr[n] = new book;
		else 
			pubarr[n] = new tape; 
		pubarr[n++]->getdata(); 
		cout << " Enter another (y/n)? ";
		cin >> choice;
	}
	while (choice == 'y'); 
	for (int j = 0; j < n; j++) 
		pubarr[j]->putdata(); 
	cout << endl;
	return 0;
}

//lab10.3
#include <iostream>
using namespace std;
class Distance {
private:
	int feet;
	float inches;
public:
	Distance() {
		feet = 0; inches = 0.0;
	}

	Distance(float fltfeet) { 
		feet = static_cast<int>(fltfeet);
		inches = 12 * (fltfeet - feet); 
	} 
	Distance(int ft, float in) : feet(ft), inches(in)
	{ }
	void showdist() {
		cout << feet << "\'-" << inches << '\"';
	}
	friend Distance operator * (Distance, Distance);
};
Distance operator * (Distance d1, Distance d2) {
	float fltfeet1 = d1.feet + d1.inches / 12; 
	float fltfeet2 = d2.feet + d2.inches / 12;
	float multfeet = fltfeet1 * fltfeet2; 
	return Distance(multfeet); 
}
int main() {
	Distance dist1(3, 6.0); 
	Distance dist2(2, 3.0);
	Distance dist3;
	dist3 = dist1 * dist2; 
	dist3 = 10.0 * dist3; 
	cout << "\ndist1 = "; 
	dist1.showdist();
	cout << "\ndist2 = "; 
	dist2.showdist();
	cout << "\ndist3 = "; 
	dist3.showdist();
	cout << endl;
	return 0;
}

//lab10.4 
#include <iostream>
using namespace std;
class Array {
private:
	int* ptr; 
	int size; 
public:
	Array(int s) {
		size = s; 
		ptr = new int[s]; 
	}
	~Array() {
		delete[] ptr;
	}
	int& operator [] (int j) {
		return *(ptr + j);
	}
};
int main() {
	const int ASIZE = 10; 
	Array arr(ASIZE); 
	for (int j = 0; j < ASIZE; j++) 
		arr[j] = j * j;
	for (int j = 0; j < ASIZE; j++) 
		cout << arr[j] << ' ';
	cout << endl;
	return 0;
}

//lab10.5	DEMO!!!
#include <iostream>
#include <string>
using namespace std;
class publication {
private:
	string title;
	float price;
public:
	virtual void getdata() {
		cout << "Enter title: ";
		cin >> title;
		cout << "Enter price: ";
		cin >> price;
	}
	virtual void putdata() {
		cout << "\nTitle: " << title;
		cout << "\nPrice: " << price << endl;
	}
	virtual bool isOveerSize() {
		return 0;
	}
};
class book : public publication {
private:
	int pages;
public:
	void getdata() {
		publication::getdata();
		cout << "Enter number of pages: "; 
		cin >> pages;
	}
	void putdata() {
		publication::putdata();
		cout << "Pages: " << pages << endl;
	}
	bool isOveersize() {
		if (pages > 800) {
			cout << "Too much pages!";
			return 1;
		}
		return 0;
	}
};
class tape : public publication {
private:
	float time;
public:
	void getdata() {
		publication::getdata();
		cout << "Enter playing time: ";
		cin >> time;
	}
	void putdata() {
		publication::putdata();
		cout << "Playing time: " << time;
	}
	bool isOveersize() {
		if (time > 90) {
			cout << "Too much minutes!";
			return 1;
		}
		return 0;
	}
};
int main() {
	publication* pubarr[100];
	int n = 0;
	int j;
	char choice;
	do {
		cout << "\nEnter data for book or tape (b/t)? ";
		cin >> choice;
		if (choice == 'b')
			pubarr[n] = new book;
		else
			pubarr[n] = new tape;
		pubarr[n++]->getdata();
		cout << "Enter another (y/n)? ";
		cin >> choice;
	} while (choice == 'y');
	for (j = 0; j < n; j++) {
		pubarr[j]->isOveerSize();
		pubarr[j]->putdata();
	}	
	cout << endl;
	return 0;
}

//lab10.6
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
	friend bMoney operator * (long double m1, bMoney b2) {
		return bMoney(m1 * b2.money);
	}
	friend bMoney operator / (long double m1, bMoney b2) {
		return bMoney(m1 / b2.money);
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
	m3 = amount / m1;
	m3.putmoney();
	m3 = amount * m1;
	m3.putmoney();
	return 0;
}

//lab10.7
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
	friend bMoney operator * (long double m1, bMoney b2) {
		return bMoney(m1 * b2.money);
	}
	friend bMoney operator / (long double m1, bMoney b2) {
		return bMoney(m1 / b2.money);
	}
	void putmoney() {
		cout << money << endl;
	}
	friend bMoney bMround(bMoney b) {
		long double drob, cel;
		drob = modf(b.money, &cel);
		if (drob < 0.5) {
			drob = 0;
		}
		else drob = 1;
		return bMoney(cel + drob);
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
	m3 = amount / m1;
	m3.putmoney();
	m3 = amount * m1;
	m3.putmoney();
	m1 = bMround(m2);
	m1.putmoney();
	return 0;
}

//lab10.8
#include <iostream>
using namespace std;
class token {
public:
	virtual float getnumber() = 0;
	virtual char getoperator() = 0;
};
class Operator : public token {
private:
	char oper;
public:
	Operator(char op) {
		oper = op;
	}
	char getoperator() {
		return oper;
	}
	float getnumber() {
		return 0;
	}
};
class number : public token {
private:
	float fnum;
public:
	number(float fn) {
		fnum = fn;
	}
	float getnumber() {
		return fnum;
	}
	char getoperator() {
		return 0;
	}
};
class Stack : public token {
private:
	token* atoken[100];
	int top;
public:
	Stack() {
		top = -1;
	}
	void push(float var) {
		atoken[++top] = new number(var);
	}
	void push(char var) {
		atoken[++top] = new Operator(var);
	}
	float pop(int useless) {
		return atoken[top--]->getnumber();
	}
	char pop(float useless) {
		return atoken[top--]->getoperator();
	}
	int return_top() {
		return top;
	}
};
int main() {
	Operator op1('+');
	number num1(3.45);
	cout << op1.getoperator() << endl;
	cout << num1.getnumber() << endl;
	return 0;
}

//lab10.9
//lab10.10
//lab10.11
