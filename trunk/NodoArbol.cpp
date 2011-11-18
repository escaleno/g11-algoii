/*
 * NodoArbol.cpp
 *
 *  Created on: 11/11/2011
 *      Author: jlezcano
 */

#include "NodoArbol.h"
#include <iostream>

using namespace std;

/******************************************************************************/

NodoArbol::NodoArbol(string tag){

	this->tag = tag;
	this->contenido = NULL;
	this->hijoIzq = NULL;
	this->hermanoDer = NULL;
	this->padre = NULL;

	//cout<<"Se contruyo NodoArbol "<<(unsigned)this<<endl;

}
/******************************************************************************/
NodoArbol::~NodoArbol() {

	if (this->contenido!=NULL)
		delete this->contenido;
}

/******************************************************************************/

NodoArbol::NodoArbol(NodoArbol& otroNodo){

	otroNodo.tag = this->tag;
	otroNodo.contenido = this->contenido;
	otroNodo.hijoIzq = this->hijoIzq;
	otroNodo.hermanoDer = this->hermanoDer;
	otroNodo.padre = this->padre;
}

/******************************************************************************/

void NodoArbol::setTag(string tag){

	this->tag = tag;
}

/******************************************************************************/

string NodoArbol::getTag(){

	return (this->tag);
}
/******************************************************************************/

void NodoArbol::setContenido(string* contenido){

	this->contenido = contenido;
}

/******************************************************************************/

string* NodoArbol::getContenido(){

	return(this->contenido);
}

/******************************************************************************/

void NodoArbol::setHijoIzq(NodoArbol* unNodo){

	this->hijoIzq = unNodo;
}

/******************************************************************************/

NodoArbol* NodoArbol::getHijoIzq(){

	return (this->hijoIzq);
}

/******************************************************************************/

void NodoArbol::setHermanoDer(NodoArbol* unNodo){

	this->hermanoDer = unNodo;
}
/******************************************************************************/

NodoArbol* NodoArbol::getHermanoDer(){

	return (this->hermanoDer);
}

/******************************************************************************/


void NodoArbol::setPadre(NodoArbol* nuevoPadre){

	this->padre = nuevoPadre;
}

/******************************************************************************/

NodoArbol* NodoArbol::getPadre(){

	return this->padre;
}


/******************************************************************************/

bool NodoArbol::esHoja(){

	return (this->hijoIzq == NULL);
}




