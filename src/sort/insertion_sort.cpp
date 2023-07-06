void insertion_sort(int* a, int len) {
    for (int j = 1; j < len; j++) {
        int key = a[j];
        // insert a[j] into the sorted sequence a[0..j-1]
        int i = j-1;
        while (i >= 0 && key < a[i]) {
            a[i+1] = a[i];
            i--;
        }
        
        a[i+1] = key;
    }
}