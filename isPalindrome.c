#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    int i, n;
    char str_number[20];
    bool equal = true;

    sprintf(str_number, "%d", x);

    n = strlen(str_number) - 1;
    for (i = 0; i < n; i++) {
        if (str_number[i] != str_number[n]) {
            equal = false;
            break;
        }
        n--;
    }

    return equal;
}

int main() {
    int number;

    printf("Type an integer number: ");
    scanf("%d", &number);

    if (isPalindrome(number)) {
        printf("The number %d is a palindrome.\n", number);
    } else {
        printf("The number %d is not a palindrome.\n", number);
    }

    return 0;
}
