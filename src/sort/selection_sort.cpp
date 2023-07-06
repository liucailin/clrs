void selection_sort(int* a, int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i+1; j < len; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        
        int tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}