#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
	char cadena[127];
	
	ofstream fs("nombre.txt");
	fs << "Hola mundo" << endl;
	fs.close();
	
	cout << "Archivo creado correctamente" << endl;
	
	system("pause");
	return 0;
}
