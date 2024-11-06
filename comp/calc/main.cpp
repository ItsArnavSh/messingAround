#include "scanner.h"
#include "token.h"
#include "error.h"
#include "parser.h"
#include "walker.h"
#include <iostream>
int main(int argc, char** argv){
    if(argc!=2)
        error("Correct Syntax ./main <filename>");
    std::vector<Token> tokens = Scanner(argv[1]);
    Parser parser(tokens);
    Node* ast = parser.parseProgram();

    mainWalker(ast);
    printAll();

    // Cleanup AST nodes
    delete ast;
}
