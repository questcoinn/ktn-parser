# Index

http://dmitrysoshnikov.com/courses/parser-from-scratch/

1. Basic expressions and Tokenizer

    1. Tokenizer | Parser
        - Course overview and agenda
        - Parsing pipeline
        - Tokenizer module (Lexical analysis)
        - Parser module (Syntactic analysis)
        - Abstract Syntax Tree (AST)
        - Regular expression notation
        - Backus-Naur form (BNF) notation
        - Grammars and productions
        - Hand-written and Automatic parsers
        - Syntax: language-agnostic parser generator
        - The Letter programming language
        - Numeric literals

    2. Numbers | String
        - Tokenizer module (Lexical analysis)
        - Number and String tokens
        - Program AST node
        - Lookahead
        - Numeric literals
        - String literals
        - Finite state machine

    3. From State Machines to Regular Expressions
        - Tokenizers as Finite state machines
        - Regular Expressions notation
        - Tokenizer spec
        - Generic getNextToken
        - Single-line and Multi-line comments

2. Program structure

    1. Statements and Statement list
        - TDD: Test-driven development
        - AST Explorer
        - Statements and Statement list
        - Left-recursion
        - Recursion-to-loop conversion to handle left-recursive grammars

    2. Blocks: nested scopes
        - Block statement
        - Nested scopes
        - Empty statement

    3. Different AST formats
        - AST formats
        - Node handles vs. Node factories
        - Default AST factory
        - S-expression AST factory
        - AST transforms

    4. Binary Expressions
        - Binary expressions
        - Additive expression
        - Multiplicative expression
        - Primary expression
        - Operator precedence
        - Parenthesized expression

3. Control flow and Functions

    1. Assignment Expression
        - Identifiers: variable names
        - Chained assignment
        - Left-hand side expression

    2. Variable Statement
        - Variable statement
        - Keyword tokens
        - Variable declarations
        - Name and optional Initializer

    3. If-Statement
        - Control flow
        - If-else statement
        - Consequent and Alternate parts
        - Relational expression

    4. Equality | Logical
        - Equality expression
        - Logical AND expression
        - Logical OR expression
        - Boolean literals
        - Null literal

    5. Unary Expression
        - Unary expression
        - Logical NOT operator
        - Minus operator
        - Single operand

    6. Iteration Statement
        - Control flow
        - Iteration Statement
        - While loop
        - Do-while loop
        - For-cycle
        - Inline variable declaration

    7. Function Declaration
        - Function declaration
        - Return statement
        - Formal parameters
        - Function body
        - Optional return

4. Object-oriented programming

    1. Member Expression
        - Member Expression
        - Property access
        - Objects and Properties
        - Computed vs. Non-computed properties
        - Chained objects
        - Assigning to object properties

    2. Call Expression
        - Call Expression
        - Function calls
        - Method calls
        - Call | Arguments
        - Chained calls

    3. OOP | Classes
        - Object-oriented programming
        - Class declaration
        - New expression
        - Super calls
        - Methods

    4. Final Executable
        - Parser CLI
        - Parsing expressions and files
        - Project overview
        - Next steps
        - Further related classes
