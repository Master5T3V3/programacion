#include <iostream> //Librerias de entradas y salidas
#include <stdlib.h> //Libreria de memoria dinamica
#include <time.h> //Libreria para usar tiempo

using namespace std; //Aimplificacion del codigo

int main(int argc, char** argv) {
	//Desactivar flecas para activar esta otra forma del codigo
	/*srand(time(NULL));
	
	cout << rand() % 100+1;*/
	
	
	//Para hacer una matriz con srand
	srand(time(NULL)); //Tiempo random
	
	int matriz [3][3]; //Matriz 1 con 4 espacios
	int matriz2 [3][3]; //Matriz 3 con 4 espacios
	
	for (int i = 0; i < 3; i++) { //Para manejar las filas
		for (int j = 0; j < 3; j++) { //Para manejar las columnas
			matriz [i][j] = rand () % 101; //Matriz tomara valores de i y j y los convierte a los de rand
		}
	}
	
	for (int i = 0; i < 3; i++) { //Maneja las filas
		for (int j = 0; j < 3; j++) { //Maneja las columnas
			cout << matriz [i][j] << "   "; //Imprimir matriz
		}
		cout << endl; //Espacio de linea
	}
	
	return 0; //Retornar valores a cero
}
