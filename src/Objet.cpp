#include <iostream>
#include "Objet.h"
#include "Moteur.h" // Nécessaire pour récupérer TAILLE_CASE

using namespace std;

// Constructeur
Objet::Objet(const Image& objets, const string& nom, const Dictionnaire& dictionnaire, int x, int y){
    // 1. On stocke l'image
    _image = objets;

    // 2. On convertit les coordonnées "Grille" (ex: 5, 2) en "Pixels" (ex: 80, 32)
    _x = x * TAILLE_CASE;
    _y = y * TAILLE_CASE;

    // 3. On remplit l'attribut _tuile en cherchant dans le dictionnaire
    // La méthode recherche va remplir _tuile avec les bonnes infos (image X, image Y, propriété)
    bool trouve = dictionnaire.recherche(nom, _tuile);

    if (!trouve) {
        cout << "ERREUR : L'objet " << nom << " n'a pas ete trouve dans le dictionnaire !" << endl;
    }
}

// Méthode dessiner
void Objet::dessiner() const{
    // On récupère les coordonnées de la tuile sur la feuille de sprites
    int sourceX = _tuile.getSkinX() * TAILLE_CASE;
    int sourceY = _tuile.getSkinY() * TAILLE_CASE;

    if (_tuile.getPropriete() != "cache")
        // On dessine la partie de l'image à l'endroit voulu sur l'écran (_x, _y)
        _image.dessiner(_x, _y, sourceX, sourceY, TAILLE_CASE, TAILLE_CASE);
}

// Méthode cacher (pour les bonus)
void Objet::cacher(){
    // On change la propriété de la tuile pour dire qu'elle est cachée
    _tuile.setPropriete("cache");
}

int Objet::getX() const
{
    return _x;
}

int Objet::getY() const
{
    return _y;
}

string Objet::getPropriete() const {
    // L'objet pose la question à sa tuile.
    return _tuile.getPropriete();
}
