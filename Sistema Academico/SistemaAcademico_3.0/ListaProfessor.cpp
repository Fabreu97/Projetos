#include "ListaProfessor.h"

ListaProfessor::ListaProfessor():
    lista()
{

}

ListaProfessor::~ListaProfessor()
{

}

const int ListaProfessor::get_Tamanho() const
{
    return(lista.get_Tamanho());
}

bool ListaProfessor::incluir_Professor(Professor* p)
{
    return(lista.incluir_Info(p));
}

void ListaProfessor::listar_Professores() const
{
    int i;
    Professor* aux;

    if(lista.get_Tamanho() > 0)
    {
        for(i = 0; i < get_Tamanho(); i++)
        {
            aux = lista.get_Info(i);
            aux->print_Info();
            //cout << aux->get_Nome() << "(" << aux->get_ID() << ")" << endl;
            //cout << "Idade: " << aux->get_Idade() << " anos" <<  endl << endl;
        }
        cout << endl;
    }
}

void ListaProfessor::limpar()
{
    lista.limpar();
}

Professor* ListaProfessor::get_Professor(const int indice) const
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
