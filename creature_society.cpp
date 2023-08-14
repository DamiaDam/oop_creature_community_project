#include "header.hpp"
/*--------------------CREATE_SOCIETY FUNCTIONS--------------------*/

creature_society::creature_society(int size, int life, int var, int g_thrsh, int b_thrsh) // constructor
{
    numOfCreatures = size;

    string goodNames[var] = {"takis(good)_", "mpampis(good)_", "maria(good)_", "kostas(good)_", "giorgis(good)_", "sifis(good)_", "panagiota(good)_", "alex(good)_", "damianos(good)_", "ioanna(good)_"};
    string badNames[var] = {"takis(bad)_", "mpampis(bad)_", "maria(bad)_", "kostas(bad)_", "giorgis(bad)_", "sifis(bad)_", "panagiota(bad)_", "alex(bad)_", "damianos(bad)_", "ioanna(bad)_"};
    arrayOfCreatures = new creature *[numOfCreatures];

    for (int i = 0; i < numOfCreatures; i++)
    {
        if (randZeroOne() == 0)
            arrayOfCreatures[i] = new good_creature(life, goodNames[pickRandName(var)] + to_string(i), g_thrsh);
        else
            arrayOfCreatures[i] = new bad_creature(life, badNames[pickRandName(var)] + to_string(i), b_thrsh);
    }

    cout << "Society of creatures created!" << endl;
}

creature_society::~creature_society() // destructor
{
    for (int i = 0; i < numOfCreatures; i++) // deallocation
        delete arrayOfCreatures[i];
    delete[] arrayOfCreatures;

    cout << "Society of creatures destroyed!" << endl;
}

void creature_society::print()
{
    cout << "-------------------------------------" << endl;
    cout << "-Society of creatures: " << endl;
    for (int i = 0; i < numOfCreatures; i++)
    {
        cout << "[" << i << "] ";
        arrayOfCreatures[i]->print();
    }
    cout << "-------------------------------------" << endl;
}

void creature_society::bless(int i)
{
    if (arrayOfCreatures[i]->is_a_good()) // creature is good
    {
        if (arrayOfCreatures[i]->bless() == true)
            clone_next(i);
    }
    else // creature is bad
    {
        if (arrayOfCreatures[i]->bless())
            clone_zombies(i);
    }
}

int creature_society::no_of_good() // count the number of goods
{
    int count = 0;
    for (int i = 0; i < numOfCreatures; i++)
    {
        if (arrayOfCreatures[i]->is_a_good() == true)
            count++;
    }
    return count;
}

int creature_society::no_of_zombies() // count the number of zombies
{
    int count = 0;
    for (int i = 0; i < numOfCreatures; i++)
    {
        if (arrayOfCreatures[i]->is_a_zombie() == true)
            count++;
    }
    return count;
}

void creature_society::beat(int i)
{
    arrayOfCreatures[i]->beat();
}

void creature_society::clone_next(int w) // w is the position is society
{
    for (int i = w; i < numOfCreatures; i++)
    {
        if (i != numOfCreatures - 1) // current creature is anywhere else
        {
            delete arrayOfCreatures[i + 1];
            arrayOfCreatures[i + 1] = arrayOfCreatures[i]->clone();
            break;
        }
        else // current creature is the last one
        {
            delete arrayOfCreatures[0];
            arrayOfCreatures[0] = arrayOfCreatures[i]->clone();
            break;
        }
    }
}

void creature_society::clone_zombies(int w) // w is the position is society
{
    if (w < numOfCreatures - 1) // creature is last one in society
    {
        int var;                                         // current variable
        if (arrayOfCreatures[w]->is_a_zombie() == false) // current creature is not a zombie
        {
            if ((arrayOfCreatures[w + 1]->is_a_zombie()) == true) // current creature is a zombie
            {
                if ((w + 2 < numOfCreatures - 1 && arrayOfCreatures[w + 2]->is_a_zombie()))
                {
                    for (int i = w + 1; i < numOfCreatures; i++) // the loop starts from the next current creature
                    {
                        if (arrayOfCreatures[i]->is_a_zombie() == true) // current creature is a zombie
                        {
                            var = i;
                        }
                        else
                            break;
                    }
                    if (var - w > 1) // if the sub  of position of zombie and current position is above one then clone
                    {
                        for (int i = w + 1; i <= var; i++)
                        {
                            delete arrayOfCreatures[i];
                            arrayOfCreatures[i] = arrayOfCreatures[w]->clone();
                        }
                    }
                }
            }
        }
    }
}