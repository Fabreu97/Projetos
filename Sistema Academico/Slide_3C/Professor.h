#ifndef INCLUDED_PROFESSOR_H
#define INCLUDED_PROFESSOR_H

#include "Pessoa.h"
#include "Universidade.h"

class Professor:
    public Pessoa
{
private:
    Departamento* ptr_depar;

public:
    Professor( int diaNa = 0, int mesNa = 0, int anoNa = 0,const char* n = "");
    ~Professor();

    void set_Departamento(Departamento* d);

    void QualDepartamentoTrabalha();
};

#endif // INCLUDED_PROFESSOR_H
