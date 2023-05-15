//
// Created by shora on 15/05/2023.
//

#include "Team.hpp"
#include <iostream>
#include <sstream>
#include "doctest.h"

using namespace ariel;
using namespace std;

TEST_SUITE("point class methods"){
    TEST_CASE("constructor"){
        SUBCASE("default constructor"){
            Point p1;
            CHECK(p1.getX() == 0);
            CHECK(p1.getY() == 0);
        }
        SUBCASE("constructor with parameters"){
            Point p1(1,2);
            CHECK(p1.getX() == 1);
            CHECK(p1.getY() == 2);
        }
    }
    TEST_CASE("distance"){
        Point p1(1,2);
        Point p2(3,4);
        CHECK(p1.distance(p2) == sqrt(8));
    }

    TEST_CASE("print"){
        Point p1(1,2);
        ostringstream oss;
        p1.print();
        CHECK(oss.str() == "(1, 2)");
    }

    TEST_CASE("moveTowards"){
        Point p1(1,2);
        Point p2(3,4);
        Point p3(2,3);
        CHECK(p1.moveTowards(p1,p2,1).getX() == p3.getX());
        CHECK(p1.moveTowards(p1,p2,1).getY() == p3.getY());
    }

    TEST_CASE("getters"){
        Point p1(1,2);
        CHECK(p1.getX() == 1);
        CHECK(p1.getY() == 2);
    }
}

TEST_SUITE("charachter class methods"){
    TEST_CASE("constructor"){

        SUBCASE("constructor with parameters"){
            Point p1(1,2);
            Character c1("shora",p1,100);
            CHECK(c1.getName() == "shora");
            CHECK(c1.getLocation().getX() == 1);
            CHECK(c1.getLocation().getY() == 2);
            CHECK(c1.isAlive() == true);
        }
    }
}
