#ifndef TOKEN_H
#define TOKEN_H
typedef enum TokenType{
    //Operators
    PLUS,
    MINUS,
    DIVIDE,
    MULTIPLY,
    OPENBRACE,
    CLOSEBRACE,
    //All the keywords
    DEF,
    //All the identifier
    IDENTIFIER,
};
#endif
