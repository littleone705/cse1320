#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "queue_utils.h"

void menu(){
    printf("1. Add Player\n");
    printf("2. Roll Initiative\n");
    printf("3. Next Turn\n");
    printf("4. View Current Order\n");
    printf("5. End Game\n");
}

int main(){
    int num_players = 0;
    player_s *players[num_players];
    char str[MAX_LEN] = { 0 };

    //Queue stuff
    int *queue = NULL;
    int size = 0;

    *players = malloc(((num_players+1)*100) * sizeof(player_s*));

    int check = 2;
    int count = 0;
    int event = 0;

    int choice = 0;
    while(choice != 5){
        menu();
        printf(">");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter a player name: ");
                scanf("%s", str);
                trim(str);

                ((*players+num_players)->name) = newPlayer(str);
                ((*players+num_players)->position) = (num_players + 1);
                num_players++;
                event = 1;
                break;
            case 2:
                check = roll(players, num_players);
                if (check == 0 || check == 1){
                    qsort(*players, num_players, sizeof(player_s), compare_roll);
                    for(int i = 0; i < num_players; i++){
                        printf("%s rolled a %d.\n", (*players+i)->name, (*players+i)->roll);
                        ((*players+i)->position) = (i + 1);
                        
                        if(check == 0){
                            enqueue(&queue, &size, i);
                        } else if (check == 1){ //reroll resets queue
                            dequeue(&queue, &size);
                            enqueue(&queue, &size, i);
                        }
                    }
                }
                break;
            case 3:
                //Next Turn
                event = 3;
                if (count < num_players){
                    print(queue, size, players, event);
                    dequeue(&queue, &size);
                    enqueue(&queue, &size, count);
                    peek(queue, size, players);
                    printf("\n");
                } else {
                    count = 0;
                    print(queue, size, players, event);
                    dequeue(&queue, &size);
                    enqueue(&queue, &size, count);
                    peek(queue, size, players);
                    printf("\n");
                }
                count++;
                break;
            case 4:
                //View Current Order
                event = 4;
                print(queue, size, players, event);
                printf("\n");
                break;
            case 5:
                break;
        }
    }
    free(*players);
    free(queue);
    return 0;
}