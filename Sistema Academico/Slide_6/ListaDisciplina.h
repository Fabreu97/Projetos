#ifndef INCLUDED_LISTA_DISCIPLINA_H
#define INCLUDED_LISTA_DISCIPLINA_H

#include "ElDisciplina.h"

class ListaDisciplina
{
private:

    int max_disc;
    int cont_disc;

    ElDisciplina* ptr_atual;
    ElDisciplina* ptr_primeiro;

public:
    ListaDisciplina(int nd = 45);
    ~ListaDisciplina();

    void inclua_Disciplina(Disciplina* d);
    void liste_Disciplina();
    void liste_Disciplina2();
};

#endif // INCLUDED_LISTA_DISCIPLINA_H
