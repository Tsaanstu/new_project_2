#ifndef NEW_STRATEGY_1_SYSTEM_HPP
#define NEW_STRATEGY_1_SYSTEM_HPP

#include <SFML/Graphics.hpp>

#include <iostream>

class String : public sf::String {
public:
    String ();
    String (char ansiChar, const std::locale &locale=std::locale());
//    String (wchar_t wideChar);
//    String (Uint32 utf32Char);
    String (const char *ansiString, const std::locale &locale=std::locale());
    String (const std::string &ansiString, const std::locale &locale=std::locale());
//    String (const wchar_t *wideString);
//    String (const std::wstring &wideString);
//    String (const Uint32 *utf32String);
//    String (const std::basic_string< Uint32 > &utf32String);
    String (const String &copy);
//    operator std::string () const;
//    operator std::wstring () const;
//    std::string toAnsiString (const std::locale &locale=std::locale()) const;
//    std::wstring toWideString () const;
//    std::basic_string< Uint8 > toUtf8 () const;
//    std::basic_string< Uint16 > toUtf16 () const;
//    std::basic_string< Uint32 > toUtf32 () const;

    String& operator= (const String &right);
    String& operator+= (const String &right);

//    Uint32 	operator[] (std::size_t index) const;
//    Uint32& operator[] (std::size_t index);

    void clear ();
    std::size_t getSize () const;
    bool isEmpty () const;
    void erase (std::size_t position, std::size_t count=1);
    void insert (std::size_t position, const String &str);
    std::size_t find (const String &str, std::size_t start=0) const;
    void replace (std::size_t position, std::size_t length, const String &replaceWith);
    void replace (const String &searchFor, const String &replaceWith);
    String 	substring (std::size_t position, std::size_t length=InvalidPos) const;
//    const Uint32* getData () const;
    sf::String::Iterator begin ();
    sf::String::ConstIterator begin () const;
    sf::String::Iterator end ();
    sf::String::ConstIterator end () const;

    sf::String get_string() const;
    void set_string(sf::String _str);
private:
    sf::String str;
};

 class Font : public sf::Font {
 public:
    Font();
    Font(const Font& other);
    ~Font();

    bool load_from_file(const std::string& file_name);

    Font& operator=(const Font& right);

  private:
   sf::Font font_;
 };

#endif //NEW_STRATEGY_1_SYSTEM_HPP