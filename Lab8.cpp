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
//lab8.4
//lab8.5
//lab8.6
//lab8.7
//lab8.8
//lab8.9
//lab8.10
//lab8.11
//lab8.12
