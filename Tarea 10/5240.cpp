#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int main() {
	int contar=0;
	int a[100] = {}; // Inicializa en 0s
	int pos = 49;

	for (int i = 0; i < 100; i++)
	{
		system("cls");
		srand(time(NULL));
		int r = 1 - rand() % 2 * 2;
		pos += r;


		pos = pos < 0 ? 99 : pos;
		pos = pos > 99 ? 0 : pos;


		for (int j = 0; j < 100; j++)
		{
			if (j == pos) {
				cout << "@";
				if (j == 49) {
					contar = contar + 1;
				}
			}
			else if (j == 49) {
				cout << "0";
				
				
			}
			else {
				cout << "*";
			}
		}
	

		Sleep(30);
	}
	cout << "\npaso por el inicio:" << contar << endl;
	system("pause");

}