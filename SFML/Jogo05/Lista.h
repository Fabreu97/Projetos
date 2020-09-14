#ifndef INCLUDED_LISTA_TEMPLATE
#define iNCLUDED_LISTA_TEMPLATE

#include <stdio.h>

//fazer o iterator e o método find

template <class TL>
class List
{
private:
    template<class TE>
    class Element
    {
    private:
        TE* data;
        Element<TE>* next;
        Element<TE>* prev;

    public:
        Element();
        ~Element();

        void setNext(Element<TE>* pn);
        Element<TE>* getNext() const;
        void setPrev(Element<TE>* pp);
        Element<TE>* getPrev() const;
        void setData(TL* d);
        TE* getData() const;
    };

    unsigned long int s; //size
    Element<TL>* first;
    Element<TL>* last;

    TL* getData(const unsigned long int indice) const;

public:

    class Iterator
    {
    private:
        Element<TL>* element;

    public:
        Iterator(Element<TL>* start = NULL);
        ~Iterator();

        Element<TL>* getElement() const;
        TL* operator*();
        void operator++();
        void operator=(const Iterator& i);
        void operator=( Element<TL>* i);
        const bool operator==(const Iterator& i) const;
        const bool operator!= (const Iterator& i) const;
    };

    List();
    ~List();

    void initializing(); //inicializando
    void clearList();
    const unsigned long int getSize() const;
    const bool insertList(TL* d);
    //TL* getData(const unsigned long int indice) const;
    void deleteData(const unsigned long int indice); //  REVIEW
    void deleteData(TL* type); //  REVIEW

    Element<TL>* Begin();
    Element<TL>* End();

    TL* operator[](const unsigned long int i) const;
};

///........................Métodos do Element........................

template<class TL>
template<class TE>
List<TL>::Element<TE>::Element()
{
    prev = NULL;
    next = NULL;
    data = NULL;
}

template<class TL>
template<class TE>
List<TL>::Element<TE>::~Element()
{
    prev = NULL;
    next = NULL;
    data = NULL;
}

template<class TL>
template<class TE>
void List<TL>::Element<TE>::setNext(Element* pn)
{
    next = pn;
}

template<class TL>
template<class TE>
List<TL>::Element<TE>* List<TL>::Element<TE>::getNext() const
{
    return(next);
}

template<class TL>
template<class TE>
void List<TL>::Element<TE>::setPrev(Element* pp)
{
    prev = pp;
}

template<class TL>
template<class TE>
List<TL>::Element<TE>* List<TL>::Element<TE>::getPrev() const
{
    return(prev);
}

template<class TL>
template<class TE>
void List<TL>::Element<TE>::setData(TL* d)
{
    data = d;
}

template<class TL>
template<class TE>
TE* List<TL>::Element<TE>::getData() const
{
    return(data);
}

///....................MÉTODOS DO ITERATOR DA LIST....................

template<class TL>
List<TL>::Iterator::Iterator(List<TL>::Element<TL>* start)
{
    element = start;
}

template<class TL>
List<TL>::Iterator::~Iterator()
{
    element = NULL;
}

template<class TL>
List<TL>::Element<TL>* List<TL>::Iterator::getElement() const
{
    return(element);
}

template<class TL>
TL* List<TL>::Iterator::operator*()
{
    return(element->getData());
}

template<class TL>
void List<TL>::Iterator::operator++()
{
    if(element != NULL)
    {
        element = element->getNext();
    }
}

template<class TL>
void List<TL>::Iterator::operator=(const List<TL>::Iterator& i)
{
    element = i.getElement();
}

template<class TL>
void List<TL>::Iterator::operator=(Element<TL>* i)
{
    element = i;
}

template<class TL>
const bool List<TL>::Iterator::operator==(const List<TL>::Iterator& i) const
{
    if(element == i.getElement())
    {
        return(true);
    }
    return(false);
}

template<class TL>
const bool List<TL>::Iterator::operator!=(const List<TL>::Iterator& i) const
{
    if(*this == i)
    {
        return(false);
    }
    return(true);
}

///....................Métodos da List Template.......................

template<class TL>
List<TL>::List():
    s(0)
{
    initializing();
}

template<class TL>
List<TL>::~List()
{
    clearList();
}

template<class TL>
void List<TL>::initializing()
{
    last = NULL;
    first = NULL;
}

template<class TL>
void List<TL>::clearList()
{
    Element<TL>* aux = first;

    while(aux != NULL)
    {
        first = first->getNext();
        delete(aux);
        s--;
        aux = first;
    }
    initializing();
}

template <class TL>
const unsigned long int List<TL>::getSize() const
{
    return(s);
}

template<class TL>
const bool List<TL>::insertList(TL* d)
{
    if(d != NULL)
    {
        Element<TL>* aux = new Element<TL>();
        aux->setData(d);
        s++;
        if(first == NULL)
        {
            first = aux;
            last = aux;
        }
        else
        {
            last->setNext(aux);
            aux->setPrev(last);
            last = aux;
        }
        return(true);
    }
    return(false);
}

template<class TL>
TL* List<TL>::getData(const unsigned long int indice) const
{
    unsigned long int i;

    if(s > indice)
    {
        Element<TL>* aux = first;
        for(i = 0lu; i < indice; i++)
        {
            aux = aux->getNext();
        }
        return(aux->getData());
    }

    return(NULL);
}



template<class TL>//...............TO REVIEW...............
void List<TL>::deleteData(const unsigned long int indice)
{
    Element<TL>* aux1 = NULL;
    Element<TL>* aux2 = NULL;

    aux2 = first;

    unsigned long int i = 0lu;

    while(aux2 != NULL && i != indice)
    {
        aux1 = aux2;
        aux2 = aux2->getNext();
        i++;
    }

    //se indice for 0
    if(aux1 == NULL)
    {
        if(indice == 0)
        {
            first = aux2->getNext();
            delete(aux2);
            s--;
        }
    }
    else if(aux2 != NULL)
    {
        aux1->setNext(aux2->getNext());
        if(aux2->getNext() != NULL)
        {
            aux2->getNext()->setPrev(aux1);
        }
        else
        {
            last = aux1;
        }
        aux2->setPrev(NULL);
        aux2->setNext(NULL);
        delete(aux2);
        s--;
    }
}

template<class TL>
void List<TL>::deleteData(TL* type)
{
    Element<TL>* aux1 = NULL;
    Element<TL>* aux2 = first;
    while(aux2 != NULL && *type != *(aux2->getData()) )
    {
        aux1 = aux2;
        aux2 = aux2->getNext();
    }
    if(aux1 == NULL)
    {
        if(*type == *(aux2->getData()) )
        {
            first = aux2->getNext();
            delete(aux2->getData());
            delete(aux2);
            s--;
        }
    }
    else if(aux2 != NULL)
    {
        aux1->setNext(aux2->getNext());
        if(aux2->getNext() != NULL)
        {
            aux2->getNext()->setPrev(aux1);
        }
        else
        {
            last = aux1;
        }
        aux2->setPrev(NULL);
        aux2->setNext(NULL);
        delete(aux2->getData());
        delete(aux2);
        s--;
    }
}

template<class TL>
List<TL>::Element<TL>* List<TL>::Begin()
{
    return(first);
}

template <class TL>
List<TL>::Element<TL>* List<TL>::End()
{
    return(NULL);
}

template<class TL>
TL* List<TL>::operator[](const unsigned long int i) const
{
    return(getData(i));

}

#endif // INCLUDED_LISTA_TEMPLATE
