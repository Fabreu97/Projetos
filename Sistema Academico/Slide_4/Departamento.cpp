#include "Disciplina.h"
#include "Universidade.h"
#include <stdio.h>
#include <string.h>

Departamento::Departamento(const char* n)
{
    strcpy(nome, n);
    ptr_univer = NULL;
    ptr_primeiro = NULL;
    ptr_atual = NULL;
}

Departamento::~Departamento()
{
    ptr_univer = NULL;
    ptr_primeiro = NULL;
    ptr_atual = NULL;
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
    if(d != NULL)
    {
        if(ptr_primeiro == NULL)
        {
            ptr_primeiro = d;
            ptr_atual = d;
        }
        else
        {
            ptr_atual->ptr_prox = d;
            ptr_atual = d;
        }
    }
}

void Departamento::liste_Disciplina()
{
    Disciplina* aux;
    aux = ptr_primeiro;
    while(aux != NULL)
    {
        printf("\tA disciplina %s pertence ao departamento %s\n", aux->get_Nome(), get_Nome());
        aux = aux->ptr_prox;
    }
}
