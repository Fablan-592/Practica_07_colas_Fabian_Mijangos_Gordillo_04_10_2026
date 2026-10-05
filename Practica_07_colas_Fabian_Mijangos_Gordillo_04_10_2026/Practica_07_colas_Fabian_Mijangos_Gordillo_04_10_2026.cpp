#include <iostream>
using namespace std;
#define maxtamc 10 ///Tamaño máximo de la cola
typedef int tipodato; 

void ingresar_valores(int& frente, int& final, tipodato A[], int &contador ) {
	if ((final + 1) % maxtamc == frente) {
		cout << "Desbordamiento de cola " << endl;
		return;
	}

	cout << "Ingrese un elemento para la cola: ";
	tipodato elemento;
	cin >> elemento;
	final = (final + 1) % maxtamc;
	A[final] = elemento;

	contador++;
	cout << "Elemento " << contador << "Agregado a la cola: " << elemento << endl;
	return;
}

void eliminar_elemento(int &frente, int final, int &contador) {
	if (frente == final) {
		cout << "La cola está vacía, no hay elemento a eliminar" << endl;
		return;
	}
	frente = (frente + 1) % maxtamc;
	contador--;
	cout << "Elemento eliminado de la cola correctamente" << endl;
}
void imprimir(int &frente, int&final, tipodato A[]){

	cout << "Elementos de la cola en el orden de ingreso: " << endl;
	for (int i = frente + 1; i <= final; i = (i + 1) % maxtamc) {
		cout << A[i] << " ";

	}
	cout << endl;
}

int main(){
	
	tipodato A[maxtamc];
	int contador = 0;
	int frente = 0; 
	int final = 0;
	cout << "Desea agregar elementos a la cola? (s/n): ";
	char respuesta;
	cin >> respuesta;
	while ((respuesta == 's' || respuesta == 'S') && contador < 10) {
		ingresar_valores(frente, final, A, contador);

		if (contador < 10) {
			cout << "Desea agregar más elementos a la cola? (s/n): ";
			cin >> respuesta;
		}
	}
	if (frente == final) {
		cout << "La cola está vacia" << endl;
		return 1;
	}
	tipodato primerElemento = A[(frente + 1) % maxtamc];
	cout << "El primer elemento de la cola es: " << primerElemento << endl;
	eliminar_elemento(frente, final, contador);
	imprimir(frente, final, A);

	return 0; 
}