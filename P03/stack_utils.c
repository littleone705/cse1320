#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "stack_utils.h"

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

char *read_string(char buffer[]){
    trim(buffer);

    char *str = calloc(strlen(buffer) + 1, sizeof(char));
    strcpy(str, buffer);

    return str;
}

void push(char *val, mystack_t *stack){
    stack->func = realloc(stack->func, (stack->num + 1) * sizeof(void *));
    stack->func[stack->num++] = val;
}

void pop(mystack_t *stack){
    char *str = stack->func[stack->num - 1];
    stack->func = realloc(stack->func, --stack->num * sizeof(void *));

    free(str);
}

void print_stack(mystack_t *stack, int dent){
    char space = ' ';
    if (dent > 0){ // If indent is needed
        for(int i = 0; i < dent; i++){
            printf("%-4c", space);
        }
        printf("%s\n", stack->func[stack->num - 1]);
    } else {
        printf("%s\n", stack->func[stack->num - 1]);
    }
}