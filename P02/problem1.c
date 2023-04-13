#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "problem1.h"

char * find_word(char *words[], char *key, int num_words){
    char *key_found = NULL; //The pointer-to-char that returns the first string that matches the key word
   
    int j = 0; //counter
    for (int i = 0; i < num_words; i++){ //loop that looks there every string in the array
        if (strcasestr(words[i], key)){
             j = i + 1;
             key_found = words[i];
             return key_found;
        }
    }

    if(j == 0){ // in the event the key cannot be found in array of words
        return key_found;
        }

    return 0;
}