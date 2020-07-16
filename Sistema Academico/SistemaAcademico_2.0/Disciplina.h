#ifndef INCLUDED_DISCIPLINA_H
#define INCLUDED_DISCIPLINA_H

#include <stdio.h>
#include <stdlib.h>
#include "Lista_Aluno.h"

class Departamento;

class Disciplina
{
private:

    int ID;
    char* nome;
    int tam;

    ListaAluno LAluno;
    Departamento* ptr_depar;

public:

    Disciplina(int id = 0, const char* n = NULL);
    ~Disciplina();

    void set_ID(const int id);
    const int get_ID() const;

    void set_Nome(const char* n);
    const char* get_Nome() const;

    void set_Departamento(Departamento* d);
    Departamento* get_Departamento() const;

    bool incluir_Aluno(Aluno* a);
    void limpa();
    void listar_Aluno();

};

#endif // INCLUDED_DISCIPLINA_H
