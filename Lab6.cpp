//lab6.1
#include <iostream>
#include <cstring>
using namespace std;
void reversit(char[]);
int main()
{
	setlocale(LC_ALL, "Russian");
	const int MAX = 80;
	char str[MAX];
	cout << "\nвведите строку: ";
	cin.get(str, MAX);
	reversit(str);
	cout << "перевернутая строка: ";
	cout << str << endl;
	return 0;
}
void reversit(char s[])
{
	int len = strlen(s); 
	for (int j = 0; j < len / 2; j++)
	{
		char temp = s[j];
		s[j] = s[len - j - 1];
		s[len - j - 1] = temp;
	}
}

//lab6.2
#include <iostream>
#include <string>
using namespace std;
class employee
{
private:
  string name;
  long number;
public:
  void getdata() {
    cout <<"введите имя: ";cin >>name;
    cout <<"введите номер: ";cin >>number;
  }
  void putdata() {
    cout <<"\n имя: " <<name;
    cout <<"\n номер: " <<number;
  }
};
int main() {
employee emparr [100];
int n = 0;
char ch;
do {
  cout <<"\nвведите данные о работнике с номером " << n+1;
  emparr[n++].getdata();
  cout << "Продолжить (y/n)? ";
  cin >> ch;
} while(ch != 'n');
for (int j = 0; j < n; j++) {
  cout <<"\nНомер работника " << j + 1;
  emparr[j].putdata();
}
cout <<endl;
return 0;
}

//lab6.3
#include <iostream>
using namespace std;
class Distance {
private:
  int feet;
  float inches;
public:
  Distance() {
    feet =0;inches =0;
  }
  Distance(int ft,float in) {
    feet =ft;inches =in;
  }
  void getdist() {
    cout <<"\nвведите футы: ";cin >>feet;
    cout <<"введите дюймы: ";cin >>inches;
  }
  void showdist() {
    cout <<feet <<"\'- " <<inches <<'\"';
  }
  void add_dist(Distance, Distance);//объявления
  void div_dist(Distance, int);
};

void Distance::add_dist(Distance d2, Distance d3) {
  inches = d2.inches + d3.inches;
  feet = 0;
  if (inches >= 12.0) {
    inches -= 12.0;
    feet++;
  }
  feet += d2.feet + d3.feet;
}
void Distance::div_dist(Distance d2,int divisor) {
  float fltfeet = d2.feet + d2.inches / 12.0;
  fltfeet /= divisor; 
  feet = int(fltfeet);
  inches = (fltfeet-feet)*12.0;
}
int main() {
Distance distarr [100];
Distance total(0, 0.0), average;
int count = 0; 
char ch;
do {
cout <<"\nвведите расстояние ";
distarr[count++].getdist();
cout << "\nпродолжить (y/n)? ";
cin >> ch;
} while(ch !='n');
for (int j = 0; j < count; j++) {
  total.add_dist(total, distarr[j]);
} 
average.div_dist(total,count);
cout <<"\nCреднее: ";
average.showdist();
cout << endl;
return 0;
}

//lab6.4 CHANGE, PLEASE. FUNCTION SHOULD GIVE YOU ONLY INDEX OF MAX ELEMENT!
#include <iostream>
using namespace std;
void maxint(int* arr, int size);
int main() {
    int N;
    cout << "Enter size of array: ";
    cin >> N;
    int* numbers = new int[N];
    for (int i = 0; i < N; i++) {
        cout << "Enter " << i << " element: ";
        cin >> numbers[i];
    }
    maxint(numbers, N);
}
void maxint(int *arr, int size) {
    int max = arr[0];
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }
    cout << max << " " << index;
}

//lab6.5
#include <iostream>
using namespace std;
class fraction {
private:
	long chisl;
	long znam;
public:
	void get_frac(long u_chisl, long u_znam) {
		chisl = u_chisl;
		znam = u_znam;
	}
	void return_frac() {
		cout << chisl << "/" << znam << endl;
	}
	void frac_sum(fraction, fraction);
	void frac_average(fraction, int);
};
void fraction::frac_sum(fraction f1, fraction f2) {
	chisl = f1.chisl * f2.znam + f2.chisl * f1.znam;
	znam = f1.znam * f2.znam;
}
void fraction::frac_average(fraction d, int size) {
	chisl = d.chisl;
	znam = d.znam * size;
}
int main() {
	int N, chisl, znam;
	char sl;
	fraction sum, average;
	cout << "Enter a size of the array: ";
	cin >> N;
	fraction* frac_array = new fraction[N];
	cout << "Enter 0 fraction like a/b: ";
	cin >> chisl >> sl >> znam;
	sum.get_frac(chisl, znam);
	for (int i = 1; i < N; i++) {
		cout << "Enter " << i << " fraction: ";
		cin >> chisl >> sl >> znam;
		frac_array[i].get_frac(chisl, znam);
	}
	for (int i = 1; i < N; i++) {
		sum.frac_sum(sum, frac_array[i]);
	}
	average.frac_average(sum, N);
	average.return_frac();
	return 0;
}

//lab6.6
#include  <iostream>
#include  <cstdlib> 
#include <ctime>
using namespace std;
enum Suit { clubs, diamonds, hearts, spades };
const int   jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
class card {   
private:    
	int number;    
	Suit suit;
public:
	card() { 
	}
	void set ( int n, Suit s ) { 
		suit = s; number = n; 
	}    
	void display();         
}; 
void card::display ( ){   
	if (number >= 2 && number <= 10)    
		cout << number;  
	else {     
		switch (number) {       
		case jack: 
			cout << 'J'; 
		break;      
		case queen: 
			cout << 'Q'; 
		break;      
		case king: 
			cout << 'K'; 
		break;      
		case ace: 
			cout << 'A'; 
		break;    }
	}   
	switch (suit) {     
	case clubs: 
		cout << static_cast<char>( 5 ); 
	break;    
	case diamonds: 
		cout << static_cast<char>( 4 ); 
	break;    
	case hearts: 
		cout << static_cast<char>( 3 ); 
	break;     
	case spades: 
		cout << static_cast<char>( 6 ); 
	break;   }
} 
int main() { 
	setlocale(LC_ALL, "Russian");
	int count = 2;
	card deck[52];
	int j;  
	cout << endl;   
	for (j = 0; j < 52; j++) {       
		int num = (j % 13) + 2;    
		Suit su = Suit(j / 13);
		deck[j].set(num, su);  
	} 
	cout << "Исходная колода:\n";   
	for (j = 0; j < 52; j++)   {     
		deck[j].display();    
		cout <<  "  "; 
		if (!((j + 1) % 13)) 
			cout << endl;
	} 
	srand(time(NULL));     
	for (j = 0; j < 52; j++) {
		int k = rand() % 52;    
		card temp = deck[j];     
		deck[j] = deck[k];
		deck[k] = temp;
	} 
	cout << "\nДеление перемешанной колоды на группы" << endl
		<< "Группа 1" << endl;
	for (j = 0; j < 52; j++) {
		deck[j].display();    
		cout << "  "; 
		if (!((j + 1) % 13) && !(j + 1 == 52)) {
			cout << endl
				<< "\nГруппа " << count << endl;
			count++;
		}
	} 
	return 0;
}

//lab6.7
//lab6.8
//lab6.9
//lab6.10
//lab6.11
//lab6.12
