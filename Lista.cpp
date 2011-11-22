#include "Lista.h"
// Constructor
/*template < typename Dato >
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
        nuevo->set_sig(primero);
    }
    primero = nuevo;
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
*/
