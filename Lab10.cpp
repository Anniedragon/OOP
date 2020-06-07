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
#include <iostream>
#include "msoftcon.h"
#include <cstdlib>
#include <ctime> 
using namespace std;
const int CPF = 5;
const int maxHorses = 7;
class track;
class horse {
protected:
	const track* ptrTrack; 
	const int horse_number; 
	float finish_time; 
	float distance_run; 
public: 
	horse(const int n, const track* ptrT) : horse_number(n), ptrTrack(ptrT), distance_run(0.0) 
	{ }
	~horse() { 
		/*empty*/
	} 
	void display_horse(const float elapsed_time);
}; 
class track {
protected:
	horse* hArray[maxHorses]; 
	int total_horses; 
	int horse_count; 
	const float track_length; 
	float elapsed_time; 
public:
	track(float lenT, int nH); 
	~track(); 
	void display_track(); 
	void run(); 
	float get_track_len() const; 
}; 
void horse::display_horse(float elapsed_time) { 
	set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);
	set_color(static_cast<color>(cBLUE + horse_number));
	char horse_char = '0' + static_cast<char>(horse_number);
	_putch(' '); 
	_putch('\xDB'); 
	_putch(horse_char);
	_putch('\xDB');
	if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF) {
		if (rand() % 3) 
			distance_run += 0.2F; 
		finish_time = elapsed_time; 
	}
	else { 
		int mins = int(finish_time) / 60;
		int secs = int(finish_time) - mins * 60;
		cout << " Time=" << mins << ":" << secs;
	}
} 
track::track(float lenT, int nH) : 
	track_length(lenT), total_horses(nH),
	horse_count(0), elapsed_time(0.0)
{
	init_graphics(); 
	total_horses = (total_horses > maxHorses) ? maxHorses : total_horses;
	for (int j = 0; j < total_horses; j++) 
		hArray[j] = new horse(horse_count++, this);
	time_t aTime; 
	srand(static_cast<unsigned>(time(&aTime)));
	display_track();
} 
track::~track() {
	for (int j = 0; j < total_horses; j++) 
		delete hArray[j];
}
void track::display_track() {
	clear_screen(); 
	for (int f = 0; f <= track_length; f++) 
		for (int r = 1; r <= total_horses * 2 + 1; r++) 
		{
			set_cursor_pos(f * CPF + 5, r);
			if (f == 0 || f == track_length)
				cout << '\xDE'; 
			else
				cout << '\xB3'; 
		}
} 
void track::run() {
	while (!_kbhit()) {
		elapsed_time += 1.75; 

		for (int j = 0; j < total_horses; j++)
			hArray[j]->display_horse(elapsed_time);
		wait(500);
	}
	_getch(); 
	cout << endl;
}
float track::get_track_len() const {
	return track_length;
}
class comhorse : public horse {
public:
	comhorse(const int n, const track* ptrT) : horse(n, ptrT) {}

	float get_distance()
	{
		return distance_run;
	}

	void horse_tick()
	{
		set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);
		set_color(static_cast<color>(cBLUE + horse_number));
		char horse_char = '0' + static_cast<char>(horse_number);
		cout << ' ' << '\xDB' << horse_char << '\xDB';
		distance_run += 0.2F;
	}
};
class comtrack : public track
{
private:
	comhorse* hArray[maxHorses];
public:
	comtrack(float lenT, int nH) : track(lenT, nH)
	{
		horse_count = 0;
		for (int j = 0; j < total_horses; j++)
			hArray[j] = new comhorse(horse_count++, this);
	}
	void run()
	{
		while (!_kbhit())
		{
			int horse_leader = 0;
			float delta = 0.0;

			elapsed_time += 1.75;
			for (int j = 0; j < total_horses; j++)
				hArray[j]->display_horse(elapsed_time);

			for (int j = 0; j < total_horses; j++)
				if (hArray[horse_leader]->get_distance() < hArray[j]->get_distance())
					horse_leader = j;

			for (int j = 0; j < total_horses; j++)
				if (hArray[horse_leader]->get_distance() - hArray[j]->get_distance() > delta)
					delta = hArray[horse_leader]->get_distance() - hArray[j]->get_distance();

			if ((hArray[horse_leader]->get_distance() > (track_length + 1.0 / CPF) / 2) &&
				(hArray[horse_leader]->get_distance() < (track_length + 1.0 / CPF)) &&
				(delta <= 2.2f))
			{
				hArray[horse_leader]->horse_tick();
			}
			wait(100);
		}
		_getch();
		cout << endl;
	}
};
int main() {
	float length;
	int total;
	cout << "\nEnter track length (furlongs; 1 to 12): ";
	cin >> length;
	cout << "\nEnter number of horses (1 to 7): ";
	cin >> total;
	track theTrack(length, total); 
	theTrack.run(); 
	return 0;
}

//lab10.10
#include <iostream>
using namespace std;
struct link
{
    int data;
    link* next;
};
class linklist {
private:
	link* first;                    
public:
	linklist() {
		first = NULL;
	}
	linklist(const linklist& list) {
		if (list.first == NULL) 
			return;
		first = new link();
		first->data = list.first->data;
		link* cur1 = first;
		link* cur2 = list.first;
		while (cur2->next != NULL) {
			cur2 = cur2->next;
			cur1->next = new link();
			cur1 = cur1->next;
			cur1->data = cur2->data;
		}
	}
	linklist& operator=(const linklist& list) {
		*this = linklist(list);
		return *this;
	}
	~linklist();                    
	void additem(int d);            
	void display();                 
};
void linklist::additem(int d) {
	link* newlink = new link;          
	newlink->data = d;                 
	newlink->next = first;             
	first = newlink;                   
}
void linklist::display() {
	link* current = first;             
	while (current != NULL) {
		cout << " " << current->data;  
		current = current->next;        
	}
}
linklist::~linklist() {
	link* current = first;             
	cout << "\nList was deleted!\n";
	while (current != NULL)           
	{
		link* temp = current;           
		current = current->next;        
		cout << temp->data << " ";
		delete temp;                    
	}
}
int main() {
	linklist* li = new linklist();
	cout << "\nNew list:\n";
	li->additem(25);    
	li->additem(36);
	li->additem(49);
	li->additem(64);
	li->display();      
	linklist copy = *li;
	delete li;
	cout << "\nCopy of the list:\n";
	copy.display();

    return 0;
}

//lab10.11
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int LEN = 80;
const int MAX = 40;
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
class token {
public:
	virtual float getnumber() = 0;
	virtual char getoperator() = 0;
};
class Operator : public token {
private:
	char oper;
public:
	Operator(char ch) {
		oper = ch;
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
	number(float f) {
		fnum = f;
	}
	float getnumber() {
		return fnum;
	}
	char getoperator() { 
		return 0; 
	}
};
class Stack {
private:
	token* st[100];
	int top;
public:
	Stack() {
		top = 0;
	}
	void push(float var) {
		st[++top] = new number(var);
	}
	void push(char var) {
		st[++top] = new Operator(var);
	}
	float pop(int useless) {
		return st[top--]->getnumber();
	}
	char pop(char useless) {
		return st[top--]->getoperator();
	}
	int gettop() {
		return top;
	}
};
class express {
private:
	Stack s; 
	char* pStr; 
	int len; 
public:
	express(char* ptr) {
		pStr = ptr; 
		len = strlen(pStr); 
	}
	void parse(); 
	float solve(); 
};
void express::parse() {
	int lock = 0;
	float m2;
	char ch;
	float chisl = 0;
	float lastval;
	char lastop;
	for (int j = 0; j < len; j++)
	{
		ch = pStr[j];
		if ((ch >= '0' && ch <= '9') || (ch == '.')) {
			if (ch >= '0' && ch <= '9' && lock == 0) {
				chisl += (float)ch - 48;
				chisl *= 10;
			}
			if (ch == '.') {
				chisl /= 10;
				lock = 1;
			}
			if (ch >= '0' && ch <= '9' && lock != 0) {
				m2 = (float)ch - 48;
				for (int k = 0; k < lock; k++) m2 /= 10;
				lock++;
				chisl += m2;
				m2 = 0;
			}
			if ((pStr[j + 1] < '0' || pStr[j + 1] > '9') && (pStr[j + 1] != '.')) {
				s.push(chisl);
				chisl = 0;
				lock = 0;
			}
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			if (s.gettop() == 1)
				s.push(ch);
			else {
				lastval = s.pop(1);
				lastop = s.pop('1');

				if ((ch == '*' || ch == '/') &&
					(lastop == '+' || lastop == '-'))
				{
					s.push(lastop);
					s.push(lastval);
				}
				else {
					switch (lastop) {
					case '+': 
						s.push(s.pop(1) + lastval); 
						break;
					case '-': 
						s.push(s.pop(1) - lastval); 
						break;
					case '*': 
						s.push(s.pop(1) * lastval); 
						break;
					case '/': 
						s.push(s.pop(1) / lastval); 
						break;
					default: 
						cout << "\nUnknown oper"; 
						exit(1);
					}
				}
				s.push(ch);
			}
		}
		else {
			cout << "\nUnknown input character"; 
			exit(1);
		}
	}
}
float express::solve() {
	float lastval;
	while (s.gettop() > 1)
	{
		lastval = s.pop(1);
		switch ((char)s.pop('1'))
		{
		case '+': 
			s.push(s.pop(1) + lastval); 
			break;
		case '-': 
			s.push(s.pop(1) - lastval); 
			break;
		case '*': 
			s.push(s.pop(1) * lastval); 
			break;
		case '/': 
			s.push(s.pop(1) / lastval); 
			break;
		default: 
			cout << "\nUnknown operator"; 
			exit(1);
		}
	}
	return float(s.pop(1));
}
int main() {
	bMoney* ar[100];
	char ans; 
	char string[LEN]; 
	cout << "\nEnter an arithmetic expression of the form 2+3*4/3-2." << endl
		<< "No number may have more than one digit." << endl	
		<< "Don't use any spaces or parentheses." << endl;
	do {
		cout << "\nEnter expresssion: ";
		cin >> string; 
		string[strlen(string)] = '\0';
		express* eptr = new express(string); 
		eptr->parse(); 
		cout << "\nThe numerical value is: " << eptr->solve(); 
		delete eptr; 
		cout << "\nDo another (Enter y or n)? ";
		cin >> ans;
	} while (ans == 'y');
	return 0;
}
