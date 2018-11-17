//Este programa fue desarrollado por: Brian Steve Rodas Hernandez
//Carnet: RH18031

/*Realice una aplicacion en consola que obtenga las ventas por clientes,
ademas almacene los datos en un archivo de texto*/

#include <iostream> //Libreria de entradas y salidas
#include <string> //Libreria de cadenas
#include <fstream> //Libreria para trabajar con ficheros
#include <windows.h> //Libreria de funciones del sistema

using namespace std; //Simplificacion del codigo

struct ventas { //Crear estructura para ventas
    string producto; //Cadena del producto
    double precio; //Variable para precios
    double cantidad; //Variable para cantidades
    double totventa; //Variable para el total de la venta
};

int main() {
    int n; //Variable para cantidades en ventas
    ventas temp; //Crear variable temporal
    string msn = "\t\tREPORTE DE VENTAS\n"; //Imprimir titulo
    msn += "-------------------------------------------------\n" ; //Imprimir linea de division
    cout << "\t\tDigita el numero de ventas realizadas: "; //Pedir numero de vnetas
    cin >> n; //Agregar a variable de numero de ventas
    
    while(cin.fail()){ //Si falla entrada
        cin.clear(); //Limpiar entrada
        cin.ignore(1000,'\n'); //Ignorar entrada
        cout << "\t\tEl valor ingresado no es valido, ingresa otro: "; //Imprimir indicacion
        cin >> n; //Agregar a variablde de numero de ventas
        cout << endl; //Espacio de linea 
    }

    ventas listaVentas[n]; //Agregar estructura 

    for(int i = 0 ; i < n; i++){ //Llenar arreglos por medio de ciclo
        system("cls"); //Limpiar pantalla del sistema
        //Pedir datos de la venta
        cout << "\t\tIngrese nuevo dato para venta " << i + 1 << endl;
        cout << "\t\tIngrese nombre del producto : ";
        cin >> listaVentas[i].producto ;
        cout << "\t\tIngrese precio del producto : ";
        cin >> listaVentas[i].precio;
        cout << "\t\tIngrese cantidad del producto vendido: ";
        cin >> listaVentas[i].cantidad;

        listaVentas[i].totventa = listaVentas[i].precio * listaVentas[i].cantidad; //Operaciones para total
        
		cout << "\t---------------------------------------------------" << endl; //Linea de division
        cout << "\n\t\tTotal de la venta es: " << listaVentas[i].totventa << endl; //Imprimir resultado
        system("pause") ; //Pausar pantalla del sistema
    }
    for(int i = 0; i <= n; i++){ //Ciclo para imprimir filas
        for(int j = i + 1; j < n; j++){ //Ciclo para imprimir columnas
            //Orenar salida
            if (listaVentas[j].totventa < listaVentas[i].totventa){
                temp = listaVentas[j];
                listaVentas[j] = listaVentas[i];
                listaVentas[i] = temp;
            }
        }
    }

    for (int i = 0 ; i < n; i++ ){ //Mostrar las ventas por medio de ciclo
        system("cls");
        cout << "\t\tVenta " << i + 1 << endl;
        cout << "\t\tProducto : " << listaVentas[i].producto << endl;
        cout << "\t\tPrecio : " << listaVentas[i].precio << endl;
        cout << "\t\tCantidad : " << listaVentas[i].cantidad << endl;
        cout << "\t\tTotal : " << listaVentas[i].totventa << endl;
 
 		//Imprimir resultados de ventas
        /*msn += "\t\tVENTA " + to_string(i+1)+ "\n";
        msn += "\t\tproducto : " + listaVentas[i].producto + "\n";
        msn += "\t\tprecio : " + to_string(listaVentas[i].precio) + "\n";
        msn += "\t\tcantidad : " + to_string(listaVentas[i].cantidad) + "\n";
        msn += "\t\ttotal : " + to_string(listaVentas[i].totventa) + "\n";
        msn += "\t\t-----------------------------------------------------\n";*/
        system("pause"); //Pausar consola
    }

    ofstream fs("ventas.txt"); //Almacenar datos en archivo de texto
    fs << msn << endl; //Publicar archivo 
    fs.close(); //Cerrar archivo de texto
    
    return 0; //Retornar valores a cero
}
