#include <iostream> //Libreria de entradas y salidas

using namespace std; //Simplificacion del codigo

//Desarrollo del codigo 
int main(int argc, char** argv) {
	int a [5][2] {{0,9}, //Introducir variable y agregar datos
				  {1,2},
				  {2,4}};
	
	for (int i = 0; i <= 5; i++) { //Para agregar datos a i
		for (int j = 0; i <= 2; j++) { //Para agregar datos a j
			cout << "a[" << i << "][" << j << "]"; //Salida de arreglo con corchetes
			cout << a [i][j] << endl; //Salida de arreglo sin corchetes
		}
	}
	
	return 0; //Retornar valores a cero
}
