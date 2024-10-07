#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void copiarFichero(const string nombreFichero, const string nombreCopia, const int filas) {
    ifstream original; // Declara un flujo de entrada
    original.open(nombreFichero); // Lo asocia con el fichero «nombreFichero»
    if (original.is_open()) {
        ofstream copia; // Declara un flujo de salida
        copia.open(nombreCopia); // Lo asocia con el fichero «nombreCopia»
        if (copia.is_open()) {
            string linea;
            for (unsigned i = 0; i < filas; i++) {
                getline(original,linea);
                // Mientras se leen los datos del flujo y la última lectura es correcta
                // Se procesa el último dato leído: se escribe en «copia»
                copia << linea << endl;
            }
            copia.close(); // Disocia el flujo y el fichero externo
    } else {
        cerr << "No se ha podido escribir en \"" << nombreCopia << "\"."
        << endl;
    }
    original.close(); // Disocia el flujo y el fichero externo
    } else {
        cerr << "No se ha podido acceder a \"" << nombreFichero << "\"." << endl;
    }
}

int main () {
    copiarFichero("datos/usos-16.csv", "datos/pruebas-10.csv", 10);
    copiarFichero("datos/usos-17.csv", "datos/pruebas-2000.csv", 2000);
    return 0;
}