#ifndef NEW_PROJECT_2_WINDOW_HPP
#define NEW_PROJECT_2_WINDOW_HPP

#include "definitions.hpp"
#include "string.hpp"

class Window {
 public:
    Window(unsigned int width, unsigned int height, sf::String window_name);
    ~Window();
    //  get
    sf::RenderWindow* get_RenderWindow() const;
    unsigned int get_width() const;
    unsigned int get_height() const;
    sf::String get_window_name() const;
 private:
    unsigned int width_;
    unsigned int height_;
    sf::String window_name_;
    sf::RenderWindow *window_;
};

#endif //NEW_PROJECT_2_WINDOW_HPP
