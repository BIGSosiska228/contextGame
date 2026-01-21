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
    unsigned short choise = 1;
    cin >> choise;
    while (choise > maxChoise || choise < 1)
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
        cout << "Ты отправляешься в мир доты за силу силу света.\n";
    else
        cout << "Ты отправляешься в доты за силу силу света.\n";


    int lore = rand() % 3;
    if (world == 1)
    {
        if (lore == 0) cout << "В Dota настали не лучшие времена\n";
        else if (lore == 1) cout << "Во имю сил света!.\n";
        else cout << "Древние зовут последуй за ними.\n";
    }
    else
    {
        if (lore == 0) cout << "Тьма поглотит этот мир!.\n";
        else if (lore == 1) cout << "Сила тьмы ведет нас к победе!.\n";
        else cout << "Страх - наше лучшее оружие!.\n";
    }


    cout << "\nВыбери героя:\n1 - Троль варлорд\n2 - Лина\n3 - Антимаг(крип)\n";
    int hero = TestChoise(3, "Таких героев у нас не было.");

    Npc* player = nullptr;
    if (hero == 1) player = new TrollWarlord();
    else if (hero == 2) player = new Lina();
    else if (hero == 3) player = new AntiMage();

    player->Create();
    player->GetInfo();

    cout << "\n--- Приключение начинается ---\n";


    int eventChance = rand() % 4;
    if (eventChance == 0)
    {
        cout << "Тебя атакует малый кемп и ты потерял 5 здоровья.\n";
        player->health -= 5;
    }
    else if (eventChance == 1)
    {
        cout << "Ты отдохнул на фонтане и восстановил 5 здоровья.\n";
        player->health += 5;
    }
    else if (eventChance == 2)
    {
        cout << "Ты встретил торговца лавки, который рассказал легенду.\n";
    }
    else
    {
        cout << "Путь был спокойным.\n";
    }
    cout << "Текущее здоровье: " << player->health << endl;


    Evil enemy1("Визаж", 15, 6);
    Evil enemy2("Огр-Маги", 20, 10);

    Evil* enemies[2] = { &enemy1, &enemy2 };

    for (int i = 0; i < 2; i++)
    {
        cout << "\n=== Появился враг: " << enemies[i]->name << " ===\n";
        enemies[i]->GetInfo();

        while (enemies[i]->health > 0 && player->health > 0)
        {
            cout << "\nТы атакуешь!\n";
            enemies[i]->health -= player->damage;
            cout << enemies[i]->name << " HP: " << enemies[i]->health << endl;

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
            cout << "Твое здоровье: " << player->health << endl;

            if (player->health <= 0)
            {
                cout << "Ты погиб...\n";
                break;
            }
        }

        if (player->health <= 0)
            break;
    }


    if (player->health > 0)
    {
        Treasure treasure(ValueQuality::редкое);
        treasure.name = "Vanguard";
        cout << "\nТы нашёл сокровище!\n";
        treasure.ShowInfo();
    }

    cout << "\n=== Конец катки ===\n";

    delete player;
    return 0;
}
