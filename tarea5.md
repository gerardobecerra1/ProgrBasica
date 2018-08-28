# Tarea 5A

Preguntas:

1.-Error en salida, sin el using namespace std no corre el programa

2.-Ningun error, salida: Hola Mundo.

3.-Sin salida y error, ocupa mas espacio.

4.-Error en salida, tiene caractéres de más.

5.-Ningun error, salida: a = 8 b = 24

6.-Ningun error, salida: 15

7.-Ningun error, salida: a = 6 b = 6

8.-Ningun error, salida: 1

9.-Ningun error, salida: 0

10.-Ningun error, salida: mo

## Hacer un programa que imprima alguna salida en la consola que dependa de:
 + *operaciones aritméticas.*
- *operaciones lógicas.*
* *índices en arreglos de caracteres.*

---
     #include iostream
    using namespace std;
    void main(){
    int>>ks;
    cout<<"¿Que eres, escribe 1 si eres hombre o 2 si eres mujer."<<endl;
     cin>>ks;
     if(ks == 1){
     char h[50];
     cout<<¿Como te llamas?"<<endl;
     cin>>h;
     cout<<"Me llamo"<< h<<" y soy bien nena"<<endl;
     }
      else{
      char m[50]
      cout<<¿Como te llamas?"<<endl;
      cin>>m;
      cout<<"Me llamo"<< m<<" y soy bien macho"<<endl;
      }
      system("pause");
    }
  ---
