#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int matriz1 [30][30];
	int matriz2 [30][30];
	int fil;
	int col;
	
	cout << "Ingrese el numero de filas: ";
	cin >> fil;
	cout << "Ingrese el numero de columnas: ";
	cin >> col;
	
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			cout << "Ingrese dato [" << i << "][" << j << "] : ";
			cin >> matriz1 [i][j];
		}
	}
	
	cout << endl;
	cout << endl;
	
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			cout << matriz1 [i][j] << "\t";
		}
	cout << endl << endl;	
	}
	
	
	cout << "Matriz 2" << endl;
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			cout << matriz2 [i][j] + 5 << "\t";
		}
	cout << endl << endl;	
	}
	
	system ("pause");
	return 0;
}
