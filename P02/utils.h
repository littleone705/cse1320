#ifndef UTILS_H_
#define UTILS_H_

#define MAX_MONSTERS 32
#define MAX_LEN 128

#define FILTER_NAME 1
#define FILTER_HP 2
#define FILTER_AC 3
#define FILTER_STATS 4
#define EXIT_CHOICE 5

typedef struct {
    char name[MAX_LEN];
    char type[MAX_LEN];
    int hp;
    int ac;
    int str;
    int dex;
    int con;
} monster_s;

void swap_int(int, int);
void trim(char *);
void parse_monster(monster_s *monster, char *csv_line);
int load_monster_csv(monster_s **monsters_ptr, FILE *fp);

//added for probelm 4
void print_monsters(monster_s **monsters, int num_monsters);

//added for problem 5
int compare_abc(const void *elem1, const void *elem2);
int compare_hp(const void *elem1, const void *elem2);
int compare_ac(const void *elem1, const void *elem2);
int compare_stats(const void *elem1, const void *elem2);

#endif
