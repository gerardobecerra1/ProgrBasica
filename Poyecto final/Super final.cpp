#include <iostream> 
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
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
	int carro=0, cpun=0,nel=0;
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
void manu();

int main() {
	//locale::global(locale("spanish"));
	ifstream archivo;
	string v;

	archivo.open("Lista alumnos registrados.txt", ios::in);
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
	cout << "1. Registrar \n2. Ver registrados \n3. Buscar matrícula \n4. Buscar nombre\n5. Eliminar\n6. Manual de usuario\n7. Salír" << endl;
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
		manu();
		break;
	case 7:
		salir();
		break;
	default:
		cout << "inválido";
		system("pause>nul");
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
		else if (r[c].Mail[0] == '@' && r[c].Mail[1] == '.') {
			cout << "Faltan letras";
		}
		else if (r[c].nel == 1) {
			cout << ",escribe de nuevo";
		}
		else {
			cout << "Todo esta correcto" << endl;
			system("pause>nul");
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
	while (1) {
		system("cls");
		cout << "Calificación 1:";
		cin >> r[c].calf1;
		cout << "Calificación 2:";
		cin >> r[c].calf2;
		cout << "Calificación 3:";
		cin >> r[c].calf3;
		if (r[c].calf1 > 0.0 && r[c].calf1 < 101.0 && r[c].calf2>0.0 && r[c].calf2<101.0 && r[c].calf3>0.0 && r[c].calf3<101.0) {
				break;
		}
		else {
			cout << "La calificación no puede ser menor a 0 ni mayor a 100.";
		}
		system("pause>nul");
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
		cout << "Mail:" << r[i].Mail << endl;
		cout << "Calle:" << r[i].ca << endl;
		cout << "número:" << r[i].co << endl;
		cout << "Colonia:" << r[i].nu << endl;
		cout.precision(5);
		cout << "Calificacíon 1: " << setprecision(4) << r[i].calf1 << endl;
		cout << "Calificacíon 2: " << setprecision(4) << r[i].calf2 << endl;
		cout << "Calificacíon 3: " << setprecision(4) << r[i].calf3 << endl;
		cout << "Promedio:" << setprecision(4) << ((r[i].calf1 * 30) / 100 + (r[i].calf2 * 45) / 100 + (r[i].calf3 * 25) / 100) << endl << endl;
	}
	ifstream archivo;
	string v;
	archivo.open("Lista alumnos registrados.txt", ios::in);
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
				cout << "¿Quieres una matrícula al aleatoria? elige 1, sino elige 2 y escribela:" << endl;
				cin >> o;
				if (o == 1) {
					srand(time(NULL));
					r[i].matri = 1800000 + rand() % (1900000 - 1800000);
					cout << r[i].matri;
					system("pause>nul");
				}
				else {
					cin >> r[i].matri;
				}
				break;
			case 2:
				cout << "Ingresa nuevo nombre: ";
				cin.ignore();
				while (1) {
					system("cls");
					cout << "Ingresa nuevo nombre: ";
					getline(cin, r[i].nombre);
					int t = 0;
					int l = 0;
					int a = 0;
					l = r[i].nombre.size();
					if (l == NULL) {
						cout << "escribíste un caracter inválido" << endl;system("PAUSE>NULL");
					}
					else {
						for (int z = 0;z < l;z++) {
							if (r[i].nombre[z] >= 65 && r[i].nombre[z] <= 122 || r[i].nombre[z] == 32 || r[i].nombre[z] >= 160 && r[i].nombre[z] <= 165) {
								t++;
							}
							else { a++; }
						}
						if (a == 0) { break; }
						else { cout << "escribíste un caracter inválido" << endl;system("PAUSE>NULL"); }
					}
				}
				break;
			case 3:
				cout << "Ingresa nuevo apellido: ";
				cin.ignore();
				while (1) {
					system("cls");
					cout << "Ingresa nuevo apellido: ";
					getline(cin, r[i].apellidos);
					int t = 0;
					int l = 0;
					int a = 0;
					l = r[i].apellidos.size();
					if (l == NULL) {
						cout << "escribíste un caracter inválido" << endl;system("PAUSE>NULL");
					}
					else {
						for (int z = 0;z < l;z++) {
							if (r[i].apellidos[z] >= 65 && r[i].apellidos[z] <= 122 || r[i].apellidos[z] == 32 || r[i].apellidos[z] >= 160 && r[i].apellidos[z] <= 165) {
								t++;
							}
							else { a++; }
						}
						if (a == 0) { break; }
						else { cout << "escribíste un caracter inválido" << endl;system("PAUSE>NULL"); }
					}
				}
				break;
			case 4:
				while (1) {
					system("cls");
					cout << "Ingresa nueva calificaión 1: ";
					cin >> r[i].calf1;
					if (r[i].calf1 > 0.0 && r[i].calf1 < 101.0) {
						break;
					}
					else {
						cout << "La calificación no puede ser menor a 0 ni mayor a 100.";
					}
					system("pause>nul");
				}
				break;
			case 5:
				while (1) {
					system("cls");
					cout << "Ingresa nueva calificaión 2: ";
					cin >> r[i].calf2;
					if (r[i].calf2 > 0.0 && r[i].calf2 < 101.0) {
						break;
					}
					else {
						cout << "La calificación no puede ser menor a 0 ni mayor a 100.";
					}
					system("pause>nul");
				}
				break;
			case 6:
				while (1) {
					system("cls");
					cout << "Ingresa nueva calificaión 3: ";
					cin >> r[i].calf3;
					if (r[i].calf3 > 0.0 && r[i].calf3 < 101.0) {
						break;
					}
					else {
						cout << "La calificación no puede ser menor a 0 ni mayor a 100.";
					}
					system("pause>nul");
				}
				break;
			case 7:
				cin.ignore();
				while (1) {
					system("cls");
					cout << "Ingresa nuevo numerocon 10 dígitos: ";
					cin >> r[i].num;
					int t = 0;
					int l = 0;
					int letra = 0;
					l = strlen(r[i].num);
					for (int z = 0;z < l;z++) {
						if (r[i].num[z] >= 48 && r[i].num[z] <= 58) {
							t++;
						}
						else { letra++; }
					}
					if (t == 10 && letra == 0) { cout << "Todos son numeros y es un celular" << endl; system("PAUSE>NULL"); break; }
					else { cout << "No son los 10 dígitos o escribíste un caracter inválido" << endl;system("PAUSE>NULL"); }
				}
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
	if (o == 32) {
		menú();
	}
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
	archivo.open("Lista alumnos registrados.txt",ios::app); 
	for (int i = 0; i < c; i++) { 
		archivo << "Nombre y apellido: " << r[i].nombre << " " << r[i].apellidos<< endl;
		archivo << "Numero de telefono: " << r[i].num << endl;
		archivo << "Mail:" << r[i].Mail << endl;
		archivo << "Matrícula: " << to_string(r[i].matri) << endl;
		archivo << "Calle:" << r[i].ca << endl;
		archivo << "número:" << r[i].co << endl;
		archivo << "Colonia:" << r[i].nu << endl;
		archivo.precision(5);
		archivo << "Calificacíon 1: " << setprecision(4) << r[i].calf1 << endl;
		archivo << "Calificacíon 2: " << setprecision(4) << r[i].calf2 << endl;
		archivo << "Calificacíon 3: " << setprecision(4) << r[i].calf3 << endl;
		archivo << "Promedio:" << setprecision(4) << ((r[i].calf1 * 30) / 100 + (r[i].calf2 * 45) / 100 + (r[i].calf3 * 25) / 100) << endl << endl;
	}
	archivo.close();
	int si;
	cout<<"¿Desea borrar los registrados?\n1. si\n2. No" << endl;
	cin >> si;
	if (si==1) {
		remove("Lista alumnos registrados.txt");
	}
	else {
		exit(1);
	}
}
void manu() {
	system("cls");
	cout << "UNIVERSIDAD AUTÓNOMA DE NUEVO LEÓN."
		<< "\nFACULTAD DE CIENCIAS FISICO - MATEMÁTICAS."
		<< "\nMANUAL DE USUARIO."
		<< "\nHecho por : Luis Gerardo Becerra Jiménez."
		<< "\nIntroducción :"
		<< "\nEste es un programa que registra alumnos con los siguientes datos :"
		<< "\n* Nombre."
		<< "\n* Apellidos."
		<< "\n* Correo electrónico."
		<< "\n* Teléfono."
		<< "\n* Matrícula."
		<< "\n* Dirección."
		<< "\n* Calle."
		<< "\n* Número."
		<< "\n* Colonia."<<endl
		<< "\nEl objetivo es demostrar que al registrar cualquier dato el programa regrese el error que el usuario a cometido y le muestre que es lo que falta o puede hacer para hacer un registro correcto." << endl << endl
		<< "#Índice:" << endl

		<< "Menú de opciones y sus funciones."
		<< "\n Solución de errores."<<endl<<endl
		<< "\n##1. Menú de opciones y sus funciones. Menú­­:"
		<< "\nAquí podrás encontrar las siguientes opciones :" << endl

		<< "Registrar: en este aparatado podrás introducir los siguientes datos :" << endl

		<< "* Nombre."
		<< "\n* Apellidos."
		<< "\n* Correo electrónico."
		<< "\n* Teléfono."
		<< "\n* Matrícula."
		<< "\n* Dirección."
		<< "\n* Calle."
		<< "\n* Número."
		<< "\n* Colonia."<<endl
		<< "\nVer registrados : en este apartado podrás visualizar todos los usuarios registrados anterior mente." << endl

		<< "Buscar Matrícula : en este apartado se introduce la matricula del usuario a buscar, en ella también se puede modificar el usuario." << endl

		<< "Buscar nombre : en este apartado se introduce el nombre del usuario que deseas buscar, aquí también se puede modificar al usuario." << endl
		<< "Eliminar : en este apartado introducirás la matrícula del usuario que deseas eliminar." << endl

		<< "Salir : aquí solo saldrás del programa y te dará la opción de eliminar a todos los registrados." << endl

		<< "#2. Solución de errores." << endl

		<< "Error de correo electrónico : Debes introducir solo un '@' y tu correo siempre debe terminar en '.com' de lo contrario el programa nunca te dejara avanzar." << endl

		<< "Error de teléfono : Él número de teléfono no debe pasar de los 10 dígitos de lo contrario marcara error.No debes de escribir ninguna letra ya que en esta parte solo aceptara números." << endl

		<< "Error de matrícula : Solo debes ingresar números ya que si ingresas algo que no sea un numero no te dejará avanzar."<< endl <<"\n Presiona ENTER para volver";
	system("pause > nul");
	menú();
 }