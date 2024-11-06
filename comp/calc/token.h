#ifndef TOKEN_H
#define TOKEN_H

#include <cstdint>
#include <string>
#include <unordered_map>

// Union to store different token values
typedef union Storage {
    int number;
    void* empty;
    short identifierKey;  // Renamed for clarity
} Storage;

// Global counter for new identifier keys
extern short counter;

// Map to store identifier strings
extern std::unordered_map<short, std::string> identifier;

// Enumeration for token types
typedef enum TokenType {
    PLUS,
    MINUS,
    DIVIDE,
    MULTIPLY,
    EQUAL,
    IDENTIFIER,
    SEMICOLON,
    BOPEN,
    BCLOSE,
    NUMBER
} TokenType;

class Token {
public:
    TokenType type;
    Storage value;

    // Constructors for different token types
    Token(TokenType type);           // For operators
    Token(std::string literal);      // For identifiers (sets identifierKey)
    Token(int number);               // For numbers (sets number)
    void printToken();
};

#endif
