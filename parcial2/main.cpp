//Este programa fue desarrollado por: Brian Steve Rodas Hernandez
//Carnet: RH18031

//Desarrollar un programa que muestre un menu con las siguientes opciones:
//-Mostrar algoritmo para ordenar la torre de hanoi
//-Generar y mostrar 100 numeros aleatorios y ordenar por metodo de burbuja

#include <stdio.h> //Libreria de manejo de memoria dinamica
#include <iostream> //Libreria de entradas y salidas
#include <windows.h> //Libreria de funciones del sistema
#include <time.h> //Libreria de funciones de semilla y tiempo

using namespace std; //Simplificacion del codigo

//Prototipo para funcion de menu de opciones
void menu();
//Prototipo para funcion de algoritmo de torre de hanoi
void movimiento(int disco, int torre1, int torre2, int torre3);
//Prototipo para funcion de generacion de cien numeros y su ordenamiento
void random(int i, int j, int aux, int numeros[100]);

//Desarrollo del codigo
int main(int argc, char *argv[]){
    int opc; //Variable de opciones de menu
    int torre1 = 1; //Variable de torre1 con su identificador '1'
    int torre2 = 2; //Variable de torre2 con su identificador '2'
    int torre3 = 3; //Variable de torre3 con su identificador '3'
    int disco = 0; //Variable para detectar discos
    int i; //Variable para manejo de ciclos
    int j; //Variable para manejo de ciclos
    int aux; //Variable auxiliar
    int numeros[100]; //Variable de numeros, con un arreglo de 100
    
    //Ejecutar funcion para menu de opciones
    menu();
    //Validacion de entradas de opciones
    while((cin >> opc).fail() || opc < 1 || opc > 3) {
        cin.clear(); //reseteamos los flags
		fflush(stdin); //limpio buffer de entrada
		system("color 04"); //Cambiar color a fondo negro con letras rojas
		cout << "\t\t\t\t\tOpcion no valida, ingrese nuevo valor: "; //Pedir dato
	}
    
    system("cls"); //Limpiar pantalla de consola
    
    switch(opc){ //Declarar casos con el switch
        case 1: //Caso uno para la torre de hanoi
            cout << endl << endl; //Espacios de linea
            //Pedir al usuario un numero
            cout << "\t\t\t\t\tCon cuantos discos jugara al hanoi?: ";
            cin >> disco; //Agregar dato a variable de discos
            //Ejecutar funcion de algoritmo de torre de hanoi
            movimiento(disco, torre1, torre2, torre3);
            //Imprimir mensaje de finalizacion
            cout << endl << endl << endl << "\t\t\t\t ------------------------";
            cout << "----------------------- " << endl;
            cout << "\t\t\t\t|\t !!!Ha completado la torre!!! \t\t|" << endl;
            cout << "\t\t\t\t ------------------------";
            cout << "----------------------- " << endl;
            break; //Terminar caso
            
        case 2: //Caso dos para generar numeros aleatorios
            //Ejecutar funcion de generacion de cien numeros y su ordenamiento
            random(i, j, aux, numeros);
            //Imprimir mensaje de finalizacion
            cout << endl << "\t\t\t\t ------------------------";
            cout << "----------------------- " << endl;
            cout << "\t\t\t\t|\t !!!Generacion completada !!! \t\t|" << endl;
            cout << "\t\t\t\t ------------------------";
            cout << "----------------------- " << endl;
            break; //Terminar caso
            
        case 3: //Caso 3 para salir del programa
            break; //Terminar caso
    }
    
    system("pause"); //Pausar pantalla del sistema
    return 0;
}

void menu() { //Funcion para menu de opciones
	system("cls"); //Limpiar pantalla de consola
	system("color F0"); //Cambiar colores, fondo azul, texto blanco
    cout << endl << endl << endl << endl << endl; //Espacios de linea
    //Imprimir menu de opciones en pantalla
	cout << "\t\t\t\t ------------------------------------------------- " << endl;
    cout << "\t\t\t\t|              << MENU DE OPCIONES >>             |" << endl;
    cout << "\t\t\t\t|-------------------------------------------------|" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t|       1. Algoritmo de torre de hanoi            |" << endl;
    cout << "\t\t\t\t|       2. Generar y ordenar numeros              |" << endl;
    cout << "\t\t\t\t|       3. Salir                                  |" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t -------------------------------------------------\n\n";
    cout << "\t\t\t\t\t\tDigite la opcion: "; //Mensaje para pedir ingreso de opcion
}

//Funcion de algoritmo de torre de hanoi
void movimiento(int disco, int torre1, int torre2, int torre3){
    cout << endl << endl; //Espacios de linea
    if(disco == 1) {//Si solo existe un disco
        //Imprimir algoritmo para solo un disco
        cout << "\t\t\t\t ------------------------";
        cout << "----------------------- " << endl;
        cout << "\t\t\t\t| Mueva el disco de la torre " << torre1 << " hacia la torre " << torre3;
        cout << " |" << endl;
        cout << "\t\t\t\t ------------------------";
        cout << "----------------------- " << endl;
        system("pause"); //Pausar pantalla de consola
        cout << endl << endl; //Espacios de linea
    }
    else{ //Si no solo existe un disco
        movimiento(disco - 1, torre1, torre3, torre2); //Disminuir el valor del disco en uno
        cout << "\t\t\t\t ------------------------";
        cout << "----------------------- " << endl;
        cout << "\t\t\t\t| Mueva el disco de la torre " << torre1 << " hacia la torre " << torre3;
        cout << " |" << endl;
        cout << "\t\t\t\t ------------------------";
        cout << "----------------------- " << endl;
        system("pause"); //Pausar pantalla de consola
        movimiento(disco - 1, torre2, torre1, torre3); //Disminuir el valor del disco en uno
        cout << endl << endl; //Espacios de linea
    }
}

//Funcion para generar numeros y ordear por metodo de la burbuja
void random(int i, int j, int aux, int numeros[100]){
    system("cls"); //Limpiar pantalla de consola
    srand(time(NULL)); //Generar semilla aleatoria
    for(i = 0; i < 100; i++){ //Ciclo para generar cien numeros
        numeros[i] = rand(); //Generar un numero aleatorio
    }
    for(i = 0; i < 100; i++){ //Ciclo para los numeros
        for(j = 0; j < 100; j++){ //Ciclo para reconocer los arreglos
            //Si el numero que esta antes es mayor
            if(numeros[j] > numeros[j+1]){
                aux = numeros[j]; //Agregar dato al auxiliar
                numeros[j] = numeros[j+1]; //Aumantar al arreglo en uno
                numeros[j+1] = aux; //Agregar el valor del auxiliar
            }
        }
    }
    
    for(i = 0; i < 100; i++){ //Ciclo para imprimir los numeros
        //Mostrar al usuario el resultado
        cout << endl << "\t\t\t\t\t\t|\t" << numeros[i] << "\t |" << endl;
    }
}
