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
    char array[MAX_STR]; 

    // Gets the information that will be sent to the write_monster function 
    num_monsters = read_monster(names, types, hp, ac, str, dex, con, num_monsters);

    printf("\nEnter a file name: "); // Prompts for File name
    scanf("%19s", array);

    //printf("Entered File Name: %s\n", array); Filename check 

    write_monster(names, types, hp, ac, str, dex, con, num_monsters, array);

    return 0;
}