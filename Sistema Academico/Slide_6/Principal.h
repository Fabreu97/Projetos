#pragma once

#include "Professor.h"
#include "Universidade.h"

class Principal
{
private:

    int cont_id_aluno;


    Aluno Fernando;
    Aluno AAA;
    Aluno BBB;
    Aluno CCC;
    Aluno DDD;
    Aluno EEE;

    Professor Einstein;
    Professor Newton;
    Professor Simao;

    Disciplina Computacao1_2006;
    Disciplina Introd_Alg_2007;
    Disciplina Computacao2_2007;
    Disciplina Metodos2_2007;

    Departamento MODA;
    Departamento DAINF;
    Departamento DAFIS;
    Departamento Matematica_Princeton;
    Departamento Fisica_Cambridge;

    Universidade UTFPR;
    Universidade Princeton;
    Universidade Cambridge;

    static const int dia_atual = 19;
    static const int mes_atual = 3;
    static const int ano_atual = 2020;

public:

    Principal();
    ~Principal();

    void inicializar();
    void inicializar_Aluno();
    void inicializar_Professor();
    void inicializar_Disciplina();
    void inicializar_Departamento();
    void inicializar_Universidade();

    void Executar();
};
