#include "Vad.hpp"

Elefant::Elefant(std::string fajta, std::string hely, std::string datum, int suly, int agyar1, int agyar2) : Vad (fajta, hely, datum, suly) {
    _agyar1 = agyar1;
    _agyar2 = agyar2;
}

Orrszarvu::Orrszarvu(std::string fajta, std::string hely, std::string datum, int suly, int orrszarv) : Vad (fajta, hely, datum, suly) {
    _orrszarv = orrszarv;
}

Oroszlan::Oroszlan(std::string fajta, std::string hely, std::string datum, int suly, std::string nem) : Vad (fajta, hely, datum, suly) {
    this->_nem = nem;
}

std::string Oroszlan::getNem () {
    return _nem;
}

/*std::string Elefant::getNem () {
    return "elefantvagyok";
}

std::string Orrszarvu::getNem () {
    return "nemelefantvagyok";
}*/