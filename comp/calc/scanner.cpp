#include "scanner.h"
#include "token.h"
std::vector<Token> Scanner(std::string filename){
    std::ifstream file(filename);
       if (!file) {
           error("Error Opening File");
       }
       std::vector<Token> tokens;
       char ch;
           std::string literal;  // For building multi-character identifiers or literals

           while (file.get(ch)) {  // Reads one character at a time
               if (std::isspace(ch)) {
                   continue;  // Skip whitespace
               }

               if (std::isdigit(ch)) {
                   // Process numbers
                   int number = ch - '0';
                   while (file.get(ch) && std::isdigit(ch)) {
                       number = number * 10 + (ch - '0');  // Accumulate multi-digit numbers
                   }
                   file.unget();  // Step back one character as it may not be part of the number
                   tokens.push_back(Token(number));
               }
               else if (std::isalpha(ch)) {
                   // Process identifiers
                   literal.clear();
                   literal += ch;  // Start building identifier with the current character
                   while (file.get(ch) && (std::isalnum(ch) || ch == '_')) {
                       literal += ch;  // Accumulate alphanumeric characters and underscores
                   }
                   file.unget();  // Step back as it may not be part of the identifier
                   tokens.push_back(Token(literal));  // Add identifier token
               }
               else {
                   // Process single-character tokens (operators, punctuation, etc.)
                   switch (ch) {
                       case '+':
                           tokens.push_back(Token(PLUS));
                           break;
                       case '-':
                           tokens.push_back(Token(MINUS));
                           break;
                       case '*':
                           tokens.push_back(Token(MULTIPLY));
                           break;
                       case '/':
                           tokens.push_back(Token(DIVIDE));  // Fixed to DIVIDE instead of PLUS
                           break;
                        case '=':
                            tokens.push_back(Token(EQUAL));  // Fixed to DIVIDE instead of PLUS
                            break;
                        case '(':
                            tokens.push_back(Token(BOPEN));  // Fixed to DIVIDE instead of PLUS
                            break;
                        case ')':
                            tokens.push_back(Token(BCLOSE));  // Fixed to DIVIDE instead of PLUS
                            break;
                        case ';':
                            tokens.push_back(Token(SEMICOLON));  // Fixed to DIVIDE instead of PLUS
                            break;
                       default:
                           // Handle unexpected characters or report an error
                           error("Unknown character: ");
                           break;
                   }
               }}
           file.close();
       return tokens;

}
