#include <iostream>
#include <map>
#include <functional>
#include <string>
void TestParsing();

int main(int argc, char** argv) {
    static const std::map<std::string, std::function<void()>> testModules = {
        { "parsing", TestParsing },
    };
    if (argc < 2) {
        for (const auto& [_, module]: testModules) {
            module();
        }
    } else if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) {
        std::cout << "Usage: ./test" << std::endl
                  << "Params (optional): test module name (./test parsing)"
                  << "Other commands:" << std::endl
                  << "    --help, -h - for help" << std::endl
                  << "    --list, -l - list of test modules" << std::endl;
    } else if (!strcmp(argv[1], "--list") || !strcmp(argv[1], "-l")) {
        std::cout << "Test modules:" << std::endl;
        for (const auto& [name, _]: testModules) {
            std::cout << "    " << name << std::endl;
        }
    } else if (testModules.count(argv[1]) == 0) {
        std::cout << "Module not found, use \"./test -l\" for get list of allowe modules" << std::endl;
        std::cout << "All tests passed!" << std::endl;
    } else {
        testModules.at(argv[1])();
        std::cout << "All tests passed!" << std::endl;
    }
}
