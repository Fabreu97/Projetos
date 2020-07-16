#ifndef INCLUDED_PROFESSOR_H
#define INCLUDED_PROFESSOR_H

#include "Pessoa.h"

class Professor:public Pessoa
{
public:

    Professor(int d = 0,int m = 0,int a = 0,const char* n = "");
    ~Professor();

    void print_Idade() const;
};
#endif // INCLUDED_PROFESSOR_H
