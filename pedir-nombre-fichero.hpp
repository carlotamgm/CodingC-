/******************************************************************************\
 * Programación 1. Práctica 6
 * Autor: Miguel Ángel Latre Abadía
 * Última revisión: 15 de noviembre de 2020
 * Resumen: Fichero de interfaz «pedir-nombre-fichero.hpp» de un módulo que 
 *          declara una función denominada «pedirNombreFichero» que facilita la 
 *          labor de convertir el nombre de un fichero solicitado al usuario en 
 *          una ruta de acceso relativa al directorio de ejecución del proyecto 
 *          solicitado en esta tarea y en la siguiente. 
\******************************************************************************/

#pragma once

#include <string>
using namespace std;

const string RUTA_DATOS = "datos/";

/*
 * Pre:  ---
 * Post: Ha solicitado al usuario el nombre de un fichero de usos del sistema
 *       Bizi escribiendo en la pantalla el mensaje
 *       "Escriba el nombre de un fichero de usos del sistema Bizi: ",
 *       lo ha leído de teclado y ha asignado a «nombreRelativo» una ruta
 *       de acceso relativa al mismo, consistente en la concatenación de la 
 *       cadena «RUTA_DATOS» y el nombre de fichero leído de teclado.
 */
void pedirNombreFichero(string& nombreRelativo);
