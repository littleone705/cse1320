#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *elem1, const void *elem2){
    int a = *(int*)elem1;
    int b = *(int*)elem2;

    //return (a - b); An initial test to make sure i was using qsort correct

    if ((a&1) && (b&1)){ // If both odd put greater of the two firts
        return (a-b);
    }

    if(!(a&1) && !(b&1)){ // If both even put greater of the two firts
        return (a-b);
    }

    if(!(a&1)){ // If a if even put b first
        return a;
    }

    return -a; // if a is odd put a first
}

int main(){
    int num_int = 10;
    int num_array[num_int];

    //prompting for and reading in the values for the 10 ints
    printf("Enter 10 values: ");
    scanf("%d %d %d %d %d %d %d %d %d %d",
           &num_array[0], &num_array[1], &num_array[2], &num_array[3], &num_array[4],
           &num_array[5], &num_array[6], &num_array[7], &num_array[8], &num_array[9]);

    //prints the set of numbers before being sorted
    for(int i = 0; i < num_int; i++){
        printf("%d ", num_array[i]);
    }
    printf("\n"); //new line

    //runs qsort using the compare_int function in order to sort he array in aceding order with odd num first
    qsort(num_array, num_int, sizeof(num_int), compare_int);

    //prints the set of numbers after being sorted.
    for(int i = 0; i < num_int; i++){
        printf("%d ", num_array[i]);
    }
    printf("\n");

    return 0;
}