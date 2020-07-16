#ifndef INCLUDED_DEPARTAMENTO_H
#define INCLUDED_DEPARTAMENTO_H

class Universidade;

class Departamento
{
private:

    char nome[50];
    Universidade* ptr_univer;

public:
    Departamento(const char* n = "");
    ~Departamento();

    void set_Nome(char* n);
    char* get_Nome();

    void set_Universidade(Universidade* u);
    Universidade* get_Universidade();

};

#endif // INCLUDED_DEPARTAMENTO_H
