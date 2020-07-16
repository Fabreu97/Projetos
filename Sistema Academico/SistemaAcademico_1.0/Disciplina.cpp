#include "Disciplina.h"
#include <string.h>
#include <stdio.h>

Disciplina::Disciplina(const char* n, const int v):
    lista_aluno(v)
{
    tam = strlen(n);
    nome = new char(tam + 1);
    strcpy(nome, n);
    p = NULL;
}

Disciplina::~Disciplina()
{
    destroiNome();
    demitirProfessor();
    limpaListaAluno();
}

void Disciplina::destroiNome()
{
    delete(nome);
    nome = NULL;
    tam = 0;
}

void Disciplina::setNome(const char* n)
{
    destroiNome();
    tam = strlen(n);
    nome = new char(tam + 1);
    strcpy(nome, n);
}

const char* Disciplina::getNome() const
{
    return(nome);
}

void Disciplina::incluirAluno(Aluno* a)
{
    lista_aluno.incluirInformacao(a);
}

void Disciplina::incluirProfessor(Professor* prof)
{
    this->p = prof;
}

Professor* Disciplina::getProfessor() const
{
    return(p);
}

void Disciplina::limpaListaAluno()
{
    lista_aluno.limpa();
}

void Disciplina::demitirProfessor()
{
    p = NULL;
}

void Disciplina::listarAlunoDisciplina()
{
    long int i = 0;

    printf("\n\tDisciplina %s: \n",this->getNome());
    for(i = 0; i < lista_aluno.getTamanho(); i++)
    {
        Aluno* aux;
        aux = lista_aluno.getInformacao(i);
        if(aux != NULL)
        {
            printf("\n\t\t%s",aux->getNome());
        }
    }
}
