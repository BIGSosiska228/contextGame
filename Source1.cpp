#include <iostream>
#include <limits>
#include "windows.h"

using namespace std;

// ������� ��� �������� ������������ ������
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
            cout << "�������� �����! ����������, ������� ����� �� " << minChoice << " �� " << maxChoice << ": ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

// ������� �����
class Npc {
protected:
    string name{ "��������" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };
public:
    virtual void GetInfo() {
        cout << "��� - " << name << endl;
        cout << "�������� - " << health << endl;
        cout << "���� - " << damage << endl;
    }
    virtual void Create() = 0;
    virtual ~Npc() = default;
};

// ����
class Warrior : public Npc {
protected:
    unsigned short strenght{ 31 };
    string weapons[4] = { "������", "�������", "������", "���" };
public:
    Warrior() {
        name = "����";
        health = 35;
        damage = 10;
    }

    void GetWeapons() {
        cout << name << " ���� � ���� " << weapons[lvl - 1] << endl;
    }

    void GetInfo() override {
        Npc::GetInfo();
        cout << "���� - " << strenght << endl;
        cout << "��������� ������ - ";
        for (int i = 0; i < lvl; i++) {
            cout << weapons[i] << " ";
        }
        cout << endl;
    }

    void Create() override {
        cout << "�� ������� �����" << endl;
        cout << "������� ��� ���������: ";
        cin >> name;
        GetInfo();
        GetWeapons();
    }

    bool operator == (const Warrior& warrior) const {
        return ((warrior.damage == this->damage) && (warrior.health == this->health)
            && (warrior.strenght == this->strenght));
    }

    ~Warrior() override {
        cout << name << " ��� ������� �������" << endl;
    }
};

// ���������
class Wizard : public Npc {
protected:
    unsigned short intellect = 27;
    string spell[4] = { "�������", "���������� ������", "�������� ���", "����������� �����" };
public:
    Wizard() {
        name = "���������";
        health = 23;
        damage = 15;
    }

    void GetInfo() override {
        Npc::GetInfo();
        cout << "��������� - " << intellect << endl;
        cout << "��������� ���������� - ";
        for (int i = 0; i < lvl; i++) {
            cout << spell[i] << " ";
        }
        cout << endl;
    }

    void CastSpell() {
        cout << name << " ��������� " << spell[lvl - 1] << endl;
    }

    void Create() override {
        cout << "�� ������� ����������" << endl;
        cout << "������� ��� ���������: ";
        cin >> name;
        GetInfo();
        CastSpell();
    }

    ~Wizard() override {
        cout << name << " �������� ���" << endl;
    }
};

// ������
class Archer : public Npc {
protected:
    unsigned short agility{ 35 };
    string bows[4] = { "�������� ���", "������� ���", "��������� ���", "���������� ���" };
public:
    Archer() {
        name = "������";
        health = 28;
        damage = 12;
    }

    void GetInfo() override {
        Npc::GetInfo();
        cout << "�������� - " << agility << endl;
        cout << "��������� ���� - ";
        for (int i = 0; i < lvl; i++) {
            cout << bows[i] << " ";
        }
        cout << endl;
    }

    void Shoot() {
        cout << name << " �������� �� " << bows[lvl - 1] << "!" << endl;
    }

    void Create() override {
        cout << "�� ������� �������" << endl;
        cout << "������� ��� ���������: ";
        cin >> name;
        GetInfo();
        Shoot();
    }

    ~Archer() override {
        cout << name << " �������� ��������� ������" << endl;
    }
};

// ����
class Priest : public Npc {
protected:
    unsigned short wisdom{ 32 };
    string prayers[4] = { "����� ���������", "�������������", "�������� �������", "�����������" };
public:
    Priest() {
        name = "����";
        health = 26;
        damage = 8;
    }

    void GetInfo() override {
        Npc::GetInfo();
        cout << "�������� - " << wisdom << endl;
        cout << "��������� ������� - ";
        for (int i = 0; i < lvl; i++) {
            cout << prayers[i] << " ";
        }
        cout << endl;
    }

    void Pray() {
        cout << name << " ������ �������: " << prayers[lvl - 1] << "!" << endl;
    }

    void Create() override {
        cout << "�� ������� �����" << endl;
        cout << "������� ��� ���������: ";
        cin >> name;
        GetInfo();
        Pray();
    }

    ~Priest() override {
        cout << name << " ���������� � �����" << endl;
    }
};

// �������
class Paladin : public Warrior, public Wizard {
public:
    Paladin() {
        name = "�������";
        health = 25;
        damage = 12;
        strenght = 27;
    }

    void GetInfo() override {
        Warrior::GetInfo();
        cout << "��������� - " << intellect << endl;
        cout << "��������� ���������� - ";
        for (int i = 0; i < lvl; i++) {
            cout << spell[i] << " ";
        }
        cout << endl;
    }

    void Create() override {
        cout << "�� ������� ��������" << endl;
        cout << "������� ��� ���������: ";
        cin >> name;
        GetInfo();
        CastSpell();
        GetWeapons();
    }

    ~Paladin() override {
        cout << name << " ��� � ��� �� ����" << endl;
    }
};

// �����
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
    cout << "��������� ������: " << (*warrior == *warrior2) << endl;

    Wizard* wizard = new Wizard();
    Paladin* paladin = new Paladin();
    Archer* archer = new Archer();
    Priest* priest = new Priest();
    Player* player = new Player();

    cout << "������, ������! ������� � ������ � �������� � ����\n";

    unsigned short choice = GetValidChoice(1, 2, "�� ������� ���? (1 - ����� ��������, 2 - ���������)\n");

    if (choice == 1) {
        cout << "������ �����:\n";
        cout << "1 - ����\n2 - ���������\n3 - �������\n4 - ������\n5 - ����\n";
        cout << "���� �����: ";

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
        cout << "������� �������� ���� �� �����������..." << endl;
        delete warrior;
        delete wizard;
        delete paladin;
        delete archer;
        delete priest;
    }

    delete player;
    return 0;
}