#ifndef NEW_STRATEGY_1_VECTOR2_HPP
#define NEW_STRATEGY_1_VECTOR2_HPP

#include <SFML/Graphics.hpp>

template <typename T>
class Vector2  {
 public:
    Vector2();
    Vector2(T X, T Y);
    sf::Vector2<T> to_sf_Vector();
    Vector2<T>& operator =(const sf::Vector2<T>& rhs);
    template <typename U>
    explicit Vector2(const Vector2<U>& vector);
    friend Vector2<T> operator -(const Vector2<T>& right);
    friend Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right);
    friend Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right);
    friend Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right);
    friend Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right);
    friend Vector2<T> operator *(const Vector2<T>& left, T right);
    friend Vector2<T> operator *(T left, const Vector2<T>& right);
    friend Vector2<T>& operator *=(Vector2<T>& left, T right);
    friend Vector2<T> operator /(const Vector2<T>& left, T right);
    friend Vector2<T>& operator /=(Vector2<T>& left, T right);
    friend bool operator ==(const Vector2<T>& left, const Vector2<T>& right);
    friend bool operator !=(const Vector2<T>& left, const Vector2<T>& right);
    T x;
    T y;
};

#include "vector2.tpp"

typedef Vector2<int>          Vector2i;
typedef Vector2<unsigned int> Vector2u;
typedef Vector2<float>        Vector2f;

#endif //NEW_STRATEGY_1_VECTOR2_HPP