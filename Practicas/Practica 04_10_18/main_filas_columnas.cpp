#include <iostream> //Libreria para funciones de entrada y salida
#include <windows.h> //Utilizar libreria de windows para funciones de sistema

using namespace std; //Simplificaci[on de codigo

//Desarrollo del codigo
int main(int argc, char** argv) {
	int x [3][3]; //Variable x y definir tamaño 3 y 3
	
	for (int i = 0; i <= 2; i++) { //Ciclo for para las filas
		for (int j = 2; j >= 0; j--) { //Ciclo for para las columnas
			cout << x [i][j] << "----"; //Igresar numeros segun los ciclos
		}
		cout << "\n"; //Imprimir salto de linea
		cout << endl; //Inprimir espacio de linea
	}
	
	//Otra ejemplo para filas y columnas, quitr flecas para habilitar su uso
	/*for (int i = 0; i <= 3; i++) { //Ciclo for que controla las filas
		x [i][i] = 0; //En los espacio 0 y 1 asignar el valor de cero
		
		if (i = 3) { //Si i es igual a tres
			x [0][0]; //Agregar a coordenadas 0 y 0
			x [3][3]; //Agregar a coordenadas 3 y 3
		}
	}
	//Imprimir datos en x
	cout << x [i][i];*/
	
	system ("pause"); //Pausar pantalla del sistema
	return 0; //Retornar valores a cero
}
