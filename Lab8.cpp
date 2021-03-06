//lab8.1
#include <iostream>
#include <string>
using namespace std;
class publication
{
private:
	string title;
	float price;
public:
	void getdata()
	{
		cout << "\nEnter title: "; cin >> title;
		cout << "Enter price: "; cin >> price;
	}
	void putdata() const
	{
		cout << "\nTitle: " << title;
		cout << "\nPrice: " << price;
	}
};
class book : private publication
{
private:
	int pages;
public:
	void getdata()
	{
		publication::getdata();
		cout << "Enter number of pages: "; cin >> pages;
	}
	void putdata() const
	{
		publication::putdata();
		cout << "\nPages: " << pages;
	}
};
class tape : private publication 
{
private:
	float time;
public:
	void getdata()
	{
		publication::getdata();
		cout << "Enter playing time: "; cin >> time;
	}
	void putdata() const
	{
		publication::putdata();
		cout << "\nPlaying time: " << time;
	}
};
int main()
{
	book book1; 
	tape tape1;
	book1.getdata(); 
	tape1.getdata();
	book1.putdata(); 
	tape1.putdata();
	cout << endl;
	return 0;
}

//lab8.2	DON'T WORK!!!
#include <iostream>
#include <cstring> 
using namespace std;
class String 
{
protected: 
	enum { SZ = 80 }; 
	char str[SZ]; 
public:
	String() 
	{
		str[0] = '\0';
	}
	String(char s[]) 
	{
		strcpy(str, s);
	} 
	void display() const 
	{
		cout << str;
	}
	operator char* () 
	{
		return str;
	}
};
class Pstring : public String 
{
public:
	Pstring(char s[]); 
};
Pstring::Pstring(char s[]) 
{
	int j;
	if (strlen(s) > SZ - 1) 
	{
		for (int j = 0; j < SZ - 1; j++) 
			str[j] = s[j]; 
		str[j] = '\0'; 
	}
	else 
		String(s); 
}
int main() {
	Pstring s1 = "This is a very long string which is probably no, certainly--going to exceed the limit set by SZ.";
	cout << "\ns1="; s1.display(); 
	Pstring s2 = "This is a short string."; 
	cout << "\ns2="; s2.display(); 
	cout << endl;
	return 0;
}

//lab8.3
#include <iostream>
#include <string>
using namespace std;
class publication
{
private:
	string title;
	float price;
public:
	void getdata()
	{
		cout << "\nEnter title: "; cin >> title;
		cout << " Enter price: "; cin >> price;
	}
	void putdata() const
	{
		cout << "\nTitle: " << title;
		cout << "\n Price: " << price;
	}
};
class sales
{
private:
	enum { MONTHS = 3 };
	float salesArr[MONTHS];
public:
	void getdata();
	void putdata() const;
};
void sales::getdata()
{
	cout << " Enter sales for 3 months\n";
	for (int j = 0; j < MONTHS; j++)
	{
		cout << " Month " << j + 1 << ": ";
		cin >> salesArr[j];
	}
}
void sales::putdata() const
{
	for (int j = 0; j < MONTHS; j++)
	{
		cout << "\n Sales for month " << j + 1 << ": ";
		cout << salesArr[j];
	}
}
class book : private publication, private sales
{
private:
	int pages;
public:
	void getdata()
	{
		publication::getdata();
		cout << " Enter number of pages: "; cin >> pages;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << "\n Pages: " << pages;
		sales::putdata();
	}
};
class tape : private publication, private sales
{
private:
	float time;
public:
	void getdata()
	{
		publication::getdata();
		cout << " Enter playing time: "; cin >> time;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << "\n Playing time: " << time;
		sales::putdata();
	}
};
int main()
{
	book book1; 
	tape tape1;
	book1.getdata(); 
	tape1.getdata();
	book1.putdata(); 
	tape1.putdata();
	cout << endl;
	return 0;
}

//lab8.4
#include <iostream>
#include <string>
using namespace std;
class publication
{
private:
	string title;
	float price;
public:
	void getdata()
	{
		cout << "\nEnter title: "; cin >> title;
		cout << " Enter price: "; cin >> price;
	}
	void putdata() const
	{
		cout << "\nTitle: " << title;
		cout << "\n Price: " << price << endl;
	}
};
class sales
{
private:
	enum { MONTHS = 3 };
	float salesArr[MONTHS];
public:
	void getdata();
	void putdata() const;
};
void sales::getdata()
{
	cout << " Enter sales for 3 months\n";
	for (int j = 0; j < MONTHS; j++)
	{
		cout << " Month " << j + 1 << ": ";
		cin >> salesArr[j];
	}
}
void sales::putdata() const
{
	for (int j = 0; j < MONTHS; j++)
	{
		cout << "\n Sales for month " << j + 1 << ": ";
		cout << salesArr[j];
	}
}
class book : private publication, private sales
{
private:
	int pages;
public:
	void getdata()
	{
		publication::getdata();
		cout << " Enter number of pages: "; cin >> pages;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << "\n Pages: " << pages;
		sales::putdata();
	}
};
class tape : private publication, private sales
{
private:
	float time;
public:
	void getdata()
	{
		publication::getdata();
		cout << " Enter playing time: "; cin >> time;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << "\n Playing time: " << time;
		sales::putdata();
	}
};
class disk : private publication, private sales {
private:
	enum type { c = 1, d };
	int d_type;
public:
	void getdata() {
		publication::getdata();
		int di;
		cout << "Enter the type of the disk (CD or DVD), write 1 or 2: ";
		cin >> di;
		d_type = di;
		sales::getdata();
	}
	void putdata() {
		publication::putdata();
		switch (d_type) {
		case c:
			cout << " Disk: CD" << endl;
			break;
		case d:
			cout << " Disk: DVD" << endl;
			break;
		default:
			cout << " Incorrect value.";
			break;
		}
		sales::putdata();
	}
};
int main()
{
	book book1; 
	tape tape1;
	disk disk1;
	book1.getdata(); 
	tape1.getdata();
	disk1.getdata();
	book1.putdata(); 
	tape1.putdata();
	disk1.putdata();
	cout << endl;
	return 0;
}

//lab8.5
#include <iostream>
#include <string>
using namespace std;
const int LEN = 80; 
class employee {
private:
	char name[LEN]; 
	unsigned long number; 
public:
	void getdata() {
		cout << "\nEnter last name: "; 
		cin >> name;
		cout << "Enter number: "; 
		cin >> number;
	}
	void putdata() const {
		cout << "\nName: " << name;
		cout << "\nNumber: " << number << endl;
	}
};
class employee2 : private employee {
private:
	double compensation;
	int c_period;
	enum period {hourly = 1, monthly, yearly};
public:
	void getdata() {
		double com;
		int per;
		employee::getdata();
		cout << "Enter the type of pay(hourly, monthly, yearly), write 1 or 2 or 3: ";
		cin >> per;
		switch (per) {
		case hourly:
			cout << "Enter the compensation: ";
			cin >> com;
			c_period = per;
			compensation = com;
			break;
		case monthly:
			cout << "Enter the compensation: ";
			cin >> com;
			c_period = per;
			compensation = com;
			break;
		case yearly:
			cout << "Enter the compensation: ";
			cin >> com;
			c_period = per;
			compensation = com;
			break;
		default:
			cout << "Incorrect value." << endl;
			break;
		}
	}
	void putdata() {
		employee::putdata();
		switch (c_period) {
		case 1:
			cout << "Period: hourly" << endl
				<< "Compensation: " << compensation << endl;
			break;
		case 2:
			cout << "Period: monthly" << endl
				<< "Compensation: " << compensation << endl;
			break;
		case 3:
			cout << "Period: yearly" << endl
				<< "Compensation: " << compensation << endl;
			break;
		default:
			break;
		}
	}
};
int main() {
	employee2 em1, em2;
	em1.getdata();
	em2.getdata();
	em1.putdata();
	em2.putdata();
	return 0;
}

//lab8.6
#include <iostream>
#include <process.h>
using namespace std;
const int LIMIT = 100; 
class safearay {
protected:
	int arr[LIMIT];
	int b_ind, e_ind;
public:
	int& operator [](int n) {	
		if (n < 0 || n >= LIMIT) {
			cout << "\nIndex out of bounds"; 
			exit(1);
		}
		return arr[n];
	}
};
class safearay2 : public safearay {
public:
	safearay2(int b, int e) {
		b_ind = b;
		e_ind = e;
	}
};
int main() {
	int beg_ind, en_ind;
	cout << "Enter the 1st and the last index of the array: ";
	cin >> beg_ind >> en_ind;
	safearay2* s = new safearay2(beg_ind, en_ind);
	return 0;
}

//lab8.7
#include <iostream>
using namespace std;
class Counter {
protected: 
	unsigned int count; 
public:
	Counter() : count(0) 
	{ }
	Counter(int c) : count(c) 
	{ }
	unsigned int get_count() const 
	{
		return count;
	}
	Counter operator ++ () 
	{
		return Counter(++count);
	}
};
class CountDn : public Counter {
public:
	CountDn() : Counter() 
	{ }
	CountDn(int c) : Counter(c) 
	{ }
	CountDn operator -- () {
		return CountDn(--count);
	}
};
class CountTn : public Counter {
public:
	CountTn() : Counter() 
	{ }
	CountTn(int c) : Counter(c)
	{ }
	CountTn operator ++ (int i) {
		return CountTn(count++);
	}
	CountTn operator -- (int i) {
		return CountTn(count--);
	}
};
int main() {
	CountTn c1(10);
	CountTn c2(20);
	c1++; c2++;
	cout << "\nc1 = " << c1.get_count() << endl;
	cout << "\nc2 = " << c2.get_count() << endl;
	c1--; c2--;
	cout << "\nc1 = " << c1.get_count() << endl;
	cout << "\nc2 = " << c2.get_count() << endl;
	return 0;
}

//lab8.8
#include <iostream>
#include <string>
using namespace std;
class String {
protected:
    int SZ = 80;
    string str;
public:
    String() {
        str[0] = '\0';
    }
    String(const char s[]) {
        str = s;
    }
    void return_string() {
        cout << str << endl;
    }
};
class Pstring : public String {
public:
    Pstring(const char s[]) {
        str = s;
    }
    void check_string() {
        string s;
        int i;
        if (str.size() > SZ - 1) {
            for (i = 0; i < SZ; i++) {
                s += str[i];
            }
            s[i] = '\0';
            str = s;
            cout << "Your string is too long!" << endl;
        }
    }
};
class Pstring2 : public String {
public:
    Pstring2(const char s[]) {
        str = s;
    }
    void left(int n) {
        string s;
        for (int i = n - 1; i < str.size(); i++) {
            s += str[i];
        }
        str = s;
    }
    void right(int n) {
        string s;
        for (int i = 0; i < str.size() - n - 1; i++) {
            s += str[i];
        }
        str = s;
    }
    void mid(int n, int m) {
        string s;
        for (int i = 0; i < str.size(); i++) {
            if ((i < m) || (i > m+n)) {
                s += str[i];
            }
        }
        str = s;
    }
};
int main() {
    Pstring s1 = "This is a very long string which is probably no, certainly--going to exceed the limit set by SZ.";
    s1.check_string();
    s1.return_string();
    Pstring s2 = "This is a short string.";
    s2.check_string();
    s2.return_string();
    Pstring2 s3 = "Hello, world";
    s3.left(4);
    s3.return_string();
    return 0;
}

//lab8.9
#include <iostream>
#include <string>
using namespace std;
class publication {
private:
	string title;
	float price;
public:
	void getdata()
	{
		cout << "\nEnter title: "; cin >> title;
		cout << "Enter price: "; cin >> price;
	}
	void putdata() const
	{
		cout << "\nTitle: " << title;
		cout << "\nPrice: " << price << endl;
	}
};
class publication2 : private publication {
private:
	string date;
public:
	void getdata() {
		string d;
		publication::getdata();
		cout << "Enter date: ";
		cin >> d;
		date = d;
	}
	void putdata() {
		publication::putdata();
		cout << "Date: " << date << endl;
	}
};
class book : private publication2
{
private:
	int pages;
public:
	void getdata() {
		publication2::getdata();
		cout << "Enter number of pages: "; cin >> pages;
	}
	void putdata() {
		publication2::putdata();
		cout << "\nPages: " << pages;
	}
};
class tape : private publication2 {
private:
	float time;
public:
	void getdata() {
		publication2::getdata();
		cout << "Enter playing time: "; cin >> time;
	}
	void putdata() {
		publication2::putdata();
		cout << "\nPlaying time: " << time;
	}
};
int main()
{
	book book1;
	tape tape1;
	book1.getdata();
	tape1.getdata();
	book1.putdata();
	tape1.putdata();
	cout << endl;
	return 0;
}

//lab8.10
#include <iostream>
using namespace std;
const int LEN = 80; 
class student {
private:
	char school[LEN]; 
	char degree[LEN]; 
public:
	void getedu() {
		cout << " Enter name of school or university: ";
		cin >> school;
		cout << " Enter highest degree earned (Highschool, Bachelor's, Master's, PhD): ";
		cin >> degree;
	}
	void putedu() const {
		cout << "\n School or university: " << school;
		cout << "\n Highest degree earned: " << degree;
	}
};
class employee {
private:
	char name[LEN]; 
	unsigned long number; 
public:
	void getdata() {
		cout << "\n Enter last name: "; 
		cin >> name;
		cout << " Enter number: "; 
		cin >> number;
	}
	void putdata() const {
		cout << "\n Name: " << name;
		cout << "\n Number: " << number;
	}
};
class manager : private employee, private student {
private:
	char title[LEN]; 
	double dues; //golf club dues
public:
	void getdata() {
		employee::getdata();
		cout << " Enter title: "; cin >> title;
		cout << " Enter golf club dues: "; cin >> dues;
		student::getedu();
	}
	void putdata() const {
		employee::putdata();
		cout << "\n Title: " << title;
		cout << "\n Golf club dues: " << dues;
		student::putedu();
	}
};
class scientist : private employee, private student {
private:
	int pubs; 
public:
	void getdata() {
		employee::getdata();
		cout << " Enter number of pubs: "; cin >> pubs;
		student::getedu();
	}
	void putdata() const {
		employee::putdata();
		cout << "\n Number of publications: " << pubs;
		student::putedu();
	}
};
class laborer : public employee {

};
class executive : private manager, private student {
private: 
	double annual_aw;
	int stock_am;
public:
	void getdata() {
		double an_aw;
		int st_am;
		manager::getdata();
		cout << "Enter the annual award: ";
		cin >> an_aw;
		cout << "Enter the amount of stocks: ";
		cin >> st_am;
		annual_aw = an_aw;
		stock_am = st_am;
		student::getedu();
	}
	void putdata() {
		manager::putdata();
		cout << "Annual award: " << annual_aw << endl;
		cout << "Stock amount: " << stock_am << endl;
		student::putedu();
	}
};
int main() {
	executive ex1;
	ex1.getdata();
	ex1.putdata();
	cout << endl;
	return 0;
}

//lab8.11
#include <iostream>
#include <process.h>
using namespace std;
class Stack { 
protected:              
	enum { MAX = 3 };    
	int st[MAX];        
	int top;                
public:
	Stack() { 
		top = -1; 
	} 
	void push(int var) { 
		st[++top] = var; 
	}     
	int pop() { 
		return st[top--]; 
	} 
}; 
class Stack2 : public Stack {   
public: 
	void push(int var) {         
		if (top >= MAX-1) { 
			cout << "\nОшибка: стек полон"; 
			exit(1); 
		}
		Stack::push (var);     
	} 
	int pop() {         
		if (top < 0) { 
			cout << "\nОшибка: стек пуст\n"; 
			exit (1); 
		}
	return Stack::pop();       
	} 
};

class pairStack : public Stack2 {
public:
	void push(int x, int y) {
		Stack2::push(x);
		Stack2::push(y);
	}
	void pop() {
		cout << Stack2::pop() << " " << Stack2::pop() << endl;
	}
};
int main() {   
	setlocale(LC_ALL, "Russian"); 
	pairStack p1;
	p1.push(4, 5);
	p1.pop();
	return 0; 
}

//lab8.12
#include <iostream>
#include <process.h>
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
	sterling(long po, int s, int pe) {
		pounds = po;
		shillings = s;
		pense = pe;
	}
	void ster(long po, int s, int pe) {
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
		cout << pounds << "." << shillings << "." << pense;
	}
	void putDouble() {
		cout << d << endl;
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
	sterling operator * (sterling s2) {
		pounds = pounds * s2.pounds;
		shillings = shillings * s2.shillings;
		pense = pense * s2.shillings;
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
class sterfrac : public sterling {
private:
	int eighths_chisl, eighths_znam, shillings, pense;
	long pounds;
	sterling st;
public:
	sterfrac(long po, int sh, int pe, int ei_ch, int ei_zn) {
		st.ster(po, sh, pe);
		eighths_chisl = ei_ch;
		eighths_znam = ei_zn;
	}
	void get_ster() {
		char s;
		int ch, zn;
		st.getSterling();
		cout << "Enter the eighth part: ";
		cin >> ch >> s >> zn;
		eighths_chisl = ch;
		eighths_znam = zn;
	}
	sterfrac operator + (sterfrac s2) {
		st = st + s2.st;
		return sterfrac(st.put_pound(), st.put_shilling(), st.put_pense(), eighths_chisl * s2.eighths_znam + s2.eighths_chisl * eighths_znam, eighths_znam * s2.eighths_znam);
	}
	sterfrac operator - (sterfrac s2) {
		st = st - s2.st;
		return sterfrac(st.put_pound(), st.put_shilling(), st.put_pense(), eighths_chisl * s2.eighths_znam - s2.eighths_chisl * eighths_znam, eighths_znam * s2.eighths_znam);
	}
	sterfrac operator * (sterfrac s2) {
		st = st * s2.st;
		return sterfrac(st.put_pound(), st.put_shilling(), st.put_pense(), eighths_chisl * s2.eighths_chisl, eighths_znam * s2.eighths_znam);
	}
	sterfrac operator / (sterfrac s2) {
		st = st / s2.st;
		return sterfrac(st.put_pound(), st.put_shilling(), st.put_pense(), eighths_chisl * s2.eighths_znam, eighths_znam * s2.eighths_chisl);
	}
	void put_ster() {
		st.putSterling();
		cout << "-" << eighths_chisl << "/" << eighths_znam << endl;
	}
};
int main() {
	sterfrac st1(1, 2, 3, 4, 5);
	sterfrac st2(6, 7, 8, 9, 10);
	st1.get_ster();
	st2.get_ster();
	sterfrac st3 = st1 + st2;
	st3.put_ster();
	return 0;
}
