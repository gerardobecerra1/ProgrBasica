#include <iostream>
#include <windows.h> 
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int o;
int c;

struct registrados {
	int id;
	string nombre;
	char apellidopa[100];
	char apellidoma[100];
	int matri;
	float calf1=0.00;
	float calf2 = 0.00;
	float calf3 = 0.00;
	char num[15];
	char Mail[30];
	int countAt, countDot;
	string ca;
};

registrados r[100];
void men�();
void registrar();
void losreg();
void buscarmatri();
void buscnombre();
void eliminar();
void salir();

int main() {
	locale::global(locale("spanish"));
	ifstream archivo;
	string v;

	archivo.open("ejemplo.txt", ios::in);
	if (archivo.fail()) {
		cout << "No se pudo abrir.";
		exit(1);
	}
	cout << "Guardados:" << endl;
	while (!archivo.eof()) {
		getline(archivo, v);
		
		cout << v << endl;
	}
	system("pause>nul");
	archivo.close();
	c = 0;
	men�();
}

void men�() {
	system("cls");
	cout << "Men�" << endl << endl;
	cout << "Elige que quieres hacer:" << endl;
	cout << "1. Registrar \n2. Ver registrados \n3. Buscar matr�cula \n4. Buscar nombre\n5. Eliminar\n6. Sal�r" << endl;
	cin >> o;
	switch (o)
	{
	case 1:
		registrar();
		break;

	case 2:
		losreg();
		break;

	case 3:
		buscarmatri();
		break;
	case 4:
		buscnombre();
		break;
	case 5:
		eliminar();
		break;
	case 6:
		salir();
		break;
	default:
		men�();
		break;
	}
}
void registrar() {
	system("cls");
	cout << "Registro" << endl << endl;
	r[c].id = c;
	while (1) {
		system("cls");
		cout << "Apellido paterno: ";
		cin >> r[c].apellidopa;
		int t = 0;
		int l = 0;
		int a = 0;
		l = strlen(r[c].apellidopa);
		for (int i = 0;i<l;i++) {
			if (r[c].apellidopa[i] >= 65 && r[c].apellidopa[i] <= 121) {
				t++;
			}
			else { a++; }
		}
		if (a== 0) {break; }
		else { cout << "escrib�ste un caracter inv�lido" << endl;system("PAUSE>NULL"); }
	}
	cout << "Apellido materno: ";
	cin >> r[c].apellidoma;
	cin.ignore();
	cout << "Nombre: ";
	getline(cin, r[c].nombre);
	while (1) {
		system("cls");
		cout << "Numero de telefono: ";
		cin >> r[c].num;
		int t = 0;
		int l = 0;
		int letra = 0;
		l = strlen(r[c].num);
		for (int i = 0;i<l;i++) {
			if(r[c].num[i]>=48 && r[c].num[i]<=58){
				t++;
			}
			else { letra++; }
		}
		if (t==10&&letra==0) {cout << "Todos son numeros y es un celular" << endl; system("PAUSE>NULL"); break;}
		else{cout << "No son los 10 d�gitos o escrib�ste un caracter inv�lido" << endl;system("PAUSE>NULL");}
	}
	while (1) {
		r[c].countAt = 0;
		r[c].countDot = 0;
		cout << "Introdusca su correo electronico: " << endl;
		cin >> r[c].Mail;
		for (int i = 0;r[c].Mail[i] != NULL;i++) {
			if (r[c].Mail[i] == '@') {
				r[c].countAt++;
			}
			if (r[c].countAt == 1 && r[c].Mail[i] == '.') {
				r[c].countDot++;
			}
		}
		if (r[c].countAt == 0) {
			cout << "No hay @ " << endl;
		}
		else if (r[c].countAt>1) {
			cout << "Hay mas de 1 @" << endl;
		}
		else if (r[c].countDot == 0) {
			cout << "falta el punto" << endl;
		}
		else if (r[c].countDot>1) {
			cout << "Hay mas de un punto" << endl;
		}
		else {
			cout << "Todo esta correcto" << endl;
			system("PAUSE>NULL");
			break;
		}
		system("PAUSE>NULL");
	}
	cout << "Matr�cula: ";
	cin >> r[c].matri;
	while (2) {
		system("cls");
		cout << "Calificaci�n 1:";
		cin >> r[c].calf1;
		cout << "Calificaci�n 2:";
		cin >> r[c].calf2;
		cout << "Calificaci�n 3:";
		cin >> r[c].calf3;
		if (r[c].calf1 > 0.0 && r[c].calf1 < 101.0 && r[c].calf2>0.0 && r[c].calf2<101.0 && r[c].calf3>0.0 && r[c].calf3<101.0) {
			cout << "ok." << endl;
			break;
		}
		else {
			cout << "La calificaci�n no puede ser menor a 0 ni mayor a 100.";
		}
		system("PAUSE>NULL");
	}
	cin.ignore();
	cout << "Direcci�n con calle, n�mero y colonia:" << endl;
	getline(cin, r[c].ca);
	c++;
	men�();
}

void losreg() {
	system("cls");
	cout << "Registrados: " << endl;
	for (int i = 0; i < c; i++) {
		cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidopa << " " << r[i].apellidoma << endl;
		cout << "Numero de telefono: " << r[i].num << endl;
		cout << "Matr�cula: " << r[i].matri << endl;
		cout << "Calificac�on 1: " << r[i].calf1 << endl;
		cout << "Calificac�on 2: " << r[i].calf2 << endl;
		cout << "Calificac�on 3: " << r[i].calf3 << endl;
		cout << "Mail: " << r[i].Mail << endl;
		cout << "Direcci�n con calle, n�mero y colonia:" << r[i].ca << endl << endl;
	}
	ifstream archivo;
	string v;

	archivo.open("ejemplo.txt", ios::in);
	if (archivo.fail()) {
		cout << "No se pudo abrir.";
		exit(1);
	}
	while (!archivo.eof()) {
		getline(archivo, v);
		cout << v << endl;
	}
	system("pause>nul");
	archivo.close();
	men�();
}

void buscarmatri() {
	system("cls");
	cout << "Buscador:" << endl << endl;
	cout << "�Qu� matr�cula es la que busca?:" << endl;
	cin >> o;
	int i = 0;
	while (i < c) {
		if (r[i].matri == o) {
			cout << "\nEncontr� a: " << endl;
			cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidopa << r[i].apellidoma << endl;
			cout << "Numero de telefono: " << r[i].num << endl;
			cout << "Matr�cula: " << r[i].matri << endl;
			cout << "Calificac�on 1: " << r[i].calf1 << endl;
			cout << "Calificac�on 2: " << r[i].calf2 << endl;
			cout << "Calificac�on 3: " << r[i].calf3 << endl;
			cout << "Mail: " << r[i].Mail << endl << endl;
			cout << "Direcci�n con calle, n�mero y colonia:" << r[i].ca;
			cout << "�Qu� deseas modificar?" << endl;
			cout << "1. Matr�cula \n2. Nombre \n3. Apellido paterno\n4. Apellido materno \n5. Calificaci�n 1\n6. Calificaci�n 2\7. Calificaci�n 3\n8. N�mero\n9.mail\n10.Direcci�n con calle, n�mero y colonia:\n0. Nada" << endl;
			cin.ignore();
			cin >> o;
			switch (o)
			{
			case 1:
				cout << "Ingresa nueva m�tricula: ";
				cin.ignore();
				cin >> r[i].matri;
				break;
			case 2:
				cout << "Ingresa nuevo nombre: ";
				cin.ignore();
				getline(cin, r[i].nombre);
				break;
			case 3:
				cout << "Ingresa nuevo apellido paterno: ";
				cin.ignore();
				cin >> r[i].apellidopa;
				break;
			case 4:
				cout << "Ingresa nuevo apellido materno: ";
				cin.ignore();
				cin >> r[i].apellidoma;
				break;
			case 5:
				cout << "Ingresa nueva calificai�n 1: ";
				cin >> r[i].calf1;
				break;
			case 6:
				cout << "Ingresa nueva calificai�n 2: ";
				cin >> r[i].calf2;
				break;
			case 7:
				cout << "Ingresa nueva calificai�n 3: ";
				cin >> r[i].calf3;
				break;
			case 8:
				cout << "Ingresa nuevo numero: ";
				cin.ignore();
				cin >> r[i].num;
				break;
			case 9:
				cout << "Ingresa nuevo Mail: ";
				cin.ignore();
				cin >> r[i].Mail;
				break;
			case 10:
				cin.ignore();
				cout << "Direcci�n con calle, n�mero y colonia:";
				getline(cin, r[i].ca);
			default:
				break;
			}
			if (o != 0) {
				cout << "Registro modificado: " << endl;
				cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidopa << r[i].apellidoma << endl;
				cout << "Numero de telefono: " << r[i].num << endl;
				cout << "Matr�cula: " << r[i].matri << endl;
				cout << "Calificac�on 1: " << r[i].calf1 << endl;
				cout << "Calificac�on 2: " << r[i].calf2 << endl;
				cout << "Calificac�on 3: " << r[i].calf3 << endl;
				cout << "Direcci�n con calle, n�mero y colonia:" << r[i].ca << endl << endl;
				cout << "�Deseas modificar algo m�s?:" << endl;
				cout << "1. Matr�cula \n2. Nombre \n3. Apellido paterno\n4. Apellido materno \n5. Calificaci�n\n6. Numero\n0. Nada" << endl;
			}
			else {
				cout << "No modificaste nada." << endl;
			}
			break;
		}
		i++;
	}
	system("pause > nul");
	men�();
}
void buscnombre() {
	cin.ignore();
	system("cls");
	cout << "Buscador" << endl << endl;
	cout << "�Qu� nombre buscas?,aseg�rate de poner tu(s) nombre(s): " << endl;
	string n;
	getline(cin, n);
	bool encontrado = false;
	for (int i = 0; i < c; i++)
	{
		if (strcmp(n.c_str(), r[i].nombre.c_str()) == 0) {
			cout << "Lo encontr�: " << endl;
			cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidopa << r[i].apellidoma << endl;
			cout << "Numero de telefono: " << r[i].num << endl;
			cout << "Matr�cula: " << r[i].matri << endl;
			cout << "Calificac�on 1: " << r[i].calf1 << endl;
			cout << "Calificac�on 2: " << r[i].calf2 << endl;
			cout << "Calificac�on 3: " << r[i].calf3 << endl;
			cout << "Direcci�n con calle, n�mero y colonia:" << r[i].ca << endl;
			encontrado = true;
			break;
		}
	}
	if (!encontrado) {
		cout << "No hab�a registros con ese nombre" << endl;
	}
	system("pause > nul");
	men�();
}

void eliminar() {
	cin.ignore();
	system("cls");
	cout << "Buscador" << endl << endl;
	cout << "�Qu� matr�cula buscas? " << endl;
	cin >> o;
	int i = 0;
	while (i < c) {
		if (r[i].matri == o) {
			cin.ignore();
			cout << "Encontr� a:" << endl;
			cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidopa << " " << r[i].apellidoma << endl;
			cout << "Numero de telefono: " << r[i].num << endl;
			cout << "Matr�cula: " << r[i].matri << endl;
			cout << "Calificac�on 1: " << r[i].calf1 << endl;
			cout << "Calificac�on 2: " << r[i].calf2 << endl;
			cout << "Calificac�on 3: " << r[i].calf3 << endl;
			cout << "Mail: " << r[i].Mail << endl;
			cout << "Direcci�n con calle, n�mero y colonia:"<<r[i].ca << endl << endl;
			cout << "�Eliminar a este usuario?"<< endl;
			cout << "1. S� \n2. No" << endl;
			cin >> o;
			if (o == 1 && c != 0) {
				for (int j = i; j < c; j++){
					r[j] = r[j + 1];
				}
			c--;
			}
			break;
		}
		if (i == c) {
			cout << "No encontr� nada" << endl;
		}
		i++;
	}
	system("pause > nul");
	men�();
}

void salir() {
	ofstream archivo; 
	archivo.open("ejemplo.txt",ios::app); 
	for (int i = 0; i < c; i++) { 
		archivo << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidopa << " " << r[i].apellidoma << endl;
		archivo << "Numero de telefono: " << r[i].num << endl;
		archivo << "Mail:" << r[i].Mail << endl;
		archivo << "Matr�cula: " << to_string(r[i].matri) << endl;
		archivo << "Calificac�on 1: " << r[i].calf1 << endl;
		archivo << "Calificac�on 2: " << r[i].calf2 << endl;
		archivo << "Calificac�on 3: " << r[i].calf3 << endl;
		archivo << "Direcci�n con calle, n�mero y colonia:" << r[i].ca << endl << endl;
	}
	archivo.close();
}
