#include "walker.h"
#include "token.h"
#include <iostream>
int* symbolTable = new int[counter]();
void mainWalker(Node* nt){
    for(auto statement : nt->children){
        //Now we are just iterating through the statements
        if(statement->type!=ASSIGNMENT){
            error("There is no assignment");
        }
        short lhs = (statement->children)[0]->value.identifierKey;
        short rhs = eval(statement->children[1]);
        symbolTable[lhs] = rhs;
    }
}
int eval(Node* nt){
    switch(nt->type){
        case MUL:
        return eval(nt->children[0])*eval(nt->children[1]);
        break;
        case DIV:
        return eval(nt->children[0])/eval(nt->children[1]);
        break;
        case ADD:
        return eval(nt->children[0])+eval(nt->children[1]);
        break;
        case SUBT:
            return eval(nt->children[0])-eval(nt->children[1]);
        break;
        case IDENT:
            return symbolTable[nt->value.identifierKey];
        break;
        case NUM:
            return nt->value.number;
        break;
        default:
            error("There has been an error while evaluating");
            return 0;

    }
}
void printAll(){
    for(int i=0;i<counter;i++)
        std::cout<<symbolTable[i]<<std::endl;
}
