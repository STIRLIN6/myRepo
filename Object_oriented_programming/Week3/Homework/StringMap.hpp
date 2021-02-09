#pragma once
#include <vector>
#include <string>

class Map
{
private:
    struct element {
        std::string value;
        int key;
    };

    std::vector<element> map;

public:
    enum Exceptions {
        KEY_IS_NOT_CONTAINED
    };

    void set(int key, std::string value);
    bool already(int key) const;
    std::string search(int key) const;
};