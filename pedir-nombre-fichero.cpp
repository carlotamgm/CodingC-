#include <iostream>
#include <string>
#include "pedir-nombre-fichero.hpp"
using namespace std;

/*
 * Pre:  ---
 * Post: Ha solicitado al usuario el nombre de un fichero de usos del sistema
 *       Bizi escribiendo en la pantalla el mensaje
 *       "Escriba el nombre de un fichero de usos del sistema Bizi: ",
 *       lo ha leído de teclado y ha asignado a «nombreRelativo» una ruta
 *       de acceso relativa al mismo, consistente en la concatenación de la 
 *       cadena «RUTA_DATOS» y el nombre de fichero leído de teclado.
 */
void pedirNombreFichero(string& nombreRelativo) {
    cout << "Escriba el nombre de un fichero de usos del sistema Bizi:" << endl;
    cin >> nombreRelativo;
    nombreRelativo = RUTA_DATOS + nombreRelativo;
}