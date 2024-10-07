#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include "usuario-bizi.hpp"
#include "uso-bizi.hpp"
#include "pedir-nombre-fichero.hpp"
using namespace std;
ifstream f;
const int NUM_LINEAS = 15;
const int COMPONENTES = 20;

/*
 * Pre: Dados un vector de registros de tipo UsuarioBizi y el número
 * de componentes utilizadas, busca a un usuario en concreto, determinado por
 * su identificador
 * Post: Devuelve el índice que ocupa en el vector, si dicho
 * usuario aparece en él, o un valor negativo (por ejemplo, −1) en caso contrario.
 */
unsigned int buscarUsuario(UsuarioBizi V[], const unsigned int usuario) {
    for(unsigned int i=0; i<COMPONENTES; i++) {
        if (V[i].IDUsuario == usuario) {
            return i;
        } else {
            return -1;
        }
    }
}

/*
 * Pre: Dados un vector de registros de tipo UsuarioBizi y el número
 * de componentes utilizadas, busca a un usuario en concreto, determinado por
 * su identificador
 * Post: Si el usuario está en el vector, la función debe devolver
 * su índice. En caso contrario, debe añadirlo al mismo en una componente no utilizada
 * del mismo y devolver el índice de la componente en la que lo ha añadido
 */
unsigned int posicionUsuario(UsuarioBizi V[], const unsigned int usuario) {
    for(unsigned int i=0; i<COMPONENTES; i++) {
        if (V[i].IDUsuario == usuario) {
            return i;
        } else {
            V[i].IDUsuario = usuario;
            return i;
        }
    }
} 

/*
 * Pre: Dados el nombre y ruta de acceso a un fichero de usos de Bizi
 * Post: almacene en las primeras componentes
 * de un vector de registros de tipo UsuarioBizi un resumen del número de usos que
 * cada usuario presente ha realizado en el fichero 
 */
bool obtenerUsosPorUsuario(UsuarioBizi V[], string& nombreRelativo, UsoBizi& uso) {
    int numUsuarios=0;
    ifstream f;
    f.open(nombreRelativo);
    if(f.is_open()) {
        string linea1;
        getline(f,linea1);
        while(leerUso(f,uso)) {
            unsigned int i=0;
            if(V[i].IDUsuario != V[i+1].IDUsuario) {
                numUsuarios++;
            }
            
            if(uso.AnclajeEstacion==uso.RetiroEstacion) {
                V[i].UsosCircular++;
            } else {
                V[i].UsosTraslado++;
            }
        } 
        f.close();
        return true;
    } else {
        return false;
    }
}

/*
 * Pre: --
 * Post: Ordena el contenido del vector de registros de tipo UsuarioBizi.
 */
void ordenarVector(UsuarioBizi V[]) {
    for(unsigned int i=0; i<COMPONENTES; i++) {
        if(numUsosTotales(V[i]) < numUsosTotales(V[i+1])) {
            i=i+1;
        }    
    intercambiar(V[i],V[i+1]);
    }
}

/*
 * Pre: --
 * Post: Escribe en pantalla los resultados
 */
void escribirResultados(UsuarioBizi usuario, int& numUsuarios) {
    cout << "Número usuarios distintos: " << numUsuarios << endl;
    cout << " Usuario  Traslados  Circular     Total" << endl;
    cout << "========= =========  =========   =========" << endl;
  
    for(unsigned int i=0; i<NUM_LINEAS; i++) {
        mostrar(usuario);
    }
}

int main() {
    UsoBizi uso;
    UsuarioBizi usuario;
    ifstream f;
    int numUsuarios;
    string nombreRelativo;
    pedirNombreFichero(nombreRelativo);
    UsuarioBizi V[]= {};
    if(obtenerUsosPorUsuario(V, nombreRelativo, uso)) {
        ordenarVector(V);
        escribirResultados(usuario, numUsuarios);
        return 0; 
    } else {
        return 1;
    }
}