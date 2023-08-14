#include "header.hpp"

/*--------------------BAD_CREATURE FUNCTIONS--------------------*/
bad_creature::bad_creature(int life, string name, int b_thrsh) : creature(life, name), b_thrsh(b_thrsh)
{
    cout << "Bad creature created!" << endl;
}

bad_creature::bad_creature(const bad_creature &bad_cret) : creature(bad_cret)
{
    cout << "Bad creature clone created!" << endl;
}

bad_creature::~bad_creature()
{
    cout << "Bad creature destroyed!" << endl;
}

bool bad_creature::is_a_good()
{
    return false;
}

creature *bad_creature::clone()
{
    bad_creature *b_cret = new bad_creature(*this);

    return b_cret;
}

bool bad_creature::bless()
{
    if (is_a_zombie() == false)
    {
        lifetime++;
        cout << "Creature got bless" << endl;
        if (lifetime > b_thrsh) // creature is thrsh
            return true;
        else
            return false;
    }
    else
        return false;
}
