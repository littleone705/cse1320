#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int main(int argc, char *argv[]){
    //char buffer[MAX_LEN] = { 0 }; 
    int num_read = 0;
    int max_length = 0;
    monster_s *monsters[num_read];

    if (argc != 2){
        printf("Incorrect amount of arguments\n");
        printf("Usage: %s filename\n", argv[0]);
    }
    else{
        FILE *fp = fopen(argv[1], "r");

        if(fp == NULL){
            printf("Cannot open the file\n");
            return 1;
        }
        else {
            printf("File succsessfully opened\n\n");
        }

        num_read = load_monster_csv(monsters, fp);

        print_monsters(monsters, num_read);

        fclose(fp);
    }
    free(*monsters);
    return 0;
}