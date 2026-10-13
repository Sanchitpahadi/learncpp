#include<iostream>
#include <vector>
#include <iostream>
#include <cstdlib>

void clearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

class Charecter
{
    public:

    virtual void charecterstic() = 0;
    virtual void attack() = 0;

    protected:
        int health = 100;
};


class Level
{
    public:
struct level
{
    std::string name;
    std::string mission;
    int timeLimit;
    float pay;
};

std::vector<level> levels =
{
    {"Goblin Forest", "Defeat 5 goblins", 120, 100.0f},
    {"Orc Fortress", "Defeat the Orc Chief", 180, 250.0f},
    {"Lost Treasure", "Find and retrieve the treasure", 240, 300.0f},
    {"Dragon Cave", "Defeat the fire dragon", 300, 500.0f},
    {"Haunted Ruins", "Survive the skeleton army", 180, 200.0f},
    {"Frozen Peaks", "Defeat the Ice Mage", 240, 350.0f},
    {"Shadow Dungeon", "Retrieve the cursed artifact", 360, 600.0f},
    {"Bandit Camp", "Defeat the bandit leader", 150, 180.0f},
    {"Ancient Temple", "Solve the temple challenge", 300, 450.0f},
    {"Final Battle", "Defeat the Dark Lord", 600, 1000.0f}
};

void list_level()
{
    std::cout << "name - " << " \t "
              << "mission- " << " \t "
              << "timelimit- " << " \t "
              << "pay- "<< "\n";
    for (int i = 0; i < levels.size(); i++)
    {
        std::cout << i + 1 << ". "
                  << levels.at(i).name << " - \t "
                  << levels.at(i).mission << " - \t "
                  << levels.at(i).timeLimit << "-  \t "
                  << levels.at(i).pay<< "\n";
    }
}
    private:
};


class Inventory
{

public:
std::vector<std::string> weapons = 
{
"Iron Sword",
"Steel Sword",
"Battle Axe",
"War Hammer",
"Dagger",
"Longbow",
"Crossbow",
"Fire Staff",
"Ice Staff",
"Shadow Blade"
};

struct Elixir
{
    std::string name;
    std::string special_characteristic;
    int duration;
};

std::vector<Elixir> elixirs = 
{
    {"Health Elixir", "Restores 50 health", 0},
    {"Strength Elixir", "Increases attack damage by 15", 60},
    {"Speed Elixir", "Increases movement speed", 30},
    {"Defense Elixir", "Reduces incoming damage by 10", 45},
    {"Fire Elixir", "Adds fire damage to attacks", 30},
    {"Ice Elixir", "Slows enemies on attack", 20},
    {"Invisibility Elixir", "Makes the user invisible", 15},
    {"Regeneration Elixir", "Restores 5 health per second", 30},
    {"Poison Resistance Elixir", "Reduces poison damage", 60},
    {"Mana Elixir", "Restores 50 mana", 0}
};

void list_wepons()
{
    for (int i = 0; i < weapons.size(); i++)
    {
        std::cout << i + 1 << ". " << weapons.at(i) << "\n";
    }
}
void list_Elixirs()
{
    for (int i = 0; i < elixirs.size(); i++)
    {
        std::cout << i + 1 << ". "
                  << elixirs.at(i).name << " - "
                  << elixirs.at(i).special_characteristic
                  << "\n";
    }
}
    private:
};


class Hero: public Charecter
{   


    void charecterstic() override
    {
        std::cout << "I am  Hero \n i take 15 points in health"<< std:: endl;
    }
    void attack ()override
    {
        std::cout << "15 down"<< std:: endl;
    }
};

class Orc: public Charecter
{

    void charecterstic() override
    {
        std::cout << "I am goaated Orc \n I take 10 points in health "<< std:: endl;
    }
    void attack ()override
    {
        std::cout << " 10 points down "<< std:: endl;
    }
};

/*
class Mage: public Charecter
{

};

class Goblin: public Charecter
{

};
*/

class Game
{
    public:

    Game()
    {

    }
    ~Game()
    {
        
    }

    void player_chosen()
    {
        int player = 0;
        std::cout << "Chose the player you like or love"<< std::endl;
        std::cout << "1. Hero"<< std::endl;
        std::cout << "2. Orc" << std::endl;
        std::cin >> player ;

        switch (player)
        {
        case 1:
            c = new Hero;
            break;
        case 2:
            c = new Orc;
            break;
        
        default:
            break;
        }
    }

    void start()
    {
        player_chosen();
        std::cout << "Chose the Wepon you want "<< std::endl;
        
        inventory.list_wepons();
        
        loop();
    }

    void loop()
    {
        int n = 1;
        char c = n;
        while(n!=0)
        {
            clearScreen();

            std::cout << "q\t FOR MISSIONS"<< std::endl;
            std::cout << "e\t FOR  INVENTORY" << std::endl;
            std::cin>> c;

            switch (c)
            {
            case 'q':
                level.list_level();
                break;
            case 'e':
                std::cout << "Wepons ARE HERE" << std::endl;
                inventory.list_wepons();
                std::cout << "Elixirs ARE HERE" << std::endl;
                inventory.list_Elixirs();
                break;
            
            default:
                break;
            }
            std::cin >> n;

            clearScreen();
        }
    }

    Charecter* player()
    {
        return c;
    }

    private:

    Charecter *c = NULL;
    Level level;
    Inventory inventory;
};



int main()
{

    Game g;
    g.start();
    Charecter *c = g.player();
    c->attack();

    delete c;
    return 0;
}