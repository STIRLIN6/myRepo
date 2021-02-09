#include "Vad.hpp"
#include "Vadasz.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

int main() {

    Vadasz vadasz("Bela", 42);
    
    std::fstream f("input.txt");

    std::string line;

    std::string fajta;
    std::string hely;
    std::string datum;
    int suly;

    std::string nem;
    int orrszarv;
    int agyar1, agyar2;


    while (getline(f, line)) {
        //std::cout << line << std::endl;
        std::stringstream ss(line);

        ss >> fajta;
        if ("oroszlan" == fajta) {
            ss >> hely;
            ss >> datum;
            ss >> suly;
            ss >> nem;
            //std::cout << fajta << " " << hely << " " << datum << " " << suly << " " << nem << std::endl;
            Oroszlan* o = new Oroszlan(fajta, hely, datum, suly, nem);
            vadasz.adder(o);
            

        }
        else if ("elefant" == fajta) {
            ss >> hely;
            ss >> datum;
            ss >> suly;
            ss >> agyar1;
            ss >> agyar2;
            //std::cout << fajta << " " << hely << " " << datum << " " << suly << " " << agyar1 << " " << agyar2 << std::endl;
            vadasz.adder(new Elefant(fajta, hely, datum, suly, agyar1, agyar2));
        }
        else if ("orrszarvu" == fajta) {
            ss >> hely;
            ss >> datum;
            ss >> suly;
            ss >> orrszarv;
            //std::cout << fajta << " " << hely << " " << datum << " " << suly << " " << orrszarv << std::endl;
            vadasz.adder(new Orrszarvu(fajta, hely, datum, suly, orrszarv));
        }
    }
    vadasz.counter();
    std::cout << vadasz.himOroszlanok << std::endl;
}