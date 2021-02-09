#pragma once

#include <vector>

class Pile {
private:
    
    std::vector<int> numbers;
    int sumCounter;

public:
    enum Exceptions {
        ITEM_IS_ALREDY_CONTAINED,
        ITEM_IS_NOT_CONTAINED
    };
    

    Pile();
    void add(int n);
    void remove(int n);
    int sum();
    int select(int n);
    void print();

    int size();
};