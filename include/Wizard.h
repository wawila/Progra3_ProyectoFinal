#ifndef WIZARD_H
#define WIZARD_H

#include <Personajes.h>

class Wizard : public Personajes
{
    public:
        Wizard();
        bool elemastery;

        bool mov1(Personajes* per);
        bool mov2(Personajes* per);
        bool mov3(Personajes* per);
        bool mov4(Personajes* per);
        bool mov5(Personajes* per);
        bool mov6(Personajes* per);
        bool mov7(Personajes* per);
         void levelBoss(int i);

        virtual ~Wizard();
    protected:
    private:
};

#endif // WIZARD_H
