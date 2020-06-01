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
//lab8.8
//lab8.9
//lab8.10
//lab8.11
//lab8.12
