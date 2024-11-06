#include "parser.h"
#include "token.h"
#include <iostream>

void Node::addChild(Node* child) {
    children.push_back(child);
}

// Parser methods
bool Parser::match(TokenType type) {
    return current < tokens.size() && tokens[current].type == type;
}

Token Parser::consume(TokenType type, const std::string& errorMessage) {
    if (match(type)) return tokens[current++];
    throw std::runtime_error(errorMessage);
}

Node* Parser::parseProgram() {
    return parseStatements();
}

Node* Parser::parseStatements() {
    Node* statements = new Node(STATEMENTS);
    while (current < tokens.size()) {
        statements->addChild(parseStatement());
        if (match(SEMICOLON)) {
            consume(SEMICOLON, "Expected ';' after statement.");
        }
    }
    return statements;
}

Node* Parser::parseStatement() {
    Token identifier = consume(IDENTIFIER, "Expected identifier.");
    consume(EQUAL, "Expected '=' after identifier.");
    Node* expr = parseExpression();
    Node* statementNode = new Node(ASSIGNMENT);
    statementNode->addChild(new Node(IDENT, &identifier));
    statementNode->addChild(expr);
    return statementNode;
}

Node* Parser::parseExpression() {  // Handles + and - operators
    Node* left = parseTerm();
    while (match(PLUS) || match(MINUS)) {
        Token operatorToken = tokens[current++];
        Node* right = parseTerm();
        Node* exprNode = new Node(operatorToken.type == PLUS ? ADD : SUBT);
        exprNode->addChild(left);
        exprNode->addChild(right);
        left = exprNode;  // Update left to continue parsing
    }
    return left;
}

Node* Parser::parseTerm() {  // Handles * and / operators
    Node* left = parseFactor();
    while (match(MULTIPLY) || match(DIVIDE)) {
        Token operatorToken = tokens[current++];
        Node* right = parseFactor();
        Node* termNode = new Node(operatorToken.type == MULTIPLY ? MUL : DIV);
        termNode->addChild(left);
        termNode->addChild(right);
        left = termNode;  // Update left to chain expressions
    }
    return left;
}

Node* Parser::parseFactor() {
    if (match(NUMBER)) {
        Token number = consume(NUMBER, "Expected number.");
        return new Node(NUM, &number);
    }
    if (match(IDENTIFIER)) {
        Token identifier = consume(IDENTIFIER, "Expected identifier.");
        return new Node(IDENT, &identifier);
    }
    if (match(BOPEN)) {
        consume(BOPEN, "Expected '('.");
        Node* expr = parseExpression();
        consume(BCLOSE, "Expected ')'.");
        return expr;
    }
    throw std::runtime_error("Unexpected token in expression.");
}
