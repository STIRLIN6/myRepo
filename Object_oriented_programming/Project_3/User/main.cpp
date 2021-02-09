#include "Bolygo.hpp"
#include "Noveny.hpp"
#include <iostream>
#include <fstream>
#include <vector>

bool szimulacio (Bolygo &bo, int db, int napok, std::vector<Noveny *> &novenyek, std::string& legerosebb)
{
    for (int i = 0; i < napok; i++)
    {
        std::cout << std::endl << i+1 << ". lepes" << std::endl;

        int alfa = bo.alfaigeny;
        int delta = bo.deltaigeny;
        //std::cout << "alfa:  " << alfa  << std::endl;
        //std::cout << "delta: " << delta << std::endl;

        bool alfaS = false;
        bool deltaS = false;

        if (alfa >= delta+3) {
                // Alfa sugarzas
                std::cout << "Alfa sugarzas" << std::endl;
                alfaS = true;
                delta = false;
            }
            else if (alfa+3 <= delta) {
                // Delta sugarzas
                std::cout << "Delta sugarzas" << std::endl;
                alfaS = false;
                deltaS = true;
            }
            else {
                // nincs sugarzas
                std::cout << "Nincs sugarzas" << std::endl;
                alfaS = false;
                deltaS = false;
            }

        for (int j = 0; j < db; j++) {

            if (alfaS) {
                // Alfa sugarzas
                if (novenyek[j]->alive()) { novenyek[j]->alfa(bo); }
            }
            else if (deltaS) {
                // Delta sugarzas
                if (novenyek[j]->alive()) { novenyek[j]->delta(bo); }
            }
            else {
                // nincs sugarzas
                if (novenyek[j]->alive()) { novenyek[j]->nincs(bo); }
            }
            std::cout << novenyek[j]->getName() << " " << novenyek[j]->getQuantity() << std::endl;
        }
    }

    //MAXKIV
    bool van = false;
    int ero = 0;
    for (int i = 0; i < db; i++) {
        if (novenyek[i]->alive() && ero < novenyek[i]->getQuantity()) {
            van = true;
            ero = novenyek[i]->getQuantity();
            legerosebb = novenyek[i]->getName();
        }
    }

    return van;
}

void beolvas (Bolygo& bo, int& db, int& napok, std::vector<Noveny*> &novenyek, std::string fileName) {
    std::ifstream f(fileName);
    if (f.fail()) {
        std::cout << "Wrong file name" << std::endl;
        exit(1);
    }
    
    std::cout << std::endl << "Fajl tartalma:" << std::endl;

    f >> db;
    std::cout << db << std::endl;
    novenyek.resize(db);

    for (int i = 0; i < db; i++) {
        char c;
        std::string name;
        int quantity;
        f >> name >> c >> quantity;
        std::cout << name << " " << c << " " << quantity << std::endl;
        if (quantity > 0) {
            switch (c) {
                case 'p' :
                    novenyek[i] = new Puffancs(name, quantity);
                    break;
                case 'd' :
                    novenyek[i] = new Deltafa(name, quantity);
                    break;
                case 'b' :
                    novenyek[i] = new Parabokor(name, quantity);
                    break;
            }
        }
    }

    /*for (int i = 0; i < db; i++) {
        std::cout << novenyek[i]->getName() << " " << novenyek[i]->getQuantity() << std::endl;
    }*/
    
    f >> napok;
    std::cout << napok << std::endl;
}

int main () {
    std::string in;

    do {
        Bolygo bo;
        int db;
        int napok;
        std::vector<Noveny*> novenyek;
        std::string legerosebb;    
        std::string fileName;

        std::cout << "Adjon meg egy input fajlt: ";
        std::cin >> fileName;

        beolvas(bo, db, napok, novenyek, fileName);

        if (szimulacio(bo, db, napok, novenyek, legerosebb)) {
            std::cout << "A legerosebb: " << legerosebb << std::endl;
        }
        else {
            std::cout << "Nincs legerosebb." << std::endl;
        }

        std::cout << "Szeretne egy kovetkezo fajlt megadni? ('i', ha igen, barmi mast, ha nem)" << std::endl;
        std::cin >> in;

        for (int i = 0; i < novenyek.size(); i++) {
            delete novenyek[i];
        }

    }
    while ("i" == in);
}