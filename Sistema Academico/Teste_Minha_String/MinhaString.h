#ifndef INCLUDED_MINHA_STRING_H
#define INCLUDED_MINHA_STRING_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
namespace ms
{
    class MinhaString
    {
    private:

        char* pstring;
        int tam;
        static int cont;
        static const char nome_classe[12];

    public:
        MinhaString(const char* n = "");
        ~MinhaString();

        void set_String(const char* n);
        const char* get_String() const;

        //Sobrecarga de Operadores
        void operator=(const char* s);
        void operator=(MinhaString ms);
        bool operator==(MinhaString& ms);
        bool operator!=(MinhaString& ms);
        MinhaString operator+(MinhaString& a);

        static int get_Numero_Objetos();
        static const char* get_Nome_Classe();

    };
}
ostream& operator<<(ostream& saida, ms::MinhaString& s);
istream& operator>>(istream& entrada, ms::MinhaString& ms);

#endif // INCLUDED_MINHA_STRING_H
