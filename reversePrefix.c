#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* reversePrefix(char* word, char ch) {
    char* character = word;
    int i = 0, j, h = 0;

    while (word[i] != '\0' && word[i] != ch) {
        i++;
    }
    
    if (word[i] == '\0') {
        return strdup(word);
    }

    char* new_word = (char*)malloc(strlen(word) + 1);
    for(j = i+1; j > 0; j--) {
        new_word[h] = *(word + j -1);
        h++;
    }

    while (word[++i] != '\0'){
        new_word[h] = *(word + h);
        h++;
    }
    new_word[h] = '\0';

    return new_word;
}

int main() {
    char ch;
    char* word;

    word = (char*) malloc(10);
    if (word == NULL){
        exit(1);
    }

    printf("Please type the word you desire: ");
    scanf("%49s", word);
    getchar();

    printf("Now, type where do you want to reverse: ");
    scanf("%c", &ch);
    getchar();

    word = reversePrefix(word, ch);

    printf("Here is your new word: %s\n", word);

    free(word);
}