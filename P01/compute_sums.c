/*firts n - 1 then start checking if it divisible by a or b  
    if so needs to be summed together*/

#include <stdio.h>

int main(){

    int num_n = 0,
        num_a = 0,
        num_b = 0,
        sum = 0;

    // Prompt user to enter 3 numbers
    printf("Enter three integers: ");
    scanf("%d%d%d", &num_n, &num_a, &num_b);
    
    //Check every number < n to see if they are divisable by a or b
    for(int i = 0; i < num_n; i++){
        if(i % num_a == 0){
            sum = sum + i;
        } else if(i % num_b == 0){
            sum = sum + i;
        }
    }

    //output the sum
    printf("%d\n", sum);


    return 0;
}