#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include "Image.h"
#include "Niveau.h"

// Les valeurs des constantes nous importent (On ne veut pas que HAUT=0 par exemple)
// donc j'ai gardé les =
enum Direction {
    BAS=0,
    GAUCHE=1,
    DROITE=2,
    HAUT=3
};

class Personnage {
private:
    Image _image;
    int _x, _y; // pos sur le plateau
    int _skin_x, _skin_y; // pos de l'apparence sur la feuille de sprites
    Direction _direction;
public:
    Personnage(const Image& image, int x, int y, int skin_x, int skin_y);

    void dessiner() const;
    void regarderDroite();
    void regarderGauche();
    void regarderHaut();
    void regarderBas();
    void deplacer(int dx, int dy);
    bool peutBougerVers(Direction direction, const Niveau& niveau) const;
    Direction getDirection() const;
    void inverserDirection();
    int getX() const;
    int getY() const;
};

#endif // PERSONNAGE_H_INCLUDED
