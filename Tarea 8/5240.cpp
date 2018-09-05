#include <iostream>
#include <stdio.h>
using namespace std;
char nom[20];
char nom2[20];
char apellidoP[20];
char apellidoM[20];
int esq;
int esq2;
void mos() {
	system("cls");
	cout << "Lista\n\n";
	cout << "Los registrado son:\n" << nom << " " << apellidoP << " " << apellidoM << endl;
}
void regis() {
	system("cls");
	cout << "Lugra de Registro\n\n";
	cout << "Introduce tu primer nombre: \n";
	cin >> nom;
	cout << "Introduce tu segundo nombre: \n";
	cin >> nom2;
	cout << "Intoduce tu apellido paterno: \n";
	cin >> apellidoP;
	cout << "Intoduce tu apellido materno: \n";
	cin >> apellidoM;
	cout << "\n!Ya estas Registrado.¡"<<endl;
	cout << "(1)Lista de registrados.\n\n(2)Salir."<<endl;
	cin >> esq2;
	if (esq2 == 1) {
		mos();
	}


}


int main() {
	locale::global(locale("spanish"));
	system("color 3");
	do {
		system("cls");
		cout << "MENÚ\n\n(1)lista de registrados\n(2)Registrarse\n(3)Salir\n";
		cin >> esq;
		switch (esq) {
		case 1: mos();
		break;
		case 2: regis();
		break;
		}
	} while (esq < 2);
	system("pause");
}
