//Una Empresa se dedica a exportar cafe;
//para cada cliente aplica la siguiente tabla de descuentos:
//Bolsas > 100 = 10%
//Bolsas > 200 = 15%
//Bolsas > 250 y < 300 = 20%
//Bolsas >= 300 = 25%
//Ademas agregar el IVA de 13%

//Incluir las librerias a utilizar
#include <iostream>
#include <math.h>

//Asigar un espacio para simplificar el codigo
using namespace std;

//Introducir el cuerpo del codigo
int main() {
	//Variable de precio unitario
	float vu = 50.0;
	//Variable de cantidad
	int cs;
	//Variable de venta con iva
	float vi;
	//Variable de venta bruta
	float vb;
	//Variable descuento
	float desc;
	//Variable iva
	float iva;
	//Variable de venta liquida
	float vl;
	
	//Imprime mensaje de bienvenida
	cout << "Bienvenid@ a Coffe Stacks S.A de C.v" << endl;
	cout << endl;
	//Imprime en pantalla mensaje para ingresar la cantidad de sacos
	cout << "Ingrese cantidad de sacos: ";
	//Guardar el dato en la variable cantidad de sacos
	cin >> cs;
	
	//Verificacion de la cantidad de sacos
	while (cs <= 0){
		cout << "La cantidad ingresada no es valida, ingrese otra: ";
		cin >> cs;
	}
	
	//Formula para obtener la venta bruta
	vb = vu * cs;
	
	//Aplicar IVA
	iva = vb * 0.13;
	
	//Agregar IVA a la venta bruta
	vi = vb + iva;
	
	//Verificar se aplica a descuento
	//Primer caso de descuento > 100
	if (cs > 100 and cs <= 200){
		cout << "Aplica descuento del 10%" << endl;
		desc = vi * 0.1;
	}
	else {
		//Segundo caso de descuento >200
		if (cs > 200 and cs <= 250){
			cout << "Aplica descuento del 15%" << endl;
			desc = vi * 0.15;
		}
		else {
			//Tercer caso de descuento > 250 y < 300
			if (cs > 250 and cs < 300){
				cout << "Aplica descuento del 20%" << endl;
				desc = vi * 0.2;
			}
			else {
				//Cuarto caso de descuento >= 300
				if (cs >= 300){
				cout << "Aplica descuento del 25%" << endl;
				desc = vi * 0.25;
				}
				else {
					cout << "No aplica a descuento" << endl;
				}
			}
		}
	}
	
	//Imprimir en pantalla la venta liquida
	vl = vi - desc;
	cout << "Total: ";
	cout << vl;
	
	return 0;
}
