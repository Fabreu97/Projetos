#ifndef INCLUDED_DISCIPLINA_H
#define INCLUDED_DISCIPLINA_H

#include "Aluno.h"
#include "Professor.h"
#include "Lista2.h"

class Disciplina
{
private:

    char* nome;
    int tam;

    Lista2<Aluno> lista_aluno;
    Professor* p;

public:
    Disciplina(const char* n = "Default", const int v = 44);
    ~Disciplina();

    void destroiNome();
    void setNome(const char* n);
    const char* getNome() const;

    void incluirAluno(Aluno* a);
    void incluirProfessor(Professor* prof);
    Professor* getProfessor() const;

    void limpaListaAluno();
    void demitirProfessor();
    void listarAlunoDisciplina();

};
#endif // INCLUDED_DISCIPLINA_H
