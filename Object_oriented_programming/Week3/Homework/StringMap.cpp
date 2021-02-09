#include "StringMap.hpp"

void Map::set (int key, std::string value) {
    bool b = false;
    for (int i = 0; i < map.size(); i++) {
        if (key == map[i].key) {
            map[i].value = value;
            b = true;
        }
    }

    if (!b) {
        element elem = {value, key};
        map.push_back(elem);
    }
}

bool Map::already (int key) const {
    bool b = false;
    for (int i = 0; i < map.size(); i++) {
        if (key == map[i].key) {
            b = true;
        }
    }
    return b;
}

std::string Map::search (int key) const {
    std::string value;
    bool b = false;
    for (int i = 0; i < map.size(); i++) {
        if (key == map[i].key) {
            b = true;
            value = this->map[i].value;
        }
    }

    if (b) {
        return value;
    }
    else {
        throw KEY_IS_NOT_CONTAINED;
    }
}