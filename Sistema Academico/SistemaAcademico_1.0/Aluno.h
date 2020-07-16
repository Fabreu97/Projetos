#ifndef INCLUDED_ALUNO_H
#define INCLUDED_ALUNO_H

#include "Pessoa.h"

class Aluno:
    public Pessoa
{
private:
    long int RA;

public:
    Aluno(const long int r = -1, int d = 0,int m = 0,int a = 0,const char* n = "");
    ~Aluno();

    void setRA(const long int r);
    const long int getRA() const;
    void print_Idade() const;
};

#endif // INCLUDED_ALUNO_H
