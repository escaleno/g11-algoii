#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
template < typename Dato >

class Nodo
{
  private:
    Dato dato; // Dato a almacenar
    Nodo* psig; // Puntero a otro nodo
  public:
    // Constructor con parametro
    // PRE: Ninguna
    // POST: Crea un nodo con el dato d
    // y el puntero a NULL
    Nodo(Dato d);
    // Destructor
    // PRE: Nodo creado
    // POST: No hace nada
    ~Nodo();
    // Setea el dato (lo cambia)
    // PRE: el nodo tiene que estar creado
    // d tiene que ser un dato válido
    // POST: el nodo queda con el dato d
    void set_dato(Dato d);
    // Setear el puntero al siguiente nodo
    // PRE: nodo creado y ps válido
    // POST: el puntero al siguiente apuntará a ps
    void set_sig(Nodo* ps);
    // Obtener el dato
    // PRE: nodo creado
    // POST: devuelve el dato que contiene el nodo
    Dato get_dato();
    // Obtener el puntero al nodo siguiente
    // PRE: nodo creado
    // POST: Devuelve el puntero al siguiente nodo
    // si es el último devuelve NULL
    Nodo* get_sig();
    // ¿Hay un siguiente?
    // PRE: nodo creado
    // POST: V si tiene sig. F sino
    bool tiene_sig();
};

// Constructor con parametro
template < typename Dato >
Nodo<Dato>::Nodo(Dato d)
{
    dato = d;
    psig = 0;
}
// Destructor
template < typename Dato >
Nodo<Dato>::~Nodo()
{
// No hace nada
}
// Setear el dato
template < typename Dato >
void Nodo<Dato>::set_dato(Dato d)
{
    dato = d;
}
// Setear el ptr al sig
template < typename Dato >
void Nodo<Dato>::set_sig(Nodo* ps)
{
    psig = ps;
}
// Devolver el dato
template < typename Dato >
Dato Nodo<Dato>::get_dato()
{
    return dato;
}
// Devolver el siguiente
template < typename Dato >
Nodo<Dato>* Nodo<Dato>::get_sig()
{
    return psig;
}
// Tiene siguiente?
template < typename Dato >
bool Nodo<Dato>::tiene_sig()
{
    return (psig != 0);
}

#endif
