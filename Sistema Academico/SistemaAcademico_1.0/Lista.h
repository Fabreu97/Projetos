#ifndef INLCUDED_LISTA_H
#define INCLUDED_LISTA_H

#include "Aluno.h"

template<class TIPO>
class Lista
{
public:
    //template<class TIPO>
    class Elemento
    {
    private:

        TIPO* ptr_info;
        Elemento* ptr_prox;
        Elemento* ptr_ant;

    public:

        Elemento();
        ~Elemento();

        void setProximo(Elemento* pprox);
        Elemento* getProximo() const;

        void setAnterior(Elemento* pant);
        Elemento* getAnterior() const ;

        void setInformacao(TIPO* pi);
        TIPO* getInformacao() const;
    };

    //Metódos da Lista
    Lista();
    ~Lista();

    void inicializar();
    void limpar();

    void incluaElemento(Elemento* e);
    void incluaInformacao(TIPO* t);

    //Atributos da Lista
private:

    Elemento* ptr_primeiro;
    Elemento* ptr_atual;
};

//metodos da class Lista

template<class TIPO>
Lista<TIPO>::Lista()
{
    ptr_atual = NULL;
    ptr_primeiro = NULL;
}


//metodos da class elemento
template<class TIPO>
Lista<TIPO>::Elemento::Elemento()
{
    ptr_info = NULL;
    ptr_ant = NULL;
    ptr_prox = NULL;
}
template<class TIPO>
Lista<TIPO>::Elemento::~Elemento()
{
    ptr_info = NULL;
    ptr_ant = NULL;
    ptr_prox = NULL;
}

template<class TIPO>
void Lista<TIPO>::Elemento::setProximo(Elemento* pprox)
{
    ptr_prox = pprox;
}

template<class TIPO>
Lista<TIPO>::Elemento* Lista<TIPO>::Elemento::getProximo() const
{
    return(ptr_prox);
}

template<class TIPO>
void Lista<TIPO>::Elemento::setAnterior(Elemento* pant)
{
    ptr_ant = pant;
}

template<class TIPO>
Lista<TIPO>::Elemento* Elemento::getAnterior() const
{
    return(ptr_ant);
}

template<class TIPO>
void Lista<TIPO>::Elemento::setInformacao(TIPO* pinfo)
{
    ptr_info = pinfo;
}

template<class TIPO>
TIPO* Lista<TIPO>::Elemento::getInformacao() const
{
    return(ptr_info);
}

#endif // INLCUDED_LISTA_H
