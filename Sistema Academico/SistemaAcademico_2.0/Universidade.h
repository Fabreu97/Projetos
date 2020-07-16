#ifndef INCLUDED_UNIVERSIDADE_H
#define INCLUDED_UNIVERSIDADE_H

#include "Lista_Departamento.h"

class Universidade
{
private:
    int ID;
    char* nome;
    int tam;

    ListaDepartamento LDepartamento;

public:

    Universidade(int id, const char* n = "");
    ~Universidade();

    void set_ID(const int id);
    const int get_ID() const;
    void set_Nome(const char* n);
    const char* get_Nome() const;

    bool incluir_Departamento(Departamento* d);
    void limpa();
    void listar_Departamentos() const;
};

#endif // INCLUDED_UNIVERSIDADE_H
