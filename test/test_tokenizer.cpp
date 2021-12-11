#include <iostream>
#include "assert.hpp"
#include "tokenizer.hpp"


using namespace ktn;

#define TEST_TOKEN_SPEC(STR, TYPE) \
    do { \
        Tokenizer tokenizer; \
        tokenizer.init(STR); \
        TokenType nextType = tokenizer.getNextToken().type; \
        std::string message; \
        message += #TYPE; \
        message += " != "; \
        message += std::to_string(nextType); \
        ASSERT(TYPE == nextType, (message)); \
    } while(0)


int main(int argc, char *argv[]) {
    // whitespace
    TEST_TOKEN_SPEC("  ", TokenType::EOT);
    TEST_TOKEN_SPEC("\t", TokenType::EOT);
    TEST_TOKEN_SPEC("\r", TokenType::EOT);
    TEST_TOKEN_SPEC("\n", TokenType::EOT);

    // comment
    TEST_TOKEN_SPEC("// single line comment", TokenType::EOT);
    TEST_TOKEN_SPEC("/* multi\nline\ncomment\n */", TokenType::EOT);

    // number
    TEST_TOKEN_SPEC("1234", TokenType::NUMBER);

    // string
    TEST_TOKEN_SPEC("'single quot string'", TokenType::STRING);
    TEST_TOKEN_SPEC("\"double quot string\"", TokenType::STRING);

    std::cout << "[Tokenizer] All test passed!\n";
    return 0;
}
