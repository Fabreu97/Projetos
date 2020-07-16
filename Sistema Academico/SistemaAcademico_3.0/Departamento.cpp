#include "Universidade.h"
#include "Departamento.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>

Departamento::Departamento(int id, const char* n):
    ID(id),
    nome(n)
{

}

Departamento::~Departamento()
{
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
    nome.set_String(n);
}

const char* Departamento::get_Nome() const
{
    return(nome.get_String());
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
    LDisciplina.limpar();
}

void Departamento::listar_Disciplina()
{
    cout << "O Departamento " << this << " possui " << LDisciplina.get_Tamanho() << " Disciplinas:" << endl;
    LDisciplina.listar_Disciplinas();
}
ostream& operator<<(ostream& saida, Departamento& d)
{
    saida << d.get_Nome();
    return(saida);
}
