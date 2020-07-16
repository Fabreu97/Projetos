
#include "Universidade.h"
#include <stdio.h>
#include <string.h>

Departamento::Departamento(const char* n)
{
    strcpy(nome, n);
    ptr_univer = NULL;
    pobj_disc = new ListaDisciplina();
}

Departamento::~Departamento()
{
    ptr_univer = NULL;
    delete(pobj_disc);
}

void Departamento::set_Nome(char* n)
{
    strcpy(nome,n);
}

char* Departamento::get_Nome()
{
    return(nome);
}

void Departamento::set_Universidade(Universidade* u)
{
    ptr_univer = u;
}

Universidade* Departamento::get_Universidade()
{
    return(ptr_univer);
}

void Departamento::incluir_Disciplina(Disciplina* d)
{
    pobj_disc->inclua_Disciplina(d);
}

void Departamento::liste_Disciplina()
{
    pobj_disc->liste_Disciplina();
}
