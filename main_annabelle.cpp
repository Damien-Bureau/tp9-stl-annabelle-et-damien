#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    // Création d'un vecteur d'entiers sans spécifier la taille initiale
    std::vector<int> monVecteur;

    // Dimensionner le vecteur à une taille de 3
    monVecteur.resize(3);

    // Affectation des valeurs dans le vecteur
    monVecteur[0] = 10;
    monVecteur[1] = 20;
    monVecteur[2] = 30;

    // Affichage des valeurs du vecteur
    std::cout << "Les valeurs du vecteur sont : ";
    for (int i = 0; i < monVecteur.size(); ++i) {
        std::cout << monVecteur[i] << " ";
    }
    std::cout << std::endl;

    // Affichage en utilisant des indices
    std::cout << "Affichage avec des indices : ";
    for (size_t i = 0; i < monVecteur.size(); ++i) {
        std::cout << monVecteur[i] << " ";
    }
    std::cout << std::endl;

    // Affichage en utilisant un itérateur
    std::cout << "Affichage avec un itérateur : ";
    for (auto it = monVecteur.begin(); it != monVecteur.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

     // Affichage en utilisant C++11
     std::cout << "Affichage avec un itérateur et boucle classique : ";
     for (std::vector<int>::iterator it = monVecteur.begin(); it != monVecteur.end(); ++it) {
         std::cout << *it << " ";
     }
     std::cout << std::endl;





    // Déclaration vecteur de string
    vector<string> mots;

    mots.push_back("Bonjour");
    mots.push_back("comment");
    mots.push_back("allez");
    mots.push_back("vous");
    mots.push_back("?");

    // Affichage
    cout << "La taille du vecteur est : " << mots.size() << std::endl;

    return 0;
}