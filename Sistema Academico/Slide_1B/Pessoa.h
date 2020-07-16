#ifndef INCLUDED_PESSOA_H
#define INCLUDED_PESSOA_H

#include <iostream>
#include <stdio.h>

class Pessoa
{
private:

    int diaP;
    int mesP;
    int anoP;
    int idadeP;

public:

    Pessoa();
    Pessoa(int diaNa, int mesNa, int anoNa);

    void calculo_Idade(int diaAT, int mesAT, int anoAT);
    int get_Idade();
};

#endif // INCLUDED_PESSOA_H
