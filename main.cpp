#include <iostream>
#include "ParserXML.h"

using namespace std;

int main()
{
    ParserXML* parser = new ParserXML("D:\\Documents\\Uba\\Algoritmos II\\C++\\tpXMLsvn\\Test.xml");
    ArbolNario* aXML = parser->procesarXML();
    if(aXML)
    {
        //pregunto que desea imprimir antes de imprimir

        aXML->imprimir("nieto4");
    }
    else
    {
        cout << "No se pudo parsear el XML" << endl;
    }
    return 0;
}
