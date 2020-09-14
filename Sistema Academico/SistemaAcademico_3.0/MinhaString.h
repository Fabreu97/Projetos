#ifndef INCLUDED_MINHA_STRING_H
#define INCLUDED_MINHA_STRING_H

#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>

using namespace std;
namespace ms
{
    class MinhaString
    {
    private:

        char* pstring;
        size_t tam;

        static const char nomeclasse[12];
        static int cont;

    public:
        MinhaString(const char* n = "");
        ~MinhaString();

        void setString(const char* n);
        const char* getString() const;

        const size_t getSize() const;

        //Sobrecarga de Operadores
        void operator = (const char* s);
        void operator = (const MinhaString& ms);
        const bool operator == (const MinhaString& ms) const;
        const bool operator != (const MinhaString& ms) const;

        static const char* getNomeClasse();
        static int getCont();

    };
    const MinhaString operator+(const MinhaString& l, const MinhaString& r);
    const MinhaString operator+(const char* l, const MinhaString& r);
    const MinhaString operator+(const MinhaString& l, const char* r);
}

ostream& operator<<(ostream& saida, ms::MinhaString& ms);
istream& operator>>(istream& entrada, ms::MinhaString& ms);

#endif // INCLUDED_MINHA_STRING_H
