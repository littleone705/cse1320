#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stack_utils.h"

int main(int argc, char *argv[]){
    mystack_t *stack = calloc(1, sizeof(mystack_t));

    if (argc != 2){ // Check to make sure correct number of arguments are present
        printf("Incorrect amount of arguments\n");
        printf("Usage: %s filename\n", argv[0]);
    }
    else{
        FILE *fp = fopen(argv[1], "r"); // Attempint to open file

        if(fp == NULL){ //If invalid file is given
            printf("Invalid log file.\n");
            return 1;
        }
        else {
            char buffer[MAX_LEN] = { 0 };
            int dent = 0; // To keep track of indentation

            while(fgets(buffer,MAX_LEN,fp)){
                char *str = read_string(buffer); // Reads the data from the file

                if(strcasestr(str, "()")){ // If its a function
                    push(str, stack);
                    print_stack(stack, dent);
                    dent++;
                } else if(strcasestr(str, "return")){ //If its a return
                    push(str, stack);
                    pop(stack);
                    dent--;
                }
            }
        }
        fclose(fp);
    }
    free(stack);
    return 0;
}