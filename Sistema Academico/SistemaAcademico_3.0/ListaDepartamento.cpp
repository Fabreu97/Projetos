#include "ListaDepartamento.h"

ListaDepartamento::ListaDepartamento():
    lista()
{

}

ListaDepartamento::~ListaDepartamento()
{

}

const int ListaDepartamento::get_Tamanho() const
{
    return(lista.get_Tamanho());
}

bool ListaDepartamento::incluir_Departamento(Departamento* d)
{
    return(lista.incluir_Info(d));
}

void ListaDepartamento::listar_Departamentos() const
{
    int i;
    Departamento* aux;

    if(lista.get_Tamanho() > 0)
    {
        for(i = 0; i < lista.get_Tamanho(); i++)
        {
            aux = lista.get_Info(i);
            cout << *aux << " (" << aux->get_ID() << ")" << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "Lista VAZIA!!!" << endl;
    }
}

void ListaDepartamento::limpar()
{
    lista.limpar();
}

Departamento* ListaDepartamento::get_Departamento(const int indice) const
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
