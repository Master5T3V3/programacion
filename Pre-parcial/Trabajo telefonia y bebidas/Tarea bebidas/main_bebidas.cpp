//Programa creado por: Brian Steve Rodas Hernandez
//Ultima fecha de modificacion: 24/09/2018

#include <iostream> //Libreria de entradas y salidas
#include <windows.h> //Libreria de funciones de windows en consola

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
	string opc; //Variable para las opciones
	string can; //Cadena para variable de cantidad
	int agua; //Variable de cantidad de agua
	int azucar; //Variable de cantidad de azucar
	int o; //Variable para seleccion de bebida
	int n; //Variable para condiciones
	char soundf[] = "C:\\Windows\\media\\chord.wav"; //Varaiable para audio en caso de repetir ciclo
	char soundt[] = "C:\\Windows\\media\\windows unlock.wav"; //Variable para audio en caso de obtener resultado
	char soundn[] = "C:\\Windows\\media\\chimes.wav"; //Variable para audio en caso de introducir dato
	
	system ("color F0"); //Cambiar color fondo/texto
	
	error: //Reinicio en caso de no cumplir condiciones
	//Validacion para ingresar tipo de bebida
	do {
		titulo (); //Limpia la pantalla
		cout << "Seleccione bebida a calcular insumos:" << endl; //Imprime en pantalla una indicacion al usuario
		cout << "+Sodas (1)" << endl; //Imprime opcion 1
		cout << "+Jugos (2)" << endl; //Imprime opcion 2
		cout << endl; //Espacio de linea
		cout << "Digite el numero correspondiente a la bebida a producir: "; //Pide al usuario que ingrese el codigo
		cin >> opc; //Agregar dato a variable de opciones
		system ("color 4F"); //Cambiar fondo/texto
		cout << PlaySound((LPCSTR)soundf, NULL, SND_FILENAME | SND_ASYNC ); //Reproduccion de audio
	}
	while (! validn (opc)); //Mientras se encuentre entre los numeros de seleccion
	
	o = atoi(opc.c_str()); //Obtener dato del string y agregarlo a variable o
	
	while (o < 1 || o > 2) { //Mientras sea diferente de los numeros de selccion
		goto error; //Regresar al punto do while
	}
	
	system ("color F0"); //Cambiar color fondo/texto
	cout << PlaySound((LPCSTR)soundn, NULL, SND_FILENAME | SND_ASYNC ); //Reproduccion de audio
	
	//Repeticion de ciclo en caso de no ser un valor admitido
	do {
		titulo (); //Ejecutar funcion 1
		cout << "Ingrese cantidad a producirse: "; //Imprime mensaje en pantalla
		cin >> can; //Introducir dato
		system ("color 4F"); //Cambiar fondo/texto
		cout << PlaySound((LPCSTR)soundf, NULL, SND_FILENAME | SND_ASYNC ); //Reproduccion de audio
	}
	while (! validn (can)); //Mientras no se ingrese un valor numerico
	
	titulo (); //Limpia la pantalla
	
	n = atoi(can.c_str()); //Obtener dato del string y agregarlo a variable n
	
	if (o <= 1) { //En caso de seleccionar la bebida soda
		agua = n * 500; //Agregar calculo a variable agua
		azucar = n * 800; //Agregar calculo a variable azucar
	}
	else { //En caso de seleccionar la bebida jugo
		agua = n * 600; //Agregar calculo a variable agua
		azucar = n * 700; //Agregar calculo a variable azucar
	}
	
	system ("color F0"); //Cambiar color fondo/texto
	cout << PlaySound((LPCSTR)soundt, NULL, SND_FILENAME | SND_ASYNC ); //Reproduccion de audio
	titulo (); //Limpia la pantalla
	cout << "Cantidad requeria de agua: " << agua << "ml" << endl; //Imprime cantidad de agua
	cout << "Cantidad requeria de azucar: " << azucar << "g" << endl; //Imprime cantidad de azucar
	
	cout << endl; //Espacio de linea
	system ("pause"); //Pausar pantalla
	return 0; //Retornar valores a cero
}

//Acciones a ejecutar por la funcion 1
void titulo() {
	system ("cls"); //Limpia el contenido en pantalla
	cout << "============================================" << endl; //Imprime en pantalla
	cout << "-----------DrinkTeam  S.A. de C.V-----------" << endl; //Imprime en pantalla
	cout << "============================================" << endl; //Imprime en pantalla
	cout << endl; //Espacio de linea
}
