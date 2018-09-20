
#include <iostream>
#include <string>
using namespace std;

int o;
int c;

struct registrados {
	int id;
	string nombre;
	char apellido[100];
	string num;
	int matri;
	float calf;
	int countNum;
	int cant;

};

registrados r[100];
void menú();
void registrar();
void losreg();
void buscar();
void buscnombre();

int main() {
	locale::global(locale("spanish"));
	c = 0;
	menú();
}

void menú() {
	system("cls");
	cout << "Menú" << endl << endl;
	cout << "Elige que quieres hacer:" << endl;
	cout << "1. Registrar \n2. Ver registrados \n3. Buscar \n4. Buscar nombre" << endl;
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
		buscar();
		break;
	case 4:
		buscnombre();
		break;
	default:
		break;
	}
}

void registrar() {
	system("cls");
	cout << "Registro" << endl << endl;
	r[c].id = c;
	cout << "Apellido: ";
	cin >> r[c].apellido;
	cin.ignore();
	cout << "Nombre: ";
	getline(cin, r[c].nombre);
	cout << "Numero de telefono: ";
	cin >> r[c].num;
	cout << "Matrícula: ";
	cin >> r[c].matri;
	c++;
	menú();
}

void losreg() {
	system("cls");
	cout << "Registrados: " << endl;
	for (int i = 0; i < c; i++) {
		cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellido << endl;
		cout << "Numero de telefono: " << r[i].num << endl;
		cout << "Matrícula: " << r[i].matri << endl;
		cout << "Calificacíon: " << r[i].calf << endl << endl;
	}
	system("pause > nul");
	menú();
}

void buscar() {
	system("cls");
	cout << "Buscador" << endl << endl;
	cout << "¿Qué id quiere ver? " << endl;
	cin >> o;
	bool busc = false;
	for (int i = 0; i < c; i++)
	{
		if (r[i].id == o) {
			cout << "Lo encontré:" << endl;
			cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellido << endl;
			cout << "Numero de telefono: " << r[i].num << endl;
			cout << "Matrícula: " << r[i].matri << endl;
			cout << "Calificacíon: " << r[i].calf << endl;
			busc = true;
			break;
		}
	}
	if (!busc) {
		cout << "No había registros con ese id." << endl;
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
			cout << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellido << endl;
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