#include <iostream> //Libreria e entradas y salidas
#include <windows.h> //Librerias de opciones de windows

using namespace std; //Simplicficacion del codigo

//Desarrollo del codigo
int main(int argc, char** argv) {
	int n[10]; //Variable pra numeros, con espacio 10
	int m; //Variable para realizar multiplicacion
	int acum; //Variable de acumulador
	
	cout << "Tabla del 10" << endl; //Imprimir titulo
	for (int i = 1; i <= 10; i++) { //Hatsa que sea 10
		cout << i << " x 10 = "; //Imprimir datos amultiplicar
		m = 10 * i; //Realizar operacion
		cout << m << endl; //Presnetar realusado
		acum = acum + n[i]; //Acumular numeros
		}
	cout << endl; //Espacio de linea
	
	
	//Otra forma, generar tablas del 1 al 10
	/*for (int x = 1; x <= 10; x++) { //Hsta que se a 10
		cout << "TABLA DEL " << x << endl; //Mostrar tipo de tabla
		
		for (int i = 1; i <= 10; i++) { Hasta que sea 10
			cout << i << " x 10 = "; //Mostrar datos a imprimir
			m = x * i; //Realizar operacion
			cout << m << endl; //Mostrar resultado
			acum = acum + n[i]; //Acumular datos
		}
	cout << endl; //Espacio de linea
	}*/
	
	cout << endl; //Espacio de linea
	
	system("pause"); //Pausar pantalla de consola
	return 0; //Retornar valores a cero
}
