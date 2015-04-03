#ifndef BOSS_H
#define BOSS_H

#include <Personajes.h>

class Boss: public Personajes
{
    public:
        Boss();
        Boss(bool d);

        int newTarget(int x);
        bool atacar();
        void levelBoss(int x);

        bool mov1(Personajes* per);
        bool mov2(Personajes* per);
        bool mov3(Personajes* per);
        bool mov4(Personajes* per);
        bool mov5(Personajes* per);
        bool mov6(Personajes* per);
        bool mov7(Personajes* per);

        virtual ~Boss();
    protected:
    private:
};

#endif // BOSS_H
