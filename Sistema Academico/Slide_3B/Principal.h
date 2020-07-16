#pragma once

#include"Professor.h"

class Principal
{
private:
    Professor Einstein;
    Professor Newton;
    Professor Simao;

    Departamento MODA;
    Departamento DAINF;
    Departamento DAFIS;
    Departamento Fisica_Princeton;
    Departamento Matematica_Cambridge;

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
