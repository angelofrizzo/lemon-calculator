#include <stdlib.h>
#include <stdio.h>

#include "utils.h"

#define TEXT_SIZE 1024

int main(int argc, char *argv[]){
    void* pParser = ParseAlloc (malloc);

    char *text = (char *)malloc(TEXT_SIZE);

    FILE *file = fopen(argv[1], "r");

    fgets(text, TEXT_SIZE, file);

    fclose(file);

    char *current_char = text;
    Token current_token = getNextToken(&current_char);

    while(current_token.type != TOKEN_EXIT){
        //printf("%d\n", current_token.type);

        if(current_token.type != TOKEN_UNKNOWN){
            Parse (pParser, ttos(current_token.type), current_token.value);
        }
    
        current_token = getNextToken(&current_char);
    }

    Parse (pParser, 0, 0);

    ParseFree(pParser, free);

    return 0;
}