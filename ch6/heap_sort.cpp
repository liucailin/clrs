#include "../util/test_sort.h"

void maxheapify(int *, int, int);
void buildmaxheap(int *, int);
void heapsort(int *, int);
void exchange(int *, int, int);

int main(int argc, char const *argv[])
{
    test_sort(heapsort);
    return 0;
}

void heapsort(int *a, int len)
{
    buildmaxheap(a, len);
    int heapsize = len;
    for (int i = len - 1; i > 0; i--) {
        exchange(a, 0, i);
        maxheapify(a, --heapsize, 0);
    }
}

void buildmaxheap(int *a, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--) {
        maxheapify(a, len, i);
    }
}

void maxheapify(int *a, int heapsize, int i)
{
    int left = 2 * i + 1;
    int right = left + 1;
    int largest = i;

    if (left < heapsize && a[left] > a[i])
        largest = left;

    if (right < heapsize && a[right] > a[largest])
        largest = right;
    
    if (largest != i) {
        exchange(a, i, largest);
        maxheapify(a, heapsize, largest);
    }
}


void exchange(int *a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}