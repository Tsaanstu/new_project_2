#include "contextsettings.hpp"

ContextSettings::ContextSettings (unsigned int depth, unsigned int stencil, unsigned int antialiasing, unsigned int major, unsigned int minor, unsigned int attributes) {
    cs = sf::ContextSettings (depth, stencil, antialiasing, major, minor, attributes);
}

sf::ContextSettings ContextSettings::get_ContextSettings() const {
    return cs;
}
