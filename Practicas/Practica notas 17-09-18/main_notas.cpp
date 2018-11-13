#include <iostream> //Libreria de entradas y salidas
#include <windows.h> //Libreria de funciones de windows
#include <stdlib.h> //Libreria de de estilos

using namespace std; //Simplificacion del codigo

//Desarrollo del codigo
int main(int argc, char** argv) {
	float notas [5]; //Variable notas, definir el tamaño
	float suma = 0; //Variable para la suma, igualar a cero
	float promedio; //Variable para el promedio
	
	
	for (int i = 0; i <= 4; i++) { //Iniciar en cero, hasta que sea menor o igual a cuatro
		do {
			cout << "Ingrese la nota " << i + 1 << endl; //Imprimir mensaje de instruccion
			cin >> notas[i]; //Agregar dato a variable de notas
		}
		while (notas[i] < 0 || notas[i] > 10); //Mientras el dato se enceuntre entre 0 y 10
			
		suma = suma + notas[i]; //Acumular la sumatoria de notas;
	}
	
	system("cls"); //Limpriar pantalla de la consola
	cout << "Las notas ingresadas son:" << endl; //Salida de datos en pantalla
	for (int i = 0; i <= 4; i++) { //Inicializar en cero, hasta que sea igual a cuatro
			cout << "N" << i + 1 << " = " << notas[i] << endl; //Imprimir datos hasta que se cumpla la condicion
	}
	cout << endl; //Espacio de linea
	
	promedio = suma / 5; //Realizar operacion de promedio
	cout << "El promedio es de: " << promedio << endl; //Imprimir El promedio en pantalla
	cout << endl; //Espacio de linea
	
	system("pause"); //Pausar pantalla de la consola
	return 0; //Retornar valores a cero
}
