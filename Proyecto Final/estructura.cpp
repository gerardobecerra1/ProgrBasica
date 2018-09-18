#include <iostream>
#include <string>
using namespace std;

int o; // opcion
string nom;
string apellidos;
string num;
int matri;
float calf;
void registrar();
void menu();
int contnum;
int cant;
char Mail[30];
int contarr, contpun;


void registrar() {
	system("cls");
	cout << "escribe tu(s) nombre(s): "<< endl;
	cin >> nom;
	cout << "escribe tu(s) apellido(s): "<< endl;
	cin >> apellidos;
	cout << "Ingrese su numero telefonico: " << endl;
	cin >> num;
	for (int i = 0;i<10;i++) {

		if (num[i] >= 48 && num[i] <= 57) {
			contnum++;
		}
		if (num[i] != NULL) {
			cant++;
		}
	}
	if (cant != 10) { cout << "No son los 10 numeros" << endl; }
	else if (contnum != 10) { cout << "No todos son numeros" << endl; }
	else { cout << "Todos son numeros y es un celular" << endl; }
	system("PAUSE>NULL");
	system("CLS");
	while (1) {
	contarr = 0;
		contpun = 0;
		cout << "Introdusca su correo electronico" << endl;                                                                                                   //Practica realizada por los becarios de LMAD  di no al ROBO
		cin >> Mail;
		for (int i = 0;Mail[i] != NULL;i++) {
			if (Mail[i] == '@') {
				contarr++;
			}
			if (contarr == 1 && Mail[i] == '.') {
				contpun++;
			}
		}
		if (contarr == 0) {
			cout << "No hay @ " << endl;
		}
		else if (contarr>1) {
			cout << "Hay mas de 1 @" << endl;
		}
		else if (contpun == 0) {
			cout << "falta el punto " << endl;
		}
		else if (contpun>1) {
			cout << "Hay mas de un punto" << endl;
		}
		else {
			cout << "Todo esta correcto" << endl;
			system("PAUSE>NULL");
			break;
		}


		system("PAUSE>NULL");
	}
	cout << "escribe tu matrícula: "<< endl;
	cin >> matri;
	cout << "escribe tu calificación: "<< endl;
	cin >> calf;

}
void menu() {
	system("cls");
	cout << "Menú: " << endl;
	cout << "¿Que quieres hacer?: " << endl << "1.-Registrate\n2.-Borrar alumno\n3.-Salir"<<endl;
	cin >> o;
	switch (o)
	{
	case 1:
		registrar();
		break;
	case 2:
		menu();
	case 3:
		menu();
		break;
	case 4:
		menu();
		break;
	default:
		break;
	}
}


int main(){
	locale::global(locale("spanish"));
	menu();
	cout << nom << " " << apellidos << "|" << num << "|" << matri << "|" << calf << "|" << Mail << endl;
	system("pause");
	return 0;
}