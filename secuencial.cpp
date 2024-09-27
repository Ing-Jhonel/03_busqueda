#include <iostream>
using namespace std;

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
			cout << endl << "Elemento a buscar = " << valor << endl;
		}
		switch(opcion){
			case 'a':
				break;
			case 'b':
				break;
			case 'c':
				break;
			default:
				break;
		}
		cout << endl << endl;
		system("pause");
	} while(opcion!='c');
	return 0;
}
