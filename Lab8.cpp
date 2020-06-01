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

//lab8.2
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
