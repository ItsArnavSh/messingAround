#include "token.h"
#include <algorithm>

short counter = 0;  // Initialize counter
std::unordered_map<short, std::string> identifier;

Token::Token(TokenType type) {
    this->type = type;
    this->value.empty = nullptr;
}

Token::Token(std::string literal) {
    this->type = IDENTIFIER;

    // Check if literal already exists in the map to avoid duplicate entries
    auto it = std::find_if(identifier.begin(), identifier.end(),[&literal](const auto& pair) { return pair.second == literal; });

    if (it != identifier.end()) {
        this->value.identifierKey = it->first; // Use existing key
    } else {
        identifier[counter] = literal;         // Add new identifier
        this->value.identifierKey = counter;
        counter++;
    }
}

Token::Token(int number) {
    this->type = NUMBER;
    this->value.number = number;
}
#include <iostream>
#include "token.h"

void Token::printToken() {
    // Print token type
    switch (type) {
        case PLUS:
            std::cout << "Token Type: PLUS";
            break;
        case MINUS:
            std::cout << "Token Type: MINUS";
            break;
        case EQUAL:
            std::cout << "Token Type: EQUAL";
            break;
        case MULTIPLY:
            std::cout << "Token Type: MULTIPLY";
            break;
        case DIVIDE:
            std::cout << "Token Type: DIVIDE";
            break;
        case IDENTIFIER:
            std::cout << "Token Type: IDENTIFIER";
            std::cout << ", Value: " << identifier[value.identifierKey];  // Print identifier string
            break;
        case NUMBER:
            std::cout << "Token Type: NUMBER";
            std::cout << ", Value: " << value.number;  // Print number value
            break;
        default:
            std::cout << "Unknown Token Type";
    }
    std::cout << std::endl;
}
