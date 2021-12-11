#ifndef _KTN_PARSER_HPP_
#define _KTN_PARSER_HPP_

#include <exception>
#include <string>
#include <utility> // move
#include <variant>
#include <cstddef>
#include "tokenizer.hpp"

#ifdef DEBUG
# include <iostream>
#endif

namespace ktn {

enum ParserError {
    UNEXPECTED_LITERAL,
};

enum LiteralType {
    NUMERIC,
    STRING_
};

/** TODO: Literal
 * :    NumericLiteral
 * |    StringLiteral
 * ;
 */
struct Literal {
    LiteralType type;
    std::variant<long double, std::string> value;
};


// {type} {identity} = {literal};
// {type} {identity};
struct Declaration {};
struct Assignment {};
struct Call {};

struct Statement {};

/** Program
 * :    Literal
 * ;
 */
struct Program {
    Literal body;
};

class Parser {
private:
    Tokenizer tokenizer;
    Token peeked;

public:
    Parser() = default;
    ~Parser() = default;

public:
    const Program parse(const std::string &str);

private:
    const Program parseProgram();
    const Literal parseLiteral();
    const Literal parseNumericLiteral();
    const Literal parseStringLiteral();

private:
    const Token consume(const TokenType tokenType);
};

} // namespace ktn

#ifdef DEBUG
std::ostream &_left_shift(std::ostream &stream, const ktn::Literal lit, const std::size_t depth = 0);
std::ostream &_left_shift(std::ostream &stream, const ktn::Program program, const std::size_t depth = 0);
std::ostream &operator<<(std::ostream &stream, const ktn::Program program);
#endif

#endif
