//lab7.1
#include <iostream>
using namespace std;
class Distance {
private:
	int feet;
	float inches;
public: 
	Distance() : feet(0), inches(0.0)
	{ } 
	Distance(int ft, float in) : feet(ft), inches(in)
	{ }
	void getdist() {
		cout << "\nEnter feet: "; cin >> feet;
		cout << "Enter inches: "; cin >> inches;
	}
	void showdist()	{
		cout << feet << "\'-" << inches << '\"';
	}
	Distance operator + (Distance);
	Distance operator - (Distance); 
};
Distance Distance::operator + (Distance d2) {
	int f = feet + d2.feet;
	float i = inches + d2.inches;
	if (i >= 12.0) {
		i -= 12.0; 
		f++; 
	} 
	return Distance(f, i); 
}
Distance Distance::operator - (Distance d2) {
	int f = feet - d2.feet; 
	float i = inches - d2.inches; 
	if (i < 0) {
		i += 12.0; 
		f--; 
	} 
	return Distance(f, i); 
}
int main() {
	Distance dist1, dist3; 
	dist1.getdist(); 
	Distance dist2(3, 6.25); 
	dist3 = dist1 - dist2; 
	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
	cout << endl;
	return 0;
}

//lab7.2
//lab7.3
//lab7.4
//lab7.5
//lab7.6
//lab7.7
//lab7.8
//lab7.9
//lab7.10
//lab7.11
//lab7.12
