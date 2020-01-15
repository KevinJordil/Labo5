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
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

using Vecteur = std::vector<int>;
using Matrice = std::vector<Vecteur>;

bool matriceValide(const Matrice &m, bool matriceCarre = false);

void lire(Vecteur &v) {
   //Ne pas ecrire "Saisir vecteur:"
   //Saisir la taille du vecteur
   //Saisir chaque composante

   unsigned nombreComposantes;

   cout << "Saisir le nombre de composantes du vecteur : ";
   cin >> nombreComposantes;

   while (cin.fail())
   {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      cout << "La valeur saisie n'est pas un entier, essayez de nouveau : ";
      cin >> nombreComposantes;
   }

   v.resize(nombreComposantes);

   int entierUtilisateur;

   for (unsigned i = 0; i < nombreComposantes; i++)
   {
      cout << "Saisir le composant numero " << i << " : ";

      cin >> entierUtilisateur;

      while (cin.fail())
      {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');

         cout << "La valeur saisie n'est pas un entier, essayez de nouveau : ";
         cin >> entierUtilisateur;
      }
      v.at(i) = entierUtilisateur;
   }
}

void afficher(const Vecteur &v) {
   //Afficher sans texte
   cout << "[";
   for (auto& val : v)
   {
      cout << val;
      if (&val != &v.back())
      {
         cout << ", ";
      }
   }
   cout << "]" << endl;
}

bool addition(const Vecteur &v1, const Vecteur &v2, Vecteur &v) {
}

Vecteur multiplicationParScalaire(int n, const Vecteur &v) {
}

bool produitScalaire(const Vecteur &v1, const Vecteur &v2, int &resultat) {
}

void lire(Matrice &m) {
   //Ne pas ecrire "Saisir matrice:"
   //Saisir la taille de la matrice
   //Saisir chaque composante
   cout << "Saisir le nombre de lignes : ";
   unsigned lignesMatrice;
   cin >> lignesMatrice;
   while (cin.fail())
   {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      cout << "La valeur saisie n'est pas un entier, essayez de nouveau : ";
      cin >> lignesMatrice;
   }

   cout << "Saisir le nombre de colonnes : ";
   unsigned colonnesMatrice;
   cin >> colonnesMatrice;
   while (cin.fail())
   {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      cout << "La valeur saisie n'est pas un entier, essayez de nouveau : ";
      cin >> colonnesMatrice;
   }

   m.resize(lignesMatrice);

   for (unsigned i = 0; i < lignesMatrice; i++)
   {
      m.at(i).resize(colonnesMatrice);
   }

   int entierUtilisateur;

   for (unsigned i = 0; i < lignesMatrice; i++)
   {
      for (unsigned j = 0; j < colonnesMatrice; j++)
      {
         cout << "Saisir le composant de la ligne " << i << " colonne" << j << " : ";

         cin >> entierUtilisateur;

         while (cin.fail())
         {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "La valeur saisie n'est pas un entier, essayez de nouveau : ";
            cin >> entierUtilisateur;
         }
         cout << m.at(0).size() << endl;
         m.at(i).at(j) = entierUtilisateur;
      }
   }
}

void afficher(const Matrice &m) {
   //Afficher sans texte
   cout << "[";
   for (auto& ligne : m)
   {
      cout << "[";
      for (auto& colonne : ligne)
      {
         cout << colonne;
         if (&colonne != &ligne.back())
         {
            cout << ", ";
         }
      }
      cout << "];";
   }
   cout << "]" << endl;
}

bool matriceValide(const Matrice &m, bool matriceCarre) {
   if (m.empty())
      return false;

   for (size_t i = 1; i < m.size(); i++) {
      if (m[i].size() != m[i - 1].size())
         return false;
   }
   return true;
}

bool addition(const Matrice &m1, const Matrice &m2, Matrice &m) {
   if (m1.size() != m2.size() || not matriceValide(m1, true) ||
       not matriceValide(m2, true) || m1[0].size() != m2[0].size())
      return false;

   m.resize(m1.size());

   for (size_t i = 0; i < m1.size(); i++) {
      m[i].resize(m1.size());
      for (size_t j = 0; j < m1[i].size(); j++) {
         m[i][j] = m1[i][j] + m2[i][j];
      }
   }

   return true;
}

bool produit(const Matrice &m1, const Matrice &m2, Matrice &m) {
   if (not matriceValide(m1) || not matriceValide(m2) ||
       m1[0].size() != m2.size())
      return false;

   // TODO Resize m
   for (size_t row = 0; row < m.size(); ++row) {
      for (size_t col = 0; col < m.at(0).size(); ++col) {
         for (size_t inner = 0; inner < m2.size(); ++inner) {
            m.at(row).at(col) += m1.at(row).at(inner) * m2.at(inner).at(col);
         }
      }
   }
   return true;
}

Matrice transposee(const Matrice &m) {
   if (not matriceValide(m))
      return m;

   std::vector<std::vector<int>> mTranspose(m.size(),std::vector<int>(m[0].size()));

   for (size_t i = 0; i < m.size(); i++)
      for (size_t j = 0; j < m[i].size(); j++)
         mTranspose[i][j] = m[j][i];

   return mTranspose;
}