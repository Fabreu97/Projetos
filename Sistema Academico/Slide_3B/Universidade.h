#ifndef INCLUDED_UNIVERSIDADE_H
#define INCLUDED_UNIVERSIDADE_H

#include "Departamento.h"

class Universidade
{
private:
    char nome[50];
    Departamento* ptr_depar[50];

public:
    Universidade(const char* n = "Default"); //Construtor
    ~Universidade();                         //Destrutor

    void set_Nome(const char* n);
    const char* get_Nome() const;

    void set_Departamento(Departamento* d, int cont);
    void imprimir_Departamentos();
};

#endif // INCLUDED_UNIVERSIDADE_H
