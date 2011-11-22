#ifndef ARBOLNARIO_H
#define ARBOLNARIO_H

#include "NodoArbol.h"
#include "Lista.h"


class ArbolNario
{
    private:
        NodoArbol* raiz;
        NodoArbol* actual;

    public:

        /*************************************************************************************************/

        /*POST:creal el arbol con la raíz y la posicion actual apuntando a NULL*/
        ArbolNario();

        /*************************************************************************************************/

        /*POST:libera la memoria utilizada por el subarbol con raiz Ptr*/
        void LiberarMemoria (NodoArbol *Ptr);

        /*************************************************************************************************/

        /*POST: elimina el arbol y libera la memoria utilizada por el mismo*/
        ~ArbolNario();

        /*************************************************************************************************/

        /*POST:retorona un puntero a la raiz*/
        NodoArbol* getRaiz();

        /*************************************************************************************************/

        /*POST: Devuelve TRUE si el arbol no tienen ningun elemento, FALSE si tiene al menos uno*/
        bool estaVacio();

        /*************************************************************************************************/

        /*POST: Verifica que el Tag no exista en sus padres*/
        bool existeTag(string tag);

        /*************************************************************************************************/

        /*POST: Agrega el nombre del Tag a su hijo y pocisiona el nodo actual al de su hijo*/
        void agregar(string tag);

        /*************************************************************************************************/

        /*PRE: hijo no vacio*/
        /*POST: busca en el hijo el hermano que este vacio*/
        NodoArbol* getHermano(NodoArbol* hijo);

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
        void buscarTag(NodoArbol* nodo,Lista<NodoArbol*>*& listaDeTag,string tag);

        /*************************************************************************************************/

        /*PRE: arbol no tiene que estar vacio*/
        /*POST: salida del árbol por pantalla incluyendo el contenido de las hojas*/
        void imprimir(NodoArbol* nodo, unsigned);

        /*************************************************************************************************/
        /*PRE: arbol no tiene que estar vacio*/
        /*POST: recorre el arbol para imprimir por pantalla sin incluir el contenido de las hojas*/
        void imprimirSinContenido(NodoArbol* nodo, unsigned nivel);

        /*************************************************************************************************/

        /*PRE: arbol no tiene que estar vacio*/
        /*POST: salida del árbol por pantalla en formato de XML*/
        void imprimirXML(NodoArbol* nodo, unsigned);

        /*************************************************************************************************/

        /*POST: agrega tabulacion por cada nivel de cada hijo*/
        void tabuladorXML(unsigned nivel);

        /*************************************************************************************************/

        /*POST: imprime los subarboles que tenga como raiz tag*/
        void imprimir(string tag);

        /*************************************************************************************************/
        /*POST:imprime por pantalla los subarboles que tengan como raiz a tag, no imprime el contenido de las hojas*/
        void imprimirSoloTag(string tag);

        /*************************************************************************************************/

};

#endif // ARBOL N-ARIO_H
