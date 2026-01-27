#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Npc.h"
#include "TrollWarlord.h"
#include "Lina.h"
#include "AntiMage.h"
#include "Treasure.h"
#include "Evil.h"



unsigned short TestChoise(unsigned short maxChoise, std::string text)
{
    unsigned short choise;
    std::cin >> choise;
    while (choise < 1 || choise > maxChoise)
    {
        std::cout << text << std::endl;
        std::cin >> choise;
    }
    return choise;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    std::cout << "=== Добро пожаловать в мир Dota 2 ===\n";

    std::cout << "Выбери мир:\n1 - Сила света\n2 - Сила тьмы\n";
    int world = TestChoise(2, "Ошибка! Выбери 1 или 2.");

    if (world == 1)
        std::cout << "Ты отправляешься за силу света.\n";
    else
        std::cout << "Ты отправляешься за силу тьмы.\n";

    std::cout << "Древние начали войну.\n";
    std::cout << "Твоя цель — прорваться через врагов\n";
    std::cout << "и доказать силу выбранной стороны.\n";

    int lore = rand() % 3;
    if (world == 1)
    {
        if (lore == 0)std::cout << "В Dota настали не лучшие времена.\n";
        else if (lore == 1)std::cout << "Во имя сил света!\n";
        else std::cout << "Древние зовут — последуй за ними.\n";
    }
    else
    {
        if (lore == 0) std::cout << "Тьма поглотит этот мир!\n";
        else if (lore == 1) std::cout << "Сила тьмы ведет нас к победе!\n";
        else std::cout << "Страх — наше лучшее оружие!\n";
    }

    std::cout << "\nВыбери героя:\n1 - Троль Варлорд\n2 - Лина\n3 - Антимаг\n";
    int hero = TestChoise(3, "Такого героя нет.");


    Npc* player = nullptr;
    if (hero == 1) player = new TrollWarlord();
    else if (hero == 2) player = new Lina();
    else player = new AntiMage();

 
    player->Create();
    player->GetInfo();

    std::cout << "\n--- Катка начинается ---\n";

 
    int eventChance = rand() % 4;
    switch (eventChance)
    {
    case 0:
        std::cout << "Тебя атакует малый кемп. -5 HP.\n";
        player->TakeDamage(5);
        break;
    case 1:
        std::cout << "Ты отдохнул на фонтане. +5 HP.\n";
        player->Heal(5);
        break;
    case 2:
        std::cout << "Ты встретил торговца, который рассказал легенду.\n";
        break;
    case 3:
        std::cout << "Путь был спокойным.\n";
        break;
    }

    std::cout << "Текущее здоровье: " << player->GetHealth() << "/" << player->GetMaxHealth() << std::endl;


    Evil enemy1("Визаж", 15, 3, 6);
    Evil enemy2("Огр-Маги", 20, 5, 10);
    Evil* enemies[2] = { &enemy1, &enemy2 };

    for (int i = 0; i < 2; i++)
    {
        std::cout << "\n=== Появился враг: " << enemies[i]->GetName() << " ===\n";
        enemies[i]->GetInfo();
        std::cout << "Враги преграждают тебе путь к древним...\n";

        while (enemies[i]->GetHealth() > 0 && player->GetHealth() > 0)
        {
            std::cout << "\nВыбери действие:\n";
            std::cout << "1 - Атаковать\n";
            std::cout << "2 - Использовать фласку (" << player->GetPotions() << ")\n";

            int action = TestChoise(2, "Выбери 1 или 2");

            if (action == 1)
            {
                std::cout << "Ты атакуешь!\n";
                enemies[i]->TakeDamage(player->GetDamage());
                std::cout << enemies[i]->GetName() << " здоровье: " << enemies[i]->GetHealth() << std::endl;
            }
            else
            {
                if (player->UsePotion())
                    std::cout << "Ты похилил себя флаской и восстановил здоровье!\n";
                else
                    std::cout << "Зелье использовать нельзя!\n";
            }

            if (enemies[i]->GetHealth() <= 0)
            {
                std::cout << "Ты убил " << enemies[i]->GetName() << "!\n";
                break;
            }

            std::cout << enemies[i]->GetName() << " атакует тебя!\n";
            player->TakeDamage(enemies[i]->GetDamage());
            std::cout << "Твое здоровье: " << player->GetHealth() << "/" << player->GetMaxHealth() << std::endl;

            if (player->GetHealth() <= 0)
            {
                std::cout << "Ты погиб...\n";
                break;
            }
        }
        if (i == 0 && player->GetHealth() > 0) 
        {
            std::cout << "\nКоманда жестко фидит...\n";
            std::cout << "Что будешь делать?\n";
            std::cout << "1 - Сломать шмотки и ливнуть\n";
            std::cout << "2 - Попробовать соло тащить катку\n";

            int choice = TestChoise(2, "Выбери 1 или 2.");

            if (choice == 1)
            {
                std::cout << "\nТы сломал шмотки и написал GG.\n";
                std::cout << "Катка закончена.\n";
                return 0; 
            }
            else
            {
                std::cout << "\nТы решил соло тащить катку!\n";
                std::cout << "Появляется сильный враг...\n";
             
            }
        }

        if (player->GetHealth() <= 0)
            break; 
    }


    if (player->GetHealth() > 0)
    {
        Treasure treasure(ValueQuality::редкое);
        std::cout << "\nТы нашёл предмет!\n";

        int loot = rand() % 4;
        switch (loot)
        {
        case 0:
            treasure.SetName("Vanguard");
            treasure.ShowInfo();
            player->AddArmor(5);
            break;
        case 1:
            treasure.SetName("Blink Dagger");
            treasure.ShowInfo();
            break;
        case 2:
            treasure.SetName("Black King Bar");
            treasure.ShowInfo();
            player->AddDamage(5);
            player->AddArmor(5);
            break;
        case 3:
            treasure.SetName("Phase Boots");
            treasure.ShowInfo();
            player->AddDamage(2);
            break;
        }

        std::cout << "Теперь твой урон: " << player->GetDamage() << std::endl;
        std::cout << "Теперь твоя броня: " << player->GetArmor() << std::endl;
    }

    if (player->GetHealth() > 0)
        std::cout << "Ты выиграл соло катку.\n";
    else
        std::cout << "Твоя попытка провалилась, но катка еще продолжается...\n";

    std::cout << "\n=== Трон упал ===\n";

    delete player;
    return 0;
}
