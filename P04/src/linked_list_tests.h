#define MAX_LEN 128

typedef struct node Node;
struct node {
    void *data;
    Node *next;
};

void linked_list_insert_sequential_start(int num_samples, int sample_size);
void linked_list_insert_sequential_end(int num_samples, int sample_size);
void linked_list_insert_random(int num_samples, int sample_size);