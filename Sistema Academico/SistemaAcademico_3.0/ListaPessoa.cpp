#include "ListaPessoa.h"

ListaPessoa::ListaPessoa():
    lista()
{

}

ListaPessoa::~ListaPessoa()
{

}

const int ListaPessoa::get_Tamanho() const
{
    return(lista.get_Tamanho());
}

bool ListaPessoa::incluir_Pessoa(Pessoa* p)
{
    return(lista.incluir_Info(p));
}

void ListaPessoa::listar_Pessoas() const
{
    int i;
    Pessoa* aux;

    for(i = 0; i < lista.get_Tamanho(); i++)
    {
        aux = lista.get_Info(i);
        cout << "\t\t" << *aux << endl;
    }
    cout << endl;
}

void ListaPessoa::limpar()
{
    lista.limpar();
}

Pessoa* ListaPessoa::get_Pessoa(const int indice) const
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

void ListaPessoa::informa_Proventos() const
{
    int i;

    for(i = 0; i < this->get_Tamanho(); i++)
    {
        get_Pessoa(i)->informa_Proventos();
    }
}
