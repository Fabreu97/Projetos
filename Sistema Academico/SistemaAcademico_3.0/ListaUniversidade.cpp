#include "ListaUniversidade.h"

ListaUniversidade::ListaUniversidade():
    lista()
    {

    }
ListaUniversidade::~ListaUniversidade()
{

}

const int ListaUniversidade::get_Tamanho() const
{
    return(lista.get_Tamanho());
}

bool ListaUniversidade::incluir_Universidade(Universidade* u)
{
    return(lista.incluir_Info(u));
}

void ListaUniversidade::listar_Universidades() const
{
    int i;
    Universidade* aux;

    if(lista.get_Tamanho() > 0)
    {
        for(i = 0; i < lista.get_Tamanho(); i++)
        {
            aux = lista.get_Info(i);
            cout << aux->get_Nome() << endl;
        }
        cout << endl;
    }
}

void ListaUniversidade::limpar()
{
    lista.limpar();
}

Universidade* ListaUniversidade::get_Universidade(const int indice) const
{
    if(indice >= 0 && indice < get_Tamanho())
    {
        return(lista.get_Info(indice));
    }
    else
    {
        return(NULL);
    }
}
