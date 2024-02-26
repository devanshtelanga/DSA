# include <stdio.h>
# include <string.h>
# include <ctype.h>

int top_op = -1, top_rslt = -1;

int isempty(int top) {
    if (top == -1) {
        return 1;
    }
    return 0;
}

int precedence(char string) {
    if (string == '^') {
        return 3;
    }
    else if (string == '*' || string == '/') {
        return 2;
    }
    else if (string == '+' || string == '-') {
        return 1;
    }
}

char pop(char operation[]) {
    char value = operation[top_op];
    top_op--;
    return value;
}

int main() {
    char expression[100];
    printf("Enter the Infix Expression :-   ");
    scanf("%s", expression);
    int lenght = strlen(expression);
    char operators[lenght], result[lenght];
    memset(operators, 0, sizeof(operators));
    memset(result, 0, sizeof(result));
                // Changing the Brackets.
    for (int i = lenght - 1; i >= 0; i--) {
        if (expression[i] == '(') {
            expression[i] = ')';
        }
        else if (expression[i] == ')') {
            expression[i] = '(';
        } 
    }
    
    for (int i = lenght - 1; i >= 0; i--) {
        // printf("%c\t", expression[i]);
        if (isalnum(expression[i])) {
            top_rslt++;
            result[top_rslt] = expression[i];
        }
        else {
            if (isempty(top_op)) {
                top_op++;
                operators[top_op] = expression[i];
            }
            else {
                if (operators[top_op] == '(') {
                    top_op++;
                    operators[top_op] = expression[i];
                    continue;
                }
                if (expression[i] == ')') {
                    while (operators[top_op] != '(') {
                        top_rslt++;
                        result[top_rslt] = pop(operators);
                    }
                    pop(operators);
                    continue;
                }
                int current = precedence(expression[i]);
                int exists = precedence(operators[top_op]);
                if (current > exists) {
                    top_op++;
                    operators[top_op] = expression[i];
                }
                else {
                    while (current <= exists) {
                        char value = pop(operators);
                        top_rslt++;
                        result[top_rslt] = value;
                        exists = precedence(operators[top_op]);
                        if (top_op == -1) {
                            break;
                        }
                    }
                    top_op++;
                    operators[top_op] = expression[i];
                }
            }
        }
        // printf("%s\t%s\n", operators, result);
    }
    // printf("\n\n%s", operators);
    if (!isempty(top_op)) {
        while (top_op != -1) {
            top_rslt++;
            result[top_rslt] = pop(operators);
        }
    }

    // printf("\n%s", result);
    printf("\nThe Prefix Expression is :-     %s\n", strrev(result));
    
}