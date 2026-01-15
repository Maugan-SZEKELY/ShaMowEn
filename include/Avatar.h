#ifndef AVATAR_H_INCLUDED
#define AVATAR_H_INCLUDED

#include "Personnage.h"
#include "Ennemi.h"

class Avatar {
private:
    Personnage _perso;
public:
    Avatar(const Image& image, int x, int y, int skin_x, int skin_y);

    void dessiner() const;
    void allerDroite(Niveau& niveau);
    void allerGauche(Niveau& niveau);
    void allerHaut(Niveau& niveau);
    void allerBas(Niveau& niveau);
    bool touche(const Ennemi& ennemi) const;
};

#endif // AVATAR_H_INCLUDED
