#include "pile.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE ("Test1", "a")
{
    Pile h = Pile();
    REQUIRE (0 == h.sum());

    h.add(6);
    h.remove(6);
    REQUIRE (0 == h.sum());
}

TEST_CASE ("Test2","b")
{
    Pile h = Pile();

    h.add(2);
    REQUIRE (2 == h.select(2));

    h.add(4);
    REQUIRE (4 == h.select(4));

    h.add(6);
    REQUIRE (6 == h.select(6));

    try {
        h.add(6); //no readding
    }
    catch (Pile::Exceptions ex) {
        if (ex == Pile::ITEM_IS_ALREDY_CONTAINED) {

        }
        else {
            REQUIRE (false);
        }
    }
    
    REQUIRE (12 == h.sum());

    try {
        h.select(-2);
        REQUIRE(false);
    }
    catch(Pile::Exceptions ex) {
        if (ex == Pile::ITEM_IS_NOT_CONTAINED) {
            REQUIRE(true);
        }
        else {
            REQUIRE(false);
        }
    }

    try {
        h.remove(5);             // ------->
        REQUIRE (false);
    }
    catch(Pile::Exceptions ex) { // <-------
        if (ex == Pile::ITEM_IS_NOT_CONTAINED) {
            REQUIRE (true);
        }
        else {
            REQUIRE (false);
        }
    }
}