#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "usuario-bizi.hpp"
using namespace std;

/*
 * Pre:  ---
 * Post: Ha devuelto el número total de usos del sistema Bizi
 *       correspondiente a «usuario».
 */
unsigned numUsosTotales(const UsuarioBizi usuario) {
    return usuario.UsosTraslado + usuario.UsosCircular;
}

/*
 * Pre:  usuario1 = X y usuario2 = Y
 * Post: usuario1 = Y y usuario2 = X
 */
void intercambiar(UsuarioBizi& usuario1, UsuarioBizi& usuario2) {
    UsuarioBizi aux;
    aux=usuario2;
    usuario2=usuario1;
    usuario1=aux;
    
}

/*
 * Pre:  ---
 * Post: Ha escrito una línea en la pantalla que contiene la información del
 *       registro «usuario» (identificador, número de usos entre estaciones
 *       distintas, número de usos entre la misma estación y número de usos
 *       totales), escrita en ese orden y utilizando un mínimo de 10 caracteres.
 */
void mostrar(const UsuarioBizi usuario) {
    cout << right << setw(10) << usuario.IDUsuario << right << setw(10) << usuario.UsosTraslado 
            << right << setw(10) << usuario.UsosCircular << right << setw(10) << numUsosTotales(usuario) << endl;
}
