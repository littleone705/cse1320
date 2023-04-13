#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"


void swap_int(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

void parse_monster(monster_s *monster, char *csv_line) {
    char *token = strtok(csv_line, ",");

    int attr = 0;

    while (token != NULL) {
        switch(attr) {
            case 0:
                strcpy(monster->name, token);
                break;
            case 1:
                strcpy(monster->type, token);
                break;
            case 2:
                monster->hp = atoi(token);
                break;
            case 3:
                monster->ac = atoi(token);
                break;
            case 4:
                monster->str = atoi(token);
                break;
            case 5:
                monster->dex = atoi(token);
                break;
            case 6:
                monster->con = atoi(token);
                break;
        }

        attr++;
        token = strtok(NULL, ",");
    }
}

/*
 * Loads all monsters from a CSV file into memory.
 * Allocates memory pointed to by `*monsters_ptr`
 *
 * Args
 * ----
 *  monster_s **monsters_ptr - A double pointer to `monster_s`.
 *      Dereferencing this once (`*monsters_ptr`) returns the value to where the
 *      allocated memory should be stored. That is, you should assign the result
 *      of an allocation call to `*monsters_ptr`.
 *
 *  FILE *fp - A file pointer representing an open CSV file.
 *
 * Return
 * ------
 *  Returns an `int` representing the number of monsters loaded.
 */
int load_monster_csv(monster_s **monsters_ptr, FILE *fp) {
    char buffer[MAX_LEN] = { 0 }; 
    int num_read = 0;

    *monsters_ptr = malloc(((num_read+1)*100) * sizeof(monster_s*));
        if (monsters_ptr == NULL){
            printf("Failed to allocate\n");
            return -1;
        }

    while (fgets(buffer, MAX_LEN, fp)) {
        trim(buffer);

        parse_monster(*monsters_ptr+num_read, buffer);
        num_read++;
        *monsters_ptr = realloc(*monsters_ptr, ((num_read+1)*100) * sizeof(monster_s*));
    }
    
    return num_read;
}

void print_monsters(monster_s **monsters, int num_monsters){
    int len = 0; //value holder
    int len_name = 0; //Longest Name
    int len_type = 0; //Longest type
    int len_hp = 0; //Longest HP
    int len_ac = 0; //Longest AC
    int len_str = 0; //Longest STR
    int len_dex = 0; //Longest DEX
    int len_con = 0; //Longest CON

    for(int i = 0; i < num_monsters; i++){ //Find the length of the longest name
        len = strlen((*monsters+i)->name); 
        if (len >= len_name){
            len_name = len;
        }
    }
    if (len_name < 4){ //If the longest name is less than 4 it sets the length to 4 for formatting
        len_name = 4;
    }

    len = 0;
    for(int i = 0; i < num_monsters; i++){ //Find the length of the longest type
        len = strlen((*monsters+i)->type);
        if (len >= len_type){
            len_type = len;
        }
    }
    if (len_type < 4){ //If the longest type is less than 4 it sets the length to 4 for formatting
        len_type = 4;
    }
    
    len = 0;
    for(int i = 0; i < num_monsters; i++){ //Find the length of the longest hp
        len = floor(log10(abs((*monsters+i)->hp))) + 1;
        if (len >= len_hp){
            len_hp = len;
        }
    }
    if (len_hp < 2){ //If the longest hp is less than 2 it sets the length to 2 for formatting
        len_hp = 2;
    }

    len = 0;
    for(int i = 0; i < num_monsters; i++){ //Find the length of the longest ac
        len = floor(log10(abs((*monsters+i)->ac))) + 1;
        if (len >= len_ac){
            len_ac = len;
        }
    }
    if (len_ac < 2){ //If the longest ac is less than 2 it sets the length to 2 for formatting
        len_ac = 2;
    }

    len = 0;
    for(int i = 0; i < num_monsters; i++){ //Find the length of the longest str
        len = floor(log10(abs((*monsters+i)->str))) + 1;
        if (len >= len_str){
            len_str = len;
        }
    }
    if (len_str < 3){ //If the longest str is less than 3 it sets the length to 3 for formatting
        len_str = 3;
    }

    len = 0;
    for(int i = 0; i < num_monsters; i++){ //Find the length of the longest dex
        len = floor(log10(abs((*monsters+i)->dex))) + 1;
        if (len >= len_dex){
            len_dex = len;
        }
    }
    if (len_dex < 3){ //If the longest dex is less than 3 it sets the length to 3 for formatting
        len_dex = 3;
    }

    len = 0;
    for(int i = 0; i < num_monsters; i++){ //Find the length of the longest con
        len = floor(log10(abs((*monsters+i)->con))) + 1;
        if (len >= len_con){
            len_con = len;
        }
    }
    if (len_con < 3){ //If the longest con is less than 3 it sets the length to 3 for formatting
        len_con = 3;
    }

    //this will print the title line
    char *title[] = {"NAME","TYPE","HP","AC","STR","DEX","CON"};
    printf("| %-*s |", len_name, title[0]);

    printf(" %-*s |", len_type, title[1]);

    printf(" %-*s |", len_hp, title[2]);
  
    printf(" %-*s |", len_ac, title[3]);

    printf(" %-*s |", len_str, title[4]);

    printf(" %-*s |", len_dex, title[5]);

    printf(" %-*s |\n", len_con, title[6]);

    //This will print the dashes 
     printf("| ");
    for(int i = 0; i < len_name; i++){
        printf("-");
    }
    printf(" | ");
    for(int i = 0; i < len_type; i++){
        printf("-");
    }
    printf(" | ");
    for(int i = 0; i < len_hp; i++){
        printf("-");
    }
    printf(" | ");
    for(int i = 0; i < len_ac; i++){
        printf("-");
    }
    printf(" | ");
    for(int i = 0; i < len_str; i++){
        printf("-");
    }
    printf(" | ");
    for(int i = 0; i < len_dex; i++){
        printf("-");
    }
    printf(" | ");
    for(int i = 0; i < len_con; i++){
        printf("-");
    }
    printf(" |\n");

    for(int i = 0; i < num_monsters; i++){
        // Monster name
        printf("| %-*s | ", len_name, (*monsters+i)->name);

        // Monster type
        printf("%-*s | ", len_type, (*monsters+i)->type);

        // Monster hp
        printf("%-*d | ", len_hp, (*monsters+i)->hp);

        // Monster ac
        printf("%-*d | ", len_ac, (*monsters+i)->ac);

        // Monster str
        printf("%-*d | ", len_str, (*monsters+i)->str);

        // Monster dex
        printf("%-*d | ", len_dex, (*monsters+i)->dex);

        // Monster con
        printf("%-*d |\n", len_con, (*monsters+i)->con);
    } 
    printf("\n");
}

int compare_abc(const void* elem1, const void* elem2){
    monster_s *a = (monster_s*) elem1;
    monster_s *b = (monster_s*) elem2;
    return strcmp(a->name, b->name);
}

int compare_hp(const void *elem1, const void *elem2){
    monster_s *a = (monster_s *) elem1;
    monster_s *b = (monster_s *) elem2;
    return b->hp - a->hp;
}

int compare_ac(const void *elem1, const void *elem2){
    monster_s *a = (monster_s *) elem1;
    monster_s *b = (monster_s *) elem2;
    return b->ac - a->ac;
}

int compare_stats(const void *elem1, const void *elem2){
    monster_s *a = (monster_s *) elem1;
    monster_s *b = (monster_s *) elem2;

    int sumA = 0;
    int sumB = 0;
    //find the sum of the stats
    sumA = a->str + a->dex + a->con; 
    sumB = b->str + b->dex + b->con;

    if (sumA < sumB){
        return b->str - a->str;
    }
    return 0;
}