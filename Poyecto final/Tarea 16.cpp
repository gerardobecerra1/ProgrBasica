#include <iostream>
#include <windows.h>   // Librería para colores
#include <string>
using namespace std;

int o;
int c;

struct registrados {
	int id;
	string nombre;
	char apellidopa[100];
	char apellidoma[100];
	int matri;
	float calf;
	int countNum, cant;
	char num[10];
	char Mail[30];
	int countAt, countDot;
	
};

registrados r[100];
void menú();
void registrar();
void losreg();
void buscarmatri();
void buscnombre();
void eliminar();

int main() {
	locale::global(locale("spanish"));
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	c = 0;
	menú();
}

void menú() {
	system("cls");
	cout << "Menú" << endl << endl;
	cout << "Elige que quieres hacer:" << endl;
	cout << "1. Registrar \n2. Ver registrados \n3. Buscar matrícula \n4. Buscar nombre\n5. Eliminar\n6. Salír" << endl;
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
	default:
		break;
	}
}
void eliminar() {
	cin.ignore();
	system("cls");
	cout << "Buscador" << endl << endl;
	cout << "¿Qué matrícula buscas? " << endl;
	cin >> o;
	int i = 0;
	while (i < c) {
		if (r[i].matri == o) {
			cin.ignore();
			cout << "Encontré a:" << endl;
			cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidopa << " " << r[i].apellidoma << endl;
			cout << "Numero de telefono: " << r[i].num << endl;
			cout << "Matrícula: " << r[i].matri << endl;
			cout << "Calificacíon: " << r[i].calf << endl;
			cout << "Mail: " << r[i].Mail << endl << endl;
			cout << "¿Eliminar a " << r[i].id << "?" << endl;
			cout << "1. Sí \n2. No" << endl;
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
			cout << "No encontré nada" << endl;
		}
		i++;
	}
	system("pause > nul");
	menú();
}
			
		

void registrar() {
	system("cls");
	cout << "Registro" << endl << endl;
	r[c].id = c;
	cout << "Apellido paterno: ";
	cin >> r[c].apellidopa;
	cout << "Apellido materno: ";
	cin >> r[c].apellidoma;
	cin.ignore();
	cout << "Nombre: ";
	getline(cin, r[c].nombre);
	cout << "Numero de telefono: ";
	cin.ignore();
	cin >> r[c].num;
	for (int i = 0;i<10;i++) {

		if (r[c].num[i] >= 48 && r[c].num[i] <= 57) {
			r[c].countNum++;
		}
		if (r[c].num[i] != NULL) {
			r[c].cant++;
		}

	}
	if (r[c].cant != 10) { cout << "No son los 10 numeros" << endl;}
	else if (r[c].countNum != 10) { cout << "No todos son numeros" << endl;}
	else { cout << "Todos son numeros y es un celular" << endl; }
	system("PAUSE>NULL");
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
			cout << "falta el punto " << endl;
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
	cout << "Matrícula: ";
	cin >> r[c].matri;
	cout << "Calificación:";
	cin >> r[c].calf;
	c++;
	menú();
}

void losreg() {
	system("cls");
	cout << "Registrados: " << endl;
	for (int i = 0; i < c; i++) {
		cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidopa <<" "<< r[i].apellidoma << endl;
		cout << "Numero de telefono: " << r[i].num << endl;
		cout << "Matrícula: " << r[i].matri << endl;
		cout << "Calificacíon: " << r[i].calf << endl;
		cout << "Mail: " << r[i].Mail << endl << endl;
	}
	system("pause > nul");
	menú();
}

void buscarmatri() {
	system("cls");
	cout << "Buscador:" << endl << endl;
	cout << "¿Qué matrícula es la que busca?:" << endl;
	cin >> o;
	int i = 0;
	while (i < c) {
		if (r[i].matri == o) {
			cout << "\nEncontré a: " << endl;
			cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidopa << r[i].apellidoma << endl;
			cout << "Numero de telefono: " << r[i].num << endl;
			cout << "Matrícula: " << r[i].matri << endl;
			cout << "Calificacíon: " << r[i].calf << endl << endl;
			cout << "Mail: " << r[i].Mail << endl << endl;

			cout << "¿Qué deseas modificar?" << endl;
			cout << "1. Matrícula \n2. Nombre \n3. Apellido paterno\n4. Apellido materno \n5. Calificación\n6. Numero\n0. Nada" << endl;
			cin >> o;

			switch (o)
			{

			case 1:
				cout << "Ingresa nueva mátricula: ";
				cin >> r[i].matri;
				break;
			case 2:
				cout << "Ingresa nuevo nombre: ";
				cin.ignore();
				getline(cin, r[i].nombre);
				break;
			case 3:
				cout << "Ingresa nuevo apellido paterno: ";
				cin >> r[i].apellidopa;
				break;
			case 4:
				cout << "Ingresa nuevo apellido materno: ";
				cin >> r[i].apellidoma;
				break;
			case 5:
				cout << "Ingresa nueva calificaión: ";
				cin >> r[i].calf;
				break;
			case 6:
				cout << "Ingresa nuevo numero: ";
				cin >> r[i].num;
				break;
			case 7:
				cout << "Ingresa nuevo Mail: ";
				cin >> r[i].Mail;
				break;

			default:
				break;
			}

			if (o != 0) {
				cout << "Registro modificado: " << endl;
				cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidopa << r[i].apellidoma << endl;
				cout << "Numero de telefono: " << r[i].num << endl;
				cout << "Matrícula: " << r[i].matri << endl;
				cout << "Calificacíon: " << r[i].calf << endl << endl;

				cout << "¿Deseas modificar algo más?:" << endl;
				cout << "1. Matrícula \n2. Nombre \n3. Apellido paterno\n4. Apellido materno \n5. Calificación\n6. Numero\n0. Nada" << endl;
			}
			else {
				cout << "No modificaste nada." << endl;
			}

			break;
		}
		i++;
	}

	system("pause > nul");
	menú();
}


void buscnombre() {
	cin.ignore();
	system("cls");
	cout << "Buscador" << endl << endl;
	cout << "¿Qué nombre buscas?,asegúrate de poner tu(s) nombre(s): " << endl;
	string n;
	getline(cin, n);
	bool encontrado = false;
	for (int i = 0; i < c; i++)
	{
		if (strcmp(n.c_str(), r[i].nombre.c_str()) == 0) {
			cout << "Lo encontré: " << endl;
			cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidopa << r[i].apellidoma << endl;
			cout << "Numero de telefono: " << r[i].num << endl;
			cout << "Matrícula: " << r[i].matri << endl;
			cout << "Calificacíon: " << r[i].calf << endl;
			encontrado = true;
			break;
		}
	}
	if (!encontrado) {
		cout << "No había registros con ese nombre" << endl;
	}
	system("pause > nul");
	menú();
}