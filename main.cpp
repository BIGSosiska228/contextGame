#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Npc.h"
#include "TrollWarlord.h"
#include "Lina.h"
#include "AntiMage.h"
#include "Treasure.h"
#include "Evil.h"

using namespace std;

unsigned short TestChoise(unsigned short maxChoise, string text)
{
    unsigned short choise;
    cin >> choise;
    while (choise < 1 || choise > maxChoise)
    {
        cout << text << endl;
        cin >> choise;
    }
    return choise;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    cout << "=== Добро пожаловать в мир Dota 2 ===\n";

    cout << "Выбери мир:\n1 - Сила света\n2 - Сила тьмы\n";
    int world = TestChoise(2, "Ошибка! Выбери 1 или 2.");

    if (world == 1)
        cout << "Ты отправляешься за силу света.\n";
    else
        cout << "Ты отправляешься за силу тьмы.\n";
    cout << "Древние начали войну.\n";
    cout << "Твоя цель — прорваться через врагов\n";
    cout << "и доказать силу выбранной стороны.\n";

    int lore = rand() % 3;
    if (world == 1)
    {
        if (lore == 0) cout << "В Dota настали не лучшие времена.\n";
        else if (lore == 1) cout << "Во имя сил света!\n";
        else cout << "Древние зовут — последуй за ними.\n";
    }
    else
    {
        if (lore == 0) cout << "Тьма поглотит этот мир!\n";
        else if (lore == 1) cout << "Сила тьмы ведет нас к победе!\n";
        else cout << "Страх — наше лучшее оружие!\n";
    }

    cout << "\nВыбери героя:\n1 - Троль Варлорд\n2 - Лина\n3 - Антимаг\n";
    int hero = TestChoise(3, "Такого героя нет.");

    Npc* player = nullptr;
    if (hero == 1) player = new TrollWarlord();
    else if (hero == 2) player = new Lina();
    else player = new AntiMage();

    player->Create();
    player->GetInfo();

    cout << "\n--- Катка начинается ---\n";

    int eventChance = rand() % 4;
    if (eventChance == 0)
    {
        cout << "Тебя атакует малый кемп. -5 HP.\n";
        player->health -= 5;
    }
    else if (eventChance == 1)
    {
        cout << "Ты отдохнул на фонтане. +5 HP.\n";
        player->health += 5;
    }
    else if (eventChance == 2)
    {
        cout << "Ты встретил торговца, который рассказал легенду.\n";
    }
    else
    {
        cout << "Путь был спокойным.\n";
    }

    cout << "Текущее здоровье: " << player->health << "/" << player->maxHealth << endl;

    Evil enemy1("Визаж", 15, 3, 6);
    Evil enemy2("Огр-Маги", 20, 5, 10);
    Evil* enemies[2] = { &enemy1, &enemy2 };

    for (int i = 0; i < 2; i++)
    {
        cout << "\n=== Появился враг: " << enemies[i]->name << " ===\n";
        enemies[i]->GetInfo();
        cout << "Враги преграждают тебе путь к древним...\n";

        while (enemies[i]->health > 0 && player->health > 0)
        {
            cout << "\nВыбери действие:\n";
            cout << "1 - Атаковать\n";
            cout << "2 - Использовать фласку (" << player->potions << ")\n";

            int action = TestChoise(2, "Выбери 1 или 2");

            if (action == 1)
            {
                cout << "Ты атакуешь!\n";
                enemies[i]->health -= player->damage;
                if (enemies[i]->health < 0)
                    enemies[i]->health = 0;
                cout << enemies[i]->name << " здоровье: "
                    << enemies[i]->health << std::endl;
            }
            else
            {
                if (player->UsePotion())
                    cout << "Ты похилил себя флаской и восстановил здоровье!\n";
                else
                    cout << "Зелье использовать нельзя!\n";
            }

            if (enemies[i]->health <= 0)
            {
                cout << "Ты убил " << enemies[i]->name << "!\n";
                int talk = rand() % 3;
                if (talk == 0) cout << "Еще один пал.\n";
                else if (talk == 1) cout << "Слабак.\n";
                else cout << "Следующий!\n";
                break;
            }

            cout << enemies[i]->name << " атакует тебя!\n";
            player->health -= enemies[i]->damage;
            cout << "Твое здоровье: " << player->health << "/" << player->maxHealth << endl;

            if (player->health <= 0)
            {
                cout << "Ты погиб...\n";
                break;
            }

        }

        if (player->health <= 0)
            break;

     
        if (i == 0 && player->health > 0)
        {
            cout << "\nКоманда жестко фидит...\n";
            cout << "Что будешь делать?\n";
            cout << "1 - Сломать шмотки и ливнуть\n";
            cout << "2 - Соло пробовать затащить\n";

            int choice = TestChoise(2, "Выбери 1 или 2.");

            if (choice == 1)
            {
                cout << "\nТы сломал шмотки и написал GG.\n";
                cout << "Катка закончена.\n";
                return 0;
            }
            else
            {
                cout << "\nТы решил соло тащить катку!\n";
                cout << "Появляется сильный враг...\n";

            }
        }
    }

    if (player->health > 0)
    {
        Treasure treasure(ValueQuality::редкое);
        cout << "\nТы нашёл предмет!\n";

        int loot = rand() % 4;
        if (loot == 0)
        {
            treasure.name = "Vanguard";
            treasure.ShowInfo();
            player->armor += 5;
        }
        else if (loot == 1)
        {
            treasure.name = "Blink Dagger";
            treasure.ShowInfo();
        }
        else if (loot == 2)
        {
            treasure.name = "Black King Bar";
            treasure.ShowInfo();
            player->damage += 5;
            player->armor += 5;
        }
        else
        {
            treasure.name = "Phase Boots";
            treasure.ShowInfo();
            player->damage += 2;
        }

        cout << "Урон: " << player->damage << endl;
        cout << "Броня: " << player->armor << endl;
    }
    if (player->health > 0)
        cout << "Ты выиграл соло катку.\n";
    else
        cout << "Твоя попытка провалилась, но катка еще продолжается...\n";
    cout << "\n=== Трон упал ===\n";

    delete player;
    return 0;
}

