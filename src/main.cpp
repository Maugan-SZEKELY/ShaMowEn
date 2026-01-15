#include <vector>
#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Avatar.h"
#include "Ennemi.h"
#include "Dictionnaire.h"
#include "Niveau.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
  // Initialisation du jeu
  Moteur moteur("ShaMowEn"); // "Mon super jeu vidéo"

  /// TODO: charger images, creer personnages, etc.
  // Image fond(moteur, "assets/fond.png");
//  Image coffreF(moteur, "assets/coffre_ferme.png");
//  Image coffreO(moteur, "assets/coffre_ouvert.png");
  Image personnages(moteur, "assets/personnages.png");
  Avatar chevalier(personnages, 1, 2, 3, 0);
  Ennemi ennemi1(personnages, 5, 2, 0, 4, HAUT);
  Ennemi ennemi2(personnages, 1, 5, 9, 4, DROITE);

  Image objets(moteur, "assets/objets.png");
  Dictionnaire dictionnaire("assets/dictionnaire.txt");
  /// dictionnaire.afficher(); /// 6. séance 4/5
  Niveau niveau(objets, "assets/niveau.txt", dictionnaire);

  bool quitter = false;
//  bool coffreOuvert = false; // bool etatCoffre = false; // ouvert (true) ou fermé (false)

  // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
  // (en general, 60 fois par seconde)
  while (!quitter)
  {
    // I. Gestion des evenements
    Evenement evenement = moteur.evenementRecu();
    while (evenement != AUCUN)
    {
      switch (evenement)
      {
        // QUITTER = croix de la fenetre ou Echap
        case QUITTER_APPUYE:
          quitter = true;
          break;
        /// TODO: gerer les autres evenements
        case GAUCHE_APPUYE:
            chevalier.allerGauche(niveau);
            break;
        case DROITE_APPUYE:
            chevalier.allerDroite(niveau);
            break;
        case HAUT_APPUYE:
            chevalier.allerHaut(niveau);
            break;
        case BAS_APPUYE:
            chevalier.allerBas(niveau);
            break;
//        case ESPACE_APPUYE:
//            coffreOuvert = true;
//            break;
//        case ESPACE_RELACHE:
//            coffreOuvert = false;
//            break;
        default:
          break;
      }

      evenement = moteur.evenementRecu();
    }

    // II. Mise à jour de l'état du jeu

    /// TODO: faire bouger vos personnages, etc.
    if (moteur.animationsAmettreAjour())
    {
        ennemi1.avancer(niveau);
        ennemi2.avancer(niveau);
    }

    // On quitte si l'un des ennemis est touché par le chevalier
    // ou si on a gagné
    quitter = quitter || chevalier.touche(ennemi1) || chevalier.touche(ennemi2) || niveau.gagne();

    // III. Generation de l'image à afficher

    moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

    /// TODO: afficher vos personnages, objets, etc.
    // fond.dessiner(0, 0);
    niveau.dessiner();
    chevalier.dessiner();
    ennemi1.dessiner();
    ennemi2.dessiner();
//    if(coffreOuvert)
//        coffreO.dessiner(0, 0);
//    else
//        coffreF.dessiner(0, 0);

    /*
      Affiche l'image en se cadencant sur la frequence de
      rafraichissement de l'ecran (donc va en general mettre le
      programme en pause jusqu'a ce que l'ecran soit rafraichi). En
      general, 60 images fois par seconde, mais ca peut dependre du
      materiel
    */
    moteur.finaliserRendu();
  }

  return 0;
}
