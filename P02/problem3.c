#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int main(int argc, char *argv[]) {
    // TODO: Verify command line arguments.
    // TODO: Attempt to open a CSV file given by the command line arguments.
    // TODO: Load all the data with `load_monsters_csv`.
    // TODO: Print the data to verify that it was loaded.
    // TODO: Be sure to free any allocated memory.
    int a = 0;
    monster_s *monsters[a];

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
            printf("File succsessfully opened\n");
        }

        a = load_monster_csv(monsters, fp);

        fclose(fp);

        for(int i = 0; i < a; i++){
            printf("%s (%s), %d HP, %d AC, %d STR, %d DEX, %d CON\n", 
                  (*monsters+i)->name, (*monsters+i)->type, (*monsters+i)->hp, (*monsters+i)->ac,
                  (*monsters+i)->str, (*monsters+i)->dex, (*monsters+i)->con);
        }
        free(*monsters);
    }

    return 0;
}
