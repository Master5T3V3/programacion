#include <iostream>

using namespace std;

struct Empleado {
	char cod [5];
	char nombre [50];
	int edad;
	float salbase;
	float salliquido;
	float isss;
	float afp;
	float renta;
	float totalprestamo;
	char departamento [60];
	char puesto [60];
}e;

struct Sucursal {
	int numsucursal;
	char nomsucuarsal [60];
}s;

float caliss (float sal) {
	int isss = 0;
	
	if (sal >= 600) {
		isss = 30;
	}
	else {
		isss = sal * 0.03;
	}
	
	return isss;
}

int main(int argc, char** argv) {
	int n;
	
	cout << "¿Cuantos empleados tiene?: ";
	cin >> n;
	Empleado e[n];
	Sucursal s;
	
	for (int i = 0; i < n; i++) {
		int cp;
		int contador;
		
		cout << "\nCodigo: " << endl;
		cin >> e[i].cod;
		cout << "Nombre: " << endl;
		cin >> e[i].nombre;
		cout << "Edad: " << endl;
		cin >> e[i].edad;
		cout << "Salario base: " << endl;
		cin >> e[i].salbase;
		e[i] = calisss * (e[i].salbase * 0.03);
		//afp
		//renta
		
		cout << "Cantidad de prestamos del empleado: " << endl;
		cin >> cp;
		contador = 0; //Contador
		float totprestamo = 0; //Acumulador
		float pres;
		
		while (contador <= cp) {
			cout << "Monte a descontar: " << endl;
			cin >> totprestamo;
			
			
		}
		
	}
	
	for (int i = 0; i < n; i++) {
		cout << e[i].cod << "\t";
		cout << e[i].nombre << "\t";
		cout << e[i].edad << "\t";
		cout << e[i].salbase << "\t";
		cout << e[i].isss << "\t";
		
		cout << endl;
	}
	
	system ("pause");
	return 0;
}
