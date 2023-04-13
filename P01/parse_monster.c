/* */

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
 
    //Promping for the line of csv data
    printf("Enter a line of CSV: "); 
    fgets(line, MAX_STR, stdin);

    //printf("\n%s\n", line); Just a test to make sure the fgets is working right

    //Calling parse function
    num_monsters = parse_monster(names, types, hp, ac, str, dex, con, num_monsters, line);

    // Output the CSV line in the new format
    printf("%s (%s), %d HP, %d AC, %d STR, %d DEX, %d CON\n", names[0], types[0], hp[0], ac[0], str[0], dex[0], con[0]);

    return 0;
}