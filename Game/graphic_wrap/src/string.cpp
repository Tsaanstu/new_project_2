#include "string.hpp"

sf::String String::get_string() const {
    return str;
}

void String::set_string(sf::String _str) {
    str = _str;
}

String::String() {
    str = sf::String();
}

String::String(char ansiChar, const std::locale &locale) {
    str = sf::String(ansiChar, locale);
}

String::String (const char *ansiString, const std::locale &locale) {
    str = sf::String(ansiString, locale);
}

String::String (const std::string &ansiString, const std::locale &locale) {
    str = sf::String(ansiString, locale);
}

String::String (const String &copy) {
    str = copy.get_string();
}

String& String::operator= (const String &right) {
    str = right.get_string();
}

String& String::operator+= (const String &right) {
    str += right.get_string();
}

void String::clear() {
    str.clear();
}

std::size_t String::getSize () const {
    return str.getSize();
}

bool String::isEmpty() const {
    return str.isEmpty();
}

void String::erase(std::size_t position, std::size_t count) {
    str.erase(position, count);
}

void String::insert(std::size_t position, const String &_str) {
    str.insert(position, _str.get_string());
}

std::size_t String::find(const String &str, std::size_t start) const {
    return str.find(str, start);
}

void String::replace(std::size_t position, std::size_t length, const String &replaceWith) {
    str.replace(position, length, replaceWith.get_string());
}

void String::replace(const String &searchFor, const String &replaceWith) {
    str.replace(searchFor.get_string(), replaceWith.get_string());
}

String String::substring(std::size_t position, std::size_t length) const {
    String r_str;
    r_str.set_string(str.substring(position, length));
    return r_str;
}

sf::String::Iterator String::begin() {
    return str.begin();
}

sf::String::ConstIterator String::begin() const {
    return str.begin();
}

std::string String::toAnsiString (const std::locale &locale) const {
    return str.toAnsiString();
}

sf::String::Iterator String::end() {
    return str.end();
}

sf::String::ConstIterator String::end() const {
    return str.end();
}