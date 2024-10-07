#include <iostream>
#include <fstream>
#include <string>
#include "uso-bizi.hpp"
#include "pedir-nombre-fichero.hpp"
using namespace std;

 
int main() {
    UsoBizi uso;
    unsigned int traslados=0, usosCirculares=0;
    string nombreRelativo;
    pedirNombreFichero(nombreRelativo);
    if(contarUsos(nombreRelativo, traslados, usosCirculares, uso)) {  
        cout << "Número de usos como traslado: " << endl;
        cout << traslados << endl;
        cout << "Número de usos circulares: " << endl;
        cout << usosCirculares << endl;
        cout << "Número total de usos: " << endl;   
        cout << usosCirculares + traslados << endl;
        return 0;
    } else {
        return 1;
    }
}