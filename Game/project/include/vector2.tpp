#include "vector2.hpp"

template<typename T>
inline Vector2<T>::Vector2() : x(0), y(0) {}

template<typename T>
inline sf::Vector2<T> Vector2<T>::to_sf_Vector() {
    sf::Vector2<T> result(x, y);
    return result;
}

template<typename T>
inline Vector2<T>::Vector2(T X, T Y) : x(X), y(Y) {}

template<typename T>
Vector2<T> &Vector2<T>::operator=(const sf::Vector2<T> &rhs) {
    x = rhs.x;
    y = rhs.y;
    return *this;
}

template<typename T>
template<typename U>
inline Vector2<T>::Vector2(const Vector2<U> &vector) : x(static_cast<T>(vector.x)), y(static_cast<T>(vector.y)) {}

template<typename T>
inline Vector2<T> operator-(const Vector2<T> &right) {
    return Vector2<T>(-right.x, -right.y);
}

template<typename T>
inline Vector2<T> &operator+=(Vector2<T> &left, const Vector2<T> &right) {
    left.x += right.x;
    left.y += right.y;
    return left;
}

template<typename T>
inline Vector2<T> &operator-=(Vector2<T> &left, const Vector2<T> &right) {
    left.x -= right.x;
    left.y -= right.y;
    return left;
}

template<typename T>
inline Vector2<T> operator+(const Vector2<T> &left, const Vector2<T> &right) {
    return Vector2<T>(left.x + right.x, left.y + right.y);
}

template<typename T>
inline Vector2<T> operator-(const Vector2<T> &left, const Vector2<T> &right) {
    return Vector2<T>(left.x - right.x, left.y - right.y);
}

template<typename T>
inline Vector2<T> operator*(const Vector2<T> &left, T right) {
    return Vector2<T>(left.x * right, left.y * right);
}

template<typename T>
inline Vector2<T> operator*(T left, const Vector2<T> &right) {
    return Vector2<T>(right.x * left, right.y * left);
}

template<typename T>
inline Vector2<T> &operator*=(Vector2<T> &left, T right) {
    left.x *= right;
    left.y *= right;
    return left;
}

template<typename T>
inline Vector2<T> operator/(const Vector2<T> &left, T right) {
    return Vector2<T>(left.x / right, left.y / right);
}

template<typename T>
inline Vector2<T> &operator/=(Vector2<T> &left, T right) {
    left.x /= right;
    left.y /= right;

    return left;
}

template<typename T>
inline bool operator==(const Vector2<T> &left, const Vector2<T> &right) {
    return (left.x == right.x) && (left.y == right.y);
}

template<typename T>
inline bool operator!=(const Vector2<T> &left, const Vector2<T> &right) {
    return (left.x != right.x) || (left.y != right.y);
}