#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "monster_utils.h"

void trim(char str[]) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

int read_monster(char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters) {

    if (num_monsters == MAX_MONSTERS) {
        return num_monsters;
    }

    printf("Enter a name: ");
    fgets(names[num_monsters], MAX_STR, stdin);
    trim(names[num_monsters]);

    printf("Enter a type: ");
    fgets(types[num_monsters], MAX_STR, stdin);
    trim(types[num_monsters]);

    printf("Enter HP: ");
    scanf("%d", &hp[num_monsters]);

    printf("Enter AC: ");
    scanf("%d", &ac[num_monsters]);

    printf("Enter STR: ");
    scanf("%d", &str[num_monsters]);

    printf("Enter DEX: ");
    scanf("%d", &dex[num_monsters]);

    printf("Enter CON: ");
    scanf("%d", &con[num_monsters]);

    return num_monsters + 1;
}

int write_monster(char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters,
    char array[MAX_STR]) {

    FILE *fp = fopen(array, "a"); // Opens the file
    
    if(fp==NULL){ // In the event the file cannot be opened
        printf("\nCannot open the file\n");
        return 1;
    }
    else
    { // Confirming that the file opened
        printf("\nFile Succsessfully Opened\n");
    }

    //Prints the info sent to the function into the now open file
    fprintf(fp, "%s,%s,%d,%d,%d,%d,%d\n", names[0], types[0], hp[0], ac[0], str[0], dex[0], con[0]);

    fclose(fp); // Closes file
    return 0;
 }

 int parse_monster(char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters,
    char line[MAX_STR]){ // Char array rep. line of csv
        
        char *token = strtok(line, ",");
        int count = 0;
        int i = 0; // To set where in the given array the token is saved
        while (token != NULL){
            switch(count){
                case 0: // Getting the name
                    strcpy(names[num_monsters], token);
                    break;
                case 1: // Getting the type
                    strcpy(types[num_monsters], token);
                    break;
                case 2: // Getting the HP
                    hp[num_monsters] = atoi(token);
                    break;
                case 3: // Getting the AC
                    ac[num_monsters] = atoi(token);
                    break;
                case 4: // Getting the STR
                    str[num_monsters] = atoi(token);
                    break;
                case 5: // Getting the DEX
                    dex[num_monsters] = atoi(token);
                    break;
                case 6: // Getting the CON
                    con[num_monsters] = atoi(token);
                    break;
                default:
                    break;
            }

            count++;
            token = strtok(NULL, ",");
        }
        
        return num_monsters + 1;
    }

int search_monsters(char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters,
    char search[MAX_STR]){

        int j = 0; //a counter
        for(int i = 0; i < num_monsters; i++){// for loop so that it goes through all of the names
            if (strcasestr(names[i], search)){ // searches for the instance of search paramenter in file
                printf("%s (%s), %d HP, %d AC, %d STR, %d DEX, %d CON\n", names[i], types[i], hp[i], ac[i], str[i], dex[i], con[i]);
                j++;
            }
        }

        if(j == 0){ // in the event the monster doesnt exist
                printf("No monsters found\n");
        }

        return 0;
    }
