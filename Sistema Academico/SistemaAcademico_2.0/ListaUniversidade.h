#ifndef INCLUDED_LISTA_UNIVERSIDADE_H
#define INCLUDED_LISTA_UNIVERSIDADE_H

#include "Universidade.h"
#include "Lista.h"

class ListaUniversidade
{
private:

    Lista<Universidade> lista;

public:

    ListaUniversidade();
    ~ListaUniversidade();

    const int get_Tamanho() const;
    bool incluir_Universidade(Universidade* u);
    void limpa();
    void listar_Universidade() const;
    Universidade* get_Universidade(const int indice) const;
};

#endif // INCLUDED_LISTA_UNIVERSIDADE_H
