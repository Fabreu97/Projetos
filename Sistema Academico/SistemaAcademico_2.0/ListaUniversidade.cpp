#include "ListaUniversidade.h"

ListaUniversidade::ListaUniversidade()
{

}

ListaUniversidade::~ListaUniversidade()
{
    limpa();
}

const int ListaUniversidade::get_Tamanho() const
{
    return(lista.get_Tamanho());
}

bool ListaUniversidade::incluir_Universidade(Universidade* u)
{
    return(lista.incluir_Info(u));
}

void ListaUniversidade::limpa()
{
    lista.limpa();
}

void ListaUniversidade::listar_Universidade() const
{
    if(lista.get_Tamanho() > 0)
    {
        int i;
        for(i = 0; i < get_Tamanho(); i++)
        {
            cout << "\t\t" <<lista.get_Info(i)->get_Nome() << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "Lista Vazia!!!" << endl;
    }
}

Universidade* ListaUniversidade::get_Universidade(const int indice) const
{
    return(lista.get_Info(indice));
}
