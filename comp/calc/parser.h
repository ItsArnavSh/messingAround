#include "token.h"
#include <stdexcept>
#include <string>
#include <vector>
class Node {
public:
    std::string type;
    std::string value;  // For identifiers and numbers
    std::vector<Node*> children;

    Node(const std::string& type, const std::string& value = "") : type(type), value(value) {}

    void addChild(Node* child);
};
class Parser{
    private:
    std::vector<Token> tokens;
    int current = 0;

    bool match(TokenType type);
    Token consume(TokenType type, const std::string& errorMessage);
    Node* parseProgram();
    Node* parseStatements();
    Node* parseStatement();
    Node* parseExpression();
    Node* parseTerm();
    Node* parseFactor();

};
