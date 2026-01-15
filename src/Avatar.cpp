#include "Avatar.h"

Avatar::Avatar(const Image& image, int x, int y, int skin_x, int skin_y)
:_perso(image, x, y, skin_x, skin_y)
{

}

void Avatar::dessiner() const {
    _perso.dessiner();
}
void Avatar::allerDroite(Niveau& niveau) {
    _perso.regarderDroite();
    if (_perso.peutBougerVers(DROITE, niveau)) {
        _perso.deplacer(TAILLE_CASE, 0);
        niveau.testerBonusEtPrendre(_perso.getX(), _perso.getY());
    }
}
void Avatar::allerGauche(Niveau& niveau) {
    _perso.regarderGauche();
    if (_perso.peutBougerVers(GAUCHE, niveau)) {
        _perso.deplacer(-TAILLE_CASE, 0);
        niveau.testerBonusEtPrendre(_perso.getX(), _perso.getY());
    }
}
void Avatar::allerHaut(Niveau& niveau) {
    _perso.regarderHaut();
    if (_perso.peutBougerVers(HAUT, niveau)) {
        _perso.deplacer(0, -TAILLE_CASE);
        niveau.testerBonusEtPrendre(_perso.getX(), _perso.getY());
    }
}
void Avatar::allerBas(Niveau& niveau) {
    _perso.regarderBas();
    if (_perso.peutBougerVers(BAS, niveau)) {
        _perso.deplacer(0, TAILLE_CASE);
        niveau.testerBonusEtPrendre(_perso.getX(), _perso.getY());
    }
}
bool Avatar::touche(const Ennemi& ennemi) const {
    // on peut simplement tester si leurs deux coordonnées sont égales
    return _perso.getX() == ennemi.getX() && _perso.getY() == ennemi.getY();
}
