#include <iostream> //Libreria de entras y salidas

using namespace std; //Simplificar codigo

void llenarMat (); //Variable de vacio para calcular
void imprimirMat (); //Variable de vacio para imprimir resultados

//Primera forma de solucion
//Desarrollo del codigo
int main(int argc, char** argv) {
	int mat [5][5]; //Variable de matriz 1
	int mat2 [5][5]; //Varaible de matriz 2
	int mat3 [5][5]; //Variable de matriz 3
	
	for (int fila = 0; fila < 5; fila++) { //Mientras sea menor a 5
		for (int col = 0; col < 5; col++) { //Mientras sea menor a 5
			mat [fila][col] = 0; //Valores se van a igualr a cero
			
			//Resolucion para generar los numeros en los espacios necesarios
			if (fila == col || fila % 2 == 0 and col % 2 == 0 || fila % 2 == 1 and col % 2 == 1) {
				mat2 [fila][col] = 0; //Valores a 0
			}
			else {
				mat2 [fila][col] = 1; //Valores a 1
			}
			
			mat3 [fila][col] = mat [fila][col] + mat2 [fila][col]; //Para obtener la matriz con todas sus condiciones
		}
	}
	for (int fila = 0; fila < 5; fila++) { //Mientras sea menor a 5
		for (int col = 0; col < 5; col++) { //Mientras sea menor a 5
			cout << mat3 [fila][col] << "\t"; //Imprimir matriz en pantalla
		}
		cout << endl; //Salto de linea
	}
	cout << endl; //Salto de linea
	
	system ("pause"); //Pausar pantalla
	return 0; //Retornar valores a cero
}


//Otra forma de resolverlo por menio de las variables de vacio
/*int main (int argc, char** argv) {
	int mat [5][5];
	int mat2 [5][5];
	int mat3 [5][5];
	
	llenarMat ();
	imprimirMat ();
	
	system ("pause");
	return 0;
}*/

//Variable de vacio para realizar operaciones
void llenarMat () {
	int mat [5][5]; //Variable 1 de de matriz
	int mat2 [5][5]; //Variable 2 de matriz
	int mat3 [5][5]; //Variable 3 de matriz
	
	for (int fila = 0; fila < 5; fila++) { //Las filas tienen que ser menores a 5
		for (int col = 0; col < 5; col++) { //Columnas menores a 5
			mat [fila][col] = 0; //Capturar valores en mat con respecto a variables de fila / columna e igualr a 0
			
			//Crear condiciones para intercalar numeros
			if (fila == col || fila % 2 == 0 and col % 2 == 0 || fila % 2 == 1 and col % 2 == 1) { //
				mat2 [fila][col] = 0; //Igualar a cero
			}
			else {
				mat2 [fila][col] = 1; //Igualar a uno
			}
			
			mat3 [fila][col] = mat [fila][col] + mat2 [fila][col]; //mat3 va a ser igual a mat + mat2 para obtener valores
		}
	}
}

//Variable de vacio para imprimir 
void imprimirMat () {
	int mat3 [5][5]; //Introducir variable para matriaz
	
	for (int fila = 0; fila < 5; fila++) { //Contar mientras sea menor a 5
		for (int col = 0; col < 5; col++) { //Contar mientras sea menor a 5
			cout << mat3 [fila][col] << "\t"; //Imprimir resultado en pantalla
		}
		cout << endl; //Salto de linea
	}
	cout << endl; //Salto de linea
}
