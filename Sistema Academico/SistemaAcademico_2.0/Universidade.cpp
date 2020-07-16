#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "Universidade.h"

Universidade::Universidade(int id, const char* n):
    ID(id)
{
    tam = strlen(n);
    this->nome = (char*)malloc( sizeof(char) * (tam + 1) );
    strcpy(this->nome, n);
}

Universidade::~Universidade()
{
    free(nome);
    nome = NULL;
    tam = 0;
    limpa();
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
    free(nome);
    tam = strlen(n);
    nome = (char*)malloc( sizeof(char) * (tam + 1) );
    strcpy(nome, n);
}

const char* Universidade::get_Nome() const
{
    return(nome);
}

bool Universidade::incluir_Departamento(Departamento* d)
{
    return(LDepartamento.incluir_Departamento(d));
}

void Universidade::limpa()
{
    LDepartamento.limpa();
}

void Universidade::listar_Departamentos() const
{
    cout << this->get_Nome() << " tem " << LDepartamento.get_Tamanho() <<  " que sao: " << endl << endl;

    LDepartamento.listar_Departamento();
}
