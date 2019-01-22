#include "videomode.hpp"

VideoMode::VideoMode(unsigned int modeWidth, unsigned int modeHeight, unsigned int modeBitsPerPixel) {
    vm = sf::VideoMode(modeWidth, modeHeight, modeBitsPerPixel);
}

bool VideoMode::isValid() const {
    return vm.isValid();
}

bool operator== (const VideoMode &left, const VideoMode &right) {
    return left.get_VideoMode() == right.get_VideoMode();
}

bool operator!= (const VideoMode &left, const VideoMode &right) {
    return left.get_VideoMode() != right.get_VideoMode();
}

bool operator< (const VideoMode &left, const VideoMode &right) {
    return left.get_VideoMode() < right.get_VideoMode();
}

bool operator> (const VideoMode &left, const VideoMode &right) {
    return left.get_VideoMode() > right.get_VideoMode();
}

bool operator<= (const VideoMode &left, const VideoMode &right) {
    return left.get_VideoMode() <= right.get_VideoMode();
}

bool operator>= (const VideoMode &left, const VideoMode &right) {
    return left.get_VideoMode() >= right.get_VideoMode();
}

sf::VideoMode VideoMode::get_VideoMode() const {
    return vm;
}