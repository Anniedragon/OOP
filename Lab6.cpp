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
//lab6.4
//lab6.5
//lab6.6
//lab6.7
//lab6.8
//lab6.9
//lab6.10
//lab6.11
//lab6.12
