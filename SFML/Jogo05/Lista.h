#ifndef INCLUDED_LISTA_TEMPLATE
#define iNCLUDED_LISTA_TEMPLATE

#include <stdio.h>

//fazer o iterator e o metodo find

template <class TIPO>
class Lista
{
private:

    class Elemento
    {
    public:

        TIPO* ptr_info;
        Elemento* ptr_prox;
        Elemento* ptr_anterior;
    public:

        Elemento();
        ~Elemento();

        void set_Proximo(Elemento* pp);
        void set_Anterior(Elemento* pa);

        void set_Info(TIPO* t);
        TIPO* get_Info() const;
    };

    unsigned long int tam;
    Elemento* ptr_primeiro;
    Elemento* ptr_atual;

public:

    Lista();
    ~Lista();

    void inicializar();
    void limpar();
    const unsigned long int get_Tamanho() const;

    const bool inserir(TIPO* t);
    //bool incluir_Info(TIPO& t);
    TIPO* get_Info(const unsigned long int indice) const;
    void eliminar_Info(const unsigned long int indice); //  REVIEW
};

///........................Métodos do Elemento........................

template<class TIPO>
Lista<TIPO>::Elemento::Elemento()
{
    ptr_anterior = NULL;
    ptr_prox = NULL;
    ptr_info = NULL;
}

template<class TIPO>
Lista<TIPO>::Elemento::~Elemento()
{
    ptr_anterior = NULL;
    ptr_prox = NULL;
    ptr_info = NULL;
}

template<class TIPO>
void Lista<TIPO>::Elemento::set_Proximo(Elemento* pp)
{
    ptr_prox = pp;
}

template<class TIPO>
void Lista<TIPO>::Elemento::set_Anterior(Elemento* pa)
{
    ptr_anterior = pa;
}

template<class TIPO>
void Lista<TIPO>::Elemento::set_Info(TIPO* t)
{
    ptr_info = t;
}

template<class TIPO>
TIPO* Lista<TIPO>::Elemento::get_Info() const
{
    return(ptr_info);
}

///....................Métodos da Lista Template.......................

template<class TIPO>
Lista<TIPO>::Lista():
    tam(0)
{
    inicializar();
}

template<class TIPO>
Lista<TIPO>::~Lista()
{
    limpar();
}

template<class TIPO>
void Lista<TIPO>::inicializar()
{
    ptr_atual = NULL;
    ptr_primeiro = NULL;
}

template<class TIPO>
void Lista<TIPO>::limpar()
{
    Elemento* aux = ptr_primeiro;

    while(aux != NULL)
    {
        ptr_primeiro = ptr_primeiro->ptr_prox;
        delete(aux);
        tam--;
        aux = ptr_primeiro;
    }
    inicializar();
}

template <class TIPO>
const unsigned long int Lista<TIPO>::get_Tamanho() const
{
    return(tam);
}

template<class TIPO>
const bool Lista<TIPO>::inserir(TIPO* t)
{
    if(t != NULL)
    {
        Elemento* aux = new Elemento();
        aux->set_Info(t);
        tam++;
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
    return(false);
}

/*
template<class TIPO>
bool Lista<TIPO>::incluir_Info(TIPO& t)
{
    Elemento* aux = new Elemento();
    aux->set_Info(&t);
    tam++;
    if(ptr_primeiro == NULL)
    {
        ptr_primeiro = aux;
        ptr_atual = aux;
        return(true);
    }
    else
    {
        ptr_atual->set_Proximo(aux);
        aux->set_Anterior(ptr_atual);
        ptr_atual = aux;
        return(true);
    }
}
*/

template<class TIPO>
TIPO* Lista<TIPO>::get_Info(const unsigned long int indice) const
{
    unsigned long int i;

    if(tam > indice)
    {
        Elemento* aux = ptr_primeiro;
        for(i = 0lu; i < indice; i++)
        {
            aux = aux->ptr_prox;
        }
        return(aux->get_Info());
    }

    return(NULL);
}



template<class TIPO>//...............TO REVIEW...............
void Lista<TIPO>::eliminar_Info(const unsigned long int indice)
{
    Elemento* aux1 = NULL;
    Elemento* aux2 = NULL;

    aux2 = ptr_primeiro;

    unsigned long int i = 0;

    while(aux2 != NULL && i != indice)
    {
        aux1 = aux2;
        aux2 = aux2->ptr_prox;
        i++;
    }

    //se indice for 0
    if(aux1 == NULL)
    {
        if(indice == 0)
        {
            ptr_primeiro = aux2->ptr_prox;
            delete(aux2);
            tam--;
        }
    }
    else if(aux2 != NULL)
    {
        aux1->set_Proximo(aux2->ptr_prox);
        if(aux2->ptr_prox != NULL)
        {
            aux2->ptr_prox->set_Anterior(aux1);
        }
        else
        {
            ptr_atual = aux1;
        }
        aux2->set_Anterior(NULL);
        aux2->set_Proximo(NULL);
        delete(aux2);
        tam--;
    }
}

#endif // INCLUDED_LISTA_TEMPLATE
