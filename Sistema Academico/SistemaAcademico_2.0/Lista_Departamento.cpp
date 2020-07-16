#include "Lista_Departamento.h"

ListaDepartamento::ListaDepartamento()
{
}

ListaDepartamento::~ListaDepartamento()
{
    this->limpa();
}

const int ListaDepartamento::get_Tamanho() const
{
    return(lista.get_Tamanho());
}

bool ListaDepartamento::incluir_Departamento(Departamento* d)
{
    return(lista.incluir_Info(d));
}

void ListaDepartamento::limpa()
{
    lista.limpa();
}

void ListaDepartamento::listar_Departamento() const
{
    if(lista.get_Tamanho() > 0)
    {
        int i;

        for(i = 0; i < lista.get_Tamanho(); i++)
        {
            cout << "\t\t" << lista.get_Info(i)->get_Nome() << endl;
        }
        cout << endl;

    }
    else
    {
        cout << "Lista Vazia!!!" << endl;
    }
}

Departamento* ListaDepartamento::get_Departamento(const int indice) const
{
    return(lista.get_Info(indice));
}
