#include <stdio.h>

#include "monster_utils.h"

int main(){
    char names[MAX_MONSTERS][MAX_STR] = { 0 };
    char types[MAX_MONSTERS][MAX_STR] = { 0 };
    int hp[MAX_MONSTERS] = { 0 };
    int ac[MAX_MONSTERS] = { 0 };
    int str[MAX_MONSTERS] = { 0 };
    int dex[MAX_MONSTERS] = { 0 };
    int con[MAX_MONSTERS] = { 0 };
    int num_monsters = 0;
    char line[MAX_STR];
    char search[MAX_STR];

    FILE *fp = fopen("monsters.csv", "r"); // Opens the file

    if(fp==NULL){ // In the event the file cannot be opened
        printf("Cannot open the file\n");
        return 1;
    }

    int count = 0;
    while(fgets(line, MAX_STR, fp) != NULL){
        //printf("%s\n", line);
        num_monsters = parse_monster(names, types, hp, ac, str, dex, con, num_monsters, line);
        count++;
    }

    fclose(fp); //closes file

    // Prompt for the user for a search term
    printf("Enter search term: ");
    fgets(search, MAX_STR, stdin);
    trim(search);
    
    //calls function search_monster
    search_monsters(names, types, hp, ac, str, dex, con, num_monsters, search);

    return 0;
}