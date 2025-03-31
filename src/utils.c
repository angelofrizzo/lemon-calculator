#include "utils.h"

Token getNextToken(char **current_char){
    Token token = {TOKEN_UNKNOWN, 0};

    while(**current_char == ' ' || **current_char == '\t' || **current_char == '\n')
        (*current_char)++;

    if(**current_char >= '0' && **current_char <= '9'){
        token.type = TOKEN_INTEGER;
        token.value = (int)(**current_char - '0');
        (*current_char)++;

        while (**current_char >= '0' && **current_char <= '9') {
            token.value = token.value * 10 + (**current_char - '0');
            (*current_char)++;
        }
    }
    else if (**current_char == '+') {
        token.type = TOKEN_PLUS;
        (*current_char)++;
    }
    else if (**current_char == '-') {
        token.type = TOKEN_MINUS;
        (*current_char)++;
    }
    else if (**current_char == '*') {
        token.type = TOKEN_TIMES;
        (*current_char)++;
    }
    else if (**current_char == '/') {
        token.type = TOKEN_DIVIDE;
        (*current_char)++;
    }
    else if (**current_char == '(') {
        token.type = TOKEN_LBRACKET;
        (*current_char)++;
    }
    else if (**current_char == ')') {
        token.type = TOKEN_RBRACKET;
        (*current_char)++;
    }
    else if (**current_char == '\0')
    {
        token.type = TOKEN_EXIT;
    }

    return token;
}

int ttos(TokenType current_type){
    switch(current_type){
        case TOKEN_PLUS:
            return 1;
        case TOKEN_MINUS:
            return 2;
        case TOKEN_DIVIDE:
            return 3;
        case TOKEN_TIMES:
            return 4;
        case TOKEN_LBRACKET:
            return 5;
        case TOKEN_RBRACKET:
            return 6;
        case TOKEN_INTEGER:
            return 7;
    }
}