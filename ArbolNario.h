#ifndef ARBOLNARIO_H
#define ARBOLNARIO_H

#include "NodoArbol.h"


class ArbolNario
{
    private:
        NodoArbol* raiz;
        NodoArbol* actual;

    public:
        /*************************************************************************************************/

        /*POST:creal el arbol con la raíz y la posicion actual apuntando a NULL*/
        ArbolNario();

        void LiberarMemoria (NodoArbol *Ptr);

        /*************************************************************************************************/

        /*POST: elimina el arbol y libera memoria*/
        ~ArbolNario();

        /*************************************************************************************************/

        /*POST: Devuelve TRUE si el arbol esá vacío y FALSE si la raíz apunta a algo*/
        bool estaVacio();

        /*************************************************************************************************/

        /*POST: Verifica que el Tag no exista en sus padres*/
        bool existeTag(string tag);

        /*************************************************************************************************/

        /*POST: Agrega el nombre del Tag a su hijo y pocisiona el nodo actual al de su hijo*/
        void agregar(string tag);

        /*************************************************************************************************/

        /*POST: Agrega el contenido a del Tag en el nodo*/
        void agregarContenido(string value);

        /*************************************************************************************************/

        /*POST: El nodo actual retorna al nodo de su padre*/
        void volver();

        /*************************************************************************************************/

        /*POST: Agrega el nombre del Tag a su hijo y pocisiona el nodo actual al de su hijo*/
        string getTag();

        /*************************************************************************************************/

        /*POST: Devuelve el puntero al subárbol que empieza en el nodo en el que se halló el valor o NULL si no se halló el valor*/
        NodoArbol* buscar(/*TAG*/);

        /*************************************************************************************************/

        /*POST: salida del árbol por pantalla*/
        void imprimir(string tag);

        /*************************************************************************************************/
        /*POST: Crea un subarbol a partir del nodo que se la pase como parámetro. No sé bien si va a servir esto. Capaz sea útil para
        las funciones imprimir y para implementar de alguna forma recursiva la función buscar().*/
        ArbolNario* Subarbol(NodoArbol*);

        /*POST: Borra todos los Tag existentes en el arbol*/
        void borrar();

        /*************************************************************************************************/
        NodoArbol* buscar(NodoArbol* raiz,string valor);

        NodoArbol* getRaiz();
};

#endif // ARBOL N-ARIO_H
