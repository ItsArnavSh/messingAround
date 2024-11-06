#ifndef  PARSER_H
#define PARSER_H
#include "token.h"
#include "error.h"
#include <cstddef>
#include <stdexcept>
#include <string>
#include <vector>
enum NodeType {
    PROGRAM,
    STATEMENTS,
    ASSIGNMENT,
    ADD,
    SUBT,
    MUL,
    DIV,
    IDENT,
    NUM,
    LEFT_PAREN,
    RIGHT_PAREN
};
class Node {
public:
    NodeType type;
    Storage value;
    std::vector<Node*> children;

    // Constructor for non-terminal nodes
    Node(NodeType type) : type(type) {}

    // Constructor for terminal nodes (tokens)
    Node(NodeType type, Token* token) : type(type), value(token->value) {}

    void addChild(Node* child);
};

class Parser{
    public:
    std::vector<Token> tokens;
    int current = 0;
    Parser(std::vector<Token> tokens): tokens(tokens){};
    bool match(TokenType type);
    Token consume(TokenType type, const std::string& errorMessage);
    Node* parseProgram();
    Node* parseStatements();
    Node* parseStatement();
    Node* parseExpression();
    Node* parseTerm();
    Node* parseFactor();

};
#endif
