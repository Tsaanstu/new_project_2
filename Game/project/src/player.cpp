#include "player.hpp"

Player::Player() : money_(DEFAULT_PLAYER_MONEY), hp_(0) {}

void Player::clear_beings_vector() {
    soldiers_.clear();
    mistborns_.clear();
    mistborns_.clear();
}

// get
short int Player::get_hp() const {
    return hp_;
}
unsigned short Player::get_money() const {
    return money_;
}

//set
void Player::set_hp(short hp) {
    hp_ = hp;
}

void Player::set_money(unsigned short money) {
    money_ = money;
}

// get army
std::vector<Soldier> Player::get_soldiers() const {
    return soldiers_;
}
std::vector<Misting> Player::get_mistings() const {
    return mistings_;
}
std::vector<Mistborn> Player::get_mistborns() const {
    return mistborns_;
}

// get resources
std::vector<Metal> Player::get_metals() const {
    return metals_;
}

Player &Player::operator=(const Player &other) {
    hp_ = other.hp_;
    money_ = other.money_;

    for (const auto &i : other.soldiers_) {
        soldiers_.push_back(i);
    }

    for (const auto &i : other.mistings_) {
        mistings_.push_back(i);
    }

    for (const auto &i : other.mistborns_) {
        mistborns_.push_back(i);
    }

    for (const auto &i : other.metals_) {
        metals_.push_back(i);
    }

    return *this;
}

//  set army // TODO: fix, link error
void Player::add_soldier(const Soldier &soldier) {
    soldiers_.push_back(soldier);
}
void Player::add_misting(const Misting &misting) {
    mistings_.push_back(misting);
}
void Player::add_mistborn(const Mistborn &mistborn) {
    mistborns_.push_back(mistborn);
}

// set resources
void Player::add_metal(const Metal &metal) {
    metals_.push_back(metal);
}

void Player::update_hp() {
    hp_ = 0;
    for (int i = 0; i < soldiers_.size(); ++i) {
        hp_ += soldiers_[i].get_hp();
    }
    for (int i = 0; i < mistborns_.size(); ++i) {
        hp_ += mistborns_[i].get_hp();
    }
    for (int i = 0; i < mistings_.size(); ++i) {
        hp_ += mistings_[i].get_hp();
    }
}

void Player::set_metals() {
    // TODO (nmerk) : для каждого объекта misting и mistborn будут присваиваться металлы
}

void Player::set_player_name(sf::String &name, const unsigned int x, const unsigned int y) {

    if (!player_name_font_.loadFromFile(PLAYER_FONT)) {
        std::cout << "UNABLE TO LOAD PLAYER NAME FONT" << std::endl;
    }
    player_name_.setFont(player_name_font_);

    player_name_.setCharacterSize(SIZE_OF_TEXT);
    player_name_.setColor(sf::Color::Black);

    player_name_.setString(name);

    player_name_.setPosition(x, y);
}

sf::Text Player::get_player_name() {
    return player_name_;
}

sf::Sprite Player::get_avatar_sprite() {
    return avatar_sprite_;
}

void Player::set_avatar_sprite(const unsigned int chosen_pic_num) {
    switch (chosen_pic_num) {
        case 1 : {
            if (!avatar_texture_.loadFromFile(PATH_TO_PICTURES + "1" + PICTURES_FORMAT)) {
                std::cout << "UNABLE TO LOAD 1ST PLAYER AVATAR" << std::endl;
            }
        }
            break;
        case 2 : {
            if (!avatar_texture_.loadFromFile(PATH_TO_PICTURES + "2" + PICTURES_FORMAT)) {
                std::cout << "UNABLE TO LOAD 2ND PLAYER AVATAR" << std::endl;
            }
        }
            break;
        default:return;
    }
    avatar_sprite_.setTexture(avatar_texture_);
    avatar_sprite_.setTextureRect(sf::IntRect(0, 0, 100, 100));
}

void Player::set_avatar_position(const unsigned int x, const unsigned int y) {
    avatar_sprite_.setPosition(x, y);
}
