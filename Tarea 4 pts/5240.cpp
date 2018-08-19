#include <iostream>
#include <math.h>
using namespace std;

int main() {

	float x,y, rad, angu;
	cout << "introduce la longitud del radio:" << endl;
	cin >> rad;
	cout << "introduce cualquier angulo: " << endl;
	cin >> angu;
	x = rad*cos(angu);
	y = rad*sin(angu);
	cout << "Las coordenadas son (" << x << "," << y << ")" << endl;

	system("pause");
	return 0;
}



