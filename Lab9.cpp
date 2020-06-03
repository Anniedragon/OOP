//lab9.1
#include <iostream>
using namespace std;
int main() {
	float flarr[100]; 
	char ch; 
	int num = 0; 
	do {
		cout << "Enter number: "; 
		cin >> *(flarr + num++); 
		cout << " Enter another (y/n)? ";
		cin >> ch;
	}
	while (ch != 'n');
	float total = 0.0; 
	for (int k = 0; k < num; k++) 
		total += *(flarr + k);
	float average = total / num; 
	cout << "Average is " << average << endl;
	return 0;
}

//lab9.2	DON'T WORK!!!
#include <iostream>
#include <cstring> 
#include <cctype> 
using namespace std;
class String {
private:
	char* str;
public:
	String(const char* s) {
		int length = strlen(s); 
		str = new char[length + 1]; 
		strcpy(str, s); 
	}
	~String() {
		delete str;
	}
	void display() {
		cout << str;
	}
	void upit(); 
};
void String::upit() {
	char* ptrch = str; 
	while (*ptrch) {
		*ptrch = toupper(*ptrch); 
		ptrch++; 
	}
}
int main() {
	String s1 = "He who laughs last laughs best.";
	cout << "\ns1="; 
	s1.display();
	s1.upit(); 
	cout << "\ns1="; 
	s1.display();
	cout << endl;
	return 0;
}

//lab9.3
//lab9.4
//lab9.5
//lab9.6
//lab9.7
//lab9.8
//lab9.9
//lab9.10
//lab9.11
//lab9.12
