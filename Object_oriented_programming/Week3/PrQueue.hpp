#ifndef PRQUEUE_HPP
#define PRQUEUE_HPP

#include <vector>
#include <string>

class PrQueue {
private:
    struct Item {
        int priority;
        std::string value;
    };

    std::vector<Item> items;

    int GetMaxItemIndex () const;

public:
    enum Exceptions {
        EMPTY
    };

    bool IsEmpty () const;
    std::string Top () const;
    void Pop ();
    void Push (int priority, std::string value);
};

#endif