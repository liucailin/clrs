void bubble_sort(int* a, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; j > i; j--) {
            if (a[j] < a[j-1]) {
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
}