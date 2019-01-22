#include "image.hpp"

void Image::create(unsigned int width, unsigned int height, const Color &color) {
    image.create(width, height, color.get_Color());
}

void Image::create(unsigned int width, unsigned int height, const uint8_t *pixels) {
    image.create(width, height, pixels);
}

bool Image::loadFromFile(const std::string &filename) {
    return image.loadFromFile(filename);
}

bool Image::saveToFile(const std::string &filename) const {
    return image.saveToFile(filename);
}

Vector2u Image::getSize() const {
    Vector2u result(image.getSize().x, image.getSize().y);
    return result;
}

void Image::createMaskFromColor(const Color &color, uint8_t alpha) {
    image.createMaskFromColor(color.get_Color(), alpha);
}

void Image::setPixel(unsigned int x, unsigned int y, const Color &color) {
    image.setPixel(x, y, color.get_Color());
}

Color Image::getPixel(unsigned int x, unsigned int y) const {
    Color result;
    result.set_Color(image.getPixel(x, y));
    return result;
}

const uint8_t* Image::getPixelsPtr() const {
    return image.getPixelsPtr();
}

void Image::flipHorizontally() {
    image.flipHorizontally();
}

void Image::flipVertically() {
    image.flipVertically();
}

sf::Image Image::get_Image() const {
    return image;
}