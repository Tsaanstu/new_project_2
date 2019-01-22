#ifndef NEW_STRATEGY_1_RECT_HPP
#define NEW_STRATEGY_1_RECT_HPP

#include "rect.hpp"
#include "vector2.hpp"

template <typename T>
class Rect {
 public:
    Rect();
    Rect(T rectLeft, T rectTop, T rectWidth, T rectHeight);
    Rect(const Vector2<T>& position, const Vector2<T>& size);
    template <typename U>
    explicit Rect(const Rect<U>& rectangle);
    bool contains(T x, T y) const;
    bool contains(const Vector2<T>& point) const;
    bool intersects(const Rect<T>& rectangle) const;
    bool intersects(const Rect<T>& rectangle, Rect<T>& intersection) const;
    T left;
    T top;
    T width;
    T height;
};

#include "rect.tpp"

typedef Rect<int>   IntRect;
typedef Rect<float> FloatRect;

#endif //NEW_STRATEGY_1_RECT_HPP