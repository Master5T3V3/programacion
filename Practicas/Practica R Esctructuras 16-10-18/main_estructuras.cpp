#include <iostream> //Libreria de entradas y salidas
#include <conio.h> //Libreria de funciones para corregir errores

using namespace std; //Simplificacion del codigo

struct peliculas { //Estructura para peliculas
	string nombre; //Cadena para el nombre
	string genero; //Cadena para genero
	int duracion; //Variable entera de duracion
	int anio; //Variable entera de anio
	string descripcion; //Cadena para descripcion
}P1, P2, P3; //Optener variables con esta estructura

struct notas { //Estructura para notas
	double notas; //Variable decimal para la nota
}M[100], C[100]; //Definir variables con 100 de ancho

//Desarrollo del codigo
int main(int argc, char** argv) {
	
	//Deshabilitar flecas para habilitar operaciones
	/*cout << "Ingrese nombre: ";
	cin >> P1.nombre;
	fflush (stdin); //Corrige errores de cadena
	cout << "Ingrese genero: ";
	cin >> P1.genero;
	cout << "Ingrese duracion (min): ";
	cin >> P1.duracion;
	cout << "Ingrese anio: ";
	cin >> P1.anio;
	
	cout << "\nPelicula 1\n";
	fflush (stdin); //Corrige errores de cadena
	cout << "\nNombre: " << P1.nombre;
	fflush (stdin); //Corrige errores de cadena
	cout << "\nGenero: " << P1.genero;
	cout << "\nDuracion (min): " << P1.duracion;
	cout << "\nAnio: " << P1.anio;
	cout << "\n\n\n";
	
	cout << "Ingrese nombre: ";
	cin >> P2.nombre;
	fflush (stdin);
	cout << "Ingrese genero: ";
	cin >> P2.genero;
	cout << "Ingrese duracion (min): ";
	cin >> P2.duracion;
	cout << "Ingrese anio: ";
	cin >> P2.anio;
	
	fflush (stdin); //Corrige errores de cadena
	
	cout << "\nPelicula 2\n";
	cout << "\nNombre: " << P2.nombre;
	cout << "\nGenero: " << P2.genero;
	cout << "\nDuracion (min): " << P2.duracion;
	cout << "\nAnio: " << P2.anio;
	cout << "\n\n";*/
	
	
	//Ejercicio 2
	cout << "\nNOTAS DE MATEMATICAS\n"; //Imprimir mensaje prinicipal
	
	for (int i = 0; i < 4; i++) { //Notas en cero, hasta que i tenga cuatro notas
		cout << "Ingrese nota " << i + 1 << " : "; //Pedir nota
		cin >> M[i].notas; //Guardar en arreglo de notas
	}
	
	cout << "\n"; //Espacio de linea
	
	system ("pause"); //Pausar pantlla de consola
	return 0; //Retornar valores a cero
}
