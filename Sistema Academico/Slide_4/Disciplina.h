#ifndef INCLUDED_DISCIPLINA_H
#define INCLUDED_DISICPLINA_H

#include "Departamento.h"

class Disciplina
{
private:
    int id;
    char nome[100];
    char area_de_conhecimento[150];

    Departamento* ptr_depart;

public:

    Disciplina(const char* n = "Default");
    ~Disciplina();

    Disciplina* ptr_prox;

    void set_ID(int i);
    int get_ID();

    void set_Nome(char* n);
    char* get_Nome();

    void set_Departamento(Departamento* d);
    Departamento* get_Departamento();
};

#endif // INCLUDED_DISCIPLINA_H
