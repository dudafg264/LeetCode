#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxDepth(char* s) {
    int i = 0, counter = 0, counter_max = 0;

    while (s[i] != '\0') {
        if (s[i] == '(') counter++;
        if (s[i] == ')') counter--;
        if (counter_max < counter) counter_max = counter;
        i++;
    }

    return counter_max;
}

int main() {
    char expression[50];
    int result;

    printf("Type the expression: ");
    scanf("%49s", expression);

    result = maxDepth(expression);

    printf("Maximum depth of nested parentheses: %d\n", result);

    return 0;
}
