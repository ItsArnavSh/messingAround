#include "scanner.h"
#include "token.h"
#include "error.h"
#include "parser.h"
#include <iostream>
int main(int argc, char** argv){
    if(argc!=2)
        error("Correct Syntax ./main <filename>");
    std::vector<Token> tokens = Scanner(argv[1]);
    for(auto token : tokens){
        token.printToken();
    }
    Parser parser(tokens);
    Node* ast = parser.parseProgram();

    std::cout << "AST:" << std::endl;
    ASTPrinter::print(ast);

    // Cleanup AST nodes
    delete ast;
}
