#include <stdio.h>
#include "handlers.h"

int main()
{
    int numbers[ARRAY_SIZE];

    printf("Generating conditioned random array...\n");
    generate_conditioned_random_array(numbers, ARRAY_SIZE);
    print_array(numbers, ARRAY_SIZE);

    printf("Sorted array:\n");
    sort_array(numbers, ARRAY_SIZE);
    print_array(numbers, ARRAY_SIZE);

    return 0;
}