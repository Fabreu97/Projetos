#ifndef INCLUDED_LISTA_DEPARTAMENTO_H
#define INCLUDED_LISTA_DEPARTAMENTO_H

#include "Lista.h"
#include "Departamento.h"

class ListaDepartamento
{
private:

    Lista<Departamento> lista;

public:

    ListaDepartamento();
    ~ListaDepartamento();

    const int get_Tamanho() const;
    bool incluir_Departamento(Departamento* d);
    void limpa();
    void listar_Departamento() const;
    Departamento* get_Departamento(const int indice) const;
};

#endif // INCLUDED_LISTA_DEPARTAMENTO_H
