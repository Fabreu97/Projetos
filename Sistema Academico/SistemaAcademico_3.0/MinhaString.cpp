#include "MinhaString.h"

using namespace ms;

const char ConjuntoString::MinhaString::nomeclasse[12] = "MinhaString";
int ConjuntoString::MinhaString::cont = 0;

ConjuntoString::MinhaString::MinhaString(const char* n):
    tam(strlen(n))
{
    cont++;
    pstring = new char[tam + 1];
    strcpy(pstring, n);
}

ConjuntoString::MinhaString::~MinhaString()
{
    cont--;
    delete []pstring;
    pstring = NULL;
}

void ConjuntoString::MinhaString::set_String(const char* n)
{
    delete []pstring;
    tam = strlen(n);
    pstring = new char[tam + 1];
    strcpy(pstring, n);
}

const char* ConjuntoString::MinhaString::get_String() const
{
    return(pstring);
}

void ConjuntoString::MinhaString::operator=(const char* s)
{
    set_String(s);
}

void ConjuntoString::MinhaString::operator=(MinhaString ms)
{
    operator=(ms.get_String());
}

bool ConjuntoString::MinhaString::operator==(MinhaString& ms)
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

bool ConjuntoString::MinhaString::operator!=(MinhaString& ms)
{
    return(!(operator==(ms)));
}

ConjuntoString::MinhaString ConjuntoString::MinhaString::operator+(MinhaString& a)
{
    int tam = strlen(pstring) + strlen(a.get_String()) + 1;
    char aux[tam];
    strcpy(aux, pstring);
    strcat(aux, a.pstring);
    return(MinhaString(aux));
}

const char* ConjuntoString::MinhaString::get_Nome_Classe()
{
    return(nomeclasse);
}

int ConjuntoString::MinhaString::get_Cont()
{
    return(cont);
}

///Métodos que não são membros da classe ms::ConjuntoString::MinhaString

ostream& operator<<(ostream& saida, ConjuntoString::MinhaString& ms)
{
    saida << ms.get_String();
    return saida; // possibilita encadeamento
}

istream& operator>>(istream& entrada, ConjuntoString::MinhaString& ms)
{
    char aux[300];
    entrada >> aux;
    ms.set_String(aux);
    return entrada;
}
