// Interface Utilisateur pour la librairie vecteurs et matrices

#ifndef INTERFACEUTILISATEUR_H
#define INTERFACEUTILISATEUR_H

#include <string>
#include <vector>

using Vecteur = std::vector<int>;
using Matrice = std::vector<Vecteur>;
using Texte = std::string;

// Affiche l'interface utilisateur
void InterfaceUtilisateur();

// Affiche le menu, renvoie le choix
unsigned affichageChoixOperation();

// Demande la saisie d'un vecteur
void demandeSaisieVecteur(const Texte &nomVecteur, Vecteur &v);

// Demande la saisie d'une matrice
void demandeSaisieMatrice(const Texte &nomMatrice, Matrice &m);


#endif