#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
typedef enum {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MUL,
    TOKEN_EOF,
    // ... other token types
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char* value;
} Token;

// Lexer (simplified)
Token getNextToken() {
    // In a real lexer, this would read input and return tokens
    // For this example, we'll just return a sequence of tokens
    static int currentToken = 0;
    Token tokens[] = {
        {TOKEN_INT, "10"},
        {TOKEN_PLUS, "+"},
        {TOKEN_INT, "20"},
        {TOKEN_MUL, "*"},
        {TOKEN_INT, "5"},
        {TOKEN_EOF, "EOF"}
    };
    return tokens[currentToken++];
}

// Parser
void parse() {
    Token token = getNextToken();
    while (token.type != TOKEN_EOF) {
        if (token.type == TOKEN_INT) {
            printf("Parsed integer: %s\n", token.value);
        } else if (token.type == TOKEN_PLUS) {
            printf("Parsed operator: %s\n", token.value);
        } else if (token.type == TOKEN_MUL) {
            printf("Parsed operator: %s\n", token.value);
        }
        // ... handle other token types
        token = getNextToken();
    }
}

int main() {
    printf("Starting parsing...\n");
    parse();
    printf("Parsing finished.\n");
    return 0;
}
