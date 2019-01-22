#ifndef NEW_STRATEGY_1_VIDEOMODE_HPP
#define NEW_STRATEGY_1_VIDEOMODE_HPP

#include <SFML/Graphics.hpp>

class VideoMode {
 public:
    VideoMode() = default;
    VideoMode(unsigned int modeWidth, unsigned int modeHeight, unsigned int modeBitsPerPixel = 32);
    ~VideoMode() = default;
    bool isValid() const;
    friend bool operator== (const VideoMode &left, const VideoMode &right);
    friend bool operator!= (const VideoMode &left, const VideoMode &right);
    friend bool operator< (const VideoMode &left, const VideoMode &right);
    friend bool operator> (const VideoMode &left, const VideoMode &right);
    friend bool operator<= (const VideoMode &left, const VideoMode &right);
    friend bool operator>= (const VideoMode &left, const VideoMode &right);
    //  get
    sf::VideoMode get_VideoMode() const;
private:
    sf::VideoMode vm;
};

#endif //NEW_STRATEGY_1_VIDEOMODE_HPP
