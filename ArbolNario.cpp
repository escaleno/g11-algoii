#include "ArbolNario.h"

ArbolNario::ArbolNario()
{
    this->raiz = NULL;
    this->actual = NULL;
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

void ArbolNario::imprimir()
{
    cout << "Imprime el Contenido del XML" << endl;
}

ArbolNario* ArbolNario::Subarbol(NodoArbol* nuevoSubarbol)
{
    ArbolNario* nuevoArbol = new ArbolNario;
    nuevoArbol->raiz = nuevoSubarbol;
    return nuevoArbol;

}
void ArbolNario::borrar()
{
    cout << "Borra los TAG del Arbol!!!" << endl;
}
