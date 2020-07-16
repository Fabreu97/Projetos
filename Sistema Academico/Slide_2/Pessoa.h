#ifndef INCLUDED_PESSOA_H
#define INCLUDED_PESSOA_H

#include <iostream>

using namespace std;

#include "Universidade.h"

class Pessoa
{
private:
    int dia;
    int mes;
    int ano;
    int idade;
    char nomep[30];

    Universidade* ptr_univer;

public:

    Pessoa(int d = 0, int m = 0, int a = 0, const char* nome = "Default");
    ~Pessoa();

    void calculo_Idade(int da, int ma, int aa);
    int informa_Idade();
    void print_Idade();

    void set_Universidade(Universidade* u);
    Universidade* get_Universidade() const;

    void Onde_Trabalha() const;
};

#endif // INCLUDED_PESSOA_H
