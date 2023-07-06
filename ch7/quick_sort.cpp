#include "../util/test_sort.h"

int partition(int *, int, int);
void exchange(int *, int, int);

void quicksort(int *a, int p, int r)
{
    if (p < r) {
        int q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

void _quicksort(int *a, int len)
{
    quicksort(a, 0, len - 1);
}

int main(int argc, char const *argv[])
{
    test_sort(_quicksort);
    return 0;
}

int partition(int *a, int p, int r)
{
    int x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (a[j] <= x)
            exchange(a, j, ++i);
    }
    exchange(a, r, i+1);
    return i+1;
}

void exchange(int *a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}