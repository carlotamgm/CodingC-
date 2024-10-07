#include <iostream>
#include <fstream>
#include <string>
#include "uso-bizi.hpp"
using namespace std;

/*
 * Pre:  El flujo «f» está asociado con un fichero de texto con el formato de 
 *       usos del sistema Bizi establecido en el enunciado y en disposición de
 *       leer desde el principio de una línea distinta a la de la cabecera.
 * Post: Ha intentado leer la línea mencionada en la precondición y, si no se
 *       han terminado los datos del fichero en dicho intento, ha almacenado en
 *       los campos del parámetro «uso» el identificador del usuario al que
 *       corresponde la utilización de la línea leída y los códigos de las
 *       estaciones de retirada y devolución de la bicicleta.
 *       Ha devuelto true si no se han terminado los datos del fichero en el
 *       intento de lectura y false en caso contrario.
 */
bool leerUso(istream& f, UsoBizi& uso) {
    string nada;
    getline(f, nada);
    while(!f.eof()) {
        f >> uso.ID;
        f.get();
        getline(f, nada, ';');
        f >> uso.RetiroEstacion;
        f.get();
        getline(f, nada, ';');
        f >> uso.AnclajeEstacion;
        return true; 
    }
    cout << "El fichero ha llegado a su fin" << endl; 
    return false;   
}

/*
 * Pre:  La cadena de caracteres «rutaFichero» representa la ruta de acceso y 
 *       el nombre de un fichero de texto con el formato de usos del sistema
 *       Bizi establecido en el enunciado.
 * Post: Si el fichero de nombre «rutaFichero» se ha podido abrir y leer
 *       correctamente, la función ha devuelto «true», «traslados» es el número
 *       de usos entre estaciones distintas del sistema Bizi Zaragoza contenidos
 *       en el fichero de nombre «rutaFichero» y «usosCirculares» es el número
 *       de usos contenidos en dicho fichero que tienen como origen y destino la
 *       misma estación. En caso contrario, la función ha devuelto «false».
 */
bool contarUsos(const string rutaFichero, unsigned& traslados, unsigned& usosCirculares,
        UsoBizi& uso) {
    ifstream f;
    string nada;
    
    f.open(rutaFichero);
    if(f.is_open()) {
        getline(f, nada);
        while(leerUso(f,uso)) {
            if((uso.RetiroEstacion)==(uso.AnclajeEstacion)) {
                usosCirculares++;
            } else {
                traslados++;
            }
        }
        f.close();
    } else {
        cerr << "No se ha podido acceder a \"" << rutaFichero << "\"" << endl;
        return false;
    }
    return true;
}
