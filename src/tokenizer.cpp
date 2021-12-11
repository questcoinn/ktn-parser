#include "tokenizer.hpp"


using namespace ktn;

void Tokenizer::init(const std::string &str) noexcept {
    this->str = str;
    this->cursor = this->str.cbegin();
}

const Token Tokenizer::getNextToken() {
    if(!this->hasMoreToken()) {
        return Token{TokenType::EOT};
    }

    std::smatch matched;
    for(const auto &spec: this->specs) {
        if(std::regex_search(this->cursor, this->str.cend(), matched, spec.regex)) {
            std::advance(this->cursor, matched.length(0));
            if(spec.type == TokenType::SKIP) {
                return this->getNextToken();
            }
            return Token{spec.type, matched.str(1)};
        }
    }

    return Token{TokenType::UNKNOWN};
}

void Tokenizer::setSpec() {
    // whitespace
    this->specs.push_back(TokenSpec{TokenType::SKIP, std::regex{"^\\s+"}});
    // comment
    this->specs.push_back(TokenSpec{TokenType::SKIP, std::regex{"^\\/\\/.*"}});
    this->specs.push_back(TokenSpec{TokenType::SKIP, std::regex{"^\\/\\*[\\s\\S]*?\\*\\/"}});
    // semicolon
    this->specs.push_back(TokenSpec{TokenType::STATEMENT_END, std::regex{"^;"}});
    // number
    this->specs.push_back(TokenSpec{TokenType::NUMBER, std::regex{"^(\\d+)"}});
    // string
    this->specs.push_back(TokenSpec{TokenType::STRING, std::regex{"^\"([^\"]*)\""}});
    this->specs.push_back(TokenSpec{TokenType::STRING, std::regex{"^\'([^\']*)\'"}});
}

bool Tokenizer::hasMoreToken() const noexcept {
    return this->cursor != this->str.cend();
}
