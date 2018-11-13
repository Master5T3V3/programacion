#include <iostream> //Libreria de entradas y salidas
#include <stdlib.h> //Libreria de memoria dinamica y control de procesos

using namespace std; //Simplificar codigo

//Para declarar, todo el tiempo se ejecutara en este orden
float sumar (float x, float y);
void pedirNumero (); //Variable de vacio para pedir numero

//Desarrollo del codigo
int main(int argc, char** argv) {
	pedirNumero (); //Ejecutar funcion
	system ("pause"); //Pausar consola
	return 0; //Reotrnar valores a cero
}

//Realizar operacion de suma
float sumar (float x, float y) { //Introducir variables para suma
	return x + y; //Retorno de valores
}

//Variable de vacio, realizacion de operaciones
void pedirNumero () {
	float x; //Variable de primer dato
	float y; //Variable de segundo dato
	float res; //Variable de resultado
	
	cout << "Ingrese un numero: "; //Pedir numero a ingresar
	cin >> x; //Agregar dato a variable
	cout << "Posicion " << &x << endl; //Obtener posicion en memoria
	cout << "Ingrese otro numero: "; //Pedir que ingrese segundo dato
	cin >> y; //Ingresar dato a variable
	cout << "Posicion " << &y << endl; //Obtener posicion
	res = sumar (x, y); //Reallizar suma
	
	cout << "El resultado es: " << res << endl; //Mostrar resultado
}
