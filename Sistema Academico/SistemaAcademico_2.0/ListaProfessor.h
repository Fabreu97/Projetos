#ifndef INCLUDED_LISTA_PROFESSOR_H
#define INCLUDED_LISTA_PROFESSOR_H

#include "Lista.h"
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
    void limpa();
    void listar_Professor() const;
    Professor* get_Professor(const int indice) const;
};
#endif // INCLUDED_LISTA_PROFESSOR_H
