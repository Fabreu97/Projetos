#ifndef INCLUDED_LISTA_H
#define INCLUDED_LISTA_H

#include <iostream>
#include "Elemento.h"

using namespace std;

template<class TIPO>
class Lista
{
private:

    int tam;
    Elemento<TIPO>* ptr_primeiro;
    Elemento<TIPO>* ptr_atual;

public:

    Lista();
    ~Lista();

    void inicializar();
    void limpa();
    const int get_Tamanho() const;

    bool incluir_Info(TIPO* t);
    TIPO* get_Info(int indice) const;
    TIPO* eliminar_Info(int indice);
};

template<class TIPO>
Lista<TIPO>::Lista():
    tam(0)
{
    inicializar();
}

template<class TIPO>
Lista<TIPO>::~Lista()
{
    limpa();
    tam = 0;
}

template<class TIPO>
void Lista<TIPO>::inicializar()
{
    ptr_primeiro = NULL;
    ptr_atual = NULL;
}

template<class TIPO>
void Lista<TIPO>::limpa()
{
    Elemento<TIPO>* aux = NULL;
    aux = ptr_primeiro;

    while(aux != NULL)
    {
        ptr_primeiro = ptr_primeiro->get_Proximo();
        delete(aux);
        tam--;
        aux = ptr_primeiro;
    }
    inicializar();
}

template<class TIPO>
bool Lista<TIPO>::incluir_Info(TIPO* t)
{
    if(t != NULL)
    {
        tam++;
        Elemento<TIPO>* aux;
        aux = new Elemento<TIPO>();
        aux->set_Info(t);

        if(ptr_primeiro == NULL)
        {
            ptr_primeiro = aux;
            ptr_atual = aux;
        }
        else
        {
            ptr_atual->set_Proximo(aux);
            aux->set_Anterior(ptr_atual);
            ptr_atual = aux;
        }
        return(true);
    }
    else
    {
        cout << "Erro, informacao nao adicionada!!!" << endl;
        return(false);
    }
}

template<class TIPO>
const int Lista<TIPO>::get_Tamanho() const
{
    return(tam);
}

template<class TIPO>
TIPO* Lista<TIPO>::get_Info(int indice) const
{
    Elemento<TIPO>* aux = ptr_primeiro;
    int i = 0;

    while( (i != indice) && (aux != NULL) )
    {
        i++;
        aux = aux->get_Proximo();
    }

    if(aux != NULL)
    {
        return(aux->get_Info());
    }
    else
    {
        return(NULL);
    }
}

template<class TIPO>
TIPO* Lista<TIPO>::eliminar_Info(int indice)
{
    Elemento<TIPO>* aux1;
    Elemento<TIPO>* aux2;
    aux1 = ptr_primeiro;
    aux2 = NULL;
    int i = 0;

    while( (aux1 != NULL) && (indice != i) )
    {
        aux2 = aux1;
        i++;
        aux1 = aux1->get_Proximo();
    }

    if(aux1 == NULL)
    {
        cout << "Lista Vazia ou indice Invalido !!!" << endl;
        return(NULL);
    }
    else if(aux2 == NULL)
    {
        ptr_primeiro = aux1->get_Proximo();
        if(ptr_primeiro != NULL)
        {
            ptr_primeiro->set_Anterior(NULL);
        }
        TIPO* aux3 = aux1->get_Info();
        delete(aux1);
        tam--;
        return(aux3);
    }
    else
    {
        aux2->set_Proximo(aux1->get_Proximo());
        if(aux1->get_Proximo() != NULL)
        {
            aux1->get_Proximo()->set_Anterior(aux2);
        }
        TIPO* aux3 = aux1->get_Info();
        delete(aux1);
        tam--;
        return(aux3);
    }
}

#endif // INCLUDED_LISTA_H
