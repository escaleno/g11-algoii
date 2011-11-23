#include <iostream>
#include "ParserXML.h"
#include "funciones.h"

using namespace std;

int main(){
	ParserXML* parser = new ParserXML("C:\\Documents and Settings\\jlezcano\\Escritorio\\algoii\\Test.xml");
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


