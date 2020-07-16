#ifndef INCLUDED_LISTA_DISCIPLINA_H
#define INCLUDED_LISTA_DISCIPLINA_H

#include "Disciplina.h"

class ListaDisciplina
{
private:

    Lista<Disciplina> lista;

public:

    ListaDisciplina();
    ~ListaDisciplina();

    const int get_Tamanho() const;
    bool incluir_Disciplina(Disciplina* d);
    void listar_Disciplinas() const;
    void limpar();
    Disciplina* get_Disciplina(const int indice) const;
};


#endif // INCLUDED_LISTA_DISCIPLINA_H
