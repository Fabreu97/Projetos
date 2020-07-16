#include "Departamento.h"
#include <string.h>
#include <stdio.h>

Departamento::Departamento(const char* n)
{
    tam = strlen(n);
    nome = new char(tam + 1);
    strcpy(nome, n);
}

Departamento::~Departamento()
{
    destroiNome();
}

void Departamento::destroiNome()
{
    delete(nome);
    this->tam = 0;
}

void Departamento::setNome(const char* n)
{
    destroiNome();
    tam = strlen(n);
    nome = new char(tam + 1);
    strcpy(nome, n);
}

const char* Departamento::getNome() const
{
    return(nome);
}

void Departamento::printNome() const
{
    printf("\n\t%s", nome);
}

void Departamento::incluirDisciplina(Disciplina* d)
{
    lista_disciplina.incluirInformacao(d);
}

void Departamento::limpaDisciplina()
{
    lista_disciplina.limpa();
}
