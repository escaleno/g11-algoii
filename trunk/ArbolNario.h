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

        /*POST:creal el arbol con la ra�z y la posicion actual apuntando a NULL*/
        ArbolNario();

        void LiberarMemoria (NodoArbol *Ptr);

        /*************************************************************************************************/

        /*POST: elimina el arbol y libera memoria*/
        ~ArbolNario();

        /*************************************************************************************************/

        /*POST: Devuelve TRUE si el arbol es� vac�o y FALSE si la ra�z apunta a algo*/
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

        /*POST: Devuelve el puntero al sub�rbol que empieza en el nodo en el que se hall� el valor o NULL si no se hall� el valor*/
        NodoArbol* buscar(/*TAG*/);

        /*************************************************************************************************/

        /*POST: salida del �rbol por pantalla*/
        void imprimir(string tag);

        /*************************************************************************************************/
        /*POST: Crea un subarbol a partir del nodo que se la pase como par�metro. No s� bien si va a servir esto. Capaz sea �til para
        las funciones imprimir y para implementar de alguna forma recursiva la funci�n buscar().*/
        ArbolNario* Subarbol(NodoArbol*);

        /*POST: Borra todos los Tag existentes en el arbol*/
        void borrar();

        /*************************************************************************************************/
        NodoArbol* buscar(NodoArbol* raiz,string valor);

        NodoArbol* getRaiz();
};

#endif // ARBOL N-ARIO_H
