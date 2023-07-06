#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

// generate random int array
void random_array(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] = rand() % 99 - 50;
    }
}

// print array
void print_array(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// check array is sorted
bool is_sorted(int *a, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (a[i] > a[i+1])
        {
            return false;
        }
    }
    return true;
}

// calculate sort time
double sort_time(void (*sort)(int *, int), int *a, int len)
{
    clock_t start, end;
    start = clock();
    sort(a, len);
    end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

void exec_sort(const char* sort_method, void (*sort)(int *, int), int *a, int len)
{
    random_array(a, len);
    printf("%s sort time: %f\n", sort_method, sort_time(sort, a, len));
    printf("%s\n", is_sorted(a, len) ? "sorted" : "not sorted");
}

int main(int argc, char const *argv[])
{

    if (argc < 3)
    {
        printf("usage: %s <sort_method> <array_length>\n", argv[0]);
        return 1;
    }

    const char *sort_method = argv[1];
    int len = atoi(argv[2]);
    int a[len];


    switch (sort_method[0])
    {
        case 'i':
            exec_sort("insertion", insertion_sort, a, len);
            break;
        case 'm':
            exec_sort("merge", merge_sort, a, len);
            break;
        case 'b':
            exec_sort("bubble", bubble_sort, a, len);
            break;
        case 's':
            exec_sort("selection", selection_sort, a, len);
            break;
        case 'q':
            printf("quick sort\n");
            break;
        case 'a':
            exec_sort("insertion", insertion_sort, a, len);
            exec_sort("merge", merge_sort, a, len);
            exec_sort("bubble", bubble_sort, a, len);
            exec_sort("selection", selection_sort, a, len);
            break;
        default:
            printf("unknown sort method\n");
            break;
    }
    // print_array(a, len);

    return 0;
}
