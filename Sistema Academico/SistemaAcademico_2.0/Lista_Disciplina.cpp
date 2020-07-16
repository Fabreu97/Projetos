#include "Lista_Disciplina.h"

ListaDisciplina::ListaDisciplina()
{

}

ListaDisciplina::~ListaDisciplina()
{

}

const int ListaDisciplina::get_Tamanho() const
{
    return(lista_disciplina.get_Tamanho());
}

bool ListaDisciplina::incluir_Disciplina(Disciplina* d)
{
    return(lista_disciplina.incluir_Info(d));
}

void ListaDisciplina::limpa()
{
    lista_disciplina.limpa();
}

void ListaDisciplina::listar_Disciplinas() const
{
    if(lista_disciplina.get_Tamanho() > 0)
    {
        int i;
        for(i = 0; i < lista_disciplina.get_Tamanho(); i++)
        {
            cout << "\t\t" << lista_disciplina.get_Info(i)->get_Nome() << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "Lista Vazia!!!" << endl;
    }
}

Disciplina* ListaDisciplina::get_Disciplina(const int indice) const
{
    return(lista_disciplina.get_Info(indice));
}
