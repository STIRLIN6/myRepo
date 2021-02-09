#pragma once

#include <string>

class Vad
{
protected:
    std::string _fajta;
    std::string _hely;
    std::string _datum;
    int _suly;
    
public:
    Vad(std::string fajta, std::string hely, std::string datum, int suly) : _fajta(fajta), _hely(hely), _datum(datum), _suly(suly) {}
    
    virtual ~Vad() = default;

    std::string getFajta() { return _fajta; };
    virtual std::string getNem () { return "ssss"; };
};

class Elefant : public Vad
{
private:
    int _agyar1;
    int _agyar2;
public:
    Elefant(std::string fajta, std::string hely, std::string datum, int suly, int agyar1, int agyar2);
    //std::string getNem() override;
};

class Orrszarvu : public Vad
{
private:
    int _orrszarv;
public:
    Orrszarvu(std::string fajta, std::string hely, std::string datum, int suly, int orrszarv);
    //std::string getNem() override;
};

class Oroszlan : public Vad
{
private:
    std::string _nem;

public:
    Oroszlan(std::string fajta, std::string hely, std::string datum, int suly, std::string nem);
    std::string getNem() override;
};