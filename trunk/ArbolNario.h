#ifndef ARBOLNARIO_H
#define ARBOLNARIO_H

#include "NodoArbol.h"
//#include "Lista.h"


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

        /*POST: Agrega el contenido a del Tag en el nodo*/
        void agregarContenido(string value);

        /*************************************************************************************************/

        /*POST: El nodo actual retorna al nodo de su padre*/
        void volver(); //ESTE METODO NO ESTA EN LA IMPLEMENTACION DE LA CLASE

        /*************************************************************************************************/

        /*POST: Agrega el nombre del Tag a su hijo y pocisiona el nodo actual al de su hijo*/
        string getTag();

        /*************************************************************************************************/

        /*POST: Devuelve el puntero al subárbol que empieza en el nodo en el que se halló el valor o NULL si no se halló el valor*/
        //Lista<NodoArbol*>* buscarTag(NodoArbol* nodo,Lista<NodoArbol*>*& listaDeTag,string tag);

        /*************************************************************************************************/

        /*POST: salida del árbol por pantalla*/
        void imprimir(NodoArbol* nodo, unsigned *);

        /*POST: salida del árbol por pantalla*/
        void imprimir(string tag);
        /*************************************************************************************************/
        /*POST: Crea un subarbol a partir del nodo que se la pase como parámetro.*/ //VERIFICAR SI ESTO SIRVE
        ArbolNario* Subarbol(NodoArbol*);

        /*************************************************************************************************/
        /*POST: Borra todos los Tag existentes en el arbol*/
        void borrar();//ESTE METODO NO ESTA EN LA IMPLEMENTACION DE LA CLASE

        /*************************************************************************************************/

        NodoArbol* buscar(NodoArbol* raiz,string valor);


};

#endif // ARBOL N-ARIO_H
