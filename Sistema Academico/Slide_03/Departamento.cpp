
#include "Universidade.h"
#include <string.h>

Departamento::Departamento(const char* n)
{
    strcpy(nome, n);
    ptr_univer = NULL;
}

Departamento::~Departamento()
{
    ptr_univer = NULL;
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
