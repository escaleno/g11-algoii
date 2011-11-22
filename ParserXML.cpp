/*
 * ParserXML.cpp
 *
 *  Created on: 15/11/2011
 *      Author: jiesperon
 */
#include "ParserXML.h"

ParserXML::ParserXML(string nombreArchivo)
{
    this->nombreArchivoXML=nombreArchivo;
    this->xml=false;
    this->isXml=false;
    this->startTag=false;
    this->closeTag=false;
    this->valueTag=false;
    this->endTag=false;
    this->raizCerrada=false;
    this->nivelTag=0;
    this->value.clear();
    this->bufferData.clear();
}

ParserXML::~ParserXML()
{
    //Nada por ahora;
}

ArbolNario* ParserXML::procesarXML()
{
    char        buff[MAX_LENGTH];
    ifstream    file;
    ArbolNario* aXml= new ArbolNario();
    file.open(nombreArchivoXML.c_str());
    if (!file.good())
    {
            cout << "No se pudo abrir el xml. " << nombreArchivoXML.c_str() << endl;
    }
    else
    {
        while (!file.eof())
        {
            file.getline(buff,MAX_LENGTH);
            string str (buff);
            if (!this->separarDatos(buff,aXml))
            {
                delete aXml;
                return 0;
            }
        }
    }
    file.close();
    return aXml;
}



bool ParserXML::separarDatos(string str, ArbolNario* aXml)
{

    string::iterator It = str.begin();
    while (It != str.end())
    {
        //      verifico xml.
        if ((*It == '<') && (*(It+1) == '?'))
        {
            this->xml=true;
            It++;
        }
        //      Es un finaliza el tag.
        else if ((*It == '<') && (*(It+1) == '/'))
        {
            It++;
            this->closeTag=true;
            this->valueTag=true;
            this->trim(this->bufferData);
            if (!this->validateTag(aXml))
            {
                cout << "XML invalido" << endl;
                return false;
            }
        }

        //      Es un comienzo de tag.
        else if (*It == '<')
        {
            this->startTag=true;
            this->endTag=false;
            this->trim(this->bufferData);
            if (!this->validateTag(aXml))
            {
                cout << "XML invalido" << endl;
                return false;
            }
        }
        //      Es un cierre de tag.
        else if (*It == '>')
        {
            this->valueTag=false;
            this->endTag=true;
            this->trim(this->bufferData);
            if (!this->validateTag(aXml))
            {
                cout << "XML invalido" << endl;
                return false;
            }
        }
        //      Es un caracter simple.
        else
        {
        //      Acumulo caracteres simples.
            this->bufferData+=*It;
        }
        if (this->raizCerrada)
        {
            this->trim(this->bufferData);
            if (!this->bufferData.empty())
            {
                cout << "XML invalido" << endl;
                return false;
            }
        }
        It++;
    }
    return true;
}

bool ParserXML::validateTag(ArbolNario* aXml)
{
    bool validate=true;
    /*Valido el inicio del xml <?xml version="1.0">*/
    if(this->existXML())
    {
        this->xml=false;
        this->endTag=false;
        string::size_type xmlpos = this->bufferData.find_first_of(" ");
        if(xmlpos!=string::npos)
        {
            string aux=this->bufferData.substr(0,xmlpos);
            if("xml"==aux)
            {
                this->bufferData.erase(0,xmlpos);
                this->trim(this->bufferData);
                xmlpos = this->bufferData.find_first_of("=");
                if(xmlpos!=string::npos)
                {
                    aux=aux=this->bufferData.substr(0,xmlpos);
                    this->trim(aux);
                    if("version"==aux)
                    {
                        this->isXml=true;

                    }
                    else
                    {
                        validate = false;
                    }
                }
                else
                {
                    validate = false;
                }
            }
            else
            {
                validate = false;
            }
        }
        else
        {
            validate = false;
        }
        this->bufferData.clear();
    }
    /*Valido el inicio del TAG*/
    else if(this->existTag())
    {

        if (this->value.empty()&& !this->bufferData.empty() && !this->raizCerrada &&
            this->bufferData.find_first_of(" ")==string::npos )
        {
            /*Verifico si existe el tag en sus padres*/
            if (!aXml->existeTag(this->bufferData))
            {
                this->nivelTag++;
                aXml->agregar(this->bufferData);
            }
            else
            {
                /*XML invalido porque existe el Tag en alguno de su pardes*/
                validate = false;
            }
        }
        else
        {
            /*ERROR en al Validar XML: si es posible
            no mete hijos*/
            validate = false;
        }
        this->startTag=false;
        this->value.clear();
        this->bufferData.clear();
    }
    /*Valido el Contenido del TAG*/
    else if(this->existTagValue())
    {
        this->endTag=false;
        this->valueTag=false;
        this->value.clear();
        if (!this->bufferData.empty())
        {
            /*Agrego el valor del tag*/
            aXml->agregarContenido(this->bufferData);
        }
        this->bufferData.clear();
    }
    /*Valido el fin del TAG*/
    else if(this->existcloseTag())
    {
        this->closeTag=false;
        this->endTag=false;
        if(this->bufferData==aXml->getTag() && this->value.empty() && !this->raizCerrada)
        {
            /*vuelvo al padre*/
            aXml->volver();
            this->nivelTag--;
        }
        else
        {
            /*No se puede leer XML: si es posible
            Elimino todo hasta el padre inclusive mal tageado*/
            validate = false;
        }
        if (!this->nivelTag)
        {
            this->raizCerrada=true;
        }
        this->value.clear();
        this->bufferData.clear();
    }
    else if (!this->isXml)
    {
        validate = false;
    }
    else
    {
        this->value=this->bufferData;
    }
    return validate;
}
bool ParserXML::existXML()
{
    return this->xml && this->endTag;
}

bool ParserXML::existTag()
{
    return this->isXml && this->startTag && this->endTag;
}

bool ParserXML::existTagValue()
{
    return this->isXml && this->endTag && this->closeTag && this->valueTag;
}

bool ParserXML::existcloseTag()
{
    return this->isXml && !this->valueTag && this->closeTag && this->endTag;
}

void ParserXML::trim(string &str)
{

    /*Verifico si tiene contenido distinto que blanco al final o al principio*/
    string::size_type begin = str.find_first_not_of(" \f\r\n\t\v");
    string::size_type end = str.find_last_not_of(" \f\r\n\t\v");
    if (end!=string::npos)
    {
        /*Borro todo los espacios en blanco del final*/
        str.erase(end+1);
        if(begin!=string::npos)
        {
            /*Borro todo los espacios en blanco del principio*/
            str.erase(0,begin);
        }
    }
    else
    {
        /*borro todo porque los unicos caracteres que tiene son espacio en blanco*/
        str.erase(str.begin(), str.end());

    }
}
