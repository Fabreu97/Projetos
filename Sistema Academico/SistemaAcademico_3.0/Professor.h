#ifndef INCLUDED_PROFESSOR_H
#define INCLDUED_PROFESSOR_H

#include "Universidade.h"
#include "Pessoa.h"

class Professor:
    public Pessoa
{
private:

    int ID;
    float salario;
    float bolsa_projeto;

    Universidade* ptr_univer;
    Departamento* ptr_depart;

public:

    Professor(int id = 0, int d = 0, int m = 0, int a = 0, const char* n = "Default");
    ~Professor();

    void set_ID(const int i);
    const int get_ID() const;
    void set_Salario(const float s);
    const float get_Salario() const;
    void set_Bolsa_Projeto(const float bp);
    const float get_Bolsa_Projeto() const;
    void set_Universidade(Universidade* u);
    Universidade* get_Universidade() const;

    void set_Departamento(Departamento* d);
    Departamento* get_Departamento() const;

    void print_Info();
    void Onde_Trabalha() const;
    void Qual_Departamento_Trabalha() const;
    void informa_Proventos() const;
};

#endif // INCLUDED_PROFESSOR_H
