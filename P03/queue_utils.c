#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "queue_utils.h"

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

char *newPlayer(char *str){
    
    char *hold = calloc(strlen(str) + 1, sizeof(char));
    strcpy(hold, str);

    return hold;
}

int roll(player_s **players, int num){
    int option = 0;
    if(((*players+0)->roll) == 0){
        for(int i = 0; i < num; i++){
            ((*players+i)->roll) = rand()%20+1;
        }
    } else {
        printf("You are about to re-roll! Are you sure?\n");
        printf("1. Yes\n2. No\n");
        scanf("%d", &option);
        if (option == 1){
            for(int i = 0; i < num; i++){
                ((*players+i)->roll) = rand()%20+1;
            }
        }
    }
    return option;
}

int compare_roll(const void *elem1, const void *elem2){
    player_s *a = (player_s *) elem1;
    player_s *b = (player_s *) elem2;
    return b->roll - a->roll;
}

void enqueue(int **queue, int *size, int i){
    *queue = realloc(*queue, (*size + 1) * sizeof(int));

    for (int y = *size; y > 0; y--){
        (*queue)[y] = (*queue)[y-1];
    }

    (*queue)[0] = i;

    (*size)++;
}

int dequeue(int **queue, int *size){
    if (size == 0){
        return 0;
    }

    (*size)--;

    *queue = realloc(*queue, *size * sizeof(int));

    return (*queue)[*size];
}

void peek(int *queue, int size, player_s **players){
    printf("%s is on deck.\n", (*players+(queue[size - 1]))->name);
}

void print(int *queue, int size, player_s **players, int event){
    if (event == 4){
        for (int i = size - 1; i >= 0; i--){
            printf("%d: %d. %s\n", queue, (*players+(queue[i]))->position, (*players+(queue[i]))->name);
        }
    } else if (event == 3){
        printf("%s's Turn!\n", (*players+(queue[size - 1]))->name);
    } else if (event == 1){
        printf("Intial Roll has not occured!\n");
        return;
    }
}