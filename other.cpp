#include "header.hpp"

/*--------------------OTHER FUNCTIONS--------------------*/
int pickRandName(int var) // pick randomly a name from the two arrays with names
{
    return (rand() % var);
}

int randPosition(int numOfCreatures) // return a random position in society to select the creature,who is about to be bless/beat.
{
    return (rand() % numOfCreatures);
}

int randZeroOne() // return randomly 0 or 1
{
    return (rand() % 2);
}
