#pragma once

#include <string>
#include <algorithm>
#include <exception>

namespace idle {

bool IsDigit(char c, size_t base = 10) {
    static const std::string available =
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz";
    if (base > available.size()) {
        throw std::runtime_error(std::string(__func__) + ": base is more than 36 is unavailable");
    }
    if (base < 2) {
        throw std::runtime_error(std::string(__func__) + ": base is less than 2");
    }
    c = std::tolower(c);
    bool rv = false;
    for (size_t i = 0; i < base; ++i) {
        if (c == available[i]) {
            rv = true;
            break;
        }
    }
    return rv;
}

bool IsInt(const std::string& str, size_t base = 10) {
    bool rv = !str.empty();
    size_t i = 0;
    if (rv) {
        if (str[i] == '-') {
            ++i;
        }
        if (i == str.size()) {
            rv = false;
        }
        for (; i < str.size(); ++i) {
            if (!IsDigit(str[i], base)) {
                rv = false;
                break;
            }
        }
    }
    return rv;
}

bool IsUInt(const std::string& str, size_t base = 10) {
    bool rv = !str.empty();
    size_t i = 0;
    if (rv) {
        for (; i < str.size(); ++i) {
            if (!IsDigit(str[i], base)) {
                rv = false;
                break;
            }
        }
    }
    return rv;
}

} // namespace idle
