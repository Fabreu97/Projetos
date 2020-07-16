#ifndef INCLUDED_LISTA_ALUNO_H
#define INCLUDED_LISTA_ALUNO_H

#include "Lista.h"
#include "Aluno.h"

class Universidade;

class ListaAluno
{
private:

    Lista<Aluno> lista;

public:

    ListaAluno();
    ~ListaAluno();

    const int get_Tamanho() const;
    bool incluir_Aluno(Aluno* a);
    void listar_Aluno() const;
    void limpar();
    Aluno* get_Aluno(const int indice) const;
};

#endif // INCLUDED_LISTA_ALUNO_H
