#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

void show_menu() {
    printf("--------------------------\n");
    printf("|      MONSTER LIST      |\n");
    printf("--------------------------\n");
    printf("| 1. Filter by name      |\n");
    printf("| 2. Filter by HP        |\n");
    printf("| 3. Filter by AC        |\n");
    printf("| 4. Filter by stats     |\n");
    printf("| 5. Exit                |\n");
    printf("--------------------------\n");
}

int main(int argc, char *argv[]) {
    int num_read = 0;
    monster_s *monsters[num_read];

    if (argc != 2){
        printf("Incorrect amount of arguments\n");
        printf("Usage: %s filename\n", argv[0]);
        return 1;
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

        if (num_read == 0){
            return 1;
        }

        // Run menu loop
        int choice = 0;
        while (choice != EXIT_CHOICE) {
            show_menu();
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    //Filter by name and print
                    qsort(*monsters, num_read, sizeof(monster_s), compare_abc);
                    print_monsters(monsters, num_read);
                    break;
                case 2:
                    //Filter by HP and print
                    qsort(*monsters, num_read, sizeof(monster_s), compare_hp);
                    print_monsters(monsters, num_read);
                    break;
                case 3:
                    //Filter by AC and print
                    qsort(*monsters, num_read, sizeof(monster_s), compare_ac);
                    print_monsters(monsters, num_read);
                    break;
                case 4:
                    //Filter by stats and print
                    qsort(*monsters, num_read, sizeof(monster_s), compare_stats);
                    print_monsters(monsters, num_read);
                    break;
                case 5:
                    if (fp) {
                        fclose(fp);
                    }
                    break;
            }
        }
    }
    free(*monsters);
    return 0;
}


