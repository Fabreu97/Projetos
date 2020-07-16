#include "Universidade.h"
#include "Departamento.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>

Departamento::Departamento(int id, const char* n):
    ID(id)
{
    tam = strlen(n);
    nome = (char*)malloc( sizeof(char) * (tam + 1) );
    strcpy(nome, n);
}

Departamento::~Departamento()
{
    free(nome);
    tam = 0;
    ptr_filiar = NULL;
    limpa();
}

void Departamento::set_ID(const int id)
{
    ID = id;
}

const int Departamento::get_ID() const
{
    return(ID);
}

void Departamento::set_Nome(const char* n)
{
    free(nome);
    tam = strlen(n);
    nome = (char*)malloc( sizeof(char) * (tam + 1) );
    strcpy(nome, n);
}

const char* Departamento::get_Nome() const
{
    return(nome);
}

void Departamento::set_Universidade(Universidade* u)
{
    ptr_filiar = u;
}

Universidade* Departamento::get_Universidade() const
{
    return(ptr_filiar);
}

bool Departamento::incluir_Disciplina(Disciplina* d)
{
    return(LDisciplina.incluir_Disciplina(d));
}

void Departamento::limpa()
{
    LDisciplina.limpa();
}

void Departamento::listar_Disciplina()
{
    cout << "O Departamento " << get_Nome() << " possui " << LDisciplina.get_Tamanho() << " Disciplinas:" << endl;
    LDisciplina.listar_Disciplinas();
}
