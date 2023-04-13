#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "problem1.h"

int main(){   
    char *strings[] = {
        "string1",
        "string2",
        "string3",
        "string4"
    };
    char *key = malloc(20);
    char *key_found;
    int num_words = 4;

    printf("Enter a search key: ");
    scanf("%s", key);

    key_found = find_word(strings, key, num_words); //calls function

    if (key_found != NULL){ // prints the string found if it exist
        printf("Found \"%s\"\n", key_found);
    } else {
        printf("Does not exist\n");
    }

    return 0;
}