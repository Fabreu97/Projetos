#include "Disciplina.h"
#include "Departamento.h"

#include <string.h>
#include <iostream>

Disciplina::Disciplina(int id, const char* n):
    ID(id)
{
    tam  = 0;
    if(n == NULL)
    {
        nome = NULL;
    }
    else
    {
        tam = strlen(n);
        nome = (char*)malloc(sizeof(char) * (tam + 1));
        strcpy(nome, n);
    }
    ptr_depar = NULL;
}

Disciplina::~Disciplina()
{
    ptr_depar = NULL;
    free(nome);
    limpa();
}

void Disciplina::set_ID(const int id)
{
    ID = id;
}

const int Disciplina::get_ID() const
{
    return(ID);
}

void Disciplina::set_Nome(const char* n)
{
    if(nome != NULL)
    {
        free(nome);
    }

    tam = strlen(n);
    nome = (char*)malloc(sizeof(char) * (tam + 1));
    strcpy(nome, n);
}

const char* Disciplina::get_Nome() const
{
    return(nome);
}

void Disciplina::set_Departamento(Departamento* d)
{
    ptr_depar = d;
}

Departamento* Disciplina::get_Departamento() const
{
    return(ptr_depar);
}

bool Disciplina::incluir_Aluno(Aluno* a)
{
    return(LAluno.incluir_Aluno(a));
}

void Disciplina::limpa()
{
    LAluno.limpar();
}

void Disciplina::listar_Aluno()
{
    cout << endl << endl <<"A Disciplina " << get_Nome() << " tem matriculado " << LAluno.get_Tamanho() << " Alunos que sao:" << endl << endl;
    LAluno.listar_Aluno();
}
