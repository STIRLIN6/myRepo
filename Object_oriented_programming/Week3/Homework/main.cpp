#include "StringMap.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE ("test1", "") {

    Map m;
    REQUIRE (true);
    m.set(1, "first");
    
    REQUIRE (m.already(1));
    REQUIRE (!m.already(3));

    REQUIRE(m.search(1) == "first");
    
    try {
        m.search(2);
        REQUIRE (false);
    }
    catch (Map::Exceptions ex) {
        if (ex == Map::KEY_IS_NOT_CONTAINED) {
            REQUIRE(true);
        }
        else {
            REQUIRE (false);
        }
    }
}