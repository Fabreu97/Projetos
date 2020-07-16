#ifndef INCLUDED_PESSOA_H
#define INCLUDED_PESSOA_H

#include <stdio.h>

struct Pessoa
{
    int dia;
    int mes;
    int ano;
    int idade;
};

int calculo_Idade(struct Pessoa p, int ano);

#endif // INCLUDED_PESSOA_H
