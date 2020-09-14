#ifndef INCLUDED_VECTOR_2D_H
#define INCLUDED_VECTOR_2D_H

#include <math.h>
#include <iostream>

template<typename T2>
class Vector2D
{
public:

    T2 x;
    T2 y;

private:

    static unsigned long int cont;

public:

    Vector2D(T2 X = 0.0, T2 Y = 0.0);
    ~Vector2D();

    const unsigned long int Quantidade_de_Instancias() const;

    //Sobrecarga de Operadores
    bool operator == (Vector2D<T2> v);
    bool operator != (Vector2D<T2> v);
    void operator = (const Vector2D<T2>& v);
    const Vector2D<T2> operator + (const Vector2D<T2>& v) const;
    //const Vector2D<T2> operator * (const int i) const;
    //const Vector2D<T2> operator * (const float f) const;
    //const Vector2D<T2> operator * (const double d) const;
    //const T2 operator * (const Vector2D<T2>& v) const;

    //Propriedades de Vetores
    const Vector2D<T2> inverse() const;
    const T2 modulo() const; //REVIEW
    const Vector2D<T2> versor() const; // REVIEW
    const Vector2D<T2> projecao(const Vector2D<T2>& v) const; // TO DO
    const T2 cosseno_angulo(const Vector2D<T2>& v1, const Vector2D<T2>& v2) const; // TO DO
};

template<typename T2>
std::ostream& operator<<(std::ostream& out, Vector2D<T2>& v)
{
    out << "(" << v.x << ", " << v.y << ")";
    return(out);
}
template<typename T2>
unsigned long int Vector2D<T2>::cont = 0;

template<typename T2>
Vector2D<T2>::Vector2D(T2 X, T2 Y):
    x(X),
    y(Y)
{
    cont++;
}

template<typename T2>
Vector2D<T2>::~Vector2D()
{
    cont--;
}

template<typename T2>
const unsigned long int Vector2D<T2>::Quantidade_de_Instancias() const
{
    return(cont);
}

template<typename T2>
bool Vector2D<T2>::operator == (Vector2D<T2> v)
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

template<typename T2>
bool Vector2D<T2>::operator != (Vector2D<T2> v)
{
    return( !(operator==(v)) );
}

template<typename T2>
void Vector2D<T2>::operator = (const Vector2D<T2>& v)
{
    this->x = v.x;
    this->y = v.y;
}

template<typename T2>
const Vector2D<T2> Vector2D<T2>::operator + (const Vector2D<T2>& v) const
{
    return(Vector2D<T2>(x + v.x, y + v.y));
}

template<typename T2>
const Vector2D<T2> Vector2D<T2>::inverse() const
{
    return(Vector2D<T2>(y,x));
}

template<typename T2> //...............TO REVIEW...............
const T2 Vector2D<T2>::modulo() const
{
    T2 aux;
    aux = x * x + y * y;
    aux = sqrtf(aux);
    return(aux);
}

template<typename T2> //...............TO REVIEW...............
const Vector2D<T2> Vector2D<T2>::versor() const
{
    T2 xx = x;
    T2 yy = y;
    T2 divisor = this->modulo();
    xx = xx/divisor;
    yy = yy/divisor;
    return(Vector2D<T2>(xx, yy));
}

template<typename T2>//...............TO DO...............
const Vector2D<T2> Vector2D<T2>::projecao(const Vector2D<T2>& v) const
{

}

template<typename T2>//...............TO DO...............
const T2 Vector2D<T2>::cosseno_angulo(const Vector2D<T2>& v1, const Vector2D<T2>& v2) const
{

}

template<typename T2>
const Vector2D<T2> operator * (const Vector2D<T2>& v, const int i)
{
    return(Vector2D<T2>(v.x * i, v.y * i));
}

template<typename T2>
const Vector2D<T2> operator * (const int i, const Vector2D<T2>& v)
{
    return(Vector2D<T2>(v.x * i, v.y * i));
}

template<typename T2>
const Vector2D<T2> operator * (const Vector2D<T2>& v, const float f)
{
    return(Vector2D<T2>(v.x * f, v.y * f));
}

template<typename T2>
const Vector2D<T2> operator * (const float f, const Vector2D<T2>& v)
{
    return(Vector2D<T2>(v.x * f, v.y * f));
}

template<typename T2>
const Vector2D<T2> operator * (const Vector2D<T2>& v, const double d)
{
    return(Vector2D<T2>(v.x * d, v.y * d));
}

template<typename T2>
const Vector2D<T2> operator * ( const double d, const Vector2D<T2>& v)
{
    return(Vector2D<T2>(v.x * d, v.y * d));
}


#endif // INCLUDED_VECTOR_2D_H
