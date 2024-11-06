#include "token.h"
#include "error.h"
#include <stdexcept>
#include <string>
#include <vector>
extern int* symboltable;
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
    Token* token;  // Pointer to the relevant Token, if this node represents a token
    std::vector<Node*> children;

    // Constructor for non-terminal nodes
    Node(NodeType type) : type(type), token(nullptr) {}

    // Constructor for terminal nodes (tokens)
    Node(NodeType type, Token* token) : type(type), token(token) {}

    void addChild(Node* child);
};

class ASTPrinter {
public:
    static void print(Node* node, int level = 0);

private:
    static std::string getNodeTypeName(NodeType type);
    static std::string getTokenValue(Token* token);
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
