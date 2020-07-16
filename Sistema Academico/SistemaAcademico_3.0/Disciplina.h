#ifndef INCLUDED_DISCIPLINA_H
#define INCLUDED_DISCIPLINA_H

#include "ListaAluno.h"

class Departamento;

class Disciplina
{
private:

    int ID;
    ConjuntoString::MinhaString nome;

    ListaAluno LAluno;
    Departamento* ptr_depar;

public:

    Disciplina(int id = 0, const char* n = "");
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

ostream& operator<<(ostream& saida, Disciplina& d);

#endif // INCLUDED_DISCIPLINA_H
