#ifndef INCLUDED_PESSOA_H
#define INCLUDED_PESSOA_H

#include "Lista.h"

using namespace std;
using namespace ms;

class Pessoa
{
protected:

    int dia;
    int mes;
    int ano;
    int idade;
    ConjuntoString::MinhaString nome;

    static int cont;

public:

    Pessoa(int d = 0, int m = 0, int a = 0, const char* n = "Default");
    ~Pessoa();

    void inicializar(int d, int m, int a, const char* n = NULL);

    void calculo_Idade(int da = 15, int ma = 3, int aa = 2020);

    void set_Idade(const int i);
    const int get_Idade() const;
    void set_Nome(const char* n);
    const char* get_Nome() const;
    static int get_Cont();

    virtual void print_Info();
    virtual void informa_Proventos() const;
};

ostream& operator<<(ostream& saida, Pessoa& a);

#endif // INCLUDED_PESSOA_H
