#ifndef NEW_PROJECT_2_OBJECT_HPP
#define NEW_PROJECT_2_OBJECT_HPP

#include "definitions.hpp"

class Object {
 public:
    Object() = default;
    Object(int c, sf::String image_file_name, sf::String name);
    ~Object() = default;
    Object(const Object &o);
    virtual void read_data_from_file(std::string path_file) = 0;
    void set_base_texture_rect(sf::IntRect rect);
    void set_base_position(std::pair<float, float> coordinate);

    //  get
    int get_cost() const;
    sf::String get_file_name() const;
    sf::String get_name() const;
    sf::Image get_image() const;
    sf::Texture get_texture() const;
    sf::Sprite get_sprite() const;

    //  set
    void set_cost(int cost);
    void set_file_name(sf::String file_name);
    void set_name(sf::String name);
    void set_image(sf::Image image);
 private:
    int cost_;
    sf::String image_file_name_;
    sf::String name_;
    sf::Image image_;
    sf::Texture texture_;
    sf::Sprite sprite_;
};

#endif //NEW_PROJECT_2_OBJECT_HPP
