#ifndef INCLUDED_PESSOA_H
#define INCLUDED_PESSOA_H

#include <iostream>

class Pessoa
{
private:
    int dia;
    int mes;
    int ano;
    int idade;

public:

    Pessoa(); // Essa e unica diferença da versão do slide 1B com esse projeto que é um construtor da class sem parametro
    Pessoa(int d, int m, int a);
    ~Pessoa();

    void calculo_Idade(int da, int ma, int aa);
    int informa_Idade();
};

#endif // INCLUDED_PESSOA_H
