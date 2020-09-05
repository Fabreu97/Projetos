#include "MinhaString.h"

const char ms::MinhaString::nomeclasse[12] = "MinhaString";
int ms::MinhaString::cont = 0;

ms::MinhaString::MinhaString(const char* n):
    tam(strlen(n))
{
    cont++;
    pstring = new char[tam + 1];
    strcpy(pstring, n);
}

ms::MinhaString::~MinhaString()
{
    cont--;
    delete []pstring;
    pstring = NULL;
}

void ms::MinhaString::setString(const char* n)
{
    delete []pstring;
    tam = strlen(n);
    pstring = new char[tam + 1];
    strcpy(pstring, n);
}

const char* ms::MinhaString::getString() const
{
    return(pstring);
}

const size_t ms::MinhaString::getSize() const
{
    return(tam);
}

void ms::MinhaString::operator=(const char* s)
{
    setString(s);
}

void ms::MinhaString::operator=(const MinhaString& ms)
{
    operator=(ms.getString());
}

const bool ms::MinhaString::operator==(const ms::MinhaString& ms) const
{

    if( 0 == strcmp(pstring, ms.getString()) )
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

const bool ms::MinhaString::operator!=(const ms::MinhaString& ms) const
{
    return(!(operator==(ms)));
}

const ms::MinhaString ms::operator+(const ms::MinhaString& l, const ms::MinhaString& r)
{
    size_t tam = l.getSize() + r.getSize() + 1;
    char aux[tam];
    strcpy(aux, l.getString());
    strcat(aux, r.getString());
    return(MinhaString(aux));
}

const ms::MinhaString ms::operator+(const char* l, const ms::MinhaString& r)
{
    size_t tam = strlen(l) + r.getSize() + 1;
    char aux[tam];
    strcpy(aux, l);
    strcat(aux, r.getString());
    return(ms::MinhaString(aux));
}

const ms::MinhaString ms::operator+(const ms::MinhaString& l, const char* r)
{
    size_t tam = l.getSize() + strlen(r) + 1;
    char aux[tam];
    strcpy(aux, l.getString());
    strcat(aux, r);
    return(ms::MinhaString(aux));
}

const char* ms::MinhaString::getNomeClasse()
{
    return(nomeclasse);
}

int ms::MinhaString::getCont()
{
    return(cont);
}

ostream& operator<<(ostream& saida, ms::MinhaString& ms)
{
    saida << ms.getString();
    return saida; // possibilita encadeamento
}

istream& operator>>(istream& entrada, ms::MinhaString& ms)
{
    char aux[300];
    entrada >> aux;
    ms.setString(aux);
    return entrada;
}
