/*
 * NodoArbol.h
 *
 *  Created on: 11/11/2011
 *      Author: jlezcano
 */


/*NodoArbol modela cada nodo de un arbol n-ario cada nodo esta compuesto por una puntero a hijo
 * mas a la izquierda y por un puntero a su hermano mas a la derecha, en el caso de que no tenga hermano a la derecha
 * apunta a su padre
 *
 * REFERENCIAS:
 * tag:es el nombre de una etiqueta leida de un archivo xml, no contiene espacios
 * contenido:es una variable puntero a string en donde se guarda el contenido propiamente dicho
 */


#ifndef NODOARBOL_H_
#define NODOARBOL_H_

#include <string>

using namespace std;

class NodoArbol {

private:
		 string tag; //tag proveniente del xml
		 string* contenido; //contenido de la hoja
		 NodoArbol* hijoIzq;  //hijo izquierdo
		 NodoArbol* hermanoDer; //hermano derecho
		 bool punteroAlPadre; /*si no tiene hermano derecho apunta al padre entonces esta
		 	 	 	 	 	  variable vale TRUE, en caso que tenga hermano derecho vale FALSE*/
public:

		 /*************************************************************************************************/

		 /*POST:creal el nodo con el tag llamado "tag", y setea el contenido con el puntero "contenido"*/
		 NodoArbol(string tag,string* contenido);

		 /*************************************************************************************************/

		 /*POST:libera los recursos utilizados por la instancia*/
		 ~NodoArbol();

		 /*************************************************************************************************/
		 /*POST:constructor de copia*/
		 NodoArbol(const NodoArbol& otroNodo);

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

		 /*POST:retorna TRUE si el puntero al hermano derecho apunta al padre, FALSE de lo contrario*/
		 bool esPunteroAlPadre();

		 /*************************************************************************************************/

};

#endif /* NODOARBOL_H_ */
