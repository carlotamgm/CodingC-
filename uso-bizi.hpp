/******************************************************************************\
 * Programación 1. Práctica 6
 * Autores: Miguel Ángel Latre
 * Modificado por: Carlota Moncasi
 * Ultima revisión: ¡¡¡!!!
 * Resumen: Fichero de interfaz «bizi-usos.hpp» de un módulo para trabajar con
 *          registros que representan usos del sistema Bizi Zaragoza.
\******************************************************************************/

#pragma once

#include <istream>
using namespace std;

struct UsoBizi {
    // Define los campos necesarios para representar los siguientes datos de un
    // uso del sistema Bizi: el identificador del usuario que utiliza la
    // bicicleta, el código de la estación de la que se retira la bicicleta y el
    // código de la estación en la que se devuelve.

    unsigned ID, AnclajeEstacion, RetiroEstacion;
};


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
bool leerUso(istream& f, UsoBizi& uso);


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
bool contarUsos(const string rutaFichero, 
                unsigned& traslados, unsigned& usosCirculares, UsoBizi& uso);
