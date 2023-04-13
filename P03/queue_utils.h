#define MAX_LEN 128

/*typedef struct {

}*/

typedef struct {
    char *name;
    int roll;
    int position;
} player_s;

void trim(char *str);
char *newPlayer(char *str);
int roll(player_s **players, int num);
int compare_roll(const void *elem1, const void *elem2);
void enqueue(int **queue, int *size, int i);
int dequeue(int **queue, int *size);
void peek(int *queue, int size, player_s **players);
void print(int *queue, int size, player_s **players, int event);