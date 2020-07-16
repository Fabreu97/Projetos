#ifndef INCLUDED_ESTAGIARIO_H
#define INCLUDED_ESTAGIARIO_H

#include "Aluno.h"

class Estagiario: public Aluno
{
private:

    float bolsa_estudo;

public:

    Estagiario(float be = 0, int id = 0, int ra = -1, int d = 0, int m = 0, int a = 0, const char* n = "Default");
    ~Estagiario();

    void set_Bolsa(const float be);
    const float get_Bolsa() const;

    void informa_Proventos() const;
};

#endif // INCLUDED_ESTAGIARIO_H
