#ifndef INCLUDED_ELEMENTO_H
#define INCLUDED_ELEMENTO_H

template<class TIPO>
class Elemento
{
private:

    TIPO* ptr_info;
    Elemento<TIPO>* ptr_prox;
    Elemento<TIPO>* ptr_ante;

public:

    Elemento();
    ~Elemento();

    void set_Proximo(Elemento<TIPO>* pp);
    Elemento<TIPO>* get_Proximo() const;

    void set_Anterior(Elemento<TIPO>* pa);
    Elemento<TIPO>* get_Anterior() const;

    void set_Info(TIPO* t);
    TIPO* get_Info() const;
};

template<class TIPO>
Elemento<TIPO>::Elemento()
{
    ptr_ante = NULL;
    ptr_info = NULL;
    ptr_prox = NULL;
}

template<class TIPO>
Elemento<TIPO>::~Elemento()
{
    ptr_ante = NULL;
    ptr_info = NULL;
    ptr_prox = NULL;
}

template<class TIPO>
void Elemento<TIPO>::set_Proximo(Elemento<TIPO>* pp)
{
    ptr_prox = pp;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::get_Proximo() const
{
    return(ptr_prox);
}

template<class TIPO>
void Elemento<TIPO>::set_Anterior(Elemento<TIPO>* pa)
{
    ptr_ante = pa;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::get_Anterior() const
{
    return(ptr_ante);
}

template<class TIPO>
void Elemento<TIPO>::set_Info(TIPO* t)
{
    ptr_info = t;
}

template<class TIPO>
TIPO* Elemento<TIPO>::get_Info() const
{
    return(ptr_info);
}

#endif // INCLUDED_ELEMENTO_H
