#pragma once

#include "Bolygo.hpp"
#include <string>

class Noveny
{
protected:
    std::string _name;
    int _quantity;
    bool _alive;
    
public:
    Noveny (const std::string &name, int quantity) : _name(name), _quantity(quantity) {} //+Noveny (name:string, quantity:int)

    std::string getName () { return _name; }
    int getQuantity () { return _quantity; }

    //std::string name() const { return _name; }
    //int quantity() const { return _quantity; }
    virtual bool alive() { return (_alive =_quantity > 0); }
    
    virtual void alfa (Bolygo &b) = 0; // +alfa(b:Bolygo): void {virtual}
    virtual void delta (Bolygo &b) = 0;
    virtual void nincs (Bolygo &b) = 0;
};

class Puffancs : public Noveny
{
public:
    Puffancs(const std::string &name, int quantity);

    void alfa(Bolygo &b) override;
    void delta(Bolygo &b) override;
    void nincs(Bolygo &b) override;

    bool alive() override;
};

class Deltafa : public Noveny
{
public:
    Deltafa(const std::string &name, int quantity);

    void alfa(Bolygo &b) override;
    void delta(Bolygo &b) override;
    void nincs(Bolygo &b) override;
};

class Parabokor : public Noveny
{
public:
    Parabokor(const std::string &name, int quantity);

    void alfa(Bolygo &b) override;
    void delta(Bolygo &b) override;
    void nincs(Bolygo &b) override;
};