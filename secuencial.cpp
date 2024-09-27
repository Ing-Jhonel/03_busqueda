#include <iostream>
using namespace std;

int secuencialDes(double a[], int, double);
void imprimir(double a[], int);

int main(){
	
	int tamanio;
	cout << "Indique el tamanio del arreglo: ";
	cin >> tamanio;
	double arr[tamanio];
	double copia[tamanio];
	for(int i=0; i<tamanio; i++){
		cout << i+1 << ". elemento: ";
		cin >> arr[i];
		copia[i]=arr[i];
	}
	
	char opcion;
	do{
		system("cls");
		double valor;
		cout << "Indique el elemento a buscar: ";
		cin >> valor;
		cout << endl << "Elija el tipo de busqueda secuencial" << endl << endl;
		cout << "a) Secuencial Desordenada" << endl;
		cout << "b) Secuencial Ordenada" << endl;
		cout << "c) Salir" << endl << endl;
		cin >> opcion;	
		
		system("cls");
		if(opcion=='a' || opcion=='b'){
			cout << "Arreglo: ";
			imprimir(arr, tamanio);
			cout << endl << "Elemento a buscar = " << valor << endl;
		}
		switch(opcion){
			case 'a':
				cout << "Posicion del elemento: ";
				cout << secuencialDes(arr, tamanio, valor);
				break;
			case 'b':
				break;
			case 'c':
				cout << "Saliendo..." << endl;
				break;
			default:
				cout << "Numero invalido";
				break;
		}
		cout << endl << endl;
		system("pause");
	} while(opcion!='c');
	return 0;
}

int secuencialDes(double a[], int n, double dato){
	int pos=-1;
	int i=0;
	while(i<n && a[i]!=dato){
		i++;
	}
	if(i<n){
		pos=i;
	}
	return pos;
}

void imprimir(double a[], int n){
	
	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
}