#include "Niveau.h"
#include <fstream>
#include <iostream>

using namespace std;

Niveau::Niveau(const Image& objets, const string& nom_fichier, const Dictionnaire& dictionnaire){
    _nb_bonus = 0;

    ifstream fichier (nom_fichier);

    if (fichier.is_open()){
        int nbObjet;
        fichier >> nbObjet ;

        for (int i=0; i<nbObjet; i++){

            string nom;
            int x,y;

            fichier >> nom >> x >> y;
            Objet o(objets, nom, dictionnaire, x, y);

            if (o.getPropriete() == "bonus") _nb_bonus++;

            _objets.push_back(o);
        }
        fichier.close();
    }else{
        cout << "Erreur : Impossible d'ouvrir le fichier " << nom_fichier << endl;
    }
}

void Niveau::dessiner() const {
    // On parcourt tous les objets stockés dans le vecteur _objets
    for (int i = 0; i < _objets.size(); i++) {
        _objets[i].dessiner(); // On demande à chaque objet de se dessiner
    }
}

bool Niveau::caseEstLibre(int x, int y) const {
    bool resultat = true;
    // On parcours le vecteur d'objets
    for (unsigned int i = 0; i < _objets.size(); i++) {

        // Pour chaque objet, tester si la propriété est "solide"
        if (_objets[i].getPropriete() == "solide") {

            // Si oui, vérifier si les coordonnées correspondent
            if (_objets[i].getX() == x && _objets[i].getY() == y) {

                // C'est solide et c'est au même endroit donc la case n'est pas libre.
                resultat = false;
            }
        }
    }

    // Si on a parcouru tout le tableau sans trouver d'obstacle, la case est libre.
    return resultat;
}

void Niveau::testerBonusEtPrendre(int x, int y) {
    // On parcours le vecteur d'objets
    for (int i = 0; i < _objets.size(); i++) {

        // On vérifie si c'est un bonus
        if (_objets[i].getPropriete() == "bonus") {

            // On vérifie si les coordonnées correspondent au joueur
            if (_objets[i].getX() == x && _objets[i].getY() == y) {

                // On est sur le Bonus

                // On décrémente le compteur du niveau
                _nb_bonus--;

                // On change la propriété de l'objet pour le "cacher"
                _objets[i].cacher();

            }
        }
    }
}

bool Niveau::gagne() const {
    // Si le compteur de bonus est tombé à 0, le joueur a gagné
    return (_nb_bonus == 0);
}
