#ifndef INCLUDED_LISTA_TEMPLATE
#define iNCLUDED_LISTA_TEMPLATE

template<class TIPO>
class ListaT
{
private:

    class ElementoT
    {
    private:
        TIPO* ptr_info;
        ElementoT* ptr_prox;
        ElementoT* ptr_anterior;

    public:
        ElementoT();
        ~ElementoT();

        void set_Proximo(ElementoT* pp);
        void set_Anterior(ElementoT* pa);

        void set_Info(TIPO* t);
        TIPO* get_Info() const;
    };

    int tam;
    ElementoT* ptr_primeiro;
    ElementoT* ptr_atual;

public:

    ListaT();
    ~ListaT();

    void inicializar();
    void limpar();
    const int get_Tamanho() const;

    bool incluir_Info(TIPO* t);
    TIPO* get_Info(const int indice) const;
    TIPO* eliminar_Info(int indice);
};

///....................Métodos do Elemento....................

template<class TIPO>
ListaT<TIPO>::ElementoT::ElementoT()
{
    ptr_anterior = NULL;
    ptr_prox = NULL;
    ptr_info = NULL;
}

template<class TIPO>
ListaT<TIPO>::ElementoT::~ElementoT()
{
    ptr_anterior = NULL;
    ptr_prox = NULL;
    ptr_info = NULL;
}

template<class TIPO>
void ListaT<TIPO>::ElementoT::set_Proximo(ElementoT* pp)
{
    ptr_prox = pp;
}

template<class TIPO>
void ListaT<TIPO>::ElementoT::set_Anterior(ElementoT* pa)
{
    ptr_anterior = pa;
}

template<class TIPO>
TIPO* ListaT<TIPO>::ElementoT::get_Info() const
{
    return(ptr_info);
}

///....................Métodos da Lista Template.......................

template<class TIPO>
ListaT<TIPO>::ListaT():
    tam(0)
{
    inicializar();
}

template<class TIPO>
ListaT<TIPO>::~ListaT()
{
    limpar();
}

template<class TIPO>
void ListaT<TIPO>::inicializar()
{
    ptr_atual = NULL;
    ptr_primeiro = NULL;
}

template<class TIPO>
void ListaT<TIPO>::limpar()
{
    ElementoT* aux = ptr_primeiro;

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
const int ListaT<TIPO>::get_Tamanho() const
{
    return(tam);
}

template<class TIPO>
bool ListaT<TIPO>::incluir_Info(TIPO* t)
{
    if(t != NULL)
    {
        ElementoT* aux = new ElementoT();
        aux->set_Info(t);
        tam++;
        if(ptr_primeiro == NULL)
        {
            ptr_primeiro = aux;
            ptr_atual = aux;
        }
        else
        {
            ptr_atual->setProximo(aux);
            aux->setAnterior(ptr_atual);
            ptr_atual = aux;
        }
        return(true);
    }
    return(false);
}

template<class TIPO>
TIPO* ListaT<TIPO>::get_Info(const int indice) const
{
    int i;

    if(tam > indice)
    {
        ElementoT* aux = ptr_primeiro;
        for(i = 0; i < indice; i++)
        {
            aux = aux->ptr_prox;
        }
        return(aux->get_Info());
    }

    return(NULL);
}

template<class TIPO>
TIPO* ListaT<TIPO>::eliminar_Info(int indice)
{
    ElementoT* aux1 = NULL;
    ElementoT* aux2 = ptr_primeiro;

    int i = 0;

    while(aux2 != NULL && i != indice)
    {
        aux1 = aux2;
        aux2 = aux2->ptr_prox;
        i++;
    }

    if(aux1 == NULL)
    {
        return(NULL); //Lista Vazia
    }
    else if(aux2 == NULL)
    {
        return(NULL);
    }
    else if(indice == i)
    {
        ElementoT* aux3;
        TIPO* pt;
        aux3 = aux2->ptr_prox;
        if(aux3 == NULL)
        {
            aux2->set_Anterior(NULL);
            aux1->set_Proximo(NULL);
        }
        else
        {
            aux3.set_Anterior(aux1);
            aux1->set_Proximo(aux3);

            aux2->set_Anterior(NULL);
            aux2->set_Proximo(NULL);
        }
        pt = aux2->get_Info();
        delete(aux2);
        tam--;
        return(pt);
    }
    else
    {
        return(NULL);
    }
}

#endif // INCLUDED_LISTA_2
