#include "Disciplina.h"
#include <string.h>

Disciplina::Disciplina(const char* n)
{
    strcpy(nome, n);
    ptr_depart = NULL;
    ptr_prox = NULL;
}

Disciplina::~Disciplina()
{
    ptr_depart = NULL;
    ptr_prox = NULL;
}

void Disciplina::set_ID(int i)
{
    id = i;
}

int Disciplina::get_ID()
{
    return(id);
}

void Disciplina::set_Nome(char* n)
{
    strcpy(nome, n);
}

char* Disciplina::get_Nome()
{
    return(nome);
}


void Disciplina::set_Departamento(Departamento* d)
{
    ptr_depart = d;

    ptr_depart->incluir_Disciplina(this);
}

Departamento* Disciplina::get_Departamento()
{
    return(ptr_depart);
}
