#ifndef LISTA_DEPARTAMENTO_H
#define LISTA_DEPARTAMENTO_H

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
    void listar_Departamentos() const;
    void limpar();
    Departamento* get_Departamento(const int indice) const;
};



#endif // LISTA_DEPARTAMENTO_H
