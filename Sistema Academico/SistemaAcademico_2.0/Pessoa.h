#ifndef INCLUDED_PESSOA_H
#define INCLUDED_PESSOA_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Pessoa
{
protected:

    int dia;
    int mes;
    int ano;
    int idade;
    int tam;
    char* nome;

public:

    Pessoa(int d = 0, int m = 0, int a = 0, const char* n = "Default");
    ~Pessoa();

    void inicializar(int d, int m, int a, const char* n = NULL);

    void calculo_Idade(int da = 15, int ma = 3, int aa = 2020);
    void destroiNome();
    const int get_Idade() const;

    void set_Nome(const char* n = "Default");
    const char* get_Nome() const;

    virtual void print_Info() = 0;
};

#endif // INCLUDED_PESSOA_H
