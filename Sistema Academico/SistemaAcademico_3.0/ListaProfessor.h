#ifndef INCLUDED_LISTA_PROFESSORES_H
#define INCLUDED_LISTA_PROFESSORES_H

#include "Professor.h"

class ListaProfessor
{
private:

    Lista<Professor> lista;

public:


    ListaProfessor();
    ~ListaProfessor();

    const int get_Tamanho() const;
    bool incluir_Professor(Professor* p);
    void listar_Professores() const;
    void limpar();
    Professor* get_Professor(const int indice) const;
};

#endif // INCLUDED_LISTA_PROFESSORES_H

