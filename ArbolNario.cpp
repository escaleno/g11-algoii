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

			NodoArbol* aux = this->getHermano(actual->getHijoIzq());
			nuevo->setPadre(actual);
			nuevo->setHermanoDer(NULL);
			aux->setHermanoDer(nuevo);
		}
	}
	actual=nuevo;
}

/********************************************************************************/

NodoArbol* ArbolNario::getHermano(NodoArbol* hijo)
{
    if(hijo->getHermanoDer()!=NULL)
    {
        return this->getHermano(hijo->getHermanoDer());
    }

    return hijo;
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
	else
	{
		actual=raiz;
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
void ArbolNario::buscarTag(NodoArbol* nodo,Lista<NodoArbol*>*& listaDeTag,string tag){

	if(nodo != NULL){
		if(nodo->getTag() == tag){
			listaDeTag->insert(nodo);
		}

		buscarTag(nodo->getHijoIzq(),listaDeTag,tag);
		buscarTag(nodo->getHermanoDer(),listaDeTag,tag);
	}
}

/*************************************************************************************************/
void ArbolNario::imprimir(NodoArbol* nodo, unsigned nivel){

	if (nodo)
	{

		//******bloque de operaciones a realizar en el nodo durante el recorrido******
		for (unsigned i=0; i<nivel; i++)
		{
			cout << "  " << "|";
		}
		cout << "->";
		cout << nodo->getTag();

		if (nodo->getHijoIzq())
		{
            nivel++;
		}
		else
		{
			cout << " = " << *(nodo->getContenido());
		}
		cout << endl;
		//*****fin del bloque*********************************************************
		imprimir(nodo->getHijoIzq(), nivel);
		//resto un nivel para no darle al hermano el nivel del hijo
		if (nodo->getHermanoDer()&& nodo->getHijoIzq())
		{
		    nivel--;
		}
		imprimir(nodo->getHermanoDer(), nivel);
	}

}


/*************************************************************************************************/

void ArbolNario::imprimirSinContenido(NodoArbol* nodo, unsigned nivel){

	if (nodo)
	{

		//******bloque de operaciones a realizar en el nodo durante el recorrido******
		for (unsigned i=0; i<nivel; i++)
		{
			cout << "  " << "|";
		}
		cout << "->";
		cout << nodo->getTag();

		if (nodo->getHijoIzq())
		{
            nivel++;
		}
		cout << endl;
		//*****fin del bloque*********************************************************
		imprimirSinContenido(nodo->getHijoIzq(), nivel);
		//resto un nivel para no darle al hermano el nivel del hijo
		if (nodo->getHermanoDer()&& nodo->getHijoIzq())
		{
		    nivel--;
		}
		imprimirSinContenido(nodo->getHermanoDer(), nivel);
	}

}

/*************************************************************************************************/

void ArbolNario::imprimirXML(NodoArbol* nodo, unsigned nivel){

	if (nodo)
	{

		//******bloque de operaciones a realizar en el nodo durante el recorrido******
		this->tabuladorXML(nivel);
		cout << "<";
		cout << nodo->getTag();
		cout << ">";

		if (nodo->getHijoIzq())
		{
            cout << endl;
            nivel++;

		}
		else
		{
			cout << *(nodo->getContenido());
		}
		//*****fin del bloque*********************************************************
		this->imprimirXML(nodo->getHijoIzq(), nivel);

		//Si tiene hijos agrego espacios para tabular xml
		if(nodo->getHijoIzq())
		{
            this->tabuladorXML(nivel-1);
		}
		//Cierro Tag de cada Hijo
		cout << "</";
        cout << nodo->getTag();
        cout << ">" << endl;

		if (nodo->getHermanoDer())
		{
            if (nodo->getHijoIzq())
            {
                nivel--;
            }
            this->imprimirXML(nodo->getHermanoDer(), nivel);
		}
	}

}

/*************************************************************************************************/

void ArbolNario::tabuladorXML(unsigned nivel)
{
    for (unsigned i=0; i<nivel; i++)
    {
			cout << "  " ;
    }
}

/*************************************************************************************************/
void ArbolNario::imprimir(string tag)
{
	NodoArbol* unNodo;
	Lista<NodoArbol*>* larbol = new Lista<NodoArbol*>();
	this->buscarTag(this->raiz,larbol,tag);
	if (!larbol->lista_vacia())
	{
		for(unsigned i=1; i<=larbol->get_tam() ;i++)
	    {
			unNodo = larbol->get_dato(i);
			if(unNodo->esHoja()){
	        	cout<<"->"<<unNodo->getTag()<<" = "<<*(unNodo->getContenido())<<endl;;
	        }else{
	        	cout<<"->"<<unNodo->getTag()<<endl;;
	        }
			this->imprimir(larbol->get_dato(i)->getHijoIzq(),1);
			cout<<endl;
	    }
	}else
	{
		cout<<"Tag inexistente!"<<endl;
	}
	delete larbol;
}

/*************************************************************************************************/
void ArbolNario::imprimirSoloTag(string tag)
{
	NodoArbol* unNodo;
	Lista<NodoArbol*>* larbol = new Lista<NodoArbol*>();
	this->buscarTag(this->raiz,larbol,tag);
	if (!larbol->lista_vacia())
	{
		for(unsigned i=1; i<=larbol->get_tam() ;i++)
	    {
			unNodo = larbol->get_dato(i);
	        cout<<"->"<<unNodo->getTag()<<endl;;

			this->imprimirSinContenido(larbol->get_dato(i)->getHijoIzq(),1);
			cout<<endl;
	    }
	}else
	{
		cout<<"Tag inexistente!"<<endl;
	}
	delete larbol;
}

/*************************************************************************************************/




