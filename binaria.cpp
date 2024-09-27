#include <iostream>
using namespace std;

int binaria(double a[], int, double);
void interDirDer(double a[], int);
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
	
	double valor;
	char buscar;
	do{
		cout << "Arreglo original: "; imprimir(arr, tamanio); cout << endl;
		interDirDer(copia, tamanio);
		cout << "Arreglo ordenado: "; imprimir(copia, tamanio); cout << endl;
		cout << "Indique el elemento a buscar con busqueda binaria: ";
		cin >> valor;
		cout << "Posicion del elemento: " << binaria(copia, tamanio, valor) << endl << endl;
		cout << "¿Desea buscar mas?(s/n): ";
		cin >> buscar;
		cout << endl;
	} while(buscar!='n');
	return 0;

}

int binaria(double a[], int n, double dato){
	
	int izq=0;
	int der=n-1;
	int cen=0, m, pos;
	
	while(izq<=der && cen==0){
		m=(izq+der)/2;
		if(a[m]==dato){	
			cen=1;
		} else if(a[m]<dato){
			izq=m+1;
		} else {
			der=m-1;
		}
	}
	if(cen==1){
		pos=m;
	}else{
		pos=-izq;
	}
	return pos;
}

void interDirDer(double a[], int n){
	
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(a[j]>a[j+1]){
				double aux=a[j];
				a[j]=a[j+1];
				a[j+1]=aux;
			}
		}
	}
}

void imprimir(double a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
