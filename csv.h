#ifndef CSV_H
#define CSV_H

#include <map>
#include <list>
#include <string>

using namespace std;

class CSV {
    private:
        string nomFichier;
        map<int,list<string>> events_par_annee;
    
    public:
        /* Constructors */
        CSV(string nomFichier) : nomFichier(nomFichier) {};

        /* Getters */
        string getNomFichier();

        /* Setters */
        void setNomFichier(string nomFichier);
        
        /* Methods */
        void lireFichier();
        void ecrireFichier();
        void afficher();
        void ajouterEvenement(int date, string name);
};

#endif /* CSV_H */