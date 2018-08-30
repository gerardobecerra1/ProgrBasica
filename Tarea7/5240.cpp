#include <iostream>
#include <time.h>
#include <stdlib.h>﻿
using namespace std;
int alea;
int sino;
int arma;
void juego();
void reglas();

void main() {
	locale::global(locale("spanish"));
	system("cls");
	reglas();
	system("pause");
}

void reglas() {
	system("cls");
	cout << "Jugemos !Piedra, Papel o Tijera¡" << endl;
	cout << "El objetivo es vencer al oponente seleccionando el arma que gana, según las siguientes reglas:\n"<<endl
		<< "1.-La piedra apalasta la tijera\n" << "2.-La tijera corta el papel\n" << "3.-El papel envuelve la piedra\n" <<
		"4.-En caso de empate se juega otra vez.\n" <<endl << "¿Entendiste las reglas?\n" <<endl<<
		"Escribe:\n1.para decir si\n" << "2.para decir no" << endl;
	cin >> sino;
	if (sino == 1) {
		juego();
	}
	else {
		reglas();
	}
}
void juego() {
	system("cls");

	cout << "Elije una arma introducinedo el numero en el cual esta situada el arma:"<<endl<<"0.-Piedra\n"<<"1.-Papael\n"
		<<"2.-Tijera"<<endl;
	cin >> arma;

	if (arma ==0) {//piedra
		srand(time(NULL));
		alea = rand() % 3;
		if (alea = 0) {
			cout <<"Compu elije Piedra.\n"<<"!Empate¡,¿Jugamos otravez?" << endl << "1.-si\n2.-no" << endl;
			cin >> sino;
			if (sino == 1) {
				juego();
			}

		}
		else if (alea == 1) {
			cout<<"Compu elije Papel.\n" << "!Perdiste¡,¿Jugamos otravez?" << endl << "1.-si\n2.-no" << endl;
			cin >> sino;
			if (sino == 1) {
				juego();
			}
		}
		else {
			cout <<"Compu elije Tijera.\n" << "!Ganaste¡,¿Jugamos otravez?" << endl << "1.-si\n2.-no" << endl;
			cin >> sino;
			if (sino == 1) {
				juego();
			}
		}


	}
	else if (arma == 1) {//papel
		srand(time(NULL));
		alea = rand() % 3;
		if (alea = 1) {
			cout <<"Compu elije Papael.\n" << "!Empate¡,¿Jugamos otravez?" << endl << "1.-si\n2.-no" << endl;
			cin >> sino;
			if (sino == 1) {
				juego();
			}

		}
		else if (alea == 2) {
			cout <<"Compu elije Tijera.\n" << "!Perdiste¡,¿Jugamos otravez?" << endl << "1.-si\n2.-no" << endl;
			cin >> sino;
			if (sino == 1) {
				juego();
			}
		}
		else {
			cout <<"Compu elije Piedra.\n" << "!Ganaste¡,¿Jugamos otravez?" << endl << "1.-si\n2.-no" << endl;
			cin >> sino;
			if (sino == 1) {
				juego();
			}
		}
	}else {//tijera
		srand(time(NULL));
		alea = rand() %3;
		if (alea = 2) {
			cout << "Compu elije Tijera.\n" << "!Empate¡,¿Jugamos otravez?" << endl << "1.-si\n2.-no" << endl;
			cin >> sino;
			if (sino == 1) {
				juego();
			}

		}
		else if (alea == 0) {
			cout << "Compu elije Piedra.\n" << "!Perdiste¡,¿Jugamos otravez?" << endl << "1.-si\n2.-no" << endl;
			cin >> sino;
			if (sino == 1) {
				juego();
			}
		}
		else {
			cout <<"Compu elije Papel.\n" << "!Ganaste¡,¿Jugamos otravez?" << endl << "1.-si\n2.-no" << endl;
			cin >> sino;
			if (sino == 1) {
				juego();
			}
		}


	}
	
	
}



