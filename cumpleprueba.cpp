#include <iostream>
#include <string>
using namespace std;

// Estructura para almacenar la fecha
struct Fecha {
    int dia;
    int mes;
    int anio;
};

// Estructura para almacenar la información del personal
struct Personal {
    string DNI;
    string nombres;
    Fecha fechaNacimiento;
};

// Función para comparar dos fechas: retorna -1 si f1 < f2, 1 si f1 > f2, y 0 si son iguales
int compararFechas(Fecha f1, Fecha f2) {
    if (f1.anio < f2.anio) return -1;
    if (f1.anio > f2.anio) return 1;
    if (f1.mes < f2.mes) return -1;
    if (f1.mes > f2.mes) return 1;
    if (f1.dia < f2.dia) return -1;
    if (f1.dia > f2.dia) return 1;
    return 0;
}

// Función de ordenación por inserción directa
void ordenarPorFechaNacimiento(Personal personal[], int n) {
    for (int i = 1; i < n; i++) {
        Personal actual = personal[i];
        int j = i - 1;
        
        // Insertar `actual` en la posición correcta comparando por fecha de nacimiento
        while (j >= 0 && compararFechas(actual.fechaNacimiento, personal[j].fechaNacimiento) < 0) {
            personal[j + 1] = personal[j];
            j--;
        }
        personal[j + 1] = actual;
    }
}

// Función de búsqueda binaria por fecha de nacimiento
int busquedaBinaria(Personal personal[], int n, Fecha fechaBusqueda) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        int comparacion = compararFechas(personal[medio].fechaNacimiento, fechaBusqueda);

        if (comparacion == 0) {
            return medio; // Fecha encontrada
        } else if (comparacion < 0) {
            inicio = medio + 1; // Buscar en la mitad derecha
        } else {
            fin = medio - 1; // Buscar en la mitad izquierda
        }
    }
    return -1; // Fecha no encontrada
}

// Función para mostrar los datos del personal
void mostrarPersonal(Personal p) {
    cout << "DNI: " << p.DNI 
         << ", Nombres: " << p.nombres 
         << ", Fecha de Nacimiento: " << p.fechaNacimiento.dia 
         << "/" << p.fechaNacimiento.mes 
         << "/" << p.fechaNacimiento.anio << endl;
}

int main() {
    // Crear un arreglo de personal con fechas de nacimiento
    Personal personal[] = {
        {"12345678", "Carlos Perez", {15, 5, 1990}},
        {"87654321", "Ana Lopez", {23, 12, 1985}},
        {"11223344", "Luis Gomez", {3, 9, 1992}},
        {"22334455", "Maria Sanchez", {7, 7, 1989}}
    };
    
    int n = sizeof(personal) / sizeof(personal[0]);

    // Ordenar el personal por fecha de nacimiento
    ordenarPorFechaNacimiento(personal, n);

    // Mostrar los datos ordenados
    cout << "Personal ordenado por fecha de nacimiento:\n";
    for (int i = 0; i < n; i++) {
        mostrarPersonal(personal[i]);
    }

    // Buscar una fecha de nacimiento
    Fecha fechaBusqueda = {7, 7, 1989}; // Fecha a buscar

    int indice = busquedaBinaria(personal, n, fechaBusqueda);

    if (indice != -1) {
        cout << "\nFecha encontrada:\n";
        mostrarPersonal(personal[indice]);
    } else {
        cout << "\nFecha no encontrada.\n";
    }

    return 0;
}

