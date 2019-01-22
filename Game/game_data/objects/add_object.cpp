#include <iostream>
#include <fstream>

unsigned short choose_type();
void input_metals();
void input_being(unsigned short int type);

int main(int argc, char** argv) {
    unsigned short int type = 0;
    bool ef;
    std::string src = "";
    while(ef) {
        type = choose_type();
        switch (type) {
            case 1:
                input_metals();
                break;
            default:
                input_being(type);
                break;
        }
        std::cout << std::endl << "Продолжить работу?" << std::endl;
        std::cout << "1) Да\n2) Нет\n";
        unsigned short int a;
        std::cin >> a;
        if (a == 1) {
            ef = 1;
        } else {
            ef = 0;
        }
    }
    return 0;
}

void input_being(unsigned short int type) {
    std::string dir, str;
    std::cout << "О, Всемогущий, сейчас тебе предстоит создать ";
    switch (type) {
        case 2:
            std::cout << "солдата";
            dir = "beings/soldiery/";
            break;
        case 3:
            std::cout << "рожденного туманом";
            dir = "beings/allomancy/mistborn/";
            break;
        case 4:
            std::cout << "туманщика";
            dir = "beings/allomancy/mistings/";
            break;
    }
    std::cout << ". Ты ведь хотел именно это?" << std::endl;
    std::cout << "1) Так точно\n2) Никак нет\n";
    std::cin >> str;
    if (str == "2") {
        std::cout << "Боги тоже могут ошибаться..." << std::endl;
        return;
    }
    std::cout << std::endl << "Название существа: ";
    std::cin >> str;
    std::ofstream fout(dir + str + ".txt");
    fout << str << std::endl;
    std::cout << "Введи здоровье: ";
    std::cin >> str;
    fout << str << std::endl;
    std::cout << "Введи силу атаки: ";
    std::cin >> str;
    fout << str << std::endl;
    std::cout << "Введи меткость: ";
    std::cin >> str;
    fout << str << std::endl;
    std::cout << "Введи дальность: ";
    std::cin >> str;
    fout << str << std::endl;
    std::cout << "Введи силу дальней атаки: ";
    std::cin >> str;
    fout << str << std::endl;
    std::cout << "Введите стоимость: ";
    std::cin >> str;
    fout << str << std::endl;
    fout.close();
}

void input_metals() {
    std::string str;
    std::cout << std::endl << "О Всемогущий, сейчас тебе предстоит создать новый металл. Ты ведь хотел именно это?" << std::endl;
    std::cout << "1) Так точно\n2) Никак нет\n";
    std::cin >> str;
    if (str == "2") {
        std::cout << "Боги тоже могут ошибаться..." << std::endl;
        return;
    }
    std::cout << std::endl << "Название металла: ";
    std::cin >> str;
    std::ifstream check("metals/" + str + ".txt");
    while (check.is_open()) {
        std::cout << "Металл с таким названием уже существует, введи другое: ";
        std::cin >> str;
        check.open("metals/" + str + ".txt");
    }
    check.close();
    std::ofstream fout("metals/" + str + ".txt");
    fout << str << std::endl;
    std::cout << "Введи время действия металла: ";
    std::cin >> str;
    fout << str << std::endl;
    std::cout << "Введи улучшение для силы атаки: ";
    std::cin >> str;
    fout << str << std::endl;
    std::cout << "Введи улучшение для меткости: ";
    std::cin >> str;
    fout << str << std::endl;
    std::cout << "Введи улучшение для дальности: ";
    std::cin >> str;
    fout << str << std::endl;
    std::cout << "Введи улучшение для силы дальней атаки: ";
    std::cin >> str;
    fout << str << std::endl;
    std::cout << "Введите стоимость: ";
    std::cin >> str;
    fout << str << std::endl;
    fout.close();
}

unsigned short choose_type() {
    unsigned short type = 0;
    std::cout << std::endl << "Выбери тип \"объекта\"" << std::endl;
    std::cout << "1) Металл" << std::endl;
    std::cout << "2) Солдат" << std::endl;
    std::cout << "3) Рожденный туманом" << std::endl;
    std::cout << "4) Туманщик" << std::endl;
    std::cout << "Введи номер типа: ";
    std::cin >> type;
    while (type < 1 || type > 4) {
        std::cout << "Тут 4 циферки, ну вот как можно было накосячить) Попробуй ещё" << std::endl;
        std::cin >> type;
    }
    return type;
}
