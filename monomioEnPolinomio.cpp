#include <iostream>
using namespace std;

struct Monomio {
    double coeficiente;
    int exponente;
};

int buscarMonomio(Monomio polinomio[], int n, Monomio buscado) {
    for (int i = 0; i < n; i++) {
        if (polinomio[i].coeficiente == buscado.coeficiente && polinomio[i].exponente == buscado.exponente) {
            return i; 
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Ingrese la cantidad de monomios en el polinomio: ";
    cin >> n;
    
    Monomio polinomio[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el coeficiente del monomio " << i+1 << ": ";
        cin >> polinomio[i].coeficiente;
        cout << "Ingrese el exponente del monomio " << i+1 << ": ";
        cin >> polinomio[i].exponente;
    }
    
    Monomio buscado;
    cout << "Ingrese el coeficiente del monomio a buscar: ";
    cin >> buscado.coeficiente;
    cout << "Ingrese el exponente del monomio a buscar: ";
    cin >> buscado.exponente;
    
    int posicion = buscarMonomio(polinomio, n, buscado);
    
    if (posicion != -1) {
        cout << "El monomio se encuentra en la posicion " << posicion << " del polinomio." << endl;
    } else {
        cout << "El monomio no forma parte del polinomio." << endl;
    }
    
    return 0;
}
