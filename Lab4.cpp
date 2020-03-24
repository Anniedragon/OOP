//lab4.1
#include <iostream>
using namespace std;
float circarea(float radius);
int main()
{
	double rad;
	setlocale(LC_ALL, "Russian");
	cout << "\nВведите радиус окружности: ";
	cin >> rad;
	cout << "S площадь равна " << circarea(rad) << endl;
	return 0;
}
float circarea(float r)
{
	const float PI = 3.14159F;
	return r * r * PI;
}

//lab4.2
//lab4.3
//lab4.4
//lab4.5
//lab4.6
//lab4.7
//lab4.8
//lab4.9
//lab4.10
//lab4.11
//lab4.12
