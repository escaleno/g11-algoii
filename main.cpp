#include <iostream>
#include "ParserXML.h"

using namespace std;

int main()
{
    ParserXML* parser = new ParserXML("C:\\Users\\gkgk\\Desktop\\Juani\\TPs\\TP3\\TP3\\bin\\Debug\\Test.xml");
    ArbolNario* aXML = parser->procesarXML();
    if(!aXML->estaVacio())
    {
        //pregunto que desea imprimir antes de imprimir
        aXML->imprimir();
    }
    else
    {
        cout << "No se pudo parsear el XML" << endl;
    }
    return 0;
}
