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
//lab10.7
//lab10.8
//lab10.9
//lab10.10
//lab10.11
//lab10.12
