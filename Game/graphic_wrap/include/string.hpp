#ifndef NEW_STRATEGY_1_STRING_HPP
#define NEW_STRATEGY_1_STRING_HPP

#include <SFML/Graphics.hpp>

class String {
public:
    String ();
    String (char ansiChar, const std::locale &locale=std::locale());
    String (const char *ansiString, const std::locale &locale=std::locale());
    String (const std::string &ansiString, const std::locale &locale=std::locale());
    String (const String &copy);
    String& operator= (const String &right);
    String& operator+= (const String &right);
    void clear ();
    std::size_t getSize () const;
    bool isEmpty () const;
    void erase (std::size_t position, std::size_t count = 1);
    void insert (std::size_t position, const String &str);
    std::size_t find (const String &str, std::size_t start = 0) const;
    void replace (std::size_t position, std::size_t length, const String &replaceWith);
    void replace (const String &searchFor, const String &replaceWith);
    String 	substring (std::size_t position, std::size_t length = 0) const;
    std::string toAnsiString (const std::locale &locale = std::locale()) const;
    sf::String::Iterator begin ();
    sf::String::ConstIterator begin () const;
    sf::String::Iterator end ();
    sf::String::ConstIterator end () const;
    //  get
    sf::String get_string() const;
    //  set
    void set_string(sf::String _str);
private:
    sf::String str;
};

#endif //NEW_STRATEGY_1_STRING_HPP
