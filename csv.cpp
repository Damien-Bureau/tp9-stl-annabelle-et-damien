#include <iostream>
#include <fstream>
#include <sstream>

#include "csv.h"

/* Getters */
string CSV::getNomFichier() {
    return this->nomFichier;
}

/* Setters */
void CSV::setNomFichier(string nomFichier) {
    if (nomFichier.empty()) {
        cout << "Erreur : nom de fichier vide" << endl;
    } else { this->nomFichier = nomFichier; }
}

/* Methods */
void CSV::lireFichier() {
    ifstream fichier(this->nomFichier);
    if (!fichier.is_open()) {
        cout << "Erreur : impossible d'ouvrir le fichier " << this->nomFichier << endl;
        return;
    }

    string ligne;
    while (getline(fichier, ligne)) {
        stringstream ss(ligne);
        string date_str, event;
        if (getline(ss, date_str, ',') && getline(ss, event)) {
            int date = stoi(date_str);
            this->events_par_annee[date].push_back(event);
        }
    }
}

void CSV::ecrireFichier() {
    if (this->events_par_annee.empty()) {
        cout << "Liste d'évènement vide !" << endl;
    }

    ofstream fichier(this->nomFichier);
    if (!fichier.is_open()) {
        cout << "Erreur : impossible d'ouvrir le fichier " << this->nomFichier << endl;
        return;
    }

    for (auto &&annee : this->events_par_annee) {
        for (auto &&event : annee.second) {
            fichier << annee.first << "," << event << endl;
        }
    }

    fichier.close();

    cout << "Fichier " << this->nomFichier << " modifié correctement !" << endl;
}

void CSV::ajouterEvenement(int date, string name) {
    this->events_par_annee[date].push_back(name);
}

void CSV::afficher() {
    cout << endl;
    if (this->events_par_annee.empty()) {
        cout << "La map d'évènements est vide !" << endl;
    } else {
        for (auto &&annee : this->events_par_annee) {
            for (auto &&event : annee.second) {
                cout << annee.first << " : " << event << endl;
            }
        }
    }
}