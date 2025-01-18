#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char* s) {
    char roman_symbols[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int values[] = {1, 5, 10, 50, 100, 500, 1000};
    int i, j, value, number, next_number, int_number = 0;

    for(i=0; i<strlen(s); i++){
        for(j=0; j<7; j++){
            if (s[i] == roman_symbols[j])
                number = values[j];
            if (s[i+1] == roman_symbols[j])
                next_number = values[j];

        }
        if (number >= next_number){
            int_number = int_number + number ;
        }
        else{
            int_number = int_number + (next_number - number);
            i++;
        }
        number = 0;
        next_number = 0;
    }
    return int_number;
}

int main(){
    char roman_number[20];
    int int_number;

    printf("Please type a roman number: ");
    scanf("%s", roman_number);

    int_number = romanToInt(roman_number);
    printf("The integer value is: %d\n", int_number);
}