#ifndef ARBOLNARIO_H
#define ARBOLN-ARIO_H

#include "NodoArbol.h"


class ArbolNario
{
    private:
        NodoArbol* raiz;

    public:
        /*************************************************************************************************/

        /*POST:creal el arbol con la ra�z apuntando a NULL*/
        ArbolNario();

        /*************************************************************************************************/

        /*POST: elimina el arbol y libera memoria*/
        virtual ~ArbolNario();

        /*************************************************************************************************/

       /*POST: Fevuelve TRUE si el arbol es� vac�o y FALSE si la ra�z apunta a algo*/
        bool estaVacio();

        /*************************************************************************************************/

       /*POST: Carga TODOS los datos del archivo en el arbol*/
        bool cargar(/*ArchivoXML*/);

        /*************************************************************************************************/

        /*POST: Devuelve el puntero al sub�rbol que empieza en el nodo en el que se hall� el valor o NULL si no se hall� el valor*/
        NodoArbol* buscar(/*TAG*/);

        /*************************************************************************************************/

        /*POST: salida del �rbol por pantalla*/
        void imprimir();

        /*************************************************************************************************/
        /*POST: Crea un subarbol a partir del nodo que se la pase como par�metro. No s� bien si va a servir esto. Capaz sea �til para
        las funciones imprimir y para implementar de alguna forma recursiva la funci�n buscar().*/
        ArbolNario* Subarbol(NodoArbol*);







};

#endif // ARBOL N-ARIO_H
