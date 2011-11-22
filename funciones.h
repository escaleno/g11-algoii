#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <string>
#include "ArbolNario.h"

/*Conjunto de funciones utilizadas en el el menu principal*/

using namespace std;
/**************************************************************************************/

/*POST: muestra por pantalla las opciones disponible,pide el ingreso de una opcion
*y retorna la misma*/
unsigned opcionesMenu();

/**************************************************************************************/

/*POST:muestra las opciones del menu y ejecuta la accion solicitada*/
void menuPrincipal(ArbolNario* aXML);

/**************************************************************************************/

/*POST:solicita el ingreso de un tag, retorna el tag ingresado*/
string pideTag();

/**************************************************************************************/

/*POST:imprime en pantalla "presione cualquier tecla para continuar", hasta que se presione
 * cualquier tecla
 */
void mjePresioneCualquierTecla();

/**************************************************************************************/

#endif // FUNCIONES_H_INCLUDED
