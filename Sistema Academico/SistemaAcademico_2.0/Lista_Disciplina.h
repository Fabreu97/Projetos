#ifndef INCLUDED_LISTA_DISCIPLINA_H
#define INCLUDED_LISTA_DISCIPLINA_H

#include "Lista.h"
#include "Disciplina.h"

class ListaDisciplina
{
private:

    Lista<Disciplina> lista_disciplina;

public:

    ListaDisciplina();
    ~ListaDisciplina();

    const int get_Tamanho() const;
    bool incluir_Disciplina(Disciplina* d);
    void limpa();
    void listar_Disciplinas() const;
    Disciplina* get_Disciplina(const int indice) const;
};

#endif // INCLUDED_LISTA_DISCIPLINA_H
