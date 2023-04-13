#include "monster_utils.h"
#include "hash_map_utils.h"
#include "utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_menu() {
    printf("1. Add Monster\n");
    printf("2. Import CSV File\n");
    printf("3. Search\n");
    printf("4. Print Map\n");
    printf("5. Exit\n");
}

//Create function to create an array of hash_element_t based on unique entries in array.
void add_monsters(hash_map_t *map, array_s monsters) {
    // Loop through `monsters` and check which of them are unique using `search`
    // For each unique monster, place it in a `hash_element_t` object using the monster's name as its key.
    // Add the array of `hash_element_t` objects to the hash map.
    int k = 0;
    int j = 0;

    array_s elements = {0}; 
    // Loop through `monsters` and check which of them are unique using `search`
    for (int i = 0; i < monsters.numel; i++){
        monster_s *monster = monsters.data[i];
        hash_element_t *elem = search(map, monster->name);

        if (elem) {
            free_monster(monster);
            j++;
        } else {
            elem = calloc(1, sizeof(hash_element_t));
            elem->key = strdup((monster->name));
            elem->value = monster;
            push(elem, &elements);
        }
        k = i;
    }
        printf("%d unique entries to be added (%d duplicates) out of %d\n", (k-j), k - (k-j), k);
        if (elements.numel != 0){
            bulk_insert(map, elements);
            printf("Import complete.\n");
        }
}

int main() {
    hash_map_t *map = calloc(1, sizeof(hash_map_t));
    char selection = 0;

    init_map(map, 4);

    while (selection != '5') {
        print_menu();
        printf("> ");
        scanf("%c", &selection);

        // Clear buffer if newline stuck.
        if (selection != '\n') while (getchar() != '\n');

        switch (selection) {
            case '1': {
                //Create a monster via `create_monster` and add it to the map.
                monster_s *m = create_monster();
                hash_element_t *elem = search(map, m->name);

                if(elem != NULL){
                    printf("%s already exist.\n", m->name);
                    free_monster(m);
                } else {
                    elem = calloc(1, sizeof(hash_element_t));
                    elem->key = strdup(m->name) ;
                    elem->value = m;
                    insert(map, elem);
                }
                break;
            }
            case '2':
                //Load a monsters via CSV.
                printf("Enter filename: ");
                char *file = get_string();

                FILE *fp = fopen(file, "r");

                if(fp == NULL){
                    printf("File does not exist!\n");
                } else {
                    array_s hold = load_monsters_csv(fp);
                    add_monsters(map, hold);
                }
                fclose(fp);

                break;
            case '3':
                //Prompt the user for a search key and then call `search`
                printf("Enter a key: ");
                char *key = get_string();

                hash_element_t *elem = search(map, key);
                if(elem != NULL){
                    print_monster(elem->value);
                    printf("\n");
                } else {
                    printf("%s not found.\n", key);
                }

                free(key);
                break;
            case '4':
                print_map(map, print_monster);
                break;
            case '5':
                printf("Good bye!\n");
                //Free all memory currently allocated.
                free_map(map, free_monster);
                break;
            default:
                printf("Invalid selection.\n");
        }
    }

    return 0;
}
