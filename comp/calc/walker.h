#ifndef WALKER_H
#define WALKER_H
#include "parser.h"
#include "error.h"
extern int* symbolTable;
void mainWalker(Node* nt);
int eval(Node* nt);
void printAll();
#endif
