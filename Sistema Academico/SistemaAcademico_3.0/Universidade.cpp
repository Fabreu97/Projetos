#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "Universidade.h"

Universidade::Universidade(int id, const char* n):
    ID(id),
    nome(n)
{

}

Universidade::~Universidade()
{
    limpar();
}

void Universidade::set_ID(const int id)
{
    this->ID = id;
}

const int Universidade::get_ID() const
{
    return(ID);
}

void Universidade::set_Nome(const char* n)
{
    nome.setString(n);
}

const char* Universidade::get_Nome() const
{
    return(nome.getString());
}

bool Universidade::incluir_Departamento(Departamento* d)
{
    return(LDepartamento.incluir_Departamento(d));
}

void Universidade::limpar()
{
    LDepartamento.limpar();
}

void Universidade::listar_Departamentos() const
{
    cout << this << " tem " << LDepartamento.get_Tamanho() <<  " Departamentos que sao: " << endl << endl;

    LDepartamento.listar_Departamentos();
}

ostream& operator<<(ostream& saida, Universidade& u)
{
    saida << u.get_Nome();
    return(saida);
}
