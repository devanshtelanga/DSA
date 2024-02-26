# include <stdio.h>
# include <string.h>

int top_op = -1, top_rslt = -1;

int is_aplha_num(char string) {
    if (string >= 65 && string <= 90) {
        return 1;
    }
    else if (string >= 97 && string <= 122) {
        return 1;
    }   
    else if (string >= 48 && string <= 57) {
        return 1;
    }
    else {
        return 0;
    }
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

char pop(char operator[]) {
    char value = operator[top_op];
    top_op--;
    return value;
}

int isempty(int top) {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char expression[] = "((A+B)-C*(D/E))+F";
    int lenght = strlen(expression);

    char operators[lenght], result[lenght];
    memset(result, 0, sizeof(result) );
    memset(operators, 0, sizeof(operators) );
    
    for (int i = 0; i < lenght; i++) {
        // printf("%c\t", ex çpression[i]);
        if (is_aplha_num(expression[i])) {
            top_rslt++;
            result[top_rslt] = expression[i];
            // puts(result);      yha tk shi h
        }
        else {
            if (isempty(top_op)) {
                top_op++;
                operators[top_op] = expression[i];
            }
            else {
                if (expression[i] == ')') {
                    while (operators[top_op] != '(') {
                        char value = pop(operators);
                        top_rslt++;
                        result[top_rslt] = value;
                    }
                    pop(operators);
                    continue;
                }
                if (operators[top_op] == '(') {
                    top_op++;
                    operators[top_op] = expression[i];
                    continue;
                }
                int current = precedence(expression[i]);
                int exist = precedence(operators[top_op]);
                if (current > exist) {
                    top_op++;
                    operators[top_op] = expression[i];
                }
                else {
                    while (current <= exist) {
                        char value = pop(operators);
                        top_rslt++;
                        result[top_rslt] = value;
                        exist = precedence(operators[top_op]);
                        if (top_op == -1) {
                            break;
                        }
                    }
                    top_op++;
                    operators[top_op] = expression[i];
                }}}
        // printf("%s\t%s\n", operators, result);
    }
    if (!isempty(top_op)) {
        while (top_op != -1) {
            char value = pop(operators);
            top_rslt++;
            result[top_rslt] = value;}    }  
    printf("\n%s\n", result);
}