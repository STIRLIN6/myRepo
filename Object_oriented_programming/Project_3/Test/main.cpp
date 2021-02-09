#include "Bolygo.hpp"
#include "Noveny.hpp"
#include <iostream>
#include <fstream>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

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

TEST_CASE ("halal", "")
{
    Bolygo bo;
    int db;
    int napok;
    std::vector<Noveny*> novenyek;
    std::string legerosebb;    
    std::string fileName;

    // 1
    fileName = "input1.txt";
    beolvas(bo, db, napok, novenyek, fileName);
    REQUIRE (!szimulacio(bo, db, napok, novenyek, legerosebb));

    // 2
    fileName = "input2.txt";
    bo.alfaigeny = 0;
    bo.deltaigeny = 0;
    REQUIRE (!szimulacio(bo, db, napok, novenyek, legerosebb));

    // 3
    fileName = "input3.txt";
    bo.alfaigeny = 0;
    bo.deltaigeny = 0;
    REQUIRE (!szimulacio(bo, db, napok, novenyek, legerosebb));

    // 4
    fileName = "input4.txt";
    bo.alfaigeny = 0;
    bo.deltaigeny = 0;
    beolvas(bo, db, napok, novenyek, fileName);
    REQUIRE (!szimulacio(bo, db, napok, novenyek, legerosebb));
}

TEST_CASE ("legerosebb", "")
{
    Bolygo bo;
    int db;
    int napok;
    std::vector<Noveny*> novenyek;
    std::string legerosebb;
    std::string fileName;

    // 5
    fileName = "input5.txt";
    beolvas(bo, db, napok, novenyek, fileName);
    if (szimulacio(bo, db, napok, novenyek, legerosebb)) {
        REQUIRE ("Pufi" ==  legerosebb);
    }
    else {
        REQUIRE (false);
    }

    // 6
    fileName = "input6.txt";
    bo.alfaigeny = 0;
    bo.deltaigeny = 0;
    beolvas(bo, db, napok, novenyek, fileName);
    if (szimulacio(bo, db, napok, novenyek, legerosebb)) {
        REQUIRE ("Dalma" ==  legerosebb);
    }
    else {
        REQUIRE (false);
    }

    // 7
    fileName = "input7.txt";
    bo.alfaigeny = 0;
    bo.deltaigeny = 0;
    beolvas(bo, db, napok, novenyek, fileName);
    if (szimulacio(bo, db, napok, novenyek, legerosebb)) {
        REQUIRE ("Boka" ==  legerosebb);
    }
    else {
        REQUIRE (false);
    }

}

TEST_CASE ("komplex", "")
{
    Bolygo bo;
    int db;
    int napok;
    std::vector<Noveny*> novenyek;
    std::string legerosebb;
    std::string fileName;

    // 8
    fileName = "input8.txt";
    beolvas(bo, db, napok, novenyek, fileName);
    if (szimulacio(bo, db, napok, novenyek, legerosebb)) {
        REQUIRE ("Bok" ==  legerosebb);
    }
    else {
        REQUIRE (false);
    }

    // 9
    fileName = "input9.txt";
    bo.alfaigeny = 0;
    bo.deltaigeny = 0;
    beolvas(bo, db, napok, novenyek, fileName);
    if (szimulacio(bo, db, napok, novenyek, legerosebb)) {
        REQUIRE ("Puf" ==  legerosebb);
    }
    else {
        REQUIRE (false);
    }

    // 10
    fileName = "input10.txt";
    bo.alfaigeny = 0;
    bo.deltaigeny = 0;
    beolvas(bo, db, napok, novenyek, fileName);
    if (szimulacio(bo, db, napok, novenyek, legerosebb)) {
        REQUIRE ("Del" ==  legerosebb);
    }
    else {
        REQUIRE (false);
    }

    // 11
    fileName = "input11.txt";
    bo.alfaigeny = 0;
    bo.deltaigeny = 0;
    beolvas(bo, db, napok, novenyek, fileName);
    if (szimulacio(bo, db, napok, novenyek, legerosebb)) {
        REQUIRE ("Puf" ==  legerosebb);
    }
    else {
        REQUIRE (false);
    }

    // 12
    fileName = "input12.txt";
    bo.alfaigeny = 0;
    bo.deltaigeny = 0;
    beolvas(bo, db, napok, novenyek, fileName);
    if (szimulacio(bo, db, napok, novenyek, legerosebb)) {
        REQUIRE ("Del" ==  legerosebb);
    }
    else {
        REQUIRE (false);
    }

    // 13
    fileName = "input13.txt";
    bo.alfaigeny = 0;
    bo.deltaigeny = 0;
    beolvas(bo, db, napok, novenyek, fileName);
    if (szimulacio(bo, db, napok, novenyek, legerosebb)) {
        REQUIRE ("Puf" ==  legerosebb);
    }
    else {
        REQUIRE (false);
    }

    // 14
    fileName = "input14.txt";
    bo.alfaigeny = 0;
    bo.deltaigeny = 0;
    beolvas(bo, db, napok, novenyek, fileName);
    if (szimulacio(bo, db, napok, novenyek, legerosebb)) {
        REQUIRE ("Puf" ==  legerosebb);
    }
    else {
        REQUIRE (false);
    }
}