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
#include <iostream>
#include <cstring> 
using namespace std;
const int DAYS = 7; 
int main() {
	void bsort(const char**, int); 
	char* arrptrs[DAYS] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	cout << "\nUnsorted:\n";
	for (int j = 0; j < DAYS; j++) 
		cout << *(arrptrs + j) << endl;
	bsort(arrptrs, DAYS);
	cout << "\nSorted:\n";
	for (int j = 0; j < DAYS; j++) 
		cout << *(arrptrs + j) << endl;
	return 0;
}
void bsort(const char** pp, int n) {
	void order(const char**, const char**);
	int j, k; 
	for (j = 0; j < n - 1; j++) 
		for (k = j + 1; k < n; k++) 
			order(pp + j, pp + k); 
}
void order(const char** pp1, const char** pp2) {
	if (strcmp(*pp1, *pp2) > 0) {
		char* tempptr = *pp1;
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}

//lab9.4
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
		cout << endl << current->data; 
		current = current->next; 
	}
}
linklist::~linklist() {
	link* current = first; 
	while (current != NULL) {
		link* temp = current; 
		current = current->next; 
		delete temp; 
	}
}
int main() {
	linklist li; 
	li.additem(25); 
	li.additem(36);
	li.additem(49);
	li.additem(64);
	li.display(); 
	cout << endl;
	return 0;
}

//lab9.5
#include <iostream>
using namespace std;
void addarrays(float* ar1, float* ar2, float* ar3, int n);
int main() {
	const int N = 5;
	float arr1[] = { 1.2, 1.3, 1.4, 1.5, 1.6 };
	float arr2[] = { 2.2, 2.3, 2.4, 2.5, 2.6 };
	float arr3[N];
	addarrays(arr1, arr2, arr3, N);
	return 0;
}
void addarrays(float* ar1, float* ar2, float* ar3, int n) {
	for (int i = 0; i < n; i++) {
		ar3[i] = ar1[i] + ar2[i];
	}
	for (int i = 0; i < n; i++) {
		cout << ar3[i] << " ";
	}
}

//lab9.6
#include <iostream>
#include <string>
using namespace std;
int compstr(string s1, string s2) {
	if (s1[0] < s2[0]) {
		return -1;
	}
	else if (s1[0] < s2[0]) {
		return 0;
	}
	else {
		for (int i = 1; i < 100; i++) {
			if (s1[i] < s2[i]) {
				return -1;
			}
			else if (s1[i] < s2[i]) {
				return 0;
			}
		}
	}
}
int main() {
	string s1, s2;
	cout << "Enter 1st string: ";
	cin >> s1;
	cout << "Enter 2nd string: ";
	cin >> s2;
	cout << compstr(s1, s2);
	return 0;
}

//lab9.7
#include <iostream>
#include <string> 
using namespace std;
class person {
protected:
	string name;
	float salary;
public:
	void setData() {
		cout << "Enter name: "; 
		cin >> name;
		cout << "Enter salary: "; 
		cin >> salary;
	}
	void printData() {
		cout << "Name: " << name << endl
			<< "Salary: " << salary << endl;
	}
	string getName() {
		return name;
	}
	float getSalary() {
		return salary;
	}
};
int main() {
	void bsort(person**, int);
	void salsort(person**, int);
	person* persPtr[100]; 
	int n = 0; 
	char choice; 
	do { 
		persPtr[n] = new person; 
		persPtr[n]->setData(); 
		n++; 
		cout << "Enter another (y/n)? "; 
		cin >> choice; 
	}
	while (choice == 'y'); 
	cout << "\nUnsorted list:" << endl;
	for (int j = 0; j < n; j++) 
	{
		persPtr[j]->printData();
	}
	bsort(persPtr, n); 
	cout << "\nSorted name list:" << endl;
	for (int j = 0; j < n; j++) {
		persPtr[j]->printData();
	}
	cout << endl;
	salsort(persPtr, n);
	cout << "\nSorted salary list: " << endl;
	for (int j = 0; j < n; j++) {
		persPtr[j]->printData();
	}
	cout << endl;
	return 0;
} 
void bsort(person** pp, int n) {
	void order(person**, person**); 
	int j, k; 
	for (j = 0; j < n - 1; j++) 
		for (k = j + 1; k < n; k++)
			order(pp + j, pp + k); 
}
void order(person** pp1, person** pp2) { 
	if ((*pp1)->getName() > (*pp2)->getName()) {
		person* tempptr = *pp1; 
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}
void salsort(person** pp, int n) {
	int j, k;
	for (j = 0; j < n - 1; j++) {
		for (k = j + 1; k < n; k++) {
			if ((*(pp + j))->getSalary() > (*(pp + k))->getSalary()) {
				person* tempptr = *(pp + j);
				*(pp + j) = *(pp + k);
				*(pp + k) = tempptr;
			}
		}
	}	
}

//lab9.8	DEMO!!! DON'T WORK!!!
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
    link* cfirst;
public:
    linklist() {
        first = NULL;
    }
    void additem(int d);
    void display();
};
void linklist::additem(int d) {
    if (first == NULL) {
        link* first = new link;
        link* cfirst = first;
    }
    link* newlink = new link;
    newlink->data = d;
    cfirst->next = newlink;
    cfirst = newlink;
}
void linklist::display() {
    link* current = first;
    link* end = NULL;
    first->next = end; 
    first = first->next; 
    while (current != NULL) {
        cout << current->data << endl;
        current = current->next;
    }
}
int main() {
    linklist li;
    li.additem(25);
    li.additem(36);
    li.additem(49);
    li.additem(64);
    li.display();
    return 0;
}

//lab9.9
#include <iostream>
using namespace std;
int main() {
    int a0[10];
    for (int i = 0; i < 10; i++) {
        a0[i] = 0;
    }
    int a1[10];
    for (int i = 0; i < 10; i++) {
        a1[i] = 1;
    }
    int a2[10];
    for (int i = 0; i < 10; i++) {
        a2[i] = 2;
    }
    int a3[10];
    for (int i = 0; i < 10; i++) {
        a3[i] = 3;
    }
    int a4[10];
    for (int i = 0; i < 10; i++) {
        a4[i] = 4;
    }
    int a5[10];
    for (int i = 0; i < 10; i++) {
        a5[i] = 5;
    }
    int a6[10];
    for (int i = 0; i < 10; i++) {
        a6[i] = 6;
    }
    int a7[10];
    for (int i = 0; i < 10; i++) {
        a7[i] = 7;
    }
    int a8[10];
    for (int i = 0; i < 10; i++) {
        a8[i] = 8;
    }
    int a9[10];
    for (int i = 0; i < 10; i++) {
        a9[i] = 9;
    }
    int* ap[10] = { a0, a1, a2, a3, a4, a5, a6, a7, a8, a9 };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << ap[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

//lab9.10
//lab9.11
//lab9.12
