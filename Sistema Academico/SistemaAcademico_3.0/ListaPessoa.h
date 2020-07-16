#ifndef INCLUDED_LISTA_PESSOA_H
#define INCLUDED_LISTA_PESSOA_H

#include "Pessoa.h"

class ListaPessoa
{
private:

    Lista<Pessoa> lista;

public:

    ListaPessoa();
    ~ListaPessoa();

    const int get_Tamanho() const;
    bool incluir_Pessoa(Pessoa* p);
    void listar_Pessoas() const;
    void limpar();
    Pessoa* get_Pessoa(const int indice) const;

    void informa_Proventos() const;

};

#endif // INCLUDED_LISTA_PESSOA_H
