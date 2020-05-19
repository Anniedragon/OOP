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
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
using namespace std;
class money {
private:
	long double sum;
public:
	long double temp = 1;
	long double result = 0;
	long double mstold(string u_sum) {
		string s;
		int len;
		len = u_sum.size() - 3;
		for (int i = 0; i < len; i++) {
			if ((u_sum[i] != '$') && (u_sum[i] != ',')) {
				if ((u_sum[i] == '.') && (i + 2 == len - 1)) {
					s += u_sum[i];
				}
				else s += u_sum[i];
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
		cout << result;
		return result;
	}
};
int main() {
	money m;
	string sum;
	cout << "Enter sum: ";
	cin >> sum;
	m.mstold(sum);
	return 0;
}

//lab6.8
#include <iostream>
using namespace std;
class safearay {
private:
    int limit[20];
public:
    void putel(int ind, int zn) {
        if ((ind > 19) || (ind < 0)) {
            cout << "You're out of array. Max index is 19 and min index is 0." << endl;
        }
        else limit[ind] = zn;
    }
    void getel(int ind) {
        if ((ind > 19) || (ind < 0)) {
            cout << "You're out of array. Max index is 19 and min index is 0." << endl;
        }
        else cout << limit[ind];
    }
};
int main() {
    safearay s;
    int index;
    int znach;
    int flag = 1;
    while (flag != 0) {
        cout << "Enter an index and value of element: ";
        cin >> index >> znach;
        s.putel(index, znach);
        cout << "Do you want to continue? yes - 1, no - 0: ";
        cin >> flag;
    }
    flag = 1;
    while (flag != 0) {
        cout << "Enter an index of element, that value you want to see: ";
        cin >> index;
        s.getel(index);
    }
}

//lab6.9
//lab6.10
#include <iostream>
using namespace std;
class matrix {
private:
	int limit[10][10];
	int N, M;
public:
	matrix(int m, int n) {
		N = n;
		M = m;
	}
	void putel(int ind1, int ind2, int el) {
		if (((ind1 < 0) || (ind1 > N - 1)) || ((ind2 < 0) || (ind2 > M - 1))) {
			cout << "You're out of matrix. Min index is 0, max index is " << N - 1 << "." << endl;
		}
		else limit[ind1][ind2] = el;
	}
	void getel(int ind1, int ind2) {
		if (((ind1 < 0) || (ind1 > N - 1)) || ((ind2 < 0) || (ind2 > M - 1))) {
			cout << "You're out of matrix. Min index is 0, max index is " << N - 1 << "." << endl;
		}
		else cout << limit[ind1][ind2] << endl;
	}
};
int main() {
	int index1, index2, value, N, M;
	char flag;
	cout << "You have a matrix[10][10]. Do you want to change it's size? y/n: ";
	cin >> flag;
	if (flag == 'y') {
		cout << "Enter a new size: ";
		cin >> N >> M;
	}
	else {
		N = 10;
		M = 10;
	}
	flag = 'y';
	matrix* m = new matrix(N, M);
	while (flag != 'n') {
		cout << "Enter two indexes and value: ";
		cin >> index1 >> index2 >> value;
		m->putel(index1, index2, value);
		cout << "Do you want to continue? y/n: ";
		cin >> flag;
	}
	flag = 'y';
	while (flag != 'n') {
		cout << "Enter two indexes of element, that value you want to see: ";
		cin >> index1 >> index2;
		m->getel(index1, index2);
		cout << "Do you want to continue? y/n: ";
		cin >> flag;
	}
}

//lab6.11
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
class money {
private:
	int sum;
public:
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
};
int main() {
    money m;
    long double sum;
    int flag = 1;
    while (flag != 0) {
        cout << "Enter sum: ";
        cin >> sum;
        m.ldtoms(sum);
        cout << "Do you want to continue? yes - 1, no - 0: ";
        cin >> flag;
    }
}

//lab6.12
