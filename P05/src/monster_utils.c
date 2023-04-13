#include "monster_utils.h"
#include "utils.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


/*
 * Frees allocated memory of a monster.
 *
 */
void free_monster(void *monster) {
    //Cast the `void *monster` to the proper type and free
    //       all struct members that have allocated memory.
    monster_s *m = monster;
    free(m->name);
    free(m->type);
    free(m);
}

/*
 * Prints the attributes of a single monster object.
 */
void print_monster(void *monster) {
    //Cast the `void *monster` to the proper type and print
    //       the attributes.
    monster_s *m = monster;
    printf("%s (%s) %d HP, %d AC, %d STR, %d DEX, %d CON", m->name, m->type, m->hp, m->ac, m->str, m->dex, m->con);
}

/*
 * Creates a monster based on user input.
 */
monster_s *create_monster() {
    char buffer[BUF_SIZE] = { 0 };

    monster_s *m = calloc(1, sizeof(monster_s));

    printf("Enter a name: ");
    m->name = get_string();

    printf("Enter a type: ");
    m->type = get_string();

    printf("Enter HP: ");
    scanf("%d", &m->hp);

    printf("Enter AC: ");
    scanf("%d", &m->ac);

    printf("Enter STR: ");
    scanf("%d", &m->str);

    printf("Enter DEX: ");
    scanf("%d", &m->dex);

    printf("Enter CON: ");
    scanf("%d", &m->con);

    return m;
}

/*
 * Parses a line of CSV containing monster stats.
 */
monster_s *parse_monster(char *csv_line) {
    char *token = strtok(csv_line, ",");
    int attr = 0;

    monster_s *monster = calloc(1, sizeof(monster_s));

    while (token != NULL) {
        switch(attr) {
            case 0:
                monster->name = malloc(strlen(token) +1);
                strcpy(monster->name, token);
                break;
            case 1:
                monster->type = malloc(strlen(token) +1);
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

    return monster;
}

/*
 * Load monster data from a CSV file.
 *
 * Returns an `array_s` object containing the monsters loaded.
 */
array_s load_monsters_csv(FILE *fp) {
    array_s monsters = { 0 };

    // Complete this function.
    char buffer[128] = { 0 };
    while(fgets(buffer, 128, fp)){
        trim(buffer);

        monster_s *m = parse_monster(buffer);
        push(m, &monsters);
    }

    return monsters;
}
