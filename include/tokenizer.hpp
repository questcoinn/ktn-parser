#ifndef _KTN_TOKENIZER_HPP
#define _KTN_TOKENIZER_HPP

#include <regex> // regex_match
#include <string>
#include <vector>
#include <cstddef>


namespace ktn {

enum TokenType {
    UNKNOWN = 0,
    EOT,
    SKIP,
    STATEMENT_END,
    NUMBER,
    STRING
};

struct Token {
    TokenType type;
    std::string value;

    Token(): type(TokenType::UNKNOWN) {}
    Token(const TokenType type): type(type) {}
    Token(const TokenType type, const std::string &value): type(type), value(value) {}
};

struct TokenSpec {
    TokenType type;
    std::regex regex;
};

class Tokenizer {
private:
    std::vector<TokenSpec> specs;
    std::string str;
    std::string::const_iterator cursor;

public:
    Tokenizer() { this->setSpec(); }
    ~Tokenizer() = default;

public:
    void init(const std::string &str) noexcept;
    const Token getNextToken();

private:
    void setSpec();
    bool hasMoreToken() const noexcept;
};

} // namespace ktn

#endif
