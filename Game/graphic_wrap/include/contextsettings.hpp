#ifndef NEW_STRATEGY_1_CONTEXTSETTINGS_HPP
#define NEW_STRATEGY_1_CONTEXTSETTINGS_HPP

#include "SFML/Graphics.hpp"

class ContextSettings {
 public:
    ContextSettings (unsigned int depth = 0, unsigned int stencil = 0, unsigned int antialiasing = 0,
            unsigned int major = 1, unsigned int minor = 1, unsigned int attributes = Default);
    enum Attribute {
        Default = 0,
        Core = 1 << 0,
        Debug = 1 << 2
    };
    //  get
    sf::ContextSettings get_ContextSettings() const;
 private:
    sf::ContextSettings cs;
};

#endif //NEW_STRATEGY_1_CONTEXTSETTINGS_HPP
