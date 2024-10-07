/******************************************************************************\
 * Programación 1. Práctica 6
 * Autores: Miguel Ángel Latre
 * Modificado por: Carlota Moncasi
 * Ultima revisión: ¡¡¡!!!
 * Resumen: Fichero de interfaz «usuario-bizi.hpp» de un módulo para trabajar
 *          con registros que permiten contabilizar el número de usos que cada
 *          usuario hace del sistema Bizi.
\******************************************************************************/

#pragma once 

struct UsuarioBizi {
    // Define los campos necesarios para representar los siguientes datos de un
    // usuario del sistema Bizi: su identificador de usuario, el número de usos
    // entre estaciones distintas realizadas por ese usuario y el número de usos
    // entre la misma estación.

   unsigned IDUsuario, UsosTraslado, UsosCircular;
};


/*
 * Pre:  ---
 * Post: Ha devuelto el número total de usos del sistema Bizi
 *       correspondiente a «usuario».
 */
unsigned numUsosTotales(const UsuarioBizi usuario);


/*
 * Pre:  usuario1 = X y usuario2 = Y
 * Post: usuario1 = Y y usuario2 = X
 */
void intercambiar(UsuarioBizi& usuario1, UsuarioBizi& usuario2);


/*
 * Pre:  ---
 * Post: Ha escrito una línea en la pantalla que contiene la información del
 *       registro «usuario» (identificador, número de usos entre estaciones
 *       distintas, número de usos entre la misma estación y número de usos
 *       totales), escrita en ese orden y utilizando un mínimo de 10 caracteres.
 */
void mostrar(const UsuarioBizi usuario);
