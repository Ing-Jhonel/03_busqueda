#include <iostream>
using namespace std;

struct Fecha {
    int dia, mes, anio;
};

struct PersonaDatos {
    int DNI;
    string nombres;
    Fecha fechaNacimiento;
};

int compararFechas(Fecha f1, Fecha f2) {
    if (f1.anio < f2.anio) return -1;
    if (f1.anio > f2.anio) return 1;
    if (f1.mes < f2.mes) return -1;
    if (f1.mes > f2.mes) return 1;
    if (f1.dia < f2.dia) return -1;
    if (f1.dia > f2.dia) return 1;
    return 0;
}

void ordenarPorFechaNacimiento(PersonaDatos personal[], int n) {
    for (int i = 1; i < n; i++) {
        PersonaDatos actual = personal[i];
        int j = i - 1;
        
        while (j >= 0 && compararFechas(actual.fechaNacimiento, personal[j].fechaNacimiento) < 0) {
            personal[j + 1] = personal[j];
            j--;
        }
        personal[j + 1] = actual;
    }
}

int busquedaBinaria(PersonaDatos personal[], int n, Fecha fechaBusqueda) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        int comparacion = compararFechas(personal[medio].fechaNacimiento, fechaBusqueda);

        if (comparacion == 0) {
            return medio;
        } else if (comparacion < 0) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1;
}

void mostrarPersonal(PersonaDatos p) {
    cout << "DNI: " << p.DNI 
         << ", Nombres: " << p.nombres 
         << ", Fecha de Nacimiento: " << p.fechaNacimiento.dia 
         << "/" << p.fechaNacimiento.mes 
         << "/" << p.fechaNacimiento.anio << endl;
}

int main() {
    int total = 100;
    PersonaDatos personal[total];
    
    int n;
    cout << "Indique la cantidad de personal: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << endl << i + 1 << ". persona" << endl << endl;
        cout << "DNI: ";
        cin >> personal[i].DNI;
        cout << "Nombres: ";
        cin.ignore();
        getline(cin, personal[i].nombres);
        cout << endl << "Nacimiento" << endl << endl;
        cout << "Dia: ";
        cin >> personal[i].fechaNacimiento.dia;
        cout << "Mes: ";
        cin >> personal[i].fechaNacimiento.mes;
        cout << "Anio: ";
        cin >> personal[i].fechaNacimiento.anio;
    }

    ordenarPorFechaNacimiento(personal, n);

    cout << "\nPersonal ordenado por fecha de nacimiento:\n";
    for (int i = 0; i < n; i++) {
        mostrarPersonal(personal[i]);
    }

    Fecha fechaBusqueda;
    cout << endl << "Indique la fecha de nacimiento que busca:\n";
    cout << "Dia: ";
    cin >> fechaBusqueda.dia;
    cout << "Mes: ";
    cin >> fechaBusqueda.mes;
    cout << "Anio: ";
    cin >> fechaBusqueda.anio;
    cout << endl;

    int indice = busquedaBinaria(personal, n, fechaBusqueda);

    if (indice != -1) {
        cout << "\nFecha encontrada:\n";
        mostrarPersonal(personal[indice]);
    } else {
        cout << "\nFecha no encontrada.\n";
    }

    return 0;
}

