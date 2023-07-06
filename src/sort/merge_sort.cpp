void merge(int *a, int mid, int len) {
    int i, j, k;
    int n1 = mid;
    int n2 = len - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = a[i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = a[mid + j];
    }

    i = 0;
    j = 0;
    k = 0;

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }

    while (i < n1) {
        a[k++] = L[i++];
    }

    while (j < n2) {
        a[k++] = R[j++];
    }
}

void merge_sort(int* a, int len) {
    if (len > 1) {
        int mid = len / 2;
        merge_sort(a, mid);
        merge_sort(a + mid, len - mid);
        merge(a, mid, len);
    }
}