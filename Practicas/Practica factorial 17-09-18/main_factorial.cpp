#include <iostream> //Libreria de entradas i salidas
#include <windows.h> //Libreria del sistema

using namespace std; //Simplificacion del codigo

//Cuerpo del codigo, para utilizar borre las flecas de comentario
/*int main(int argc, char** argv) {
	int n; //Varaible para numero
	int f = 1; //Variable de calculo factorial, igualar a 1
	
	cout << "Introduce el numero a factorizar: "; //Pedir que se introduzca numero
	cin >> n; //Agregar dato a variable
	
	for (int i = 1; i <= n; i++) { //Completar hasta que sea igual que el numero introducido
		f = f * i; //Calculo del factor
	}
	
	//cout << "El resultado es: " << f << endl; //Motrar resultado
	
	system("pause"); //Pausar pantalla
	return 0; //Retornar valores a cero
}*/


//Otra forma
int main(int argc, char** argv) {
	int n; //Introducir variable para numeros
	
	cout << "El resultado es: " << factorial(n) << endl; //Motrar resultado en pantalla
	
	system("pause"); //Pausa de pantalla
	return 0; //Retornar valores a cero
}
