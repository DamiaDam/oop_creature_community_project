#include <iostream>
#include <cstdlib>
#include <cstring>
#include <time.h>
#include <string.h>

using namespace std;

/* FUNCTION PROTOTYPES */
int pickRandName(int var);            // pick a rand name from array with names
int randPosition(int numOfCreatures); // return rand position in society
int randZeroOne();                    // return randomly 0 or 1 (bless or beat)

class creature_society;

class creature
{
protected:
    string creatureName;
    int lifetime;

public:
    creature(int, string);          // constructor
    creature(const creature &cret); // copy constructor
    ~creature();                    // destructor
    bool is_a_zombie();
    virtual bool is_a_good() = 0;  // virtual
    virtual creature *clone() = 0; // pure virtual
    virtual bool bless() = 0;      // pure virtual
    void beat();
    void print();
};

class good_creature : public creature
{
private:
    int g_thrsh;

public:
    good_creature(int life, string name, int g_thrsh); // constructor
    good_creature(const good_creature &good_cret);     // copy constructor
    ~good_creature();                                  // destructor
    bool is_a_good() override;
    bool bless() override;
    creature *clone() override;
};

class bad_creature : public creature
{
private:
    int b_thrsh;

public:
    bad_creature(int life, string name, int b_thrsh); // construcror
    bad_creature(const bad_creature &bad_cret);       // copy constrctor
    ~bad_creature();                                  // destructor
    creature *clone() override;
    bool is_a_good() override;
    bool bless() override;
};

class creature_society
{
private:
    int numOfCreatures;
    creature **arrayOfCreatures;

public:
    creature_society(int size, int life, int var, int g_thrsh, int b_thrsh); // constructor
    ~creature_society();                                                     // destructor
    void print();
    void bless(int i);
    void beat(int i);
    void clone_next(int w);
    void clone_zombies(int position);
    int no_of_good();
    int no_of_zombies();
};