#include <iostream>
#include "ParserXML.h"

using namespace std;

int main()
{
    ParserXML* parser = new ParserXML("C:\\Users\\gkgk\\Desktop\\Juani\\TPs\\TPxml\\tpxml\\Test.xml");
    ArbolNario* aXML = parser->procesarXML();

    if(aXML)
    {
        //pregunto que desea imprimir antes de imprimir
        aXML->imprimir(aXML->getRaiz(), 0);
        aXML->imprimirXML(aXML->getRaiz(), 0);
    }
    else
    {
        cout << "No se pudo parsear el XML" << endl;
    }

   //Lista<NodoArbol*>* listaDeTags = new Lista<NodoArbol*>;
   //Lista<NodoArbol*>* plista;

   //plista = aXML->buscarTag(aXML->getRaiz(),listaDeTags,"h6");


    delete aXML;
    //delete plista;

    return 0;

}
