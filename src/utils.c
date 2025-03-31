#include "utils.h"

Token getNextToken(char **current_char){
    Token token = {TOKEN_UNKNOWN, 0};

    while(**current_char == ' ' || **current_char == '\t' || **current_char == '\n')
        (*current_char)++;

    if(**current_char >= '0' && **current_char <= '9'){
        token.type = TOKEN_DOUBLE;
        token.value = (int)(**current_char - '0');
        (*current_char)++;

        while (**current_char >= '0' && **current_char <= '9') {
            token.value = token.value * 10 + (**current_char - '0');
            (*current_char)++;
        }

        if(**current_char == '.') {
            (*current_char)++;

            int c = 1;
            while (**current_char >= '0' && **current_char <= '9') {
                token.value = token.value + (double)(**current_char - '0') / pow(10, c++);
                (*current_char)++;
            }
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
    else if (**current_char == '^') {
        token.type = TOKEN_POWER;
        (*current_char)++;
    }
    else if (**current_char == '%') {
        token.type = TOKEN_MOD;
        (*current_char)++;
    }
    else if (**current_char == 's') {
        (*current_char)++;
        if (**current_char == 'i') {
            (*current_char)++;
            if (**current_char == 'n') {
                token.type = TOKEN_SIN;
                (*current_char)++;
            }
        }
    }
    else if (**current_char == 'c') {
        (*current_char)++;
        if (**current_char == 'o') {
            (*current_char)++;
            if (**current_char == 's') {
                token.type = TOKEN_COS;
                (*current_char)++;
            }
        }
    }
    else if (**current_char == 't') {
        (*current_char)++;
        if (**current_char == 'a') {
            (*current_char)++;
            if (**current_char == 'n') {
                token.type = TOKEN_TAN;
                (*current_char)++;
            }
        }
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
        case TOKEN_POWER:
            return 5;
        case TOKEN_MOD:
            return 6;
        case TOKEN_SIN:
            return 7;
        case TOKEN_COS:
            return 8;
        case TOKEN_TAN:
            return 9;
        case TOKEN_LBRACKET:
            return 10;
        case TOKEN_RBRACKET:
            return 11;
        case TOKEN_DOUBLE:
            return 12;
    }
}