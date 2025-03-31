#ifndef UTILS_H
#define UTILS_H

// Token definition
typedef enum {
    TOKEN_UNKNOWN,
    TOKEN_INTEGER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_TIMES,
    TOKEN_DIVIDE,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_EXIT
} TokenType;

typedef struct {
    TokenType type;
    int value;
} Token;

Token getNextToken(char **current_char);

int ttos(TokenType current_type);

#endif