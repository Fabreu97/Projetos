#ifndef INCLUDED_DISCIPLINA_H
#define INCLUDED_DISICPLINA_H

#include "ElAluno.h"

class Departamento;

class Disciplina
{
private:
    int id;
    char nome[100];
    char area_de_conhecimento[150];
    Departamento* ptr_depart;

    int cont_aluno;
    int max_aluno;
    ElAluno* ptr_primeiro;
    ElAluno* ptr_atual;

public:

    Disciplina(int na = 45, const char* n = "Default");
    ~Disciplina();

    Disciplina* ptr_prox;

    void set_ID(int i);
    int get_ID();

    void set_Nome(char* n);
    char* get_Nome();

    void set_Departamento(Departamento* d);
    Departamento* get_Departamento();

    void inclua_Aluno(Aluno* a);
    void liste_Aluno();
    void liste_Aluno2();
};

#endif // INCLUDED_DISCIPLINA_H
