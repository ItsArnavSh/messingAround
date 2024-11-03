#include "errors.h"
void causeError(char* message){
    perror(message);
    exit(EXIT_FAILURE);
}
