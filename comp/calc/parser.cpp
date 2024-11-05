#include "parser.h"

void Node::addChild(Node* child) {
    children.push_back(child);
}

bool Parser::match(TokenType type){
    return current < tokens.size() && tokens[current].type == type;
}

Token Parser::consume(TokenType type, const std::string& errorMessage) {
    if (match(type)) return tokens[current++];
    throw std::runtime_error(errorMessage);
}

Node* parseProgram();
Node* parseStatements();
Node* parseStatement();
Node* parseExpression();
Node* parseTerm();
Node* parseFactor();
