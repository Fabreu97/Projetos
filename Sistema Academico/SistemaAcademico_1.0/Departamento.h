#ifndef INCLUDED_DEPARTAMENTO_H
#define INCLUDED_DEPARTAMENTO_H

#include "Lista2.h"
#include "Disciplina.h"

class Departamento
{
private:

    char* nome;
    int tam;

    Lista2<Disciplina> lista_disciplina;

public:

    Departamento(const char* n = "Default");
    ~Departamento();

    void destroiNome();
    void setNome(const char* n);
    const char* getNome() const;
    void printNome() const;

    void incluirDisciplina(Disciplina* d);
    void limpaDisciplina();

};

#endif // INCLUDED_DEPARTAMENTO_H
