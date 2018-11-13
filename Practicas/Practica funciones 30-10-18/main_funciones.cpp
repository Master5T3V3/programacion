#include <iostream> //Libreria de entradas y salidas

using namespace std; //Simplificacion del codigo

float suma(float a, float b); //Protitipo para funcion e suma

//Desarrollo del codigo
int main(int argc, char** argv) {
	float resultado = suma(2.5, 5.4); //Variable de resultado, asignar valores en a y b
	
	//std:: para declarar las salidas, en vez del using namespace, pero es mas complicado
	cout << resultado << endl; //Imprimir resultado de forma 1
	
	//imprimir resultado de forma 2
	cout << suma(7.5, 4.9) << endl; //Imprime resultado 1
	cout << suma(4.6, 6.7) << endl; //Imprime resultado 2
	
	system("pause"); //Pausar pantalla de consola
	return 0; //Retornar valores a cero
}

float suma(float a, float b) { //Procesos a realizar en funcion de suma
	return a+b; //Returnar la suma de a y b
}
