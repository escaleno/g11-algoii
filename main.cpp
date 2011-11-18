#include <iostream>
#include "ParserXML.h"

using namespace std;

int main()
{
    ParserXML* parser = new ParserXML("C://Algo2//Tp Grupal 2do cuat 2011 - TRUNK//Test.xml");
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
    delete nivel;
    return 0;

}
