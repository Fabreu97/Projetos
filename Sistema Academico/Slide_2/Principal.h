#pragma once

#include "Pessoa.h"
#include "Universidade.h"

class Principal
{
private:
    Pessoa Einstein;
    Pessoa Newton;
    Pessoa Simao;

    Universidade UTFPR;
    Universidade Princeton;
    Universidade Cambridge;

    static const int dia_atual = 19;
    static const int mes_atual = 3;
    static const int ano_atual = 2020;



public:

    Principal();
    ~Principal();

    void Executar();
};
