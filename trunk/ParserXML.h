/*
 * ParserXML.h
 *
 *  Created on: 15/11/2011
 *      Author: jiesperon
 */

 /*ParserXML Parsea el XML para agregar el contenido en un Arbol.
 *
 * REFERENCIAS:
 * nombreArchivoXML: direccion y nombre del archivo que se desea parsear como XML.
 */

#ifndef _PARSER_XML_H
#define _PARSER_XML_H

#include "ArbolNario.h"

#ifndef MAX_LENGTH
#define MAX_LENGTH 256
#endif



class ParserXML
{
    private:
        string nombreArchivoXML;
        string bufferData;
        string value;
        int nivelTag;
        bool xml;
        bool isXml;
        bool startTag;
        bool closeTag;
        bool endTag;
        bool valueTag;
        bool raizCerrada;

        /*************************************************************************************************/

        /*POST:Valida el contenido del XML y agrega cada TAG al arbol*/
        bool validateTag(ArbolNario* aXml);
                /*************************************************************************************************/

        /*POST: retorna verdadero si contien "<? >"*/
        bool existXML();

        /*************************************************************************************************/

        /*POST: retorna verdadero si abre el TAG*/
        bool existTag();

        /*************************************************************************************************/

        /*POST: retorna verdadero tiene Contenido el TAG*/
        bool existTagValue();

        /*************************************************************************************************/

        /*POST: retorna verdadero si cierra el TAG*/
        bool existcloseTag();

        /*************************************************************************************************/

        /*POST:Borra los espacios del principio y del final de str*/
        void trim(string &str);


    public:

        /*************************************************************************************************/

        /*PRE:el nomberArchivo tiene el nombre y la direccion del XML que se quiere procesar*/
        /*POST:creal el Parser del XML con el archivo que se desea procesar*/
        ParserXML(string nombreArchivo);

        /*************************************************************************************************/

        /*POST:Nada*/
        ~ParserXML();

        /*************************************************************************************************/

        /*POST:procesa el tag y retorna el un arbol con el contenido del XML*/
        ArbolNario* procesarXML();

        /*************************************************************************************************/

        /*POST:Verifica los serparadores de los TAG y para validar los TAG y agregarlo al arbol*/
        bool separarDatos(string str, ArbolNario* aXml);

        /*************************************************************************************************/

};

#endif
