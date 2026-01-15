#include "Ennemi.h"

Ennemi::Ennemi(const Image& image, int x, int y, int skin_x, int skin_y, Direction direction)
    :_perso(image, x, y, skin_x, skin_y)
{
    switch (direction)
    {
    case BAS:
        _perso.regarderBas();
        break;
    case GAUCHE:
        _perso.regarderGauche();
        break;
    case DROITE:
        _perso.regarderDroite();
        break;
    case HAUT:
        _perso.regarderHaut();
        break;
    default:
        break;
    }
}

void Ennemi::dessiner() const
{
    _perso.dessiner();
}
void Ennemi::avancer(const Niveau& niveau)
{
    if (_perso.peutBougerVers(_perso.getDirection(), niveau))
    {
        // faire avancer l’ennemi dans sa direction courante
        switch (_perso.getDirection())
        {
        case DROITE:
            _perso.deplacer(TAILLE_CASE, 0);
            break;
        case GAUCHE:
            _perso.deplacer(-TAILLE_CASE, 0);
            break;
        case HAUT:
            _perso.deplacer(0, -TAILLE_CASE);
            break;
        case BAS:
            _perso.deplacer(0, TAILLE_CASE);
            break;
        default:
            break;
        }
    }
    else
    {
        _perso.inverserDirection();
    }
}
int Ennemi::getX() const {
    return _perso.getX();
}
int Ennemi::getY() const {
    return _perso.getY();
}
