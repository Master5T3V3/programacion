#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	cout << "Press the enter key to continue ..." << endl;
	int vector[5];
	int i, j, temp;
	
	//Tamano del vector
	for (i = 0; i <= 4; i++) {
		cout << i + 1 << ";";
		cin >> vector[i];
		cout << endl;
	}
	
	//Metodo de la burbuja
	for (i = 0; i <= 4; i++) {
		for (j = 0; j <= 4; j++) {
			if (vector[j] < vector[i]) {
				temp = vector[j];
				vector[j] = vector[i];
				vector[i] = vector[j];
				vector[i] = temp;
			}
		}
	}
	
	for (i = 0; i <= 4; i++) {
		cout << vector[i] << " ";
	}
	
	system("pause");
	return 0;
}
