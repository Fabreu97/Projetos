#ifndef INCLUDED_PESSOA_H
#define INCLUDED_PESSOA_H

#include <iostream>

using namespace std;

class Pessoa
{
protected:

    int dia;
    int mes;
    int ano;
    int idade;

    int tam;
    char* nome;

public:
    Pessoa(int d = 0,int m = 0,int a = 0,const char* n = "");
    ~Pessoa();

    void destroiNome();
    void setNome(const char* n);
    const char* getNome() const;

    void inicializar(int d, int m, int a,const char* n);
    void calculo_Idade(int da, int ma, int aa);
    const int get_Idade() const;

    virtual void print_Idade() const;
};

#endif // INCLUDED_PESSOA_H
