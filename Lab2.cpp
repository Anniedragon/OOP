//lab2.1
#include <iostream>
#include <iomanip> 
using namespace std;
int main()
{
	unsigned long n; 
	cout << "Enter a number: ";
	cin >> n; 
	for (int j = 1; j <= 200; j++) 
	{
		cout << setw(5) << j * n << " "; 
		if (j % 10 == 0) 
			cout << endl; 
	}
	return 0;

}

//lab2.2
//lab2.3
//lab2.4
//lab2.5
//lab2.6
//lab2.7
//lab2.8
//lab2.9
//lab2.10
//lab2.11
//lab2.12
