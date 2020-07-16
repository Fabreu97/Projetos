#include "Disciplina.h"
#include <stdio.h>
#include <string.h>

Disciplina::Disciplina(int na, const char* n):
    max_aluno(na)
{
    this->cont_aluno = 0;
    strcpy(nome, n);
    ptr_depart = NULL;
    ptr_prox = NULL;
    ptr_atual = NULL;
    ptr_primeiro = NULL;
}

Disciplina::~Disciplina()
{
    ptr_depart = NULL;
    ElAluno* aux = ptr_primeiro;

    while(aux != NULL)
    {
        ptr_primeiro = aux->ptr_prox;
        delete(aux);
        aux = ptr_primeiro;
    }

    ptr_prox = NULL;
    ptr_atual = NULL;
    ptr_primeiro = NULL;
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

void Disciplina::inclua_Aluno(Aluno* a)
{
    ElAluno* aux;
    aux  = new ElAluno();
    aux->set_Aluno(a);

    if(cont_aluno < max_aluno && a != NULL)
    {
        if(ptr_primeiro == NULL)
        {
            ptr_primeiro = aux;
            ptr_atual = aux;
        }
        else
        {
            ptr_atual->ptr_prox = aux;
            aux->ptr_anterior = ptr_atual;
            ptr_atual = aux;
        }
        cont_aluno++;
    }
    else
    {
        printf("Aluno nao incluido, turma ja lotada com %d", cont_aluno);
    }
}

void Disciplina::liste_Aluno()
{
    ElAluno* aux;
    aux = ptr_primeiro;

    printf("A Disicplina %s possui %d que sao:\n", get_Nome(), cont_aluno);

    while(aux != NULL)
    {
        printf("\t%s\n",aux->get_Nome());
        aux = aux->ptr_prox;
    }
}

void Disciplina::liste_Aluno2()
{
    ElAluno* aux;
    aux = ptr_atual;

    printf("\nA Disicplina %s possui %d que sao:\n", get_Nome(), cont_aluno);

    while(aux != NULL)
    {
        printf("\t%s\n",aux->get_Nome());
        aux = aux->ptr_anterior;
    }
}
