#ifndef INCLUDED_LISTA2
#define INCLUDED_LISTA2

#include <iostream>
#include "Elemento2.h"

using namespace std;

template<class TIPO>
class Lista2
{
private:
    int max_info;
    int cont_info;

    Elemento2<TIPO>* ptr_atual;
    Elemento2<TIPO>* ptr_primeiro;

public:

    Lista2(const int a = 100);
    ~Lista2();

    void incluirInformacao(TIPO* t);
    void limpa();

    TIPO* getInformacao(int indice);
    const int getTamanho() const;
};

template<class TIPO>
Lista2<TIPO>::Lista2(const int a):
    max_info(a)
{
    ptr_atual = NULL;
    ptr_primeiro = NULL;
    cont_info = 0;
}

template<class TIPO>
Lista2<TIPO>::~Lista2()
{
    limpa();
}

template<class TIPO>
void Lista2<TIPO>::incluirInformacao(TIPO* t)
{
    Elemento2<TIPO>* aux = NULL;
    aux = new Elemento2<TIPO>();
    aux->setInformacao(t);
    if(t != NULL && cont_info < max_info)
    {
        if(cont_info == 0)
        {
            ptr_atual = aux;
            ptr_primeiro = aux;
            cont_info++;
        }
        else
        {
            ptr_atual->setProximo(aux);
            aux->setAnterior(ptr_atual);
            ptr_atual = aux;

            cont_info++;
        }
    }
    else
    {
        cout << "Lista cheia!!! Elemento nao inserido!!!" << endl;
    }
}

template<class TIPO>
void Lista2<TIPO>::limpa()
{
    Elemento2<TIPO>* aux;
    aux = ptr_primeiro;
    while(aux != NULL)
    {
        ptr_primeiro = ptr_primeiro->getProximo();
        delete(aux);
        aux = ptr_primeiro;
    }

    ptr_atual = NULL;
    ptr_primeiro = NULL;
}

template<class TIPO>
TIPO* Lista2<TIPO>::getInformacao(int indice)
{

    int i;
    if(ptr_primeiro)
    {
        if(indice == 0)
        {
            return(ptr_primeiro->getInformacao());
        }
        else if(indice > 0 && indice < max_info)
        {
            Elemento2<TIPO>* aux = ptr_primeiro;
            for(i = 0; i < getTamanho(); i++)
            {
                if(i == indice)
                {
                    return(aux->getInformacao());
                }
                aux = aux->getProximo();
            }
            return(NULL);
        }

        else
        {
            return(NULL);
        }
    }
    return(NULL);
}

template<class TIPO>
const int Lista2<TIPO>::getTamanho() const
{
    return(cont_info);
}
#endif // INCLUDED_LISTA2
