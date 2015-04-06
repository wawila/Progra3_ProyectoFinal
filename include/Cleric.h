#include <Personajes.h>

#ifndef CLERIC_H
#define CLERIC_H


class Cleric: public Personajes
{
    public:
        Cleric();
        bool getShadowstance();
        bool shadowstance;

        // agregar si tiene suficiente energia

        bool mov1(Personajes* per);
        bool mov2(Personajes* per);
        bool mov3(Personajes* per);
        bool mov4(Personajes* per);
        bool mov5(Personajes* per);
        bool mov6(Personajes* per);
        bool mov7(Personajes* per);
        void levelBoss(int i);


        virtual ~Cleric();
    protected:
    private:
};

#endif // CLERIC_H
