#include "arbolNario.h"

ArbolNario::ArbolNario()
{
    this->raiz = NULL;
}

bool ArbolNario::estaVacio()
{
    return (this->raiz==NULL);
}

ArbolNario* Subarbol(NodoArbol* nuevoSubarbol)
{
    ArbolNario* nuevoArbol = new ArbolNario;
    nuevoArbol->raiz = nuevoSubarbol;
    return nuevoArbol;

}
