#include <iostream> //Libreria de entraas y salidas

using namespace std; //Simplificacion del codigo

//Desarrollo del factorial
int factorial (int n) {
	if (n < 0) //Si n es menor que 0
		return 0; //Retornar valores a cero
	
	else if (n > 1) //Si es mayor que 1
		return n * factorial (n - 1); //Retornar valores con el calculo del factorial
	
	return 1; //Retornar un valor diferente de cero
}

//Cuerpo del codigo
int main(int argc, char** argv) { 
	cout << factorial (3) << endl; //Imprimir en pantalla el factorial, con un 3
	cout << endl; //Salto de linea
	
	system ("pause"); //Pusar pantalla del sistema
	return 0; //Retornar valores a cero
}
