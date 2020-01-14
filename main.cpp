/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05
 Fichier     : main.cpp
 Auteur(s)   : Kevin Jordil & Filipe Dias Morais
 Date        : 21.01.2020

 But         :

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "outils.h"

using namespace std;

unsigned affichageChoixOperation();
void demandeSaisieVecteur(const string& nomVecteur, vector<int>& v);
void demandeSaisieMatrice(const string& nomMatrice, vector<vector<int>>& m);

int main()
{
   vector<int> v1, v2, vResultat;
   vector<vector<int>> m1, m2, mResultat;

   unsigned numeroOperation;
   bool quitter = false;

   while(not quitter){

      numeroOperation = affichageChoixOperation();
      switch (numeroOperation){
         case 0:
            quitter = true;
            break;

         case 1:
            demandeSaisieVecteur("vecteur 1", v1);
            demandeSaisieVecteur("vecteur 2", v2);
            if (addition(v1, v2, vResultat))
               afficher(vResultat);
            else
               cout << "L'addition des vecteurs n'a pas pu etre effectuee" << endl;
            break;

         case 2:
            int scalaire;
            demandeSaisieVecteur("vecteur", v1);
            cout << "Saisir le scalaire : ";
            cin >> scalaire;
            vResultat = multiplicationParScalaire(scalaire, v1);
            afficher(vResultat);
            break;

         case 3:
            int resultat;
            demandeSaisieVecteur("vecteur 1", v1);
            demandeSaisieVecteur("vecteur 2", v2);
            if (produitScalaire(v1, v2, resultat))
               cout << "Le resultat est : " << resultat;
            else
               cout << "Le produit scalaire n'a pas pu etre realise" << endl;
            break;

         case 4:
            demandeSaisieMatrice("matrice 1", m1);
            demandeSaisieMatrice("matrice 2", m2);
            if (addition(m1, m2, mResultat))
               afficher(mResultat);
            else
               cout << "L'addition des matrices n'a pas pu etre effectuee" << endl;
            break;

         case 5:
            demandeSaisieMatrice("matrice 1", m1);
            demandeSaisieMatrice("matrice 2", m2);
            if(produit(m1, m2, mResultat))
               afficher(mResultat);
            else
               cout << "Le produit des matrices n'a pas pu etre effectue" << endl;
            break;

         case 6:
            demandeSaisieMatrice("matrice", m1);
            mResultat = transposee(m1);
            afficher(mResultat);
            break;

         default:
            break;
      }
   }


   system("PAUSE");
   return EXIT_SUCCESS;
}

unsigned affichageChoixOperation(){
   system("cls");
   cout << "----------------------MENU----------------------" << endl;
   cout << "0. Quitter" << endl;
   cout << "VECTEURS :" << endl;
   cout << "1. Addition de deux vecteurs" << endl;
   cout << "2. Multiplication d'un vecteur par un scalaire" << endl;
   cout << "3. Produit scalaire de deux vecteurs" << endl;
   cout << "MATRICES :" << endl;
   cout << "4. Addition de deux matrices" << endl;
   cout << "5. Produit de deux matrices" << endl;
   cout << "6. Transposee d'une matrices" << endl;
   cout << "------------------------------------------------" << endl;

   cout << "Entrer le numero de votre choix : ";

   unsigned choixUtilisateur;
   cin >> choixUtilisateur;

   while(choixUtilisateur > 5){
      cout << "Saisie erronnee !" << endl;
      cout << "Entrer a nouveau le numero de votre choix : ";
      cin >> choixUtilisateur;
   }
   return choixUtilisateur;
}

void demandeSaisieVecteur(const string& nomVecteur, vector<int>& v) {
   cout << "Saisir le " << nomVecteur << " :" << endl;
   lire(v);
}

void demandeSaisieMatrice(const string& nomMatrice, vector<vector<int>>& m){
   cout << "Saisir le " << nomMatrice << " :" << endl;
   lire(m);
}