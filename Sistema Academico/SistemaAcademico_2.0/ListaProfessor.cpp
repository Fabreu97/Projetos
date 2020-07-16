#include "ListaProfessor.h"

ListaProfessor::ListaProfessor()
{

}

ListaProfessor::~ListaProfessor()
{
    limpa();
}

const int ListaProfessor::get_Tamanho() const
{
    return(lista.get_Tamanho());
}

bool ListaProfessor::incluir_Professor(Professor* p)
{
    return(lista.incluir_Info(p));
}

void ListaProfessor::limpa()
{
    lista.limpa();
}

void ListaProfessor::listar_Professor() const
{
    int i;
    if(lista.get_Tamanho() > 0)
    {
        for(i = 0; i < lista.get_Tamanho(); i++)
        {
            cout << "\t\t" << lista.get_Info(i)->get_Nome() << " - (" << lista.get_Info(i)->get_ID() << ")" << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "Lista Vazia!!!" << endl;
    }
}

Professor* ListaProfessor::get_Professor(const int indice) const
{
    return(lista.get_Info(indice));
}
