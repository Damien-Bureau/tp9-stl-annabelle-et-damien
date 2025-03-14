#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>
#include <map>

#include "csv.h"

using namespace std;

void afficherContenuVecteur(vector<string> const&);
string concatene(vector<string>&);
vector<string> ajouteVirgule(vector<string>&);
void ajouterEvenement(map<int,list<string>>& events_par_annee, int date, string name);
void affichageMapEventsParAnnee(map<int,list<string>> events_par_annee);

int main() {
    /*  PARTIE 1  */
    cout << endl << "---------- PARTIE 1 : VECTEUR D'ENTIERS ----------" << endl;

    vector<int> myVector;
    
    // Vecteur de taille 3
    myVector.resize(3);

    // Affichage du vecteur par indices
    cout << endl << "Affichage du vecteur par indices" << endl;
    for (int index = 0; index < myVector.size(); index++)
    {
        cout << "myVector[" << index << "] = " << myVector[index] << endl;
    }
    
    // Affichage par boucle sur une plage de nombres
    cout << endl << "Affichage par boucle sur une plage de nombres" << endl;
    for (auto &&element : myVector)
    {
        cout << element << endl;
    }
    
    // Affichage à l'aide d'un itérateur
    cout << endl << "Affichage à l'aide d'un itérateur" << endl;
    for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++) {
        cout << *it << endl;
    };
    
    // Ajout d'un élément en fin de vecteur et vérification de la taille
    cout << endl << "Taille du vecteur avant : " << myVector.size() << endl;
    myVector.push_back(5);
    cout << "Taille du vecteur après : " << myVector.size() << endl;
    
    // Copie d'un vecteur dans d'autres vecteurs
    cout << endl << "Copie d'un vecteur dans d'autres vecteurs" << endl;
    cout << "v2 using copy(), v3 using assign()" << endl;
    vector<int> v2;
    copy(myVector.begin(), myVector.end(), back_inserter(v2));
    vector<int> v3;
    v3.assign(v2.begin(), v2.end());
    cout << "v1 v2 v3" << endl;
    for (int i=0; i<myVector.size(); i++)
    {
        cout << myVector[i] << "  " << v2[i] << "  " << v3[i] << endl;
    }


    /*  PARTIE 2  */

    cout << endl << "---------- PARTIE 2 : VECTEUR DE STRING ----------" << endl;

    // Declaration vecteur de string
    vector<string> mots;

    mots.push_back("Bonjour");
    mots.push_back("comment");
    mots.push_back("allez");
    mots.push_back("vous");
    mots.push_back("?");

    // Affichages
    cout << endl << "La taille du vecteur est : " << mots.size() << endl;
    cout << "La capacité du vecteur est : " << mots.capacity() << endl; 
    // La taille c'est le nombre d'éléments actuellement dans le vecteur 
    // Alors que la capacité c'est le nombre d'éléments max que le vecteur peut avoir 

    // Affichage du vecteur par indices
    cout << endl << "Par indice: " << endl;
    for (size_t i = 0; i < mots.size(); i++) {
        cout << mots[i] << " ";
    }
    std::cout << std::endl;
    
    // Affichage par boucle sur une plage de nombres
    cout << endl << "Par plage de nombres: " << endl;
    for (auto &&mot : mots) {
        cout << mot << " ";
    }
    cout << endl;
     
    // Affichage à l'aide d'un itérateur
    cout << endl << "Par itérateur: " << endl;
    for (auto it = mots.begin(); it != mots.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Échange des éléments d'indice 1 et 3
    swap(mots[1], mots[3]);
    
    // Insertion de "a tous" après le premier élément
    cout << endl << "Insertion de \"a tous\" : " << endl;
    mots.insert(mots.begin() + 1, "a");
    mots.insert(mots.begin() + 2, "tous");
    for (auto &&mot : mots) {
        cout << mot << " ";
    }
    cout << endl;

    // Modification du point d'interrogation final
    mots.back() = "???";
    cout << endl << "Modification du point d'interrogation : " << endl;
    for (auto &&mot : mots) {
        cout << mot << " ";
    }
    cout << endl;

    // Affichage avec une virgule comme séparateur
    cout << endl << "Affichage avec une virgule comme séparateur : " << endl;
    for (auto &&mot : mots) {
        cout << mot << ", ";
    }
    cout << endl;

    // Tri du vecteur avec un algorithme de la STL
    vector<string> mots_sorted = mots;
    sort(mots_sorted.begin(), mots_sorted.end());
    cout << endl << "Affichage après tri alphabétique : " << endl;
    for (auto &&mot : mots_sorted) {
        cout << mot << ", ";
    }
    cout << endl;

    // Test de la fonction afficherContenuVecteur()
    cout << endl << "Test de la fonction afficherContenuVecteur() : " << endl;
    afficherContenuVecteur(mots);
    cout << endl;
    
    // Test de la fonction concatene()
    cout << endl << "Test de la fonction concatene() : " << endl;
    cout << concatene(mots) << endl;
    
    // Test de la fonction ajouteVirgule()
    cout << endl << "Test de la fonction ajouteVirgule() : " << endl;
    vector<string> mots_avec_virgules = ajouteVirgule(mots);
    for (auto &&mot : mots_avec_virgules) {
        cout << mot;
    }
    cout << endl;
    

    /*  PARTIE 3  */

    cout << endl << "---------- PARTIE 3 : LES LISTES ----------" << endl;
    
    // Création d'une liste de 8 entiers
    list<int> myList(8);
    int i = 1;
    for (auto it = myList.begin(); it != myList.end(); ++it, ++i)
    {
        *it = i;
    }    

    // Affichage de la liste
    cout << endl << "Affichage de la liste : ";
    for (auto &&element : myList) {
        cout << element;
    }

    // Suppression du troisième élément
    myList.erase(next(myList.begin(),2));

    // Affichage de la liste
    cout << endl << "Affichage de la liste : ";
    for (auto &&element : myList) {
        cout << element;
    }
    cout << endl;


    /*  PARTIE 4  */

    cout << endl << "---------- PARTIE 4 : LES MAPS ----------" << endl;

    // Création de la map
    map<int,list<string>> events_par_annee;

    // Remplissage de la map
    ajouterEvenement(events_par_annee, 2025, "Découverte de l'UML");
    ajouterEvenement(events_par_annee, 2024, "Rentrée à Centrale");
    ajouterEvenement(events_par_annee, 2024, "Apprentissage des classes en C++");
    
    // Affichage de la map
    affichageMapEventsParAnnee(events_par_annee);


    /*  PARTIE 5  */

    cout << endl << "---------- PARTIE 5 : LECTURE/ECRITURE CSV ----------" << endl;

    CSV myCSV = CSV("events.csv");
    
    myCSV.ajouterEvenement(2025, "Découverte de l'UML");
    myCSV.ajouterEvenement(2024, "Rentrée à Centrale");
    myCSV.ajouterEvenement(2024, "Apprentissage des classes en C++");
    
    myCSV.afficher();
    myCSV.ecrireFichier();
    myCSV.setNomFichier("dates.csv");
    myCSV.lireFichier();
    myCSV.afficher();



    cout << endl;
    return 0;
}


void afficherContenuVecteur(vector<string> const& mots) {
    for (auto &&mot : mots) {
        cout << mot << ", ";
    }
}

string concatene(vector<string> &mots) {
    string mot_concat;
    for (auto &&mot : mots) {
        mot_concat += mot + " ";
    }
    return mot_concat;
}

vector<string> ajouteVirgule(vector<string> &mots) {
    vector<string> mots_avec_virgules = mots;
    for_each(mots_avec_virgules.begin(), mots_avec_virgules.end(), [](string &mot) {
        mot += ",";
    });
    return mots_avec_virgules;
}

void ajouterEvenement(map<int,list<string>>& events_par_annee, int date, string name) {
    events_par_annee[date].push_back(name);
}

void affichageMapEventsParAnnee(map<int,list<string>> events_par_annee) {
    cout << endl;
    if (events_par_annee.empty()) {
        cout << "La map d'évènements est vide !" << endl;
    } else {
        for (auto &&annee : events_par_annee) {
            for (auto &&event : annee.second) {
                cout << annee.first << " : " << event << endl;
            }
        }
    }
}