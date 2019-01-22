#include "window.hpp"

Window::Window(unsigned int width, unsigned int height, sf::String window_name) {
    window_ = new sf::RenderWindow(sf::VideoMode(width, height), window_name);
    width_ = width;
    height_ = height;
    window_name_ = window_name;
}

sf::RenderWindow* Window::get_RenderWindow() const {
    return window_;
}

sf::String Window::get_window_name() const {
    return window_name_;
}

unsigned int Window::get_width() const {
    return width_;
}

unsigned int Window::get_height() const {
    return height_;
}

Window::~Window() {
    delete window_;
}
