#ifndef NEW_PROJECT_2_PLAYER_HPP
#define NEW_PROJECT_2_PLAYER_HPP

#include <vector>

#include "definitions.hpp"
#include "soldier.hpp"
#include "mistborn.hpp"
#include "misting.hpp"

class Player {
 public:
    Player();
    ~Player() = default;

    void clear_beings_vector();

    // get
    short int get_hp() const;
    unsigned short get_money() const;
    void set_money(unsigned short money);

    // set
    void set_hp(short hp);

    // get army
    std::vector<Soldier> get_soldiers() const;
    std::vector<Misting> get_mistings() const;
    std::vector<Mistborn> get_mistborns() const;

    // get resources
    std::vector<Metal> get_metals() const;

    // set army
    void add_soldier(const Soldier &soldier);
    void add_misting(const Misting &misting);
    void add_mistborn(const Mistborn &mistborn);

    // set resources
    void add_metal(const Metal &metal);

    void update_hp();

    void set_metals(); // TODO (nmerk): for each type of being set metal

    Player &operator=(const Player &other);

    // name
    void set_player_name(sf::String &name, const unsigned int x, const unsigned int y);
    sf::Text get_player_name();

    // avatar
    sf::Sprite get_avatar_sprite();
    void set_avatar_sprite(const unsigned int chosen_pic_num);
    void set_avatar_position(const unsigned int x, const unsigned int y);
 private:
    unsigned short hp_;
    unsigned short money_;

    std::vector<Soldier> soldiers_;
    std::vector<Mistborn> mistborns_;
    std::vector<Misting> mistings_;

    std::vector<Metal> metals_;

    sf::Font player_name_font_;
    sf::Text player_name_;

    sf::Texture avatar_texture_;
    sf::Sprite avatar_sprite_;
};

#endif  // NEW_PROJECT_2_PLAYER_HPP
