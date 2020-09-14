#ifndef INCLUDED_VECTOR_4D_H
#define INCLUDED_VECTOR_4D_H

#include <iostream>
#include <math.h>

template<typename T4>
class Vector4D
{
public:

    T4 x;
    T4 y;
    T4 z;
    T4 k;

private:

    static unsigned long int cont;

public:

    Vector4D(T4 xx = 0, T4 yy = 0, T4 zz = 0, T4 kk = 0);
    ~Vector4D();

    const unsigned long int quantity() const;
    const bool operator== (const Vector4D<T4>& v) const;
    const bool operator!= (const Vector4D<T4>& v) const;
    void operator=(const Vector4D<T4>& v);
    const Vector4D<T4> operator+(const Vector4D<T4> v1) const;
};

template<typename T4>
unsigned long int Vector4D<T4>::cont = 0lu;

template<typename T4>
Vector4D<T4>::Vector4D(T4 xx, T4 yy, T4 zz, T4 kk):
    x(xx),
    y(yy),
    z(zz),
    k(kk)
{
    cont++;
}

template<typename T4>
Vector4D<T4>::~Vector4D()
{
    cont--;
}

template<typename T4>
const unsigned long int Vector4D<T4>::quantity() const
{
    return(cont);
}

template<typename T4>
const bool Vector4D<T4>::operator== (const Vector4D<T4>& v) const
{
    if(x == v.x)
    {
        if(y == v.y)
        {
            if(z = v.z)
            {
                if(k = v.k)
                {
                    return(true);
                }
            }
        }
    }
    return(false);
}

template<typename T4>
const bool Vector4D<T4>::operator!= (const Vector4D<T4>& v) const
{
    return(*this == v ? false : true);
}

template<typename T4>
void Vector4D<T4>::operator=(const Vector4D<T4>& v)
#endif // INCLUDED_VECTOR_4D_H
