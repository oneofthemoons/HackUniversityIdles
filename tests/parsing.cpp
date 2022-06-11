#include <hack_university_idles.h>
#include <cassert>
#include <set>
#include <numeric>
#include <iostream>

void TestIsDigit() {
    static const std::string availableStr =
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::set<char> available;
    available.insert('0');
    available.insert('1');
    for (size_t base = 2; base < 37; ++base) {
        available.insert(availableStr[base - 1]);
        available.insert(std::toupper(availableStr[base - 1]));
        for (char c = std::numeric_limits<char>::min(); c < std::numeric_limits<char>::max(); ++c) {
            assert(idle::IsDigit(c, base) == (available.count(c) != 0));
        }
    }
    try {
        idle::IsDigit('0', 0);
        assert(false);
    } catch (...) {}
    try {
        idle::IsDigit('1', 1);
        assert(false);
    } catch (...) {}
    try {
        idle::IsDigit('0', 37);
        assert(false);
    } catch (...) {}
}

void TestParsing() {
    TestIsDigit();
}