#ifndef INCLUDED_VECTOR_2D_H
#define INCLUDED_VECTOR_2D_H

#include <math.h>
#include <iostream>

namespace Vector
{
    template<typename T>
    class Vector2D
    {
    public:

        T x;
        T y;

    private:

        static unsigned long int cont;

    public:

        Vector2D(T X = 0.0, T Y = 0.0);
        ~Vector2D();

        const unsigned long int Quantidade_de_Instancias() const;

        //Sobrecarga de Operadores
        bool operator == (Vector::Vector2D<T> v);
        bool operator != (Vector::Vector2D<T> v);
        void operator = (const Vector::Vector2D<T>& v);
        const Vector2D<T> operator + (const Vector::Vector2D<T>& v) const;
        const Vector2D<T> operator * (const int i) const;
        const Vector2D<T> operator * (const float f) const;
        const Vector2D<T> operator * (const double d) const;
        //const Vector2D<T> operator * (const Vector::Vector2D<T>& v) const;
        const T operator * (const Vector::Vector2D<T>& v) const;

        //Propriedades de Vetores
        const T modulo() const; //REVIEW
        const Vector2D<T> versor() const; // REVIEW
        const Vector2D<T> projecao(const Vector2D<T>& v) const; // TO DO
        const T cosseno_angulo(const Vector2D<T>& v1, const Vector2D<T>& v2) const; // TO DO
    };
}


template<typename T>
std::ostream& operator<<(std::ostream& saida, Vector::Vector2D<T>& v)
{
    saida << "(" << v.x << ", " << v.y << ")";
    return(saida);
}
template<typename T>
unsigned long int Vector::Vector2D<T>::cont = 0;

template<typename T>
Vector::Vector2D<T>::Vector2D(T X, T Y):
    x(X),
    y(Y)
{
    cont++;
}

template<typename T>
Vector::Vector2D<T>::~Vector2D()
{
    cont--;
}

template<typename T>
const unsigned long int Vector::Vector2D<T>::Quantidade_de_Instancias() const
{
    return(cont);
}

template<typename T>
bool Vector::Vector2D<T>::operator == (Vector::Vector2D<T> v)
{
    if(x  == v.x)
    {
        if(y == v.y)
        {
            return(true);
        }
    }
    return(false);
}

template<typename T>
bool Vector::Vector2D<T>::operator != (Vector::Vector2D<T> v)
{
    return( !(operator==(v)) );
}

template<typename T>
void Vector::Vector2D<T>::operator = (const Vector::Vector2D<T>& v)
{
    this->x = v.x;
    this->y = v.y;
}

template<typename T>
const Vector::Vector2D<T> Vector::Vector2D<T>::operator + (const Vector::Vector2D<T>& v) const
{
    return(Vector::Vector2D<T>(x + v.x, y + v.y));
}

template<typename T>
const Vector::Vector2D<T> Vector::Vector2D<T>::operator * (const int i) const
{
    return(Vector::Vector2D<T>(x * i, y * i));
}

template<typename T>
const Vector::Vector2D<T> Vector::Vector2D<T>::operator * (const float f) const
{
    return(Vector::Vector2D<T>(x * f, y * f));
}

template<typename T>
const Vector::Vector2D<T> Vector::Vector2D<T>::operator * (const double d) const
{
    return(Vector::Vector2D<T>(x * d, y * d));
}

/*template<typename T>
const Vector::Vector2D<T> Vector::Vector2D<T>::operator * (const Vector::Vector2D<T>& v) const
{
    return(Vector::Vector2D<T>(x * v.x, y * v.y));
}
*/
template<typename T>
const T Vector::Vector2D<T>::operator * (const Vector::Vector2D<T>& v) const
{
    T aux = x * v.x + y * v.y;
    return(aux);
}

template<typename T> //...............TO REVIEW...............
const T Vector::Vector2D<T>::modulo() const
{
    T aux;
    aux = x * x + y * y;
    aux = sqrtf(aux);
    return(aux);
}

template<typename T> //...............TO REVIEW...............
const Vector::Vector2D<T> Vector::Vector2D<T>::versor() const
{
    T xx = x;
    T yy = y;
    T divisor = this->modulo();
    xx = xx/divisor;
    yy = yy/divisor;
    return(Vector::Vector2D<T>(xx, yy));
}


template<typename T>//...............TO DO...............
const Vector::Vector2D<T> Vector::Vector2D<T>::projecao(const Vector::Vector2D<T>& v) const
{

}

template<typename T>//...............TO DO...............
const T Vector::Vector2D<T>::cosseno_angulo(const Vector2D<T>& v1, const Vector2D<T>& v2) const
{

}

#endif // INCLUDED_VECTOR_2D_H
