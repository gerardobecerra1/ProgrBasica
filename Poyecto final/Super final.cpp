#include <iostream>
#include <windows.h> 
#include <string>
#include <iomanip>
#include <fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int o;
int c;

struct registrados {
	int id;
	string nombre;
	string apellidos;
	int matri;
	float calf1= 0.00;
	float calf2 = 0.00;
	float calf3 = 0.00;
	char num[15];
	char Mail[30];
	int carro, cpun;
	string ca;
	string co;
	string nu;
};

registrados r[100];
void menú();
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
		cout << "No hay archivo";
	}
	archivo.close();
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
	case 6:
		salir();
		break;
	default:
		cout << "inválido";
		system("pause");
		menú();
		break;
	}
}
void registrar() {
	system("cls");
	cout << "Registro" << endl << endl;
	r[c].id = c;
	cin.ignore();
	while (1) {
		system("cls");
		cout << "Apellidos: ";
		getline(cin, r[c].apellidos);
		int t = 0;
		int l = 0;
		int a = 0;
		l = r[c].apellidos.size();
		if (l == NULL) {
			cout << "escribíste un caracter inválido" << endl;system("PAUSE>NULL");
		}
		else {
			for (int i = 0;i < l;i++) {
				if (r[c].apellidos[i] >= 65 && r[c].apellidos[i] <= 122 || r[c].apellidos[i] == 32|| r[c].apellidos[i] >= 160 && r[c].apellidos[i] <= 165) {
					t++;
				}
				else { a++; }
			}
			if (a == 0) { break; }
			else { cout << "escribíste un caracter inválido" << endl;system("PAUSE>NULL"); }
		}
	}
	while (1) {
		system("cls");
		cout << "Nombre: ";
		getline(cin, r[c].nombre);
		int t = 0;
		int l = 0;
		int a = 0;
		l = r[c].nombre.size();
		if (l == NULL) {
			cout << "escribíste un caracter inválido" << endl;system("PAUSE>NULL");
		}
		else {
			for (int i = 0;i < l;i++) {
				if (r[c].nombre[i] >= 65 && r[c].nombre[i] <= 122 || r[c].nombre[i] == 32 || r[c].nombre[i] >= 160 && r[c].nombre[i] <= 165) {
					t++;
				}
				else { a++; }
			}
			if (a == 0) { break; }
			else { cout << "escribíste un caracter inválido" << endl;system("PAUSE>NULL"); }
		}
	}
	
	while (1) {
		system("cls");
		cout << "Numero de telefono con 10 dígitos: ";
		cin >> r[c].num;
		int t = 0;
		int l = 0;
		int letra = 0;
		l = strlen(r[c].num);
		for (int i = 0;i < l;i++) {
			if (r[c].num[i] >= 48 && r[c].num[i] <= 58) {
				t++;
			}
			else { letra++; }
		}
		if (t == 10 && letra == 0) { cout << "Todos son numeros y es un celular" << endl; system("PAUSE>NULL"); break; }
		else { cout << "No son los 10 dígitos o escribíste un caracter inválido" << endl;system("PAUSE>NULL"); }
	}
	while (1) {
		system("cls");
		r[c].carro = 0;
		r[c].cpun = 0;
		cout << "Introdusca su correo electronico: " << endl;
		cin >> r[c].Mail;
		for (int i = 0;r[c].Mail[i] != NULL;i++) {
			if (r[c].Mail[i] == '@') {
				r[c].carro++;
			}
			if (r[c].carro == 1 && r[c].Mail[i] == '.') {
				r[c].cpun++;
			}
		}
		if (r[c].carro == 0) {
			cout << "Falta @ " << endl;
		}
		else if (r[c].cpun == 0) {
			cout << "Falta un punto " << endl;
		}
		else if (r[c].carro>1) {
			cout << "Hay mas de 1 @" << endl;
		}
		else if (r[c].cpun>1) {
			cout << "Hay mas de un punto" << endl;
		}
		else {
			cout << "Todo esta correcto" << endl;
			system("PAUSE>NULL");
			break;
		}
		system("PAUSE>NULL");
	}
	cout << "Matrícula:"<<endl;
	cout << "¿Quieres una matrícula al aleatoria? elige 1, sino elige 2 y escribela:" << endl;
	cin >> o;
	if (o==1) {
		srand(time(NULL));
		r[c].matri = 1800000 + rand() % (1900000-1800000);
		cout << r[c].matri;
		system("pause>nul");
	}
	else {
		cin >> r[c].matri;
	}
	while (2) {
		system("cls");
		cout << "Calificación 1:";
		cin >> r[c].calf1;
		cout << "Calificación 2:";
		cin >> r[c].calf2;
		cout << "Calificación 3:";
		cin >> r[c].calf3;
		if (r[c].calf1 > 0.0 && r[c].calf1 < 101.0 && r[c].calf2>0.0 && r[c].calf2<101.0 && r[c].calf3>0.0 && r[c].calf3<101.0) {
			cout << "ok." << endl;
			break;
		}
		else {
			cout << "La calificación no puede ser menor a 0 ni mayor a 100.";
		}
		system("PAUSE>NULL");
	}
	cin.ignore();
	cout << "Dirección :"<< endl;
	cout << "Calle:" << endl;
	getline(cin, r[c].ca);
	cout << "número:" << endl;
	getline(cin, r[c].nu);
	cout << "Colonia:" << endl;
	getline(cin, r[c].co);
	c++;
	menú();
}

void losreg() {
	system("cls");
	cout << "Registrados: " << endl;
	for (int i = 0; i < c; i++) {
		cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidos << endl;
		cout << "Numero de telefono: " << r[i].num << endl;
		cout << "Matrícula: " << r[i].matri << endl;
		cout << "Calificacíon 1: " << r[i].calf1 << endl;
		cout << "Calificacíon 2: " << r[i].calf2 << endl;
		cout << "Calificacíon 3: " << r[i].calf3 << endl;
		cout << "Mail:" << r[i].Mail << endl;
		cout << "Calle:" << r[i].ca << endl;
		cout << "número:" << r[i].co << endl;
		cout << "Colonia:" << r[i].nu << endl;
	}
	ifstream archivo;
	string v;
	archivo.open("ejemplo.txt", ios::in);
	if (archivo.fail()) {
		cout << "No hay guardados.";
		system("pause>nul");
		menú();
	}
	while (!archivo.eof()) {
		getline(archivo, v);
		cout << v << endl;
	}
	system("pause>nul");
	archivo.close();
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
			cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidos << endl;
			cout << "Numero de telefono: " << r[i].num << endl;
			cout << "Matrícula: " << r[i].matri << endl;
			cout << "Calificacíon 1: " << r[i].calf1 << endl;
			cout << "Calificacíon 2: " << r[i].calf2 << endl;
			cout << "Calificacíon 3: " << r[i].calf3 << endl;
			cout << "Mail: " << r[i].Mail << endl << endl;
			cout << "Calle:" << r[i].ca << endl;
			cout << "número:" << r[i].nu << endl;
			cout << "Colonia:" << r[i].co << endl << endl;
			cout << "¿Qué deseas modificar?" << endl;
			cout << "1. Matrícula \n2. Nombre \n3. Apellidos\n4. Calificación 1\n5. Calificación 2\n6. Calificación 3\n7. Número\n8. Mail\n9. Calle\n10. Número de calle\n11. Colonia\n0. Nada" << endl;
			cin.ignore();
			cin >> o;
			switch (o)
			{
			case 1:
				cout << "Ingresa nueva mátricula: ";
				cin.ignore();
				cin >> r[i].matri;
				break;
			case 2:
				cout << "Ingresa nuevo nombre: ";
				cin.ignore();
				getline(cin, r[i].nombre);
				break;
			case 3:
				cout << "Ingresa nuevo apellido materno: ";
				cin.ignore();
				getline(cin ,r[i].apellidos);
				break;
			case 4:
				cout << "Ingresa nueva calificaión 1: ";
				cin >> r[i].calf1;
				break;
			case 5:
				cout << "Ingresa nueva calificaión 2: ";
				cin >> r[i].calf2;
				break;
			case 6:
				cout << "Ingresa nueva calificaión 3: ";
				cin >> r[i].calf3;
				break;
			case 7:
				cout << "Ingresa nuevo numero: ";
				cin.ignore();
				cin >> r[i].num;
				break;
			case 8:
				cout << "Ingresa nuevo Mail: ";
				cin.ignore();
				cin >> r[i].Mail;
				break;
			case 9:
				cin.ignore();
				cout << "Calle:";
				getline(cin, r[i].ca);
			case 10:
				cout << "Número:";
				getline(cin, r[i].nu);
			case 11:
				cout << "Colonia;";
				getline(cin, r[i].co);
			default:
				break;
			}
			if (o != 0) {
				cout << "Registro modificado: " << endl;
				cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidos<<endl;
				cout << "Numero de telefono: " << r[i].num << endl;
				cout << "Matrícula: " << r[i].matri << endl;
				cout << "Calificacíon 1: " << r[i].calf1 << endl;
				cout << "Calificacíon 2: " << r[i].calf2 << endl;
				cout << "Calificacíon 3: " << r[i].calf3 << endl;
				cout << "Calle:" << r[i].ca << endl;
				cout << "número:" << r[i].co << endl;
				cout << "Colonia:" << r[i].nu << endl << endl;
				cout << "¿Deseas modificar algo más?:" << endl;
				cout << "1. Matrícula \n2. Nombre \n3. Apellidos\n4. Calificación 1\n5. Calificación 2\6. Calificación 3\n7. Número\n8. Mail\n9. Calle\n10. Número de calle\n11. Colonia\n0. Nada" << endl;
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
			cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidos<< endl;
			cout << "Numero de telefono: " << r[i].num << endl;
			cout << "Matrícula: " << r[i].matri << endl;
			cout << "Calificacíon 1: " << r[i].calf1 << endl;
			cout << "Calificacíon 2: " << r[i].calf2 << endl;
			cout << "Calificacíon 3: " << r[i].calf3 << endl;
			cout << "Calle:" << r[i].ca << endl;
			cout << "número:" << r[i].co << endl;
			cout << "Colonia:" << r[i].nu << endl;			
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
			cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidos<< endl;
			cout << "Numero de telefono: " << r[i].num << endl;
			cout << "Matrícula: " << r[i].matri << endl;
			cout << "Calificacíon 1: " << r[i].calf1 << endl;
			cout << "Calificacíon 2: " << r[i].calf2 << endl;
			cout << "Calificacíon 3: " << r[i].calf3 << endl;
			cout << "Mail: " << r[i].Mail << endl;
			cout << "Calle:" << r[i].ca << endl;
			cout << "número:" << r[i].co << endl;
			cout << "Colonia:" << r[i].nu << endl << endl;
			cout << "¿Eliminar a este usuario?"<< endl;
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

void salir() {
	ofstream archivo; 
	archivo.open("ejemplo.txt",ios::app); 
	for (int i = 0; i < c; i++) { 
		archivo << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidos<< endl;
		archivo << "Numero de telefono: " << r[i].num << endl;
		archivo << "Mail:" << r[i].Mail << endl;
		archivo << "Matrícula: " << to_string(r[i].matri) << endl;
		archivo << "Calificacíon 1: " << r[i].calf1 << endl;
		archivo << "Calificacíon 2: " << r[i].calf2 << endl;
		archivo << "Calificacíon 3: " << r[i].calf3 << endl;
		archivo << "Promedio:" <<(r[i].calf1*.30 + r[i].calf2*.45 + r[i].calf3*.25) / 3 << endl;
		archivo << "Calle:" << r[i].ca << endl;
		archivo << "número:" << r[i].co << endl;
		archivo << "Colonia:" << r[i].nu << endl << endl;
	}
	archivo.close();
	int si;
	cout<<"¿Desea borrar los registrados?\n1. si\n2. No" << endl;
	cin >> si;
	if (si==1) {
		remove("ejemplo.txt");
	}
	else {
		exit(1);
	}
}
