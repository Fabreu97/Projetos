#include "Universidade.h"
#include <string.h>
#include <iostream>


Universidade::Universidade(const char* n)
{
    if(n != NULL)
    {
        strcpy(nome, n);
    }
}

Universidade::~Universidade()
{

}

void Universidade::set_Nome(const char* n)
{
    if(n != NULL)
    {
        strcpy(nome, n);
    }
}

const char* Universidade::get_Nome() const
{
    return(nome);
}

void Universidade::set_Departamento(Departamento* d)
{
    LpDpto.push_back(d);
}

void Universidade::imprimir_Departamentos()
{
    list<Departamento*>::iterator it;

    cout << endl << "Os Departamentos da " << get_Nome() << " sao:" << endl << endl;


    for(it = LpDpto.begin(); it != LpDpto.end(); it++)
    {
        cout << "\t\t" << (*it)->get_Nome() << endl;
    }
}
