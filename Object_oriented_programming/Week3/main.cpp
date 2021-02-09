#include "PrQueue.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE ("IsEmpty", "")
{
    PrQueue q;
    REQUIRE (q.IsEmpty () == true);
    q.Push (0, "x");
    REQUIRE (q.IsEmpty () == false);
    q.Pop ();
    REQUIRE (q.IsEmpty () == true);
}

TEST_CASE ("Empty throws")
{
    PrQueue q;
    try {
        q.Top();
        REQUIRE (false);
    }
    catch (PrQueue::Exceptions ex) {
        if (ex == PrQueue::EMPTY) {}
        else {
            REQUIRE (false);
        }
    }
}

TEST_CASE ("Dezoxiribonukleinsav", "5") {
    PrQueue q;
    REQUIRE (q.IsEmpty () == true);
    q.Push(10, "zacsko");
    q.Push(11, "zsak");
    REQUIRE (q.Top() == "zsak");
    q.Pop();
    REQUIRE (q.Top() == "zacsko");
}

// g++ -std=c++14 *.cpp