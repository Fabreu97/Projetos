#include "Universidade.h"
#include <string.h>
#include <stdio.h>

Universidade::Universidade(const char* n)
{
    tamanho = strlen(n);
    ptr_nome = new char[tamanho + 1];
    strcpy(ptr_nome, n);
}

Universidade::~Universidade()
{
    this->destroiNome();
}

void Universidade::destroiNome()
{
    tamanho = 0;
    delete(ptr_nome);
    ptr_nome = NULL;
}

void Universidade::setNome(char* n)
{
    destroiNome();
    tamanho = strlen(n);
    ptr_nome = new char[tamanho + 1];
    strcpy(ptr_nome, n);
}

const char* Universidade::getNome() const
{
    return(ptr_nome);
}

void Universidade::printNome() const
{
    printf("\n%s",this->getNome());
}
