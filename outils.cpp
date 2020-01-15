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
#include <limits>

using namespace std;

using Vecteur = std::vector<int>;
using Matrice = std::vector<Vecteur>;

void verificationEntier(int &entreeUtilisateur);
void verificationEntierPositif(int &entreeUtilisateur);

void lire(Vecteur &v)
{
   //Ne pas ecrire "Saisir vecteur:"
   //Saisir la taille du vecteur
   //Saisir chaque composante

   int nombreComposantes;

   cout << "Saisir le nombre de composantes du vecteur : ";
   cin >> nombreComposantes;

   verificationEntierPositif(nombreComposantes);

   v.resize(nombreComposantes);

   int entierUtilisateur;

   for (unsigned i = 0; i < nombreComposantes; i++)
   {
      cout << "Saisir le composant numero " << i << " : ";

      cin >> entierUtilisateur;

      verificationEntier(entierUtilisateur);
      v.at(i) = entierUtilisateur;
   }
}

void afficher(const Vecteur &v)
{
   //Afficher sans texte
   cout << "[";
   for (auto &val : v)
   {
      cout << val;
      if (&val != &v.back())
      {
         cout << ", ";
      }
   }
   cout << "]" << endl;
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
   cout << "Saisir le nombre de lignes : ";
   int lignesMatrice;
   cin >> lignesMatrice;
   verificationEntierPositif(lignesMatrice);

   cout << "Saisir le nombre de colonnes : ";
   int colonnesMatrice;
   cin >> colonnesMatrice;
   verificationEntierPositif(colonnesMatrice);

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
         cout << "Saisir le composant de la ligne " << i << " colonne " << j << " : ";

         cin >> entierUtilisateur;

         verificationEntier(entierUtilisateur);
         m.at(i).at(j) = entierUtilisateur;
      }
   }
}

void afficher(const Matrice &m)
{
   //Afficher sans texte
   cout << "[";
   for (auto &ligne : m)
   {
      cout << "[";
      for (auto &colonne : ligne)
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

bool addition(const Matrice &m1, const Matrice &m2, Matrice &m)
{
   m = m1;
   return true;
}

bool produit(const Matrice &m1, const Matrice &m2, Matrice &m)
{
}

Matrice transposee(const Matrice &m)
{
}

void verificationEntier(int &entreeUtilisateur)
{
   while (cin.fail())
   {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      cout << "La valeur n'est pas un entier, essayez de nouveau : ";
      cin >> entreeUtilisateur;
   }
}

void verificationEntierPositif(int &entreeUtilisateur)
{
   while (cin.fail() || entreeUtilisateur < 1)
   {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      cout << "La valeur n'est pas un entier positif, essayez de nouveau : ";
      cin >> entreeUtilisateur;
   }
}