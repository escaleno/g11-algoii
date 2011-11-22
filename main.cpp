#include <iostream>
#include "ParserXML.h"
#include "funciones.h"

using namespace std;

int main(){
	ParserXML* parser = new ParserXML("D:\\Documents\\JohnAdq\\C++\\xmlfinal\\Test.xml");
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


