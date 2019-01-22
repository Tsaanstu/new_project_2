#ifndef NEW_STRATEGY_1_PROJECT_INCLUDE_BUTTON_HPP
#define NEW_STRATEGY_1_PROJECT_INCLUDE_BUTTON_HPP

#include "definitions.hpp"

class Button {
 private:
    float thickness_;
    bool mouse_on_;
	bool active_;
    std::shared_ptr<sf::RenderWindow> window_;
    sf::Color fill_color_;
    sf::Color outline_color_;
    sf::Color text_color_;
    sf::RectangleShape form_;
    sf::Text name_;
    sf::Vector2f size_;
    sf::Vector2f position_;
    void invertColors();
 public:
    Button();

	void setActive(bool active);
    void setName(sf::Text name);
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    void setWindow(std::shared_ptr<sf::RenderWindow>& window);

    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;

    bool isMouseOn(sf::Vector2i mouse);

    void mouseOver();
    void mouseLeave();

    void display();
};

#endif  // NEW_STRATEGY_1_PROJECT_INCLUDE_BUTTON_HPP
