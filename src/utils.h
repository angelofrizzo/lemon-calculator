#ifndef UTILS_H
#define UTILS_H

#include <math.h>

// Token definition
typedef enum {
    TOKEN_UNKNOWN,
    TOKEN_DOUBLE,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_TIMES,
    TOKEN_DIVIDE,
    TOKEN_POWER,
    TOKEN_MOD,
    TOKEN_SIN,
    TOKEN_COS,
    TOKEN_TAN,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_EXIT
} TokenType;

typedef struct {
    TokenType type;
    double value;
} Token;

Token getNextToken(char **current_char);

int ttos(TokenType current_type);

#endif