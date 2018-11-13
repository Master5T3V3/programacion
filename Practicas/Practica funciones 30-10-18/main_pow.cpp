/*#include <iostream> //Libreria de entradas y salidas
#include <stdlib.h> //Libreria de memoria dinamica y control de proceso
#include <math.h> //Libreria de funciones matematicas

using namespace std; //Simplificacion de codigo

float pow_(float base, float exp); //Prototipo de funcion para exponenciales

//Desarrollo del codigo
int main () {
	cout << pow_(2, 3) << endl; //Ejecutar funcion de exponenciales
	
	system("pause"); //Pusar pantalla del sistema
	return 0; //Retornar valores a cero
}

float pow_(float base, float exp) { //Procesos de la funcion de exponenciales
	float result = base; //Variable de resultado, igualar a la base
	
	if (exp == 0) { //Si el exponencial es cero
		return 0; //Retornar valor, seria la misma base
	}
	
	for (int i = 1; i < exp; i++) { //Ciclo para realizar potenciacion
		result = result * base; //Realizar operacion por la cantidad de veces del exponencial
	}
	
	return result; //Retornar valor de la variable resultado
}*/
