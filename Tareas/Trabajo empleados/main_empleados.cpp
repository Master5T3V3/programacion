//Este programa fue desarrollado por: Brian Steve Rodas Hernandez
//Codigo de carnet: RH18031

#include <cstdlib> //Libreria de control de procesos
#include <iostream> //Libreria de entradas y salideas
#include <iomanip> //Libreria para corregir errores numericos

using namespace std; //Utilizar simplificacion del lenguaje

//Estructura, entidad empleado
struct Empleado {
	char cod[5]; //Variable de codigo
	char nombre[50]; //Variable de nombre
	int edad; //Variable de edad
	float salbase; //Variable de salario base
	float salliquido; //Variable de salario liquido
	float isss; //Variable de descuento isss
	float afp; //Variable de descuento afp
	float renta; //Variable de descuento de renta
	float totalprestamo; //Variable de total en prestamos
	char departamento[60]; //Variable de departamento de empresa
	char puesto[60]; //Variable de puesto/cargo de empresa
};

int tomarINTE (); //Funcion para comprobar edad
bool tipoINTvalidoE (string); //Funcion para validar enteros en edad

int tomarINTS (); //Funcion para comprobar salario
bool tipoINTvalidoS (string); //Funcion para validar enteros en salario

int tomarINTP (); //Funcion para comprobar prestamos
bool tipoINTvalidoP (string); //Funcion para validar enteros en prestamos

int tomarINTM (); //Funcion para comprobar montos
bool tipoINTvalidoM (string); //Funcion para validar enteros en montos

float calisss(float salbase) { //Calcular isss, introducir variable salario y tope
	float isss = 0.00; //Variable isss
	
	if(salbase >= 600.00) //Si el salario es mayor a los 600 dolares
		isss = 30.00; //isss es igual a 30 dolares
	else
		isss = salbase * 0.03; //Sino, calcular impuesto multiplicando salario por el 3%
	return isss; //Retornar valores de isss
}

//Crear las funciones para calcular el isss, afp y renta del empleado
float calafp(float salbase) { //Calcular afp, agregar salario base
	float afp = 0.00; //Igualar afp a cero
	
	afp = salbase * 0.0725; //Multiplicar salario base por el 7.25% para obtener afp
	
	return afp; //Retornar valores del afp
}
float calrenta(float salbase, float isss, float afp) { //Calcular renta, agregar salario, isss, afp
	float renta = 0.00; //Variable de renta, igualar a cero
	float tram; //Variable para obtener tramo
	
	tram = salbase - (isss + afp); //Calculo para obtener tramo
	
	if(tram < 0.01) { //Sies menor a cualquiera de los tramos
		cout << "La cantidad ingresada no es valida, ingrese otra: "; //Alerta en caso de error
	}
	else if (tram >= 0.01 and tram <= 472.01) { //Para el primer tramo, entre 0.01 y 472.00 
		renta = 0.00; //No hay renta
	} 
	else if (tram > 472.00 and tram < 895.25) { //Para el segundo tramo, entre 472.01 y 895.24
		renta = ((tram - 472.00) * 0.10) + 17.67; //Se le resta el isss y afp, se quita el exceso, se multiplica por el 10% y se le suma la cuota fija 
	}
	else if (tram > 895.24 and tram < 2038.11) { //Para el tercer tramo, entre 895.25 y 2038.10
		renta = ((tram - 895.24) * 0.20) + 60.00; //Se le resta el isss y afp, se quita el exceso, se multiplica por el 20% y se le suma la cuota fija
	}
	else if (tram > 2038.10) { //Para el cuarto tramo, de 2038.11 en adelante
		renta = ((tram - 2038.10) * 0.30) + 288.57; //Se le resta el isss y afp, se quita el exceso, se multiplica por el 30% y se le suma la cuota fija
	}
	
	return renta; //Retornar valor de la renta
}

//Desarrollo o cupero del codigo
int main (int argc, char *argv[]) { 
	int n; //Variable de cantidad de empleados
	float a;
	
	cout << "Cuantos empleados tiene?" << endl; //Preguntar por el numero de empleados
	cin >> n; //Introducir dato a variable numero de empleados
	cout << endl; //Espacio de linea
	
	Empleado e[n]; //Ejecutar estructura empleado
	int cp; //Variable de cantidad de prestamos
	int contador; //Variable de contador
	
	system ("cls"); //Limpiar pantalla de consola
	
	//Ciclo para ingresar datos segun cantidad de empleados
	for(int i = 0; i < n; i++) {
		cout << "Empleado " << i + 1 << endl; //Mostrar titulo con numero de empleado
		cout << "Ingrese codigo:" << endl; //Pedir codigo
		cin >> e[i].cod; //Ingresar dato a variable de codigo
		cout << "Ingrese nombre:" << endl; //Pedir que digite el nombre
		cin >> e[i].nombre; //Agregar dato a variable nombre
		
		//Validacion para rango de edad
		do {
			e[i].edad = tomarINTE (); //Ejecutar funcion y agregar dato a variable edad
		}
		while (e[i].edad < 18 || e[i].edad > 100); //Mientras sea menor de edad o sobrepase una cierta cantidad de edad
		
		//Validacion para rango de salario
		do {
			e[i].salbase = tomarINTS (); //Ejecutar funcion para salario y agregar dato a variable de salario
		}
		while (e[i].salbase < 300.00); //Mientras sea menor al salario minimo
		
		//Validacion de rango de prestamos
		do {
			cp = tomarINTP (); //Ejecutar funcion de prestamos y asignar dato a variable cantidad de prestamos
		}
		while (cp < 0 || cp > 5); //Mientras sea menor a 0 o mayor a 5
		
		e[i].isss = calisss (e[i].salbase); //Ejecutar funcion para isss y agregar dato a variable isss
		e[i].afp = calafp (e[i].salbase); //Ejecutar funcion para calcular afp y agregar dato a variable afp
		e[i].renta = calrenta (e[i].salbase, e[i].isss, e[i].afp); //Ejecutar funcion para calcular renta y agregar dato a variable renta
		contador = 0; //Contador
		float totpres = 0; //Acumulador
		int pres; //Variable de prestamos
		
		//Iniciar ciclo para comprobar montos
		while(contador < cp && cp > 0) {
			reinicio : //Punto de partida
				pres = (float)tomarINTM (); //Ejecutar funcion para montos
				if(e[i].salbase * 0.8 > (totpres + pres)) { //Mientras no sobrepase el 80% del salario
					totpres = totpres + pres; //Sumar dato al total
					e[i].totalprestamo = totpres; //Agregar dato a estructura, variable total prestamo
				}
				else {
					cout << "A sobrepasado el limite, resta menos del 20% del sueldo, ingrese nuevamente los datos" << endl; //Mensaje de error
					system ("pause"); //Pausar pantalla para ver mensaje de error
					goto reinicio; //Repetir proceso
				}
			contador++; //Aumentar el contador en 1
			system ("cls"); //Limpiar pantalla de consola
		}
		
		e[i].salliquido = (((e[i].salbase - e[i].isss) - e[i].afp) - e[i].renta) - e[i].totalprestamo; //Calcular salario liquido
	}
	
	system("cls"); //Limpiar pantalla e consola
	
	cout << "Codigo" << "\t"; //Titulo para columna codigo
	cout << "Nombre" << "\t"; //Titulo para columna nombre
	cout << "Edad" << "\t"; //Titulo para columna edad
	cout << "Salario" << "\t\t"; //Titulo para columna salario
	cout << "ISSS" << "\t"; //Titulo para columna ISSS
	cout << "AFP" << "\t"; //Titulo para columna AFP
	cout << "Renta" << "\t\t"; //Titulo para columna renta
	cout << "Prestamos" << "\t"; //Titulo para columna prestamos
	cout << "Salario liquido" << "\t"; //Titulo para columna salario liquido
	cout << endl; //Espacio de linea
	
	//Ciclo para imprimir Datos de empleados
	for(int i = 0; i < n; i++) {
		cout << e[i].cod << "\t"; //Imprime el codigo
		cout << e[i].nombre << "\t"; //Imprime el nombre
		cout << e[i].edad << "\t"; //Imprime la edad
		cout << fixed << setprecision (2) << e[i].salbase << "\t\t"; //Imprime el salario base
		cout << fixed << setprecision (2) << e[i].isss << "\t"; //Imprime ISSS
		cout << fixed << setprecision (2) << e[i].afp << "\t"; //Imprime AFP
		cout << fixed << setprecision (2) << e[i].renta << "\t\t"; //Imprime renta
		cout << fixed << setprecision (2) << e[i].totalprestamo << "\t\t"; //Imprime prestamos
		cout << fixed << setprecision (2) << e[i].salliquido << "\t"; //Imprime sueldo liquido
		cout << endl << endl; //Espacio de linea
	}
	
	system("pause"); //Pausa la pantalla de consola
	return 0;
}

int tomarINTS () {
	string numero; //Cadena numero
	bool esValido = false; //Variable booleana en falso
	
	while (! esValido) { //Mientras no es valido
		try { //INTENTAR
			system ("cls"); //Limpiar pantalla de sistema
			cout << "Ingrese salario base: " << endl; //Imprimir mensaje y pedor ingreso de datos
			getline(cin,numero); //Obtener dato de variable numero
			esValido = tipoINTvalidoS (numero); //Variable esValido toma el dato
			
			if (! esValido) { //Si no es valido
				throw numero; //Arrojar numero
			}
		}
		
		catch(string e) { //Obtener mediante string
			cout << endl; //Salto de linea
		}
	}
	return atoi(numero.c_str()); //Convertir cadena a int y regresar datos
}

bool tipoINTvalidoS (string numero) { //Booleano, tomar cadena numero
	int inicio = 0; //Variable inicio, igual a cero
	
	if (numero.length() == 0) { //Si la cadena esta vacia
		return 0; //Retornar a falso
	}
	
	if (numero[0] == '+' || numero[0] == '-') { //Si tiene algun signo mas o menos
		inicio = 1; //Si hay signo hay que empezar desde uno
		
		if (numero.length() == 1) { //En caso de que no tengamos numero sino un signo
			return 0; //Retornar a falso
		}
	}
	
	for (int i = inicio; i < numero.length(); i++) { //Variable i recorre toda la cadena, para verificar
		if (! isdigit(numero[i])) { //Si no es un digito
			return 0; //Retornar a falso
		}
	}
	
	return 1; //Retornar a verdadero
}

int tomarINTP () {
	string numero; //Cadena numero
	bool esValido = false; //Variable booleana en falso
	
	while (! esValido) { //Mientras no es valido
		try { //INTENTAR
			system ("cls"); //Limpiar pantalla de sistema
			cout << "Ingrese cantidad de prestamos: " << endl; //Imprimir mensaje y pedor ingreso de datos
			getline(cin,numero); //Obtener dato de variable numero
			esValido = tipoINTvalidoP (numero); //Variable esValido toma el dato
			
			if (! esValido) { //Si no es valido
				throw numero; //Arrojar numero
			}
		}
		
		catch(string e) { //Obtener mediante string
			cout << endl; //Salto de linea
		}
	}
	return atoi(numero.c_str()); //Convertir cadena a int y regresar datos
}

bool tipoINTvalidoP (string numero) { //Booleano, tomar cadena numero
	int inicio = 0; //Variable inicio, igual a cero
	
	if (numero.length() == 0) { //Si la cadena esta vacia
		return 0; //Retornar a falso
	}
	
	if (numero[0] == '+' || numero[0] == '-') { //Si tiene algun signo mas o menos
		inicio = 1; //Si hay signo hay que empezar desde uno
		
		if (numero.length() == 1) { //En caso de que no tengamos numero sino un signo
			return 0; //Retornar a falso
		}
	}
	
	for (int i = inicio; i < numero.length(); i++) { //Variable i recorre toda la cadena, para verificar
		if (! isdigit(numero[i])) { //Si no es un digito
			return 0; //Retornar a falso
		}
	}
	
	return 1; //Retornar a verdadero
}

int tomarINTM () {
	string numero; //Cadena numero
	bool esValido = false; //Variable booleana en falso
	
	while (! esValido) { //Mientras no es valido
		try { //INTENTAR
			system ("cls"); //Limpiar pantalla de sistema
			cout << "Ingrese monto: " << endl; //Imprimir mensaje y pedor ingreso de datos
			getline(cin,numero); //Obtener dato de variable numero
			esValido = tipoINTvalidoM (numero); //Variable esValido toma el dato
			
			if (! esValido) { //Si no es valido
				throw numero; //Arrojar numero
			}
		}
		
		catch(string e) { //Obtener mediante string
			cout << endl; //Salto de linea
		}
	}
	return atoi(numero.c_str()); //Convertir cadena a int y regresar datos
}

bool tipoINTvalidoM (string numero) { //Booleano, tomar cadena numero
	int inicio = 0; //Variable inicio, igual a cero
	
	if (numero.length() == 0) { //Si la cadena esta vacia
		return 0; //Retornar a falso
	}
	
	if (numero[0] == '+' || numero[0] == '-') { //Si tiene algun signo mas o menos
		inicio = 1; //Si hay signo hay que empezar desde uno
		
		if (numero.length() == 1) { //En caso de que no tengamos numero sino un signo
			return 0; //Retornar a falso
		}
	}
	
	for (int i = inicio; i < numero.length(); i++) { //Variable i recorre toda la cadena, para verificar
		if (! isdigit(numero[i])) { //Si no es un digito
			return 0; //Retornar a falso
		}
	}
	
	return 1; //Retornar a verdadero
}

int tomarINTE () {
	string numero; //Cadena numero
	bool esValido = false; //Variable booleana en falso
	
	while (! esValido) { //Mientras no es valido
		try { //INTENTAR
			system ("cls"); //Limpiar pantalla de sistema
			cout << "Ingrese edad: " << endl; //Imprimir mensaje y pedor ingreso de datos
			getline(cin,numero); //Obtener dato de variable numero
			esValido = tipoINTvalidoE (numero); //Variable esValido toma el dato
			
			if (! esValido) { //Si no es valido
				throw numero; //Arrojar numero
			}
		}
		
		catch(string e) { //Obtener mediante string
			cout << endl; //Salto de linea
		}
	}
	return atoi(numero.c_str()); //Convertir cadena a int y regresar datos
}

bool tipoINTvalidoE (string numero) { //Booleano, tomar cadena numero
	int inicio = 0; //Variable inicio, igual a cero
	
	if (numero.length() == 0) { //Si la cadena esta vacia
		return 0; //Retornar a falso
	}
	
	if (numero[0] == '+' || numero[0] == '-') { //Si tiene algun signo mas o menos
		inicio = 1; //Si hay signo hay que empezar desde uno
		
		if (numero.length() == 1) { //En caso de que no tengamos numero sino un signo
			return 0; //Retornar a falso
		}
	}
	
	for (int i = inicio; i < numero.length(); i++) { //Variable i recorre toda la cadena, para verificar
		if (! isdigit(numero[i])) { //Si no es un digito
			return 0; //Retornar a falso
		}
	}
	
	return 1; //Retornar a verdadero
}
