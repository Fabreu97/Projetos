#include "Universidade.h"
#include <string.h>
#include <iostream>

using namespace std;

Universidade::Universidade(const char* n)
{
    if(n != NULL)
    {
        strcpy(nome, n);
    }
    int i;
    for(i = 0; i < 50; i++)
    {
        ptr_depar[i] = NULL;
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

void Universidade::set_Departamento(Departamento* d, int cont)
{
    ptr_depar[cont] = d;
}

void Universidade::imprimir_Departamentos()
{
    int i;

    cout << "Os Departamentos da Universidade " << get_Nome() << " sao: " << endl << endl;
    for(i = 0; i < 50; i++)
    {
        if(ptr_depar[i] != NULL)
        {
            cout << ptr_depar[i]->get_Nome() << endl;
        }
    }

    cout << endl << endl;
}
