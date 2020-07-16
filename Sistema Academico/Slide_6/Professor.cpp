#include "Professor.h"

Professor::Professor(int diaNa, int mesNa, int anoNa,const char* n):
    Pessoa(diaNa, mesNa, anoNa, n)
    {
        ptr_depar = NULL;
        ptr_univer = NULL;
    }

Professor::~Professor()
{
    ptr_depar = NULL;
    ptr_univer = NULL;
}

void Professor::set_Departamento(Departamento* d)
{
    ptr_depar = d;
}

void Professor::QualDepartamentoTrabalha()
{
    cout << "O Professor " << get_Nome() << "da " << ptr_univer->get_Nome() << " trabalha no Departamento " << ptr_depar->get_Nome() << endl;
}
