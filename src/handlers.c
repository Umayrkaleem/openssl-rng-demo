#include <stdio.h>
#include <openssl/rand.h>
#include "handlers.h"

static int is_valid_candidate(int candidate, int *arr, int index)
{
    for (int i = 0; i < index; i++)
    {
        if (abs(candidate - arr[i]) <= 1)
        {
            return 0; // Too close to existing value
        }
    }
    return 1;
}

void generate_conditioned_random_array(int *arr, int size)
{
    unsigned char byte;
    int i = 0;
    while (i < size)
    {
        if (RAND_bytes(&byte, 1) != 1)
        {
            fprintf(stderr, "OpenSSL random generation failed.\n");
            return;
        }

        if (byte >= 200)
            continue; // avoid modulo bias
        int candidate = byte % 100;

        if (is_valid_candidate(candidate, arr, i))
        {
            arr[i++] = candidate;
        }
    }
}

void sort_array(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void print_array(const int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}