#include "header.hpp"
/*--------------------GOOD_CREATURE FUNCTIONS--------------------*/
good_creature::good_creature(int life, string name, int g_thrsh) : creature(life, name), g_thrsh(g_thrsh)
{
    cout << "Good creature created!" << endl;
}

good_creature::good_creature(const good_creature &good_cret) : creature(good_cret)
{
    cout << "Good creature clone created!" << endl;
}

good_creature::~good_creature()
{
    cout << "Good creature destroyed!" << endl;
}

bool good_creature::is_a_good()
{
    return true;
}

creature *good_creature::clone()
{
    good_creature *g_cret = new good_creature(*this);

    return g_cret;
}

bool good_creature::bless()
{
    if (is_a_zombie() == false) // creature is not a zombie
    {
        lifetime++;
        cout << "Creature got bless" << endl;
        if (lifetime > g_thrsh) // creature is thrsh
        {
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
