#ifndef NEW_STRATEGY_1_EVENT_HPP
#define NEW_STRATEGY_1_EVENT_HPP

#include <SFML/Graphics.hpp>

class Event {
public:
    //  get
    sf::Event get_Event() const;
private:
    sf::Event event;
};

#endif //NEW_STRATEGY_1_EVENT_HPP
