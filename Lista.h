#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"

template < typename Dato >
class Lista
{
  private:
    // Primer elemento de la lista
    Nodo<Dato>* primero;
    // Tamaño de la lista
    unsigned tam;
  public:
    // Constructor
    // PRE: Ninguna
    // POST: construye una lista vacía
    // - primero apunta a nulo
    // - tam = 0
    Lista();
    // Destructor
    // PRE: Lista creada
    // POST: Libera todos los recursos de la lista
    ~Lista();
    // Agregar un elemento a la lista
    // PRE: lista creada y d válido
    // POST: agrega un dato dentro de un nodo al principio
    // - modifica el primero
    // - tam se incrementa en 1
    void insert(Dato d);
    // Obtener el tamaño de la lista
    // PRE: Lista creada
    // POST: devuelve el tamaño de la lista (cantidad de nodos)
    unsigned get_tam();
    // Obtener el dato que está en la posición pos
    // PRE: - lista creada y no vacía
    // - 0 < pos <= tam
    // POST: devuelve el dato que está en la posición pos
    // se toma 1 como el primero
    Dato get_dato(unsigned pos);
    // ¿Lista vacia?
    // PRE: Lista creada
    // POST: T si es vacia, F sino
    bool lista_vacia();
    // Borrado del nodo que está en la posición pos
    // PRE: - lista creada y no vacía
    // - 0 < pos <= tam
    // POST: libera el nodo que está en la posición pos
    // se toma 1 como el primero
    void del_dato(unsigned pos);
  private:
    // PRE: Lista con datos
    // POST: obtiene el ultimo nodo
    Nodo<Dato>* getUltimo(Nodo<Dato>* d);
};

template < typename Dato >
Lista<Dato>::Lista()
{
    primero = 0;
    tam = 0;
}
// Destructor
template < typename Dato >
Lista<Dato>::~Lista()
{
    while (!this->lista_vacia())
    {
        this->del_dato(1);
    }
}
// Devuelve T si la lista esta vacia
// Sino F
template < typename Dato >
bool Lista<Dato>::lista_vacia()
{
    return (tam == 0);
}
// Colocar, al principio, un nuevo nodo con el dato d
template < typename Dato >
void Lista<Dato>::insert(Dato d)
{
    Nodo<Dato>* nuevo = new Nodo<Dato>(d);
    if (!(this->lista_vacia()))
    {
        Nodo<Dato>* aux = this->getUltimo(this->primero);
        aux->set_sig(nuevo);
    }
    else
    {
        primero = nuevo;
    }
    tam++;
}
// Devuelve el dato que esta en la posición pos
template < typename Dato >
Dato Lista<Dato>::get_dato(unsigned pos)
{
    Nodo<Dato>* aux = primero;
    if (!lista_vacia())
    {
        for (unsigned cont = 1; (cont < pos && aux); cont++)
            aux = aux->get_sig();
        return aux->get_dato();
    }
    return 0;
}
// Devuelve la cantidad de nodos de la Lista
template < typename Dato >
unsigned Lista<Dato>::get_tam()
{
    return tam;
}
// Elimina el dato que esta en la posición pos
template < typename Dato >
void Lista<Dato>::del_dato(unsigned pos)
{
    Nodo<Dato>* aux = primero;
    if (!lista_vacia())
    {
        if (pos == 1)
        {
            primero = primero->get_sig();
        }
        else
        {
            for (unsigned cont = 0; (cont < pos-1 && aux->get_sig()); cont++)
                aux = aux->get_sig();
            aux->set_sig(aux->get_sig());
        }
        Nodo<Dato>* borrar = aux;
        delete borrar;
        tam--;
    }
}

//Busca el ultimo nodo
template < typename Dato >
Nodo<Dato>* Lista<Dato>::getUltimo(Nodo<Dato>* nodo)
{
    if(nodo->get_sig())
    {
        return this->getUltimo(nodo->get_sig());
    }
    else
    {
        return nodo;
    }
}

#endif
