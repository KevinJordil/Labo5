// Outils de base pour faire du calcul vectoriel et matriciel

#ifndef OUTILS_H
#define OUTILS_H

#include <vector>

using Vecteur = std::vector<int>;
using Matrice = std::vector<Vecteur>;

// Pour la saisie interactive contrôlée d'un vecteur.
// L'utilisateur est invité à saisir le nombre de composantes voulues ainsi
// que les valeurs de ces composantes
void lire(Vecteur& v);

// Affiche un vecteur sous la forme:
// [valeur_1, valeur_2,...]
void afficher(const Vecteur& v);

// Addition de 2 vecteurs
// La fonction renvoie true en valeur de retour si l'opération a pu être faite et
// false sinon
bool addition(const Vecteur& v1, const Vecteur& v2, Vecteur& v);

// Multiplication d'un vecteur par un scalaire
Vecteur multiplicationParScalaire(int n, const Vecteur& v);

// Produit scalaire de 2 vecteurs
// La fonction renvoie true en valeur de retour si l'opération a pu être faite et
// false sinon
bool produitScalaire(const Vecteur& v1, const Vecteur& v2, int& resultat);

// Pour la saisie interactive contrôlée d'une matrice
// L'utilisateur est invité à saisir le nombre de lignes et de colonnes voulues
// ainsi que les valeurs de diverses composantes de la matrice
void lire(Matrice& m);

// Affiche une matrice sous la forme:
// [[valeur11, valeur12,...];[valeur21, valeur22,...];...]
void afficher(const Matrice& m);

// Addition de 2 matrices
// La fonction renvoie true en valeur de retour si l'opération a pu être faite et
// false sinon
bool addition(const Matrice& m1, const Matrice& m2, Matrice& m);

// Produit de 2 matrices
// La fonction renvoie true en valeur de retour si l'opération a pu être faite et
// false sinon
bool produit(const Matrice& m1, const Matrice& m2, Matrice& m);

// Transposée d'une matrice
Matrice transposee(const Matrice& m);

#endif