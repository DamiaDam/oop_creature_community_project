/*
DAMIANAKIS DAMIANOS
1115201800306
ERGASIA 3 2021-22
*/

#include "header.hpp"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int var = 10; // amount of names in the static arrays of good and bad names (creature_society.cpp)

    int numOfCreatures;   // N
    int numOfRepetitions; // M
    int lifetime;         // L
    int good_thrsh;       // good_thrsh
    int bad_thrsh;        // bad_thrsh

    if (argc != 6)
    {
        cout << "Wrong amount of arguments!" << endl;
        return 1;
    }

    // convert arguments to integers
    numOfCreatures = atoi(argv[1]);
    numOfRepetitions = atoi(argv[2]);
    lifetime = atoi(argv[3]);
    good_thrsh = atoi(argv[4]);
    bad_thrsh = atoi(argv[5]);

    if (numOfRepetitions < 0 || numOfCreatures < 0 || lifetime < 0 || good_thrsh < 0 || bad_thrsh < 0)
    {
        cout << "Inputs must be positive integers!" << endl;
        return 1;
    }

    creature_society soc(numOfCreatures, lifetime, var, good_thrsh, bad_thrsh);

    soc.print();

    for (int i = 0; i < numOfRepetitions; i++)
    {
        if (randZeroOne() == 0)
            soc.bless(randPosition(numOfCreatures));
        else
            soc.beat(randPosition(numOfCreatures));
        soc.print();
    }

    if (soc.no_of_good() > numOfCreatures - soc.no_of_good())
        cout << "Good Dominates in the World!" << endl;
    else if (soc.no_of_zombies() > numOfCreatures - soc.no_of_zombies())
        cout << "This is a dead society!" << endl;
    else
        cout << "Try again to improve the world!" << endl;

    return 0;
}
