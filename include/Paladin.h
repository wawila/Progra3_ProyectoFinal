#ifndef PALADIN_H
#define PALADIN_H

#include <Personajes.h>


class Paladin : public Personajes
{
    public:
        bool vindspiritusado;
        Paladin();

        bool mov1(Personajes* per);
        bool mov2(Personajes* per);
        bool mov3(Personajes* per);
        bool mov4(Personajes* per);
        bool mov5(Personajes* per);
        bool mov6(Personajes* per);
        bool mov7(Personajes* per);

        virtual ~Paladin();
    protected:
    private:
};

#endif // PALADIN_H
