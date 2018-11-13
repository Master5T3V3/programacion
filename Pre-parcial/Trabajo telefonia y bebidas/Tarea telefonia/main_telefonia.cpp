//Programa creado por: Brian Steve Rodas Hernandez
//Ultima fecha de modificacion: 23/09/2018

#include <iostream> //Libreria de entradas y salidas
#include <windows.h> //Libreria de funciones de windows en consola
#include <iomanip> //Libreria para utilizar setprecision

using namespace std; //Simplificar el codigo

void titulo (); //Declaracion de funcion 1, no retorna, no recibe parametros

bool validn (string entrada) { //Validar entrada de numeros
	bool valid = true; ////Variable de validacion
	int tam = entrada.size (); //Variable para definir tamaño
	
	for (int i = 0; i < tam; i++) { //Reconocer caracteres numericos
		if (entrada [i] <= 47 || entrada [i] >= 57) { //Toma los digitos numericos
			valid = false; //Cambiar valor a falso del booleano
			break; //Terminar proceso
		}
	}
	return valid; //Retornar la variable
}

//Desarrollo del codigo
int main(int argc, char** argv) {
	string min; //Cadena para variable de minutos
	float tar; //Variable de tarifa
	int n; //Variable para condiciones
	char soundf[] = "C:\\Windows\\media\\chord.wav"; //Varaiable para audio en caso de repetir ciclo
	char soundt[] = "C:\\Windows\\media\\windows unlock.wav"; //Variable para audio en caso de obtener resultado
	
	system ("color F0"); //Cambiar color fondo/texto
	
	error: //Punto de reinicio en caso de error
	do { //Repeticion de ciclo en caso de no ser un valor admitido
		titulo (); //Ejecutar funcion 1
		cout << "Ingrese tiempo de llamada (minutos): "; //Imprime mensaje en pantalla
		cin >> min; //Introducir dato
		system ("color 4F"); //Cambiar fondo/texto
		cout << PlaySound((LPCSTR)soundf, NULL, SND_FILENAME | SND_ASYNC ); //Reproduccion de audio
	}
	while (! validn (min)); //Mientras no se ingrese un valor numerico
	
	n = atoi(min.c_str()); //Obtener dato del string y agregarlo a variable n
	
	while (n <= 0) { //En caso que el valor sea igual o menor a cero
		goto error; //Volver al punto de condicion do while
	}
	
	titulo (); //Ejecutar de funcion 1
	
	if (n <= 10) { //Mientras este entre 1 a 10 min
		tar = n * 0.05; //Agregar el dato a la variavle tarifa
	}
	else if (n <= 15) { //Mientras este entre 11 a 15 min
		tar = n * 0.08; //Agregar el dato a la variavle tarifa
	}
	else if (n > 15) { //Mientras sea mayor a 15 min
		tar = n * 0.10; //Agregar el dato a la variavle tarifa
	}
	
	system ("color F0"); //Cambiar color fondo/texto
	cout<< PlaySound ((LPCSTR)soundt, NULL, SND_FILENAME | SND_ASYNC ); //Reproduccion de audio
	titulo (); //Limpiar pantalla
	cout << "Coste de la llamada: $" << fixed << setprecision (2) << tar << endl; //Imprimir resultado
	cout << endl; //Espacio de linea
	system ("pause"); //Pausa el programa, para continuer persionar tecla enter
	return 0; //Retorno de valores a cero
}

//Acciones a ejecutar por la funcion 1
void titulo() {
	system ("cls"); //Limpia el contenido en pantalla
	cout << "============================================" << endl; //Imprime en pantalla
	cout << "-----------Telefonica S.A. de C.V-----------" << endl; //Imprime en pantalla
	cout << "============================================" << endl; //Imprime en pantalla
	cout << endl; //Espacio de linea
}
