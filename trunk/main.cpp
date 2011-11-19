#include <iostream>
#include "ParserXML.h"

using namespace std;

int main()
{
    ParserXML* parser = new ParserXML("C:\\Documents and Settings\\jlezcano\\Escritorio\\algoii\\Test.xml");
    ArbolNario* aXML = parser->procesarXML();
    NodoArbol* Recorrido;
    Recorrido = aXML->getRaiz();
    unsigned* nivel = new unsigned;
    *nivel = 0;

    if(aXML)
    {
        //pregunto que desea imprimir antes de imprimir

        aXML->imprimir(Recorrido, nivel);
    }
    else
    {
        cout << "No se pudo parsear el XML" << endl;
    }

   //Lista<NodoArbol*>* listaDeTags = new Lista<NodoArbol*>;
   //Lista<NodoArbol*>* plista;

   //plista = aXML->buscarTag(aXML->getRaiz(),listaDeTags,"h6");


    delete nivel;
    //delete plista;
    return 0;

}
