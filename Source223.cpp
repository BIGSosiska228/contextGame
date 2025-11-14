#include <iostream>
#include "windows.h"
#include <fstream>
#include"mainClass.h"
#pragma once
using namespace std;

enum class ValueQuality
{
    мусор, редкое,обычное, мифическое, легендарное//эквивалент перечислению чисел
};

enum class ValueCharachers
{
    Воин, Лучник, Маг, Жрец//эквивалент перечислению чисел
};

enum class ValueMainMenu
{
    Начатьсначала, Загрузить//эквивалент перечислению чисел
};

enum class ValueWeapon
{
   кастет, дубинка, клинок, меч,короткийлук, длинныйлук, составнойлук, магическийлук//эквивалент перечислению чисел
};

enum class ValueSpells
{
    вспышка, магическаястрела, огненныйшар, метеоритныйдождь //эквивалент перечислению чисел
};

unique_ptr<Npc> createCharacter(ValueCharachers type)
{
    switch (type)
    {
    case  ValueCharachers::Воин:
        return make_unique<warrior>();
        break;
    case  ValueCharachers::Лучник:
        return make_unique<archer>()
        break;
    case  ValueCharachers::Маг:
        return make_unique<wizard>()
        break;
    case  ValueCharachers::Жрец:
        return make_unique<priest>()
        break;
    default:
        throw
            ivalid_argument("неизвестный персонаж");
        break;
    }
}


struct Treasure//всё по умолчанию внутри public
{
    string name{ "добыча" };
    ValueQuality quality = ValueQuality::мусор;
    unsigned int price{ 0 };
    Treasure(ValueQuality quality)
    {
        switch (quality)
        {
        case ValueQuality::мусор:
            cout << "качество закалённое\n";
            break;
        case ValueQuality::обычное:
            cout << "качество среднечёк\n";
            break;
        case ValueQuality::редкое:
            cout << "качество хорошее\n";
            break;
        case ValueQuality::мифическое:
            cout << "качество крутое\n";
            break;
        case ValueQuality::легендарное:
            cout << "качество прямо с завода\n";
            break;
        default:
            break;
        }


        struct Treasure//все по умолчанию внутри public
        {
            string name{ "Добыча" };
            ValueQuality quality = ValueQuality::мусор;
            unsigned int price{ 0 };
        };
        struct Cloth : Treasure//наследование по умолчанию public
        {
            string  valueSite[5]{ "обувь","перчатки","шлем","нагрудник","пояс" };
            string site{ NULL };
            unsigned short armor{ 1 };
        };
        /*
        struct Treasure//все по умолчанию внутри private
        {
            string name{ "Добыча" };
            string  quality[5]{ "мусор","редкое","мифическое","легендарное" };
            unsigned int price{ 0 };
        };
        */

        // базовый класс
        class Npc
        {
        public:
            string name{ "персонаж" };
            unsigned int health{ 10 };
            float damage{ 5 };
            unsigned short lvl{ 1 };

            virtual void GetInfo()
            {
                cout << "Имя - " << name << endl;
                cout << "Здоровье - " << health << endl;
                cout << "Урон - " << damage << endl;
            }

            virtual void Create() {};

            virtual string GetClassName() { return "Npc"; }
        };

        // класс Воин
        class Warrior : public virtual Npc
        {
        protected:
            unsigned short strenght{ 31 };
            string weapons[4] = { "кастет", "дубинка", "клинок", "меч" };
        public:
            Warrior()
            {
                name = "воин";
                health = 35;
                damage = 10;
            }

            void GetWeapons()
            {
                cout << name << " взял в руки " << weapons[lvl - 1] << endl;
            }
            void GetInfo() override
            {
                Npc::GetInfo();
                cout << "Сила - " << strenght << endl;
                cout << "Доступное оружие - ";
                for (int i = 0; i < lvl; i++)
                {
                    cout << weapons[i] << " ";
                }
                cout << endl;
            }
            void Create() override
            {
                cout << "Вы создали война" << endl;
                cout << "Введите имя персонажа\t";
                cin >> name;
                GetInfo();
                GetWeapons();
            }

            string GetClassName() override { return "Warrior"; }

            bool operator == (const Warrior& warrior) const
            {
                return ((warrior.damage == this->damage) &&
                    (warrior.health == this->health) &&
                    (warrior.strenght == this->strenght));
            }

            ~Warrior()
            {
                cout << name << " пал смертью храбрых" << endl;
            }
        };

        // класс Волшебник
        class Wizard : public virtual Npc
        {
        protected:
            unsigned short intellect = 27;
            string spell[4] = { "вспышка", "магическая стрела", "огненный шар", "метеоритный дождь" };
        public:
            Wizard()
            {
                name = "волшебник";
                health = 23;
                damage = 15;
            }

            void GetInfo() override
            {
                Npc::GetInfo();
                cout << "Интеллект - " << intellect << endl;
                cout << "Доступные заклинания в книге заклинаний - ";
                for (int i = 0; i < lvl; i++)
                {
                    cout << spell[i] << " ";
                }
                cout << endl;
            }
            void CastSpell()
            {
                cout << name << " применяет " << spell[lvl - 1] << endl;
            }
            void Create() override
            {
                cout << "Вы создали волшебника" << endl;
                cout << "Введите имя персонажа\t";
                cin >> name;
                GetInfo();
                CastSpell();
            }

            string GetClassName() override { return "Wizard"; }

            ~Wizard()
            {
                cout << name << " испустил дух" << endl;
            }
        };

        // класс Паладин
        class Paladin : public Warrior, public Wizard
        {
        public:
            Paladin()
            {
                name = "паладин";
                health = 25;
                damage = 12;
            }
            void GetInfo() override
            {
                Warrior::GetInfo();
                cout << "Интеллект - " << intellect << endl;
                cout << "Доступные заклинания - ";
                for (int i = 0; i < lvl; i++)
                {
                    cout << spell[i] << " ";
                }
                cout << endl;
            }
            void Create() override
            {
                cout << "Вы создали паладина" << endl;
                cout << "Введите имя персонажа\t";
                cin >> name;
                GetInfo();
                CastSpell();
                GetWeapons();
            }

            string GetClassName() override { return "Paladin"; }
        };
        // класс Лучник
        class Archer : public virtual Npc
        {
        protected:
            unsigned short agility{ 35 };
            string bows[4] = { "короткий лук", "длинный лук", "составной лук", "магический лук" };
        public:
            Archer()
            {
                name = "лучник";
                health = 28;
                damage = 12;
            }

            void GetInfo() override
            {
                Npc::GetInfo();
                cout << "Ловкость - " << agility << endl;
                cout << "Доступные луки - ";
                for (int i = 0; i < lvl; i++)
                {
                    cout << bows[i] << " ";
                }
                cout << endl;
            }

            void Shoot()
            {
                cout << name << " стреляет из " << bows[lvl - 1] << "!" << endl;
            }

            void Create() override
            {
                cout << "Вы создали лучника" << endl;
                cout << "Введите имя персонажа\t";
                cin >> name;
                GetInfo();
                Shoot();
            }

            string GetClassName() override { return "Archer"; }

            ~Archer()
            {
                cout << name << " выпустил последнюю стрелу" << endl;
            }
        };

        // класс Жрец
        class Priest : public virtual Npc
        {
        protected:
            unsigned short wisdom{ 32 };
            string prayers[4] = { "малое исцеление", "благословение", "изгнание нечисти", "воскрешение" };
        public:
            Priest()
            {
                name = "жрец";
                health = 26;
                damage = 8;
            }

            void GetInfo() override
            {
                Npc::GetInfo();
                cout << "Мудрость - " << wisdom << endl;
                cout << "Доступные молитвы - ";
                for (int i = 0; i < lvl; i++)
                {
                    cout << prayers[i] << " ";
                }
                cout << endl;
            }

            void Pray()
            {
                cout << name << " читает молитву: " << prayers[lvl - 1] << "!" << endl;
            }

            void Create() override
            {
                cout << "Вы создали жреца" << endl;
                cout << "Введите имя персонажа\t";
                cin >> name;
                GetInfo();
                Pray();
            }

            string GetClassName() override { return "Priest"; }

            ~Priest()
            {
                cout << name << " отправился к богам" << endl;
            }
        };
        //класс Злодей 
        class Evil : public Npc {
        public:
            Evil(string name) {
                this->name = name;
                health = 10;
                damage = 5;
            }
            Evil(string name, int health) : Evil(name) {
                this->health = health;
            }
            Evil(string name, int health, int damage) : Evil(name, health) {
                this->damage = damage;
            }

            void GetInfo() override {
                cout << endl;
                cout << "на вас напал " << name << endl;
                if (health >= 0 && damage < 0) {
                    cout << "Здоровье - " << health << endl;
                }
                if (health < 0 && damage >= 0) {
                    cout << "урон - " << damage << endl;
                }
                if (health >= 0 && damage >= 0) {
                    cout << "Здоровье - " << health << endl;
                    cout << "урон - " << damage << endl;
                }
            }
        };
        void TakeDamage(Npc & npc, float damage)
        {
            float tempHealth = (float)npc.health - damage
                if (((float)npc.health - damage) < 0)
                {
                    npc.health = 0;
                    cout << "Персонаж погиб" << endl;
                }
                else
                {
                    npc.health = *tempHealth;
                }
            delete tempHealth;
            tempHealth = nullptr;
        }

        // класс Игрок
        class Player
        {
        private:
            unique_ptr<Npc> currentCharacter;
        public:
            void Create(unique_ptr<Npc> player)
            {
                currentCharacter = move(player);
                currentCharacter->Create();
            }
        };

        // --- функции сохранения и загрузки ---
        void SaveNpc(Npc * npc)
        {
            ofstream save("save.txt", ios::binary);
            if (!save.is_open())
            {
                cout << "Увы, ошибка сохранение!\n";
                return;
            }

            string className = npc->GetClassName();
            size_t nameLen = npc->name.size();
            size_t classLen = className.size();

            save.write(reinterpret_cast<char*>(&classLen), sizeof(classLen));
            save.write(className.c_str(), classLen);
            save.write(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
            save.write(npc->name.c_str(), nameLen);
            save.write(reinterpret_cast<char*>(&npc->health), sizeof(npc->health));
            save.write(reinterpret_cast<char*>(&npc->damage), sizeof(npc->damage));
            save.write(reinterpret_cast<char*>(&npc->lvl), sizeof(npc->lvl));

            cout << "Персонаж сохранён!\n";
        }

        Npc* LoadNpc()
        {
            ifstream load("save.txt", ios::binary);
            if (!load.is_open())
            {
                cout << "Что-то пошло не так (файл не найден)\n";
                return nullptr;
            }

            size_t classLen, nameLen;
            string className, name;
            unsigned int health;
            float damage;
            unsigned short lvl;

            load.read(reinterpret_cast<char*>(&classLen), sizeof(classLen));
            className.resize(classLen);
            load.read(&className[0], classLen);

            load.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
            name.resize(nameLen);
            load.read(&name[0], nameLen);

            load.read(reinterpret_cast<char*>(&health), sizeof(health));
            load.read(reinterpret_cast<char*>(&damage), sizeof(damage));
            load.read(reinterpret_cast<char*>(&lvl), sizeof(lvl));

            //----основной сюжет игры


            Evil* evil1 = new Evil("Мафиози", 1.1);
            Evil* evil2 = new Evil("крестный Отец", 1, 5);
            Evil* evil3 = new Evil("Зек", 3, 10);
            Evil* evil4 = new Evil("Отчим", 2, 10);
            Evil* evil5 = new Evil("Коронованный вор", rand() % 5 + 5, rand() % 5 + 5);
            Evil evils[5] = { *evil1, *evil2, *evil3, *evil4, *evil5 };


            cout << "\nВы отправляетесь в путешествие. Выберите направление:\n\t1 - королевство Бумбург\n\t2 - Катакомбы\n";
            choise = TestChoise(2);
            if (choise == 1)
            {
                cout << "Вы в пути...\n";
                for (int i = 0; i < 10; i++)
                {
                    Sleep(1000); //1 секунда
                    cout << "\nвы преодолели " << i * 10 << "% пути\n";
                    if (rand() % 100 > 50)
                    {
                        cout << "\nНа вас напал противник\n";
                        evils[(int)i / 2].GetInfo();
                    }
                }
                cout << "\nвы на месте!\n";
            }

            Npc* npc = nullptr;
            if (className == "Warrior") npc = new Warrior();
            else if (className == "Wizard") npc = new Wizard();
            else if (className == "Paladin") npc = new Paladin();
            else if (className == "Archer") npc = new Archer();
            else if (className == "Priest") npc = new Priest();
            else npc = new Npc();

            npc->name = name;
            npc->health = health;
            npc->damage = damage;
            npc->lvl = lvl;

            cout << "Персонаж успешно загружен: " << npc->GetClassName() << endl;
            npc->GetInfo();
            return npc;
        }

        int main()
        {
            setlocale(LC_ALL, "Rus");
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);

            Treasure treasure;
            treasure.name = "древняя тарелка";
            treasure.price = 30;
            treasure.quality = treasure.valueQuality[3];
            cout << treasure.name << "\n" << treasure.price << "\n" << treasure.quality << "\n";

            Warrior warrior;
            Wizard wizard;
            Paladin paladin;
            Archer archer;
            Priest priest;
            Player player;

            cout << "Привет, путник\nПрисядь у костра и расскажи о себе\n";
            cout << "Ты впервые тут? (1 - новый персонаж, 2 - загрузить)\n";

            unsigned short choise = 1;
            cin >> choise;
            while (choise > 2 || choise < 1)
            {
                cout << "Наверное ты ошибся, повтори снова\n";
                cin >> choise;
            }

            Npc* current = nullptr;

            if (choise == 1)
            {
                cout << "Расскажи о своих навыках\n";
                cout << "\t1 - Воин\n\t2 - Волшебник\n\t3 - Паладин\n\t4 - Лучник\n\t5 - Жрец\n";
                cin >> choise;
                while (choise > 5 || choise < 1)
                {
                    cout << "Такого еще не было в наших краях\nНе мог бы ты повторить\n";
                    cin >> choise;
                }

                switch (choise)
                {
                case 1:
                    player.Create(&warrior);
                    current = &warrior;
                    break;
                case 2:
                    player.Create(&wizard);
                    current = &wizard;
                    break;
                case 3:
                    player.Create(&paladin);
                    current = &paladin;
                    break;
                case 4:
                    player.Create(&archer);
                    current = &archer;
                    break;
                case 5:
                    player.Create(&priest);
                    current = &priest;
                    break;
                }
            }
            else
            {
                current = LoadNpc();
            }
            if (current != nullptr)
            {
                cout << "\nСделаем остановку тут?\n\t1 - сохранить игру\n\t2 - выйти без сохранения\n";
                cin >> choise;
                if (choise == 1)
                {
                    SaveNpc(current);
                }
            }

            cout << "\nДо новых встреч, герой!\n";
            return 0;
        }

