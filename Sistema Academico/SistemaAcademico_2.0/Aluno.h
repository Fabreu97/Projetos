#ifndef INCLUDED_ALUNO_H
#define INCLUDED_ALUNO_H

#include "Pessoa.h"

class Universidade;

class Aluno:
    public Pessoa
{
private:

    int ID;
    int RA;
    Universidade* ptr_univer;

public:

    Aluno(int id = 0, int ra = -1, int d = 0, int m = 0, int a = 0, const char* n = "Default");
    ~Aluno();

    void set_RA(const int r);
    const int get_RA() const;
    void set_ID(const int id);
    const int get_ID() const;

    void set_Universidade(Universidade* u);
    Universidade* get_Universidade() const;

    void print_Info();
};


#endif // INCLUDED_ALUNO_H
