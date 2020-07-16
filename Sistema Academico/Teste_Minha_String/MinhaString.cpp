#include "MinhaString.h"

using namespace ms;

int MinhaString::cont = 0;
const char MinhaString::nome_classe[12] = "MinhaString";

MinhaString::MinhaString(const char* n):
    tam(strlen(n))
{
    cont++;
    pstring = new char[tam + 1];
    strcpy(pstring, n);
}

MinhaString::~MinhaString()
{
    delete []pstring;
    pstring = NULL;
    cont--;
}

void MinhaString::set_String(const char* n)
{
    delete []pstring;
    tam = strlen(n);
    pstring = new char[tam + 1];
    strcpy(pstring, n);
}

const char* MinhaString::get_String() const
{
    return(pstring);
}

void MinhaString::operator=(const char* s)
{
    set_String(s);
}

void MinhaString::operator=(MinhaString ms)
{
    operator=(ms.get_String());
}

bool MinhaString::operator==(MinhaString& ms)
{

    if( 0 == strcmp(pstring, ms.get_String()) )
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

bool MinhaString::operator!=(MinhaString& ms)
{
    return(!(operator==(ms)));
}

MinhaString MinhaString::operator+(MinhaString& a)
{
    int tam = strlen(pstring) + strlen(a.get_String()) + 1;
    char aux[tam];
    strcpy(aux, pstring);
    strcat(aux, a.pstring);
    return(MinhaString(aux));

}

int MinhaString::get_Numero_Objetos()
{
    return(cont);
}

const char* MinhaString::get_Nome_Classe()
{
    return(nome_classe);
}

///Métodos que não estão na classe ms::MinhaString

ostream& operator<<(ostream& saida, MinhaString& s)
{
    saida << s.get_String();
    return saida; // possibilita encadeamento
}

istream& operator>>(istream& entrada, MinhaString& ms)
{
    char* aux = new char[50];
    entrada >> aux;
    ms.set_String(aux);
    return entrada;
}
