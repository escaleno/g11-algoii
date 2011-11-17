#include "ArbolNario.h"

ArbolNario::ArbolNario()
{
    this->raiz = NULL;
    this->actual = NULL;
}

ArbolNario::~ArbolNario()
{
	this->LiberarMemoria(this->raiz);
}

bool ArbolNario::estaVacio()
{
    return (this->raiz==NULL && this->actual==NULL);
}

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

void ArbolNario::agregarContenido(string value)
{
    string* nuevCont = new string();
    *nuevCont=value;
    actual->setContenido(nuevCont);
}

void ArbolNario::volver()
{
    if (actual->getPadre()!=NULL)
    {
        actual=actual->getPadre();
    }
}

string ArbolNario::getTag()
{
    if(!this->estaVacio())
    {
        return actual->getTag();
    }
    return "";
}

NodoArbol* ArbolNario::buscar(/*TAG*/)
{
    cout << "Busca el TAG que se desea encontrar" << endl;
    return NULL;
}

void ArbolNario::imprimir(string tag)
{
    NodoArbol* buscado = this->buscar(this->raiz,tag);
    cout << "Tag encontrado: " << *(buscado->getContenido()) << endl ;


}

ArbolNario* ArbolNario::Subarbol(NodoArbol* nuevoSubarbol)
{
    ArbolNario* nuevoArbol = new ArbolNario;
    nuevoArbol->raiz = nuevoSubarbol;
    return nuevoArbol;

}
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
};


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

NodoArbol* ArbolNario::getRaiz(){
	return this->raiz;
}

