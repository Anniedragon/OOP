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

//lab9.2
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
