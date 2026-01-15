#include "Dictionnaire.h"
#include <fstream>
#include <iostream>

using namespace std;

Dictionnaire::Dictionnaire(const string& nom_fichier){
    //ouvre le fichier
    ifstream fichier(nom_fichier);

    //vérifie si l'ouverture a réussi
    if (fichier.is_open())
    {
        // 2 lit le nombre total de tuiles
        int nbElements;
        fichier >> nbElements;

        // 3 boucle autant de fois qu'il y a d'éléments
        for (int i = 0; i < nbElements; i++)
        {
            //variables temporaires
            string nom, propriete;
            int x, y;

            //4 infos sur la ligne (Nom X Y Propriété)
            fichier >> nom >> x >> y >> propriete;

            //crée un objet Tuile avec ces infos
            Tuile t(nom, x, y, propriete);

            //range cette tuile dans le vecteur _tuiles
            _tuiles.push_back(t);
        }

        //ferme le fichier
        fichier.close();
    }else{
        //message d'erreur si le fichier n'existe tout simplement pas
        cout << "Erreur : Impossible d'ouvrir le fichier " << nom_fichier << endl;
    }
}

bool Dictionnaire::recherche(const string& nom_tuile, Tuile& tuile_trouvee) const {
    int debut = 0;
    int fin = _tuiles.size() - 1; // Indices du vecteur
    bool trouve = false;

    while (debut <= fin && !trouve) {
        int milieu = (debut + fin) / 2;

        // On récupère le nom de la tuile au milieu pour comparer
        string nomCourant = _tuiles[milieu].getNom();

        if (nomCourant == nom_tuile) {
            trouve = true;
            tuile_trouvee = _tuiles[milieu]; // On copie la tuile trouvée dans le paramètre résultat
        }
        else if (nom_tuile < nomCourant) {
            fin = milieu - 1; // On cherche dans la partie gauche
        }
        else {
            debut = milieu + 1; // On cherche dans la partie droite
        }
    }

    return trouve;
}

void Dictionnaire::afficher() const {

    cout << "--- Contenu du Dictionnaire ---" << endl;

    for (int i = 0; i < _tuiles.size(); i++) {
        _tuiles[i].afficher(); // On appelle la méthode afficher() de la classe Tuile
    }
}
