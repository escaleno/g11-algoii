#include "ArbolNario.h"
#include <iostream>

using namespace std;

/*************************************************************************************************/
ArbolNario::ArbolNario()
{
	this->raiz = NULL;
	this->actual = NULL;
}

/*************************************************************************************************/
void ArbolNario::LiberarMemoria (NodoArbol *Ptr)
{
	//Caso base. El puntero no apunta a ningún nodo. No hacemos nada.
	//Caso recursivo. El puntero apunta al menos a un nodo. Eliminamos recursivamente
	//todos los nodos.
	if (Ptr != NULL)
	{
		LiberarMemoria (Ptr -> getHijoIzq());
		LiberarMemoria (Ptr -> getHermanoDer());
		delete (Ptr);
	}
}

/*************************************************************************************************/
ArbolNario::~ArbolNario()
{
	this->LiberarMemoria(this->raiz);
}

/*************************************************************************************************/
NodoArbol* ArbolNario::getRaiz(){
	return this->raiz;
}

/*************************************************************************************************/
bool ArbolNario::estaVacio()
{
	return (this->raiz==NULL && this->actual==NULL);
}

/*************************************************************************************************/
bool ArbolNario::existeTag(string tag)
{
	NodoArbol* aux=actual;
	if (!this->estaVacio())
	{
		while(aux->getPadre()!=NULL)
		{
			if(aux->getTag()==tag)
			{
				return true;
			}
			aux=aux->getPadre();
		}

		if(aux->getTag()==tag)
		{
			return true;
		}
	}
	return false;
}

/*************************************************************************************************/
void ArbolNario::agregar(string tag)
{
	NodoArbol* nuevo = new NodoArbol(tag);
	if(this->estaVacio())
	{
		nuevo->setHermanoDer(NULL);
		nuevo->setPadre(NULL);
		nuevo->setHijoIzq(NULL);
		raiz=nuevo;
	}
	else
	{
		if (actual->getHijoIzq()==NULL)
		{
			nuevo->setHermanoDer(NULL);
			nuevo->setPadre(actual);
			actual->setHijoIzq(nuevo);
		}
		else
		{
			nuevo->setPadre(actual);
			nuevo->setHermanoDer(actual->getHijoIzq());
			actual->setHijoIzq(nuevo);
		}
	}
	actual=nuevo;
}

/*************************************************************************************************/
void ArbolNario::agregarContenido(string value)
{
	string* nuevCont = new string();
	*nuevCont=value;
	actual->setContenido(nuevCont);
}

/*************************************************************************************************/
void ArbolNario::volver()
{
	if (actual->getPadre()!=NULL)
	{
		actual=actual->getPadre();
	}
}

/*************************************************************************************************/
string ArbolNario::getTag()
{
	if(!this->estaVacio())
	{
		return actual->getTag();
	}
	return "";
}

/*************************************************************************************************/
/*Lista<NodoArbol*>* ArbolNario::buscarTag(NodoArbol* nodo,Lista<NodoArbol*>*& listaDeTag,string tag){

	if(nodo != NULL){
		if(nodo->getTag() == tag){
			listaDeTag->agregar(nodo);
		}

		buscarTag(nodo->getHijoIzq(),listaDeTag,tag);
		buscarTag(nodo->getHermanoDer(),listaDeTag,tag);
	}

	return listaDeTag;
}*/

/*************************************************************************************************/
void ArbolNario::imprimir(NodoArbol* nodo, unsigned * nivel){

	if (nodo != 0) {

		//******bloque de operaciones a realizar en el nodo durante el recorrido******
		for (unsigned i=0; i<*nivel; i++)
		{
			cout << '\t' << "|";
		}
		cout << "->";
		cout << nodo->getTag();

		if (nodo->getHijoIzq()) *nivel+=1;
		else
		{
			if ((!nodo->getHermanoDer())&&(*nivel !=0)) *nivel-=1;
			cout << " = " << *(nodo->getContenido());
		}
		cout << endl;
		//*****fin del bloque*********************************************************
		imprimir(nodo->getHijoIzq(), nivel);
		imprimir(nodo->getHermanoDer(), nivel);



	}

}

/*************************************************************************************************/
void ArbolNario::imprimir(string tag)
{
	NodoArbol* buscado = this->buscar(this->raiz,tag);
	cout << "Tag encontrado: " << *(buscado->getContenido()) << endl ;


}

/*************************************************************************************************/
ArbolNario* ArbolNario::Subarbol(NodoArbol* nuevoSubarbol)
{
	ArbolNario* nuevoArbol = new ArbolNario;
	nuevoArbol->raiz = nuevoSubarbol;
	return nuevoArbol;

}

/*************************************************************************************************/
NodoArbol* ArbolNario::buscar(NodoArbol* raiz,string valor){


	if(raiz->esHoja()){
		if (raiz->getTag() == valor) return raiz;
		else
			return 0;
	}


	NodoArbol* nodo = 0;
	NodoArbol* hijo = raiz->getHijoIzq();

	while(hijo && !nodo){ //tiene hijo y no encontro
		nodo = buscar(hijo,valor);
		hijo = hijo->getHermanoDer();
	}


	if((!nodo) && (raiz->getTag() == valor)) //verifica que sea la raiz
		nodo = raiz;

	return nodo;
}

/*************************************************************************************************/


