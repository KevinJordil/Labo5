/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : outils.cpp
 Auteur(s)   : Kevin Jordil & Filipe Dias Morais
 Date        : 21.01.2020

 But         : Mets a disposition les outils suivants :
               Vecteurs :
                  - Affichage d'un vecteur
                  - Saisie d'un vecteur par l'utilisateur
                  - Addition de deux vecteurs
                  - Multiplication d'un vecteur par un scalaire
                  - Produit scalaire de deux vecteurs
               Matrices :
                  - Affichage d'une matrice
                  - Saisie d'une matrice par l'utilisateur
                  - Addition de deux matrices
                  - Multiplication de deux matrices
                  - Transposée d'une matrice

 Remarque(s) : Une matrice vide est considérée comme une matrice invalide. On ne
               peut donc pas faire d'opération avec.
               L'affichage des matrices fonctionne uniquement avec des matrices
               valides.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>

using namespace std;

using Vecteur = std::vector<int>;
using Matrice = std::vector<Vecteur>;

static bool matriceValide(const Matrice &m);
static void saisieUtilisateurEntier(int &entreeUtilisateur, bool positif = false);
static int  additionEntiers(int a, int b);
static int  multiplicationEntiers(int a, int b);


void lire(Vecteur &v) {
   int nombreComposantes;

   cout << "Saisir le nombre de composantes du vecteur : ";
   // Demande à l'utilisateur de saisir le nombre de composantes
   saisieUtilisateurEntier(nombreComposantes, true);

   v.resize(nombreComposantes);

   int entierUtilisateur;

   for (unsigned i = 0; i < nombreComposantes; i++) {
      cout << "Saisir le composant numero " << i + 1 << " : ";

      // Demande à l'utilisateur de saisir une composante et la stocke dans le
      // vecteur
      saisieUtilisateurEntier(entierUtilisateur);
      v.at(i) = entierUtilisateur;
   }
}

void afficher(const Vecteur &v) {
   cout << "[";
   // Comparaison des adresses des variables
   // Permet de trouver la dernière itération de la boucle
   for (auto &val : v) {
      cout << val;
      if (&val != &v.back()) {
         cout << ", ";
      }
   }
   cout << "]" << endl;
}

bool addition(const Vecteur &v1, const Vecteur &v2, Vecteur &v) {
   // Controle si l'addition est possible
   if (v1.size() != v2.size() || v1.empty())
       return false;

   v.resize(v1.size());
   transform(v1.begin(), v1.end(), v2.begin(), v.begin(), additionEntiers);

   // Reduit la capacité à la taille actuelle
   v.shrink_to_fit();
   return true;
}

Vecteur multiplicationParScalaire(int n, const Vecteur &v) {
   Vecteur resultat(v.size());
   // Vecteur du scalaire
   Vecteur s (v.size(), n);
   transform(v.begin(), v.end(), s.begin(), resultat.begin(), multiplicationEntiers);
   return resultat;
}

bool produitScalaire(const Vecteur &v1, const Vecteur &v2, int &resultat) {
   if (v1.size() != v2.size() || v1.empty())
      return false;

   resultat = inner_product(v1.begin(), v1.end(), v2.begin(), 0);
   return true;
}

void lire(Matrice &m) {
   cout << "Saisir le nombre de lignes : ";
   int lignesMatrice;
   saisieUtilisateurEntier(lignesMatrice, true);

   cout << "Saisir le nombre de colonnes : ";
   int colonnesMatrice;
   saisieUtilisateurEntier(colonnesMatrice, true);

   m.resize(lignesMatrice);

   int entierUtilisateur;

   for (unsigned i = 0; i < lignesMatrice; i++) {
      m.at(i).resize(colonnesMatrice);
      for (unsigned j = 0; j < colonnesMatrice; j++) {
         cout << "Saisir le composant de la ligne " << i + 1 << " colonne " << j
              << " : ";

         saisieUtilisateurEntier(entierUtilisateur);
         m.at(i).at(j) = entierUtilisateur;
      }
   }
}

void afficher(const Matrice &m) {
   if (not matriceValide(m)) {
      cout << "L'element n'est pas une matrice" << endl;
      return;
   }

   cout << "[";
   for (auto &ligne : m) {
      cout << "[";
      for (auto &colonne : ligne) {
         cout << colonne;
         if (&colonne != &ligne.back())
            cout << ", ";
      }
      cout << "]";
      if (&ligne != &m.back())
         cout << ";";
   }
   cout << "]" << endl;
}

bool addition(const Matrice &m1, const Matrice &m2, Matrice &m) {
   // Controle si les matrices sont valides et si elles ont la même taille
   if (m1.size() != m2.size() || not matriceValide(m1) ||
       not matriceValide(m2) ||  m1.front().size() != m2.front().size())
      return false;

   // Redimension des lignes
   m.resize(m1.size());

   for (size_t i = 0; i < m1.size(); i++) {
      // Utilisation de l'addition de vecteur
      addition(m1[i], m2[i], m[i]);
   }

   // Reduit la capacité à la taille actuelle
   m.shrink_to_fit();
   return true;
}

bool produit(const Matrice &m1, const Matrice &m2, Matrice &m) {
   // Contrôle si les matrices sont valides et possèdent les tailles adéquatent
   // pour réaliser une multiplication
   if (not matriceValide(m1) || not matriceValide(m2) ||
   m1.front().size() != m2.size())
      return false;

   // Redimension des lignes
   m.resize(m1.size());

   for (size_t i = 0; i < m1.size(); ++i) {
      // Redimension des colonnes de la ligne courante
      m[i].resize(m2.front().size());
      for (size_t j = 0; j < m2.front().size(); ++j) {
         // Définit l'élément a zéro pour le calcul
         m[i][j] = 0;
         for (size_t k = 0; k < m1.front().size(); ++k) {
            m[i][j] += m1[i][k] * m2[k][j];
         }
      }
   }

   // Reduit la capacité à la taille actuelle
   m.shrink_to_fit();
   return true;
}

Matrice transposee(const Matrice &m) {
   // Contrôle si la matrice est valide
   if (not matriceValide(m))
      return m;

   vector<vector<int>> mTranspose(m.front().size(), vector<int>(m.size()));

   // Passe les valeurs dans la matrice transposée
   for (size_t i = 0; i < m.size(); ++i)
      for (size_t j = 0; j < m.front().size(); ++j)
         mTranspose[j][i] = m[i][j];

   // Reduit la capacité à la taille actuelle
   mTranspose.shrink_to_fit();
   return mTranspose;
}

// Controle que la matrice possède à chaque ligne le même nombre de colonnes
bool matriceValide(const Matrice &m) {
   if (m.empty())
      return false;

   // On controle que la ligne a le meme nombre de colonne que la ligne precedente
   for (size_t i = 1; i < m.size(); i++) {
      if (m[i].size() != m[i - 1].size())
         return false;
   }
   return true;
}

void saisieUtilisateurEntier(int &entreeUtilisateur, bool positif) {
   do {
      if (cin >> entreeUtilisateur && (positif ? entreeUtilisateur > 0 : true)) {
         cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vide le buffer
         break;
      } else {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "La valeur n'est pas un entier"
              << (positif ? " positif" : "")
              << ", essayez de nouveau : ";
      }
   } while (true);
}

int additionEntiers (int a, int b){
   return a + b;
}

int multiplicationEntiers (int a, int b){
   return a * b;
}