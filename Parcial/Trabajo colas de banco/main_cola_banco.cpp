//Progrema creado por:Brian Steve Rodas Hernandez
//Numero de carnet: RH18031

#include <iostream> //Libreria de entradas y salidas
#include <stdlib.h> //Libreria para funciones como new o delete
#include <stdio.h>
#include <conio.h>
#include <windows.h> //Libreria de funciones de windows

using namespace std; //Simplificar codigo

void bienvenida(); //Funcion para mensaje de bienvenida

void case1(); //Funcion para menu de caso 1
void six(); //Funcion para mensaje de advertencia de cola llena
int sinox(int x); //Funcion para asignar numero y continuidad

void case2_4(); //Funcion para menu de caso 2 y 3
int sino2x(int x); //Funcion para mensaje de numero eliminado
void advacia(); //Funcion para mensaje de cola vacia

void case5(); //Funcion para menu de caso 4

void defa(); //Funcion para mensaje en default

struct nodo { //Crear estructura para nodos
    int nro; //Variable numero
    struct nodo *sgte; //Variable siguiente de tipo puntero
};
 
typedef struct nodo *Puntero; //Definir estructura con variavle puntero de tipo puntero
 
class Cola{ //Crear clase
    public: //Clases publicas
        Cola(void); //Cola vacia
        void insertar(int); //Funcion insertar elementos en cola
        int eliminar(void); //Funcion eliminar elementos en cola
        bool vacio(void); //Funcion cola vacia
        void mostrar(void); //Funcion mostrar cola
        void vaciar(void); //Funcion vaciar cola
 
    private: //Clases privadas
        Puntero delante; //puntero al primer elemento de la cola
        Puntero atras; //puntero al ultimo elemento de la cola
 
};

struct datos { //Estrucura para llevar datos
 int dato; //Variable de dato
 datos *s; //Variable de tipo puntero para datos
 }*p,*aux,*u; //Variables de tipo puntero para la estructura

int menu(void) { //Ejecutar la funcion de menu
	system("cls"); //Limpiar pantalla de consola
	system("color 3F"); //Cambiar colores, fondo turquesa, texto blanco
    cout << endl << endl << endl << endl << endl; //Espacios de linea
    //Imprimir menu de opciones en pantalla
	cout << "\t\t\t\t ------------------------------------------------- " << endl;
    cout << "\t\t\t\t|           [[MENU DE OPCIONES DE COLA]]          |" << endl;
    cout << "\t\t\t\t|-------------------------------------------------|" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t|        1. Agregar numero a la cola              |" << endl;
    cout << "\t\t\t\t|        2. Eliminar numero en la cola            |" << endl;
    cout << "\t\t\t\t|        3. Llamar a numero                       |" << endl;
    cout << "\t\t\t\t|        4. Mostrar cola                          |" << endl;
    cout << "\t\t\t\t|        5. Vaciar toda la cola                   |" << endl;
    cout << "\t\t\t\t|        6. Salir                                 |" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t -------------------------------------------------\n\n";
    cout << "\t\t\t\t\t\tDigite la opcion: "; //Mensaje para pedir ingreso de opcion
}

//Desarrollo del codigo
int main(void) {
	Cola cola; //Incluir cola
    int x; //Variable x, para manejar datos
    int xx[49]; //Variable para manejar posiciones de x
    int i; //Variable i
    int op; //Variable para opciones del menu
    int opx; //Variable para opcion de continuar o terminar operaciones de caso 1
    Puntero p_aux;
	char soundi[] = "C:\\Windows\\media\\ring06.wav"; //Variable de audio de bienvenida
	char sound1[] = "C:\\sistema_colas\\audios\\1.wav";
	
	bienvenida(); //Ejecutar funcion en pantalla
	
	cout << PlaySound((LPCSTR)soundi, NULL, SND_FILENAME | SND_ASYNC); //Reproducir audio de bienvenida
	Sleep(3000); //Mantener texto en pantalla durante un tiempo, 1000 = 1 segundo
 	
	returnmenu: //Punto de retorno, utilizado en algunos de los casos
	menu(); //Ejecutar funcion de menu
	cin >> op; //Agregar dato introducido a variable que maneja las opciones
	system("cls"); //Limpiar pantalla de consola
	system("color F0"); //Cambiar colores de consola, fondo blanco, letras negras
	
    switch(op) {
        case 1: //Caso 1, para insertar numeros
			do { //Ciclo para ingresar numeros
				system("cls");
				x = x + 1; //Acumulador, para agregar numeros a la cola en x
				for ( i = 0; i < x; i++) {
					xx[i] = x; //Asignar valores de x
				}
				case1(); //Ejecutar funcion menu de caso 1
				if (x > 50) { //Si x sobrepasa el limite a encolar de 50
					six(); //Ejecutar funcion de caso de avertencia de cola llena
				}
				else {
					cola.insertar(x); //Ejecutar funcion para insertar numeros en cola
					sinox(x); //Ejecutar funcion de ingreso de numero y continuidad
					cin >> opx; //Agregar dato a la opcion que controla meno de insertar en cola
				}
			}
			while(opx == 1 and x <= 50); //Mientras se escoge opcion uno y no existan mas de 50 numeros
			system("pause"); //Pausar pantalla de la consola
			goto returnmenu; //Regresar a el punto del menu
			
        case 2: //Caso 2, Para eliminar numeros
        	case2_4(); //Ejecutar cabecera del menu
            if(cola.vacio() == true) { //Si se demuestra con la funcion que la cola esta vacia
               	advacia(); //Ejecutar funcion con mensaje de cola vacia
			}
            else { //Si no esta vacio
                x = cola.eliminar(); //Hacer que x se deshaga del orimer valor en cola
                sino2x(x); //Ejecutar funcion con mensaje de numero eliminado
            }
            system("pause"); //Pausar pantalla de la consola
            goto returnmenu; //Regresar al punto del menu
            
        case 3:
        	if (xx[i] == 1) { // Si es igual a uno
        		cout << PlaySound((LPCSTR)sound1, NULL, SND_FILENAME | SND_ASYNC); //Reproducir audio
        		system("pause"); //Pusar pantalla del sistema
        		goto returnmenu; //Regresar al punto del menu
			}
			else if (xx[i] == 2) { //Si no es igual a uno
				cout << PlaySound((LPCSTR)sound1, NULL, SND_FILENAME | SND_ASYNC); //Reproducir audio
				system("pause"); //Pusar pantalla del sistema
        		goto returnmenu; //Regresar al punto del menu
			}
            
        case 4:
        	case2_4(); //Ejecutar funcion de menu de caso 3
        	if(cola.vacio()!=true) { //Si no esta vacia la cola
            	cola.mostrar(); //Ejecutar funcion de mostrar cola
			}
            else {
            	advacia(); //Ejecutar funcion de advertencia en caso de tener cola vacia
			}
			system("pause"); //Pausar pantalla de la consola
            goto returnmenu; //Regresar a punto del menu
 
        case 5:
            cola.vaciar(); //Ejecutar funcion de vaciar cola 
            case5();
			x = 0;
			system("pause"); //Pausar pantalla de la consola
            goto returnmenu; //Regresar a punto del menu
            
        case 6:
        	goto exit; //Ir al punto de salida
 
        default: //Ejecuta error por defecto
            defa(); //Ejecutar funcion de mensaje para default
            goto returnmenu; //Regresar a punto del menu
    }
	exit: //Direccion de salida para caso 6
	system("pause"); //Pausar pantalla de consola
	return 0; //Retornar valores a cero
}

void bienvenida() { //Funcion para mensaje de bienvenida
	system("color 03"); //Cambiar color de consola, fondo negro, letras turquesa
	cout << endl << endl << endl << endl << endl << //Espacios de linea
	//Imprimir mensaje de bienvenida en pantalla de consola
			"\t\t\t\t1111111111111111111111111111111111111111111111111111111" << endl;
	cout << "\t\t\t\t1                                                     1" << endl;
	cout << "\t\t\t\t1 ++++  + +++++ +   + +   + +++++ +   + + ++++  +++++ 1" << endl;
	cout << "\t\t\t\t1 +   + + +     ++  + +   + +     ++  + + +   + +   + 1" << endl;
	cout << "\t\t\t\t1 ++++  + +++++ + + + +   + +++++ + + + + +   + +   + 1" << endl;
	cout << "\t\t\t\t1 +   + + +     +  ++  + +  +     +  ++ + +   + +   + 1" << endl;
	cout << "\t\t\t\t1 ++++  + +++++ +   +   +   +++++ +   + + ++++  +++++ 1" << endl;
	cout << "\t\t\t\t1                                                     1" << endl;
	cout << "\t\t\t\t1                 BANCO NACIONAL BSRH                 1" << endl;
	cout << "\t\t\t\t1                 BANCO NACIONAL BSRH                 1" << endl;
	cout << "\t\t\t\t1                 BANCO NACIONAL BSRH                 1" << endl;
	cout << "\t\t\t\t1                                                     1" << endl;
	cout << "\t\t\t\t111111111111111111111111111111111111111111111111111111";
}

Cola::Cola(void){ //Funcion para manejar punteros de cola
    delante = NULL;//Inicializar puntero delante
    atras= NULL; //Inicializar puntero atras
}

bool Cola::vacio(){ //Funcion para manejar vacios en cola
    if(delante==NULL) { //Si no hay numeros delante
    	return true; //Convertir a verdadero
	}
    else { //Si existen numeros delante
    	return false; //Convertir a falso
	}
}

void Cola::insertar(int x){ //Funcion para insertar numero en cola
    Puntero p_aux; //Agregar puntero
 
    p_aux = new(struct nodo); //Crear nuevo nodo
    p_aux -> nro = x; //Puntero accede al elemendo nro de nodo y asigna valor de x
    p_aux -> sgte = NULL; //Puntero accede al elemento sgte y lo converte en nulo
 
    if(delante == NULL) { //Si delante es igual a nulo
     	delante = p_aux; //Delante es igual al puntero
	}
    else { //Si delante no es nulo
     	atras -> sgte = p_aux; //Atras accede al elemento sgte de nodo y asigna valor de puntero
	}
    atras = p_aux; //Atras es igual a puntero
}
 
int Cola::eliminar(void) { //Funcion para eliminar elementos en cola
    int n; //Agregar variable n
    Puntero p_aux; //Agregar puntero
 
    p_aux = delante; //Puntero es igual a delante
    n = p_aux -> nro; //Variable n es igual a puntero, puntero accede al elemento nro de nodo
    delante = (delante) -> sgte; //Delante asigna el valor al acceder el elemendo sgte de nodo
    delete(p_aux); //Funcion para borrar elemento en puntero
    return n; //Retornar valor de n
}
 
void Cola::mostrar(void){ //Funcion mostrar cola
    Puntero p_aux; //Agregar puntero
    p_aux = delante; //Asignar a puntero valor de elemento delante
    //Imprimir separador
    cout << "\t\t\t\t|                                                       |" << endl;
    
    while(p_aux != NULL) { //Mientras sea diferente de un valor nulo
        cout << "\t\t\t\t|                 - Cliente numero " << p_aux -> nro; //Imprimir numero
        cout << "                    |" << endl; //Imprimir restante del separador
        p_aux = p_aux -> sgte; //Acumular, acceder a elemento sgte de nodo
    }
     //Imprimir separador
    cout << "\t\t\t\t ------------------------------------------------------- " << endl;
}
 
void Cola::vaciar(void) { //Funcion para vaciar cola
    Puntero p_aux, //Agregar puntero principal
	r_aux; //Agregar puntero secundario
    p_aux = delante; //Puntero principal es igual a delante
     
    while(p_aux!=NULL) { //Mientras puntero principal sea igual a nulo
    	r_aux = p_aux; //Agregar valor de puntero principal a secundario
        p_aux = p_aux -> sgte; //Acumular puntero principal accediento a elemento sgte
        delete(r_aux); //Borrar todos los elementos en el puntero
    }
    delante = NULL; //Delante se convierte en nulo
    atras = NULL; //Atras se convierte en nulo
}

void case1() { //Funcion para menu de caso 1		
	cout << endl << endl << endl << endl << endl << endl; //Espacios de linea
	//Imprimir en pantalla cabecera del programa
	cout << "\t\t\t\t -------------------------------------------------------" << endl;
    cout << "\t\t\t\t|             [[INGRESO DE NUMEROS A COLA]]             |" << endl;
    cout << "\t\t\t\t|-------------------------------------------------------|" << endl;
}

void six() { //Funcion para mostrar advertencia de cola llena
	system("color 04"); //Cambiar colores de consola, fondo negro, texto rojo
	//Imprimir mensaje de cola llena
	cout << "\t\t\t\t|-------------------------------------------------------|";
	cout << "\t\t\t\t| No se pueden agregar mas datos, borre numeros en cola |";
	cout << "\t\t\t\t|-------------------------------------------------------|";
}

int sinox(int x) { //Funcion para mostrar numero insertado y preguntar continuidad
	//Imprimir mensaje de exito al insertar numero en cola
    cout << "\t\t\t\t|-------------------------------------------------------|" << endl;
	cout << "\t\t\t\t|          ==> Numero " << x << " agregado con exito <==          |" << endl;
	cout << "\t\t\t\t ------------------------------------------------------- " << endl;
	//Imprimir mensaje para preguntar si se desea continuar insertando numeros
    cout << "\t\t\t\t\t      Continuar agregando numeros?:" << endl;
	cout << "\t\t\t\t\t       1. Si               2. No" << endl;
}

int sino2x(int x) { //Variable en caso que se elimine un numero
	//Imprimir mensaje de exito al insertar numero en cola
    cout << "\t\t\t\t|-------------------------------------------------------|" << endl;
	cout << "\t\t\t\t|              ==> Numero " << x << " eliminado <==               |" << endl;
	cout << "\t\t\t\t ------------------------------------------------------- " << endl;
}

void case2_4() { //Funcion para menu de opcion 2 y 4
	cout << endl << endl << endl << endl << endl << endl; //Espacios de linea
    //Imprimir cabecera de menu mostrar cola
    cout << "\t\t\t\t -------------------------------------------------------" << endl;
    cout << "\t\t\t\t|                       [[COLA]]                        |" << endl;
    cout << "\t\t\t\t|-------------------------------------------------------|" << endl;
}

void advacia() { //Funcion para advertencia de cola vacia
	system("color 04"); //Cambiar colores de consola, fondo negro, texto rojo
    //imprimir mensaje de errar en caso de estar vacia la cola
   	cout << "\t\t\t\t|                                                       |" << endl;
    cout << "\t\t\t\t|               ## La cola esta vacia ##                |" << endl;
    cout << "\t\t\t\t|                                                       |" << endl;
    cout << "\t\t\t\t ------------------------------------------------------- " << endl;
}

void case5() { //Funcion para manu de caso 4
	cout << endl << endl << endl << endl << endl; //Espacios de linea
    //Imprimir menu de vaciado de cola
    cout << "\t\t\t\t ------------------------------------------------------- " << endl;
    cout << "\t\t\t\t|                   [[VACIAR COLA]]                     |" << endl;
    cout << "\t\t\t\t|-------------------------------------------------------|" << endl;
    cout << "\t\t\t\t|                                                       |" << endl;
    cout << "\t\t\t\t|           !!! Cola eliminada con exito !!!            |" << endl;
    cout << "\t\t\t\t|                                                       |" << endl;
    cout << "\t\t\t\t -------------------------------------------------------" << endl;
}

void defa() { //Funcion para mensaje en modo default
	system("color 04"); //Cambiar colores de consola, fondo negro, texto rojo
    cout << endl << endl << endl << endl << endl << endl << endl << endl; //Espacios de linea
	//Imprimir de error en pantalla
    cout << "\t\t\t\t -------------------------------------------------" << endl;
    cout << "\t\t\t\t|         ## Digite una opcion valida ##          |" << endl;
    cout << "\t\t\t\t -------------------------------------------------" << endl;
    system("pause"); //Pusar pantalla de consola
}
