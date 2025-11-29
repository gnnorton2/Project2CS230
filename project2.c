//Project by Nathan & Brielle

#include <stdio.h>
#include <ctype.h>
#include <string.h>
void numConversion(char input) {
    printf("0b");
    int zeroes = 0;
    for (int i = 3; i >= 0; i--) { //only checking 4 bits
        char bit = (input >> i) & 1;
        printf("%d", bit);
    }
}

void charConversion(char input) {
    if (input < 'G') {
        char map = input + 9;
        for (int i = 3; i >= 0; i--) { //only checking 4 bits
            char bit = (map >> i) & 1;
            printf("%d", bit);
        }
    }
}

int main() {
    char input;

    printf("Please enter a character or single-digit integer or type X to exit: \n");
    scanf(" %c", &input);

    if (input == 'X') { //if exiting
       printf("Goodbye");
            return 0;
        }
    else if (input & (1 << 6)) { //checked 2nd MSB, bit 6 if set
        printf("%c is a letter: ", input);
        charConversion(input);
    }
    else {
        printf("%c is a num: ", input);
        numConversion(input);
    }

    return 0;
}