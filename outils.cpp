/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : outils.cpp
 Auteur(s)   : Kevin Jordil & Filipe Dias Morais
 Date        : 21.01.2020

 But         :

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include <vector>

using Vecteur = std::vector<int>;
using Matrice = std::vector<Vecteur>;

void lire(Vecteur &v)
{
   //Ne pas ecrire "Saisir vecteur:"
   //Saisir la taille du vecteur
   //Saisir chaque composante
}

void afficher(const Vecteur &v)
{
   //Afficher sans texte
}

bool addition(const Vecteur &v1, const Vecteur &v2, Vecteur &v)
{
}

Vecteur multiplicationParScalaire(int n, const Vecteur &v)
{
}

bool produitScalaire(const Vecteur &v1, const Vecteur &v2, int &resultat)
{
}

void lire(Matrice &m)
{
   //Ne pas ecrire "Saisir matrice:"
   //Saisir la taille de la matrice
   //Saisir chaque composante
}

void afficher(const Matrice &m)
{
   //Afficher sans texte
}

bool addition(const Matrice &m1, const Matrice &m2, Matrice &m)
{
}

bool produit(const Matrice &m1, const Matrice &m2, Matrice &m)
{
}

Matrice transposee(const Matrice &m)
{
}