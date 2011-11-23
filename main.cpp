#include <iostream>
#include "ParserXML.h"
#include "funciones.h"

using namespace std;

int main(int argc, char *argv[]){
    if (argc<2)
    {
        cout << "Argumentos insuficientes: programa.exe <path del archivo>\\archivo.xml";
    }
    else
    {
        ParserXML* parser = new ParserXML(argv[1]);
        ArbolNario* aXML = parser->procesarXML();
        if(aXML){
            menuPrincipal(aXML);
        }
        else{
            cout << "No se pudo parsear el XML" << endl;
        }

        delete aXML;
        return 0;
    }
}

