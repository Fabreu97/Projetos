#ifndef INCLUDED_MINHA_STRING_H
#define INCLUDED_MINHA_STRING_H

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
namespace ms
{
    class ConjuntoString
    {
    public:

        class MinhaString
        {
        private:

            char* pstring;
            int tam;

            static const char nomeclasse[12];
            static int cont;

        public:
            MinhaString(const char* n = "");
            ~MinhaString();

            void set_String(const char* n);
            const char* get_String() const;

            //Sobrecarga de Operadores
            void operator = (const char* s);
            void operator = (MinhaString ms);
            bool operator == (MinhaString& ms);
            bool operator != (MinhaString& ms);
            MinhaString operator + (MinhaString& a);

            static const char* get_Nome_Classe();
            static int get_Cont();
        };
    };
}

ostream& operator<<(ostream& saida, ms::ConjuntoString::MinhaString& ms);
istream& operator>>(istream& entrada, ms::ConjuntoString::MinhaString& ms);

#endif // INCLUDED_MINHA_STRING_H
