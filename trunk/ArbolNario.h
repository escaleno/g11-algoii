#ifndef ARBOLNARIO_H
#define ARBOLN-ARIO_H

#include "NodoArbol.h"


class ArbolNario
{
    private:
        NodoArbol* raiz;

    public:
        /*************************************************************************************************/

        /*POST:creal el arbol con la raíz apuntando a NULL*/
        ArbolNario();

        /*************************************************************************************************/

        /*POST: elimina el arbol y libera memoria*/
        virtual ~ArbolNario();

        /*************************************************************************************************/

       /*POST: Fevuelve TRUE si el arbol esá vacío y FALSE si la raíz apunta a algo*/
        bool estaVacio();

        /*************************************************************************************************/

       /*POST: Carga TODOS los datos del archivo en el arbol*/
        bool cargar(/*ArchivoXML*/);

        /*************************************************************************************************/

        /*POST: Devuelve el puntero al subárbol que empieza en el nodo en el que se halló el valor o NULL si no se halló el valor*/
        NodoArbol* buscar(/*TAG*/);

        /*************************************************************************************************/

        /*POST: salida del árbol por pantalla*/
        void imprimir();

        /*************************************************************************************************/
        /*POST: Crea un subarbol a partir del nodo que se la pase como parámetro. No sé bien si va a servir esto. Capaz sea útil para
        las funciones imprimir y para implementar de alguna forma recursiva la función buscar().*/
        ArbolNario* Subarbol(NodoArbol*);







};

#endif // ARBOL N-ARIO_H
