#include "HorgaszEnor.hpp"
#include "VersenyEnor.hpp"
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

bool Harcsa (std::string input, std::string& horgasz, std::string& verseny) {
    //LINEARIS KERESES TETEL
    bool van = false;
    HorgaszEnor enor(input);
    for (enor.First(); !van && !enor.End(); enor.Next()) {
        if (enor.Current().csakharcsa && enor.Current().legalabb3) {
            van = true;
            horgasz = enor.Current().horgasz;
            verseny = enor.Current().verseny;
        }
    }

    return van;
}

std::string Verseny (std::string input)
{
    //MAXKIV
    VersenyEnor enor(input);
    
    enor.first();
    std::string maxVerseny = enor.current().verseny;
    int maxResztvevo = enor.current().occurrence;
    enor.next();
    
    for (; !enor.end(); enor.next()) {
        if (enor.current().occurrence > maxResztvevo) {
            maxResztvevo = enor.current().occurrence;
            maxVerseny = enor.current().verseny;
        }
    }

    return maxVerseny;
}

TEST_CASE ("feladat1", "")
{
    std::string horgasz;
    std::string verseny;

    // input 1
    bool van = Harcsa("input.txt", horgasz, verseny);
    REQUIRE (true == van);
    if (van) {
        REQUIRE ("Janos" == horgasz);
        REQUIRE ("HorgaszRoyal" == verseny);
    }

    // input 2
    van = Harcsa("input2.txt", horgasz, verseny);
    REQUIRE (false == van);

    // input 3
    van = Harcsa("input3.txt", horgasz, verseny);
    REQUIRE (true == van);
    if (van) {
        REQUIRE ("Nandor" == horgasz);
        REQUIRE ("Kupa" == verseny);
    }

    // input 4
    van = Harcsa("input4.txt", horgasz, verseny);
    REQUIRE (true == van);
    if (van) {
        REQUIRE ("Frigyes" == horgasz);
        REQUIRE ("Verseny" == verseny);
    }

    // input 5
    van = Harcsa("input5.txt", horgasz, verseny);
    REQUIRE (false == van);
    
}

TEST_CASE ("feladat2", "")
{
    std::string verseny;

    // input 1
    verseny = Verseny ("input.txt");
    REQUIRE("HorgaszTorna" == verseny);

    // input 2
    verseny = Verseny ("input2.txt");
    REQUIRE("Verseny" == verseny);

    // input 3
    verseny = Verseny ("input3.txt");
    REQUIRE("Vetelkedo" == verseny);

    // input 4
    verseny = Verseny ("input4.txt");
    REQUIRE ("Verseny" == verseny);

    // input 5
    verseny = Verseny ("input5.txt");
    REQUIRE ("BalatonszemesOpen" == verseny);

}