#define MAX_LEN 128

typedef struct {
    char **func;
    int num;
} mystack_t;

void trim(char *str);
char *read_string(char buffer[]);
void push(char *val, mystack_t *stack);
void pop(mystack_t *stack);
void print_stack(mystack_t *stack, int dent);