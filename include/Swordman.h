#ifndef SWORDMAN_H
#define SWORDMAN_H

#include <Personajes.h>

class Swordman : public Personajes
{
    public:
        Swordman();
        Swordman(bool d);

        bool mov1(Personajes* per);
        bool mov2(Personajes* per);
        bool mov3(Personajes* per);
        bool mov4(Personajes* per);
        bool mov5(Personajes* per);
        bool mov6(Personajes* per);
        bool mov7(Personajes* per);
         void levelBoss(int i);

        virtual ~Swordman();
    protected:
    private:
};

#endif // SWORDMAN_H
