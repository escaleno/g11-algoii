#include "funciones.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
/**************************************************************************************/

unsigned opcionesMenu(){

    unsigned opcion;
    system("CLS");
    /*cout<<"########     ###    ########   ######  ######## ########     ##     ## ##     ## ##       "<<endl;
    cout<<"##     ##   ## ##   ##     ## ##    ## ##       ##     ##     ##   ##  ###   ### ##       "<<endl;
    cout<<"##     ##  ##   ##  ##     ## ##       ##       ##     ##      ## ##   #### #### ##       "<<endl;
    cout<<"########  ##     ## ########   ######  ######   ########        ###    ## ### ## ##       "<<endl;
    cout<<"##        ######### ##   ##         ## ##       ##   ##        ## ##   ##     ## ##       "<<endl;
    cout<<"##        ##     ## ##    ##  ##    ## ##       ##    ##      ##   ##  ##     ## ##       "<<endl;
    cout<<"##        ##     ## ##     ##  ######  ######## ##     ##    ##     ## ##     ## ######## "<<endl;
    cout<<"------------------------------------------------------------------------------------------"<<endl;*/
    cout<<"888888ba                                                  dP    dP 8888ba.88ba  dP        "<<endl;
    cout<<"88    `8b                                                 Y8.  .8P 88  `8b  `8b 88        "<<endl;
    cout<<"a88aaaa8P' .d8888b. 88d888b. .d8888b. .d8888b. 88d888b.    Y8aa8P  88   88   88 88        "<<endl;
    cout<<"88        88'  `88 88'  `88 Y8ooooo. 88ooood8 88'  `88    d8'  `8b 88   88   88 88        "<<endl;
    cout<<"88        88.  .88 88             88 88.  ... 88          88    88 88   88   88 88        "<<endl;
    cout<<"dP        `88888P8 dP       `88888P' `88888P' dP          dP    dP dP   dP   dP 88888888P "<<endl;
    cout<<"ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"<<endl;
    cout <<endl;
    cout<<"OPCIONES: "<<endl;
    cout<<endl;
    cout<<"1) Imprimir XML completo"<<endl;
    cout<<"2) Imprimir un tag cualquiera (con hijos y contenido)"<<endl;
    cout<<"3) Listar los hijos (solamente los nombre) de un tag dado"<<endl;
    cout<<"0) SALIR"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcion;
    if ((opcion <0) || (opcion > 3)){
    	cout<<"Opcion invalida!"<<endl;
    	mjePresioneCualquierTecla();
    	system("CLS");
    	return 100;
    }else
    {
    	return opcion;
    }
}


/**************************************************************************************/

void menuPrincipal(ArbolNario* aXML){

    unsigned opcion;
    bool sale = false;
    string tag;

    do{
        do{
    	opcion = opcionesMenu();
        }while(opcion == 100);

        switch (opcion){

        case 1: cout << endl;
                aXML->imprimirXML(aXML->getRaiz(), 0);
        		mjePresioneCualquierTecla();
                break;
        case 2:  tag = pideTag();
                cout << endl;
        		aXML->imprimir(tag);
        		mjePresioneCualquierTecla();
                break;
        case 3:  tag = pideTag();
        		cout << endl;
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
