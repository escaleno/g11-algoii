#include "funciones.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
/**************************************************************************************/

unsigned opcionesMenu(){

    unsigned opcion;
    system("CLS");
    cout<<"::::::PARSER XML::::::"<<endl;
    cout<<""<<endl;
    cout<<"OPCIONES: "<<endl;
    cout<<"1) Imprimir XML completo"<<endl;
    cout<<"2) Imprimir un tag cualquiera (con hijos y contenido)"<<endl;
    cout<<"3) Listar los hijos (solamente los nombre) de un tag dado"<<endl;
    cout<<"0) SALIR"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcion;

    return opcion;
}

/**************************************************************************************/

void menuPrincipal(ArbolNario* aXML){

    unsigned opcion;
    bool sale = false;
    string tag;

    do{
        opcion = opcionesMenu();

        switch (opcion){

        case 1:  aXML->imprimirXML(aXML->getRaiz(), 0);
        		mjePresioneCualquierTecla();
                break;
        case 2:  tag = pideTag();
        		aXML->imprimir(tag);
        		mjePresioneCualquierTecla();
                break;
        case 3:  tag = pideTag();
        		aXML->imprimirSoloTag(tag);
        		mjePresioneCualquierTecla();
                break;
        case 0:  sale = true;
                break;
        };
    }while(opcion != 0);
}

/**************************************************************************************/

string pideTag(){
	string tag;
	cout<<"Ingrese el tag a buscar y presione ENTER: ";
	cin >>tag;
	return tag;
}

/**************************************************************************************/

void mjePresioneCualquierTecla(){
	cout <<endl;
	cout<<"Presione cualquier tecla para volver al menu principal...";
	cin.get();
	cin.get();
}

/**************************************************************************************/
