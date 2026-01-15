#include "Personnage.h"

Personnage::Personnage(const Image& image, int x, int y, int skin_x, int skin_y) {
    _image = image;
    _x = x*TAILLE_CASE;
    _y = y*TAILLE_CASE;
    _direction = BAS;
    _skin_x = skin_x;
    _skin_y = skin_y;
}

void Personnage::dessiner() const {
    _image.dessiner(_x, _y, (_skin_x+1)*TAILLE_CASE, (_skin_y+_direction)*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
}
void Personnage::regarderDroite() {
    _direction = DROITE;
}
void Personnage::regarderGauche() {
    _direction = GAUCHE;
}
void Personnage::regarderHaut() {
    _direction = HAUT;
}
void Personnage::regarderBas() {
    _direction = BAS;
}
void Personnage::deplacer(int dx, int dy) {
    _x += dx;
    _y += dy;
}
bool Personnage::peutBougerVers(Direction direction, const Niveau& niveau) const {
    bool reponse = false;
    switch (direction) {
        case BAS:
            // éviter de sortir de l'écran
            reponse = _y + TAILLE_CASE < HAUTEUR_FENETRE; // + TAILLE_CASE pour prendre le bord bas du héros
            // et éviter d'aller sur un objet `solide`
            reponse &= niveau.caseEstLibre(_x, _y+TAILLE_CASE);
            break;
        case GAUCHE:
            // éviter de sortir de l'écran
            reponse = 0 < _x;
            // et éviter d'aller sur un objet `solide`
            reponse &= niveau.caseEstLibre(_x-TAILLE_CASE, _y);
            break;
        case DROITE:
            // éviter de sortir de l'écran
            reponse = _x + TAILLE_CASE < LARGEUR_FENETRE; // + TAILLE_CASE pour prendre le bord droit du héros
            // et éviter d'aller sur un objet `solide`
            reponse &= niveau.caseEstLibre(_x+TAILLE_CASE, _y);
            break;
        case HAUT:
            // éviter de sortir de l'écran
            reponse = 0 < _y;
            // et éviter d'aller sur un objet `solide`
            reponse &= niveau.caseEstLibre(_x, _y-TAILLE_CASE);
            break;
        default:
            // false
            break;
    }
    return reponse;
}
Direction Personnage::getDirection() const {
    return _direction;
}
void Personnage::inverserDirection() {
    // met la direction à droite (si elle était à gauche), en bas (si elle était en haut), etc.
    switch (_direction) {
        case BAS:
            regarderHaut();
            break;
        case GAUCHE:
            regarderDroite();
            break;
        case DROITE:
            regarderGauche();
            break;
        case HAUT:
            regarderBas();
            break;
        default:
            break;
    }
}
int Personnage::getX() const {
    return _x;
}
int Personnage::getY() const {
    return _y;
}
