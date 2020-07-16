#ifndef INCLUDED_ELEMENTO2
#define INCLUDED_ELEMENTO2

template<class TIPO>
class Elemento2
{
private:
    TIPO* ptr_info;
    Elemento2<TIPO>* ptr_prox;
    Elemento2<TIPO>* ptr_anterior;

public:
    Elemento2();
    ~Elemento2();

    void setInformacao(TIPO* t);
    TIPO* getInformacao();

    void setProximo(Elemento2<TIPO>* e);
    Elemento2<TIPO>* getProximo();

    void setAnterior(Elemento2<TIPO>* e);
    Elemento2<TIPO>*  getAnterior();

};

template<class TIPO>
Elemento2<TIPO>::Elemento2()
{
    ptr_info = NULL;
    ptr_anterior = NULL;
    ptr_prox = NULL;
}

template<class TIPO>
Elemento2<TIPO>::~Elemento2()
{
    ptr_info = NULL;
    ptr_anterior = NULL;
    ptr_prox = NULL;
}

template<class TIPO>
void Elemento2<TIPO>::setInformacao(TIPO* t)
{
    ptr_info = t;
}

template<class TIPO>
TIPO* Elemento2<TIPO>::getInformacao()
{
    return(ptr_info);
}

template<class TIPO>
void Elemento2<TIPO>::setProximo(Elemento2<TIPO>* e)
{
    ptr_prox = e;
}

template<class TIPO>
Elemento2<TIPO>* Elemento2<TIPO>::getProximo()
{
    return(ptr_prox);
}

template<class TIPO>
void Elemento2<TIPO>::setAnterior(Elemento2<TIPO>* e)
{
    ptr_anterior = e;
}

template<class TIPO>
Elemento2<TIPO>* Elemento2<TIPO>::getAnterior()
{
    return(ptr_anterior);
}

#endif // INCLUDED_ELEMENTO2
