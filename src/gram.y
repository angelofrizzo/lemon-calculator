%token_type {double}  

%include {#include <math.h>}

%left PLUS MINUS.   
%left DIVIDE TIMES.  
%left POWER MOD.
%left SIN COS TAN.  

program ::= expr(A).        
{
    printf("Result=%f\n", A);
}  

expr(A) ::= expr(B) MINUS  expr(C).     { A = B - C; }  
expr(A) ::= expr(B) PLUS  expr(C).      { A = B + C; }  
expr(A) ::= expr(B) TIMES  expr(C).     { A = B * C; }  

expr(A) ::= expr(B) DIVIDE expr(C).  
{   
    if(C != 0){
        A = B / C;
    } else {
        printf("divide by zero\n");
    }
}

expr(A) ::= LBRACKET expr(B) RBRACKET.  { A = B; }

expr(A) ::= expr(B) POWER expr(C).      { A = pow(B, C); }
expr(A) ::= expr(B) MOD expr(C).        { A = (int)B % (int)C; }

expr(A) ::= SIN expr(B).  { A = sin(B); }
expr(A) ::= COS expr(B).  { A = cos(B); }
expr(A) ::= TAN expr(B).  { A = tan(B); }

expr(A) ::= DOUBLE(B).     { A = B; }