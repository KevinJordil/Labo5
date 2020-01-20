/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : interfaceUtilisateur.cpp
 Auteur(s)   : Kevin Jordil & Filipe Dias Morais
 Date        : 21.01.2020

 But         : Permet d'afficher un menu sur la console. L'utilisateur peut donc
               executer les différentes fonctions de la librairie outils.h.
               Si un l'opération demandée est possible sur les éléments saisis
               alors le programme affiche le résultat pour l'utilisateur.

 Remarque(s) : Le menu se relance après chaque opération, pour quitter il faut
               saisir le numero 0 dans le menu (comme indiqué)

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include "outils.h"

using Vecteur = std::vector<int>;
using Matrice = std::vector<Vecteur>;
using Texte = std::string;

using namespace std;

// Affiche le menu, renvoie le choix
unsigned affichageChoixOperation(){
   cout << "----------------------MENU----------------------" << endl;
   cout << "0. Quitter" << endl;
   cout << "VECTEURS :" << endl;
   cout << "1. Addition de deux vecteurs" << endl;
   cout << "2. Multiplication d'un vecteur par un scalaire" << endl;
   cout << "3. Produit scalaire de deux vecteurs" << endl;
   cout << "MATRICES :" << endl;
   cout << "4. Addition de deux matrices" << endl;
   cout << "5. Multiplication de deux matrices" << endl;
   cout << "6. Transposee d'une matrices" << endl;
   cout << "------------------------------------------------" << endl;


   unsigned choixUtilisateur;

   do {
      cout << "Entrer le numero de votre choix (de 0 a 6) : ";
      if (cin >> choixUtilisateur && choixUtilisateur <= 6) {
         cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vide le buffer
         break;
      } else {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Saisie erronnee !" << endl;
      }
   } while (true);


   return choixUtilisateur;
}

// Demande la saisie d'un vecteur
void demandeSaisieVecteur(const Texte &nomVecteur, Vecteur &v){
   cout << "Saisie du " << nomVecteur << endl;
   lire(v);
}

// Demande la saisie d'une matrice
void demandeSaisieMatrice(const Texte &nomMatrice, Matrice &m){
   cout << "Saisie de la " << nomMatrice << endl;
   lire(m);
}

// Affiche l'interface utilisateur
void InterfaceUtilisateur(){
   vector<int> v1, v2, vResultat;
   vector<vector<int>> m1, m2, mResultat;

   unsigned numeroOperation;
   bool quitter = false;

   while (not quitter) {

      numeroOperation = affichageChoixOperation();
      switch (numeroOperation) {
         case 0: // Quitter l'application
            quitter = true;
            break;

         case 1: //Addition deux vecteurs
            demandeSaisieVecteur("vecteur 1", v1);
            demandeSaisieVecteur("vecteur 2", v2);
            if (addition(v1, v2, vResultat))
               afficher(vResultat);
            else
               cout << "L'addition des vecteurs n'a pas pu etre effectuee" << endl;
            break;

         case 2: // Multiplication d'un vecteur pas un scalaire
            int scalaire;
            demandeSaisieVecteur("vecteur", v1);
            cout << "Saisir le scalaire : ";
            cin >> scalaire;
            vResultat = multiplicationParScalaire(scalaire, v1);
            afficher(vResultat);
            break;

         case 3: // Produit scalaire de deux vecteurs
            int resultat;
            demandeSaisieVecteur("vecteur 1", v1);
            demandeSaisieVecteur("vecteur 2", v2);
            if (produitScalaire(v1, v2, resultat))
               cout << "Le resultat est : " << resultat << endl;
            else
               cout << "Le produit scalaire n'a pas pu etre realise" << endl;
            break;

         case 4: // Addition de deux matrices
            demandeSaisieMatrice("matrice 1", m1);
            demandeSaisieMatrice("matrice 2", m2);
            if (addition(m1, m2, mResultat))
               afficher(mResultat);
            else
               cout << "L'addition des matrices n'a pas pu etre effectuee" << endl;
            break;

         case 5: // Produit de deux matrices
            demandeSaisieMatrice("matrice 1", m1);
            demandeSaisieMatrice("matrice 2", m2);
            if (produit(m1, m2, mResultat))
               afficher(mResultat);
            else
               cout << "Le produit des matrices n'a pas pu etre effectue" << endl;
            break;

         case 6: // Transposée d'une matrice
            demandeSaisieMatrice("matrice", m1);
            mResultat = transposee(m1);
            afficher(mResultat);
            break;

         default:
            break;
      }
   }
}

