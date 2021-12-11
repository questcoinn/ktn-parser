#include <iostream>
#include <string>
#include "parser.hpp"


int main(int argc, char *argv[]) {
    ktn::Parser parser;

    const std::string str = "\n"
        "/**\n"
        " * Comment\n"
        " */\n"
        "\"hello\""
        ;

    const ktn::Program program = parser.parse(str);

#ifdef DEBUG
    std::cout << program << "\n";
#endif

    return 0;
}
