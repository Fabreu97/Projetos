#ifndef INCLUDED_DEPARTAMENTO_H
#define INCLUDED_DEPARTAMENTO_H

#include "ListaDisciplina.h"

class Universidade;

class Departamento
{
private:

    int ID;
    ConjuntoString::MinhaString nome;

    Universidade* ptr_filiar;
    ListaDisciplina LDisciplina;

public:

    Departamento(int id = 0, const char* n = "Default");
    ~Departamento();

    void set_ID(const int id);
    const int get_ID() const;
    void set_Nome(const char* n);
    const char* get_Nome() const;
    void set_Universidade(Universidade* u);
    Universidade* get_Universidade() const;

    bool incluir_Disciplina(Disciplina* d);
    void limpa();
    void listar_Disciplina();
};

ostream& operator<<(ostream& saida, Departamento& d);

#endif // INCLUDED_DEPARTAMENTO_H
