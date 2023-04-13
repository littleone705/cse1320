#define MAX_MONSTERS 32
#define MAX_STR 64

void trim(char str[]);
int read_monster(char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters);
int write_monster(char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters,
    char array[MAX_STR]);
int parse_monster(char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters,
    char line[MAX_STR]); // Char array rep. line of csv.
int search_monsters(char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters,
    char search[MAX_STR]);