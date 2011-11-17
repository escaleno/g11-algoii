/*
 * NodoArbol.h
 *
 *  Created on: 11/11/2011
 *      Author: jlezcano
 */


/*NodoArbol modela cada nodo de un arbol n-ario, cada nodo esta formado por un puntero al primer hijo de la izquierda, un puntero al primer
 * hermano mas a la derecha y un puntero al padre.
 *
 * REFERENCIAS:
 * tag:es el nombre de una etiqueta leida de un archivo xml, no contiene espacios
 * contenido:es una variable puntero a string en donde se guarda el contenido propiamente dicho
 */


#ifndef NODOARBOL_H_
#define NODOARBOL_H_

#include <fstream>
#include <iostream>
using namespace std;

class NodoArbol {

private:
		 string tag; //tag proveniente del xml
		 string* contenido; //contenido de la hoja
		 NodoArbol* hijoIzq;  //puntero hijo izquierdo
		 NodoArbol* hermanoDer; //puntero hermano derecho
		 NodoArbol* padre; //puntero al padre
public:

		 /*************************************************************************************************/

		 /*POST:creal el nodo con el tag llamado "tag", y setea el contenido con el puntero "contenido"*/
		 NodoArbol(string tag);

		 /*************************************************************************************************/

		 /*POST:libera los recursos utilizados por la instancia*/
		 ~NodoArbol();

		 /*************************************************************************************************/
		 /*POST:constructor de copia*/
		 NodoArbol(NodoArbol& otroNodo);

		 /*************************************************************************************************/

		 /*POST:asigna el valor "tag" al nodo*///NO CREO QUE QUE LO USEMOS YA QUE ESTA EL CONSTRUCTOR 1 QUE ASIGNA EL TAG
		 void setTag(string tag);

		 /*************************************************************************************************/

		 /*POST:retorna el valor del tag*/
		 string getTag();

		 /*************************************************************************************************/

		 /*PRE:asigna el puntero "contenido" al contenido del nodo*/
		 void setContenido(string* contenido);

		 /*************************************************************************************************/

		 /*POST:retorna un puntero al contenido*/
		 string* getContenido();

		 /*************************************************************************************************/

		 /*POST: asigna unNodo como hijo izquierdo*/
		 void setHijoIzq(NodoArbol* unNodo);

		 /*************************************************************************************************/
		 /*POST:retorna un puntero al hijo izquierdo*/
		 NodoArbol* getHijoIzq();

		 /*************************************************************************************************/

		 /*POST:asigna unNodo como hermano derecho*/
		 void setHermanoDer(NodoArbol* unNodo);

		 /*************************************************************************************************/
		 /*POST:retorna un puntero al hermano derecho*/
		 NodoArbol* getHermanoDer();

		 /*************************************************************************************************/

		/*POST:asigna nuevoPadre como padre*/
		 void setPadre(NodoArbol* nuevoPadre);
		 /*************************************************************************************************/

		 /*POST:retorna un puntero al padre*/
		 NodoArbol* getPadre();

		 /*************************************************************************************************/
		 bool esHoja();

};

#endif /* NODOARBOL_H_ */
