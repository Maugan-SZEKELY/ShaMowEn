#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED

#include "Personnage.h"

class Ennemi {
private:
    Personnage _perso;
public:
    Ennemi(const Image& image, int x, int y, int skin_x, int skin_y, Direction direction);

    void dessiner() const;
    void avancer(const Niveau& niveau);
    int getX() const;
    int getY() const;
};

#endif // ENNEMI_H_INCLUDED
