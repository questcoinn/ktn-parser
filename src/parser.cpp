#include "parser.hpp"


using namespace ktn;

const Program Parser::parse(const std::string &str) {
    this->tokenizer.init(str);
    this->peeked = this->tokenizer.getNextToken();
    return this->parseProgram();
}

const Program Parser::parseProgram() {
    return Program{this->parseLiteral()};
}

const Literal Parser::parseLiteral() {
    switch(this->peeked.type) {
        case TokenType::NUMBER:
            return this->parseNumericLiteral();
        case TokenType::STRING:
            return this->parseStringLiteral();
    }
    throw std::runtime_error("Literal: unexpected literal production - TOKEN(" + std::to_string(this->peeked.type) + ")");
}

const Literal Parser::parseNumericLiteral() {
    const Token token = this->consume(TokenType::NUMBER);
    return Literal{LiteralType::NUMERIC, std::stold(token.value)};
}

const Literal Parser::parseStringLiteral() {
    const Token token = this->consume(TokenType::STRING);
    return Literal{LiteralType::STRING_, token.value};
}

const Token Parser::consume(const TokenType tokenType) {
    const Token token = this->peeked;

    if(token.type == TokenType::EOT) {
        throw std::runtime_error("Unexpected end of input: expected TOKEN(" + std::to_string(tokenType) + ")");
    }

    if(token.type != tokenType) {
        throw std::runtime_error("Unexpected TOKEN(" + std::to_string(token.type) + "), expected: TOKEN(" + std::to_string(tokenType) + ")");
    }

    this->peeked = this->tokenizer.getNextToken();
    return std::move(token);
}

#ifdef DEBUG
std::ostream &_left_shift(std::ostream &stream, const Literal lit, const std::size_t depth) {
    std::string leftPadding;
    for(int i = 0; i < depth; i++) {
        leftPadding += "  ";
    }
    stream << "{\n";

    stream << leftPadding << "  type: ";
    switch(lit.type) {
        case LiteralType::NUMERIC: stream << "NumericLiteral"; break;
        case LiteralType::STRING_: stream << "StringLiteral"; break;
    }
    stream << "\n";

    stream << leftPadding << "  value: ";
    switch(lit.type) {
        case LiteralType::NUMERIC: stream << std::get<long double>(lit.value); break;
        case LiteralType::STRING_: stream << "\"" << std::get<std::string>(lit.value) << "\""; break;
    }
    stream << "\n";

    stream << leftPadding << "}";
    return stream;
}

std::ostream &_left_shift(std::ostream &stream, const Program program, const std::size_t depth) {
    std::string leftPadding;
    for(int i = 0; i < depth; i++) {
        leftPadding += "  ";
    }
    stream << leftPadding << "{\n";
    stream << leftPadding << "  type: Program\n";
    stream << leftPadding << "  body: ";
    _left_shift(stream, program.body, depth + 1);
    stream << "\n" << leftPadding << "}";
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const Program program) {
    return _left_shift(stream, program);
}
#endif