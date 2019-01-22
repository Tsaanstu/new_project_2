#ifndef NEW_STRATEGY_1_IMAGE_HPP
#define NEW_STRATEGY_1_IMAGE_HPP

#include <SFML/Graphics.hpp>
#include "vector2.hpp"
#include "color.hpp"
#include "rect.hpp"

class Image {
public:
    Image() = default;
    ~Image() = default;
    void create (unsigned int width, unsigned int height, const Color &color = Color(0, 0, 0));
    void create (unsigned int width, unsigned int height, const uint8_t *pixels);
    bool loadFromFile (const std::string &filename);
    bool saveToFile (const std::string &filename) const;
    Vector2u getSize () const;
    void createMaskFromColor (const Color &color, uint8_t alpha=0);
    void setPixel (unsigned int x, unsigned int y, const Color &color);
    Color getPixel (unsigned int x, unsigned int y) const;
    const uint8_t* getPixelsPtr () const;
    void flipHorizontally ();
    void flipVertically ();
    //  get
    sf::Image get_Image() const;
private:
    sf::Image image;
};

#endif //NEW_STRATEGY_1_IMAGE_HPP