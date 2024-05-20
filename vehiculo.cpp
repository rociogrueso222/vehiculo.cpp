#include <iostream>
#include <stdlib.h>
using namespace std;

// Definición de la estructura para representar un vehículo
struct Vehiculo {
    int tipo; // 0 para auto, 1 para moto
    int codigo;
    struct Vehiculo *sig;
};

struct Vehiculo *cabecera, *nuevo, *aux, *aux2;

// Variables para almacenar el dinero total por tipo de vehículo
int dineroAutos = 0;
int dineroMotos = 0;

void registrar() {
    nuevo = (struct Vehiculo *) malloc(sizeof(struct Vehiculo));
    cout << "Tipo de vehículo (0 para auto, 1 para moto): ";
    cin >> nuevo->tipo;
    cout << "Código: ";
    cin >> nuevo->codigo;
    nuevo->sig = NULL;
    
    if (cabecera == NULL) {
        cabecera = nuevo;
    } else {
        nuevo->sig = cabecera;
        cabecera = nuevo;
    }

    // Calcular el costo de parqueo y acumular dinero por cada tipo de vehículo
    if (nuevo->tipo == 0) {
        dineroAutos += 6000; // 5000 + 1000 por movimiento
    } else if (nuevo->tipo == 1) {
        dineroMotos += 3000; // 2500 + 500 por movimiento
    }
}

void mostrar() {
    for (aux = cabecera; aux != NULL; aux = aux->sig) {
        cout << "Código: " << aux->codigo << endl;
        cout << "Tipo de vehículo: " << (aux->tipo == 0 ? "Auto" : "Moto") << endl << endl;
    }
}

int main() {
    int opcion = 0;
    do {
        cout << "1. Registrar vehículo" << endl;
        cout << "2. Ver vehículos" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                registrar();
                break;
            case 2:
                mostrar();
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 3);

    // Mostrar el dinero total por cada tipo de vehículo
    cout << "Dinero total por autos: " << dineroAutos << endl;
    cout << "Dinero total por motos: " << dineroMotos << endl;

    return 0;
}
