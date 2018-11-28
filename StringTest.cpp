#include "catch.hpp"
#include "String.hpp"
#include <cstring>
#include <iostream>

using namespace tutorial;

TEST_CASE ("testConstruction") {
    String s{"abcdefghij"};
    
    REQUIRE(std::strcmp(s.c_str(), "abcdefghij") == 0);
}

TEST_CASE ("testAppend") {
    String s{"abcdefghij"};
    std::cout << s << "\n";
    s += 'k';
    std::cout << s << "\n";
    s += 'l';
    std::cout << s << "\n";
    s += 'm';
    std::cout << s << "\n";
    s += 'n';
    std::cout << s << "\n";
    s += 'o';
    std::cout << s << "\n";
    s += 'p';
    std::cout << s << "\n";

    REQUIRE(std::strcmp(s.c_str(), "abcdefghijklmnop") == 0);

    String s2 = "Hell";
    s2 += " and high water";
    std::cout << s2 << "\n";
     
    REQUIRE(std::strcmp(s2.c_str(), "Hell and high water") == 0);
}

TEST_CASE ("testConcatenation") {
    String s{"abcdefghij"};
    String s3{"qwerty"};

    String s2 = s + ". " + s3 + String{". "} + "Horsefeathers\n";

    REQUIRE(std::strcmp(s2.c_str(), "abcdefghij. qwerty. Horsefeathers\n") == 0);
}
   
TEST_CASE ("testOutput") {
    String s{"abcdefghij"};
     
    std::cout << s << "\n";
}

TEST_CASE ("testAssignment") {
    String s{"abcdefghij"};
    String s3 = "qwerty";

    s = s3;
    std::cout << s << "\n";

    REQUIRE(std::strcmp(s.c_str(), "qwerty") == 0);

    String s4{"the quick brown fox jumped over the lazy dog"};
    std::cout << s4 << "\n";
    s4 = s4;
    std::cout << s4 << "\n";

    REQUIRE(std::strcmp(s4.c_str(), "the quick brown fox jumped over the lazy dog") == 0);
} 
   
