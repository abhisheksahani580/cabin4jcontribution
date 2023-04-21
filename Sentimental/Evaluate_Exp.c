#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 100


int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '^') {
        return 3;
    }
    return 0;
}


int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int) pow(a, b);
        default: return 0;
    }
}


int evaluate(char* tokens) {
    int i = 0;
    int values[MAX_SIZE];
    int top_v = -1;
    char ops[MAX_SIZE];
    int top_o = -1;

    while (tokens[i] != '\0') {
        if (tokens[i] == ' ') {
            i++;
            continue;
        }
        else if (tokens[i] == '(') {
            ops[++top_o] = '(';
        }
        else if (isdigit(tokens[i])) {
            int val = 0;
            while (isdigit(tokens[i])) {
                val = val * 10 + (tokens[i] - '0');
                i++;
            }
            values[++top_v] = val;
            i--;
        }
        else if (tokens[i] == ')') {
            while (top_o >= 0 && ops[top_o] != '(') {
                int val2 = values[top_v--];
                int val1 = values[top_v--];
                char op = ops[top_o--];
                values[++top_v] = applyOp(val1, val2, op);
            }
            top_o--;
        }
        else {
            while (top_o >= 0 && precedence(ops[top_o]) >= precedence(tokens[i])) {
                int val2 = values[top_v--];
                int val1 = values[top_v--];
                char op = ops[top_o--];
                values[++top_v] = applyOp(val1, val2, op);
            }
            ops[++top_o] = tokens[i];
        }
        i++;
    }

    while (top_o >= 0) {
        int val2 = values[top_v--];
        int val1 = values[top_v--];
        char op = ops[top_o--];
        values[++top_v] = applyOp(val1, val2, op);
    }

    return values[top_v];
}


int main() {
    char expression[MAX_SIZE];
    printf("Enter an expression: ");
    fgets(expression, MAX_SIZE, stdin);

    // Remove newline character at the end of the input
    expression[strcspn(expression, "\n")] = '\0';

    int result = evaluate(expression);
    printf("Result of expression %s is %d\n", expression, result);
    return 0;
}
