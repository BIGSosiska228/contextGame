#include <iostream>
#include <limits>
#include "windows.h"

using namespace std;

// Функция для проверки корректности выбора
unsigned short GetValidChoice(unsigned short minChoice, unsigned short maxChoice, const string& prompt = "") {
    unsigned short choice;

    if (!prompt.empty()) {
        cout << prompt;
    }

    while (true) {
        cin >> choice;

        if (cin.fail() || choice < minChoice || choice > maxChoice) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный выбор! Пожалуйста, введите число от " << minChoice << " до " << maxChoice << ": ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

// Базовый класс
class Npc {
protected:
    string name{ "персонаж" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };
public:
    virtual void GetInfo() {
        cout << "Имя - " << name << endl;
        cout << "Здоровье - " << health << endl;
        cout << "Урон - " << damage << endl;
    }
    virtual void Create() = 0;
    virtual ~Npc() = default;
};

// Воин
class Warrior : public Npc {
protected:
    unsigned short strenght{ 31 };
    string weapons[4] = { "кастет", "дубинка", "клинок", "меч" };
public:
    Warrior() {
        name = "воин";
        health = 35;
        damage = 10;
    }

    void GetWeapons() {
        cout << name << " взял в руки " << weapons[lvl - 1] << endl;
    }

    void GetInfo() override {
        Npc::GetInfo();
        cout << "Сила - " << strenght << endl;
        cout << "Доступное оружие - ";
        for (int i = 0; i < lvl; i++) {
            cout << weapons[i] << " ";
        }
        cout << endl;
    }

    void Create() override {
        cout << "Вы создали война" << endl;
        cout << "Введите имя персонажа: ";
        cin >> name;
        GetInfo();
        GetWeapons();
    }

    bool operator == (const Warrior& warrior) const {
        return ((warrior.damage == this->damage) && (warrior.health == this->health)
            && (warrior.strenght == this->strenght));
    }

    ~Warrior() override {
        cout << name << " пал смертью храбрых" << endl;
    }
};

// Волшебник
class Wizard : public Npc {
protected:
    unsigned short intellect = 27;
    string spell[4] = { "вспышка", "магическая стрела", "огненный шар", "метеоритный дождь" };
public:
    Wizard() {
        name = "волшебник";
        health = 23;
        damage = 15;
    }

    void GetInfo() override {
        Npc::GetInfo();
        cout << "Интеллект - " << intellect << endl;
        cout << "Доступные заклинания - ";
        for (int i = 0; i < lvl; i++) {
            cout << spell[i] << " ";
        }
        cout << endl;
    }

    void CastSpell() {
        cout << name << " применяет " << spell[lvl - 1] << endl;
    }

    void Create() override {
        cout << "Вы создали волшебника" << endl;
        cout << "Введите имя персонажа: ";
        cin >> name;
        GetInfo();
        CastSpell();
    }

    ~Wizard() override {
        cout << name << " испустил дух" << endl;
    }
};

// Лучник
class Archer : public Npc {
protected:
    unsigned short agility{ 35 };
    string bows[4] = { "короткий лук", "длинный лук", "составной лук", "магический лук" };
public:
    Archer() {
        name = "лучник";
        health = 28;
        damage = 12;
    }

    void GetInfo() override {
        Npc::GetInfo();
        cout << "Ловкость - " << agility << endl;
        cout << "Доступные луки - ";
        for (int i = 0; i < lvl; i++) {
            cout << bows[i] << " ";
        }
        cout << endl;
    }

    void Shoot() {
        cout << name << " стреляет из " << bows[lvl - 1] << "!" << endl;
    }

    void Create() override {
        cout << "Вы создали лучника" << endl;
        cout << "Введите имя персонажа: ";
        cin >> name;
        GetInfo();
        Shoot();
    }

    ~Archer() override {
        cout << name << " выпустил последнюю стрелу" << endl;
    }
};

// Жрец
class Priest : public Npc {
protected:
    unsigned short wisdom{ 32 };
    string prayers[4] = { "малое исцеление", "благословение", "изгнание нечисти", "воскрешение" };
public:
    Priest() {
        name = "жрец";
        health = 26;
        damage = 8;
    }

    void GetInfo() override {
        Npc::GetInfo();
        cout << "Мудрость - " << wisdom << endl;
        cout << "Доступные молитвы - ";
        for (int i = 0; i < lvl; i++) {
            cout << prayers[i] << " ";
        }
        cout << endl;
    }

    void Pray() {
        cout << name << " читает молитву: " << prayers[lvl - 1] << "!" << endl;
    }

    void Create() override {
        cout << "Вы создали жреца" << endl;
        cout << "Введите имя персонажа: ";
        cin >> name;
        GetInfo();
        Pray();
    }

    ~Priest() override {
        cout << name << " отправился к богам" << endl;
    }
};

// Паладин
class Paladin : public Warrior, public Wizard {
public:
    Paladin() {
        name = "паладин";
        health = 25;
        damage = 12;
        strenght = 27;
    }

    void GetInfo() override {
        Warrior::GetInfo();
        cout << "Интеллект - " << intellect << endl;
        cout << "Доступные заклинания - ";
        for (int i = 0; i < lvl; i++) {
            cout << spell[i] << " ";
        }
        cout << endl;
    }

    void Create() override {
        cout << "Вы создали паладина" << endl;
        cout << "Введите имя персонажа: ";
        cin >> name;
        GetInfo();
        CastSpell();
        GetWeapons();
    }

    ~Paladin() override {
        cout << name << " пал в бою за свет" << endl;
    }
};

// Игрок
class Player {
public:
    void Create(Npc* player) {
        player->Create();
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Warrior* warrior = new Warrior();
    Warrior* warrior2 = new Warrior();
    cout << "Сравнение воинов: " << (*warrior == *warrior2) << endl;

    Wizard* wizard = new Wizard();
    Paladin* paladin = new Paladin();
    Archer* archer = new Archer();
    Priest* priest = new Priest();
    Player* player = new Player();

    cout << "Привет, путник! Присядь у костра и расскажи о себе\n";

    unsigned short choice = GetValidChoice(1, 2, "Ты впервые тут? (1 - новый персонаж, 2 - загрузить)\n");

    if (choice == 1) {
        cout << "Выбери класс:\n";
        cout << "1 - Воин\n2 - Волшебник\n3 - Паладин\n4 - Лучник\n5 - Жрец\n";
        cout << "Твой выбор: ";

        choice = GetValidChoice(1, 5);

        switch (choice) {
        case 1:
            player->Create(warrior);
            delete wizard;
            delete paladin;
            delete archer;
            delete priest;
            break;
        case 2:
            player->Create(wizard);
            delete warrior;
            delete paladin;
            delete archer;
            delete priest;
            break;
        case 3:
            player->Create(paladin);
            delete warrior;
            delete wizard;
            delete archer;
            delete priest;
            break;
        case 4:
            player->Create(archer);
            delete warrior;
            delete wizard;
            delete paladin;
            delete priest;
            break;
        case 5:
            player->Create(priest);
            delete warrior;
            delete wizard;
            delete paladin;
            delete archer;
            break;
        }
    }
    else {
        cout << "Функция загрузки пока не реализована..." << endl;
        delete warrior;
        delete wizard;
        delete paladin;
        delete archer;
        delete priest;
    }

    delete player;
    return 0;
}