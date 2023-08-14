#include "header.hpp"

/*--------------------CREATURE FUNCTIONS--------------------*/
creature::creature(int life, string name) : lifetime(life), creatureName(name)
{
    cout << "Creature created!" << endl;
}

creature::creature(const creature &cret) : lifetime(cret.lifetime), creatureName(cret.creatureName)
{
    cout << "Creature clone created!" << endl;
}

creature::~creature()
{
    cout << "Creature destroyed!" << endl;
}

bool creature::is_a_zombie()
{
    if (lifetime == 0) // creature is a zombie
        return true;
    else // creature is not a zombie
        return false;
}

void creature::beat()
{
    if (is_a_zombie() == false) // creature is not a zombie
    {
        if (lifetime > 0)
        {
            lifetime--;
            cout << "Creature got beated" << endl;
        }
    }
}

void creature::print()
{
    cout << "name: " << creatureName << " | life: " << lifetime << endl;
}