#include "ListaDisciplina.h"

ListaDisciplina::ListaDisciplina():
    lista()
{

}
ListaDisciplina::~ListaDisciplina()
{

}

const int ListaDisciplina::get_Tamanho() const
{
    return(lista.get_Tamanho());
}

bool ListaDisciplina::incluir_Disciplina(Disciplina* d)
{
    return(lista.incluir_Info(d));
}

void ListaDisciplina::listar_Disciplinas() const
{
    Disciplina* aux;
    int i;

    if(lista.get_Tamanho() > 0)
    {
        for(i = 0; i < lista.get_Tamanho(); i++)
        {
            aux = lista.get_Info(i);
            cout << *aux << " (" << aux->get_ID() << ")" << endl;
        }
        cout << endl;
    }
}

void ListaDisciplina::limpar()
{
    lista.limpar();
}

Disciplina* ListaDisciplina::get_Disciplina(const int indice) const
{
    if(indice >= 0 && indice < lista.get_Tamanho())
    {
        return(lista.get_Info(indice));
    }
    else
    {
        return(NULL);
    }
}
