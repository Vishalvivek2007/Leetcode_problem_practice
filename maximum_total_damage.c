
void merge(ll *arr1, ll *arr2, ll *arr, ll len) {
    ll middle = len / 2;
    ll i = 0, l = 0, r = 0;

    while (l < middle && r < len - middle) {
        if (arr1[l] < arr2[r]) {
            arr[i++] = arr1[l++];
        } else {
            arr[i++] = arr2[r++];
        }
    }
    while (l < middle) {
        arr[i++] = arr1[l++];
    }
    while (r < len - middle) {
        arr[i++] = arr2[r++];
    }
}

void mergesort(ll *arr, ll len) {
    if (len <= 1) {
        return;
    }
    ll middle = len / 2;

    ll *left = (ll *)malloc(middle * sizeof(ll));
    ll *right = (ll *)malloc((len - middle) * sizeof(ll));

    if (left == NULL || right == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (ll i = 0; i < middle; i++) {
        left[i] = arr[i];
    }
    for (ll i = middle; i < len; i++) {
        right[i - middle] = arr[i];
    }

    mergesort(left, middle);
    mergesort(right, len - middle);

    merge(left, right, arr, len);

    free(left);
    free(right);
}

long long maximumTotalDamage(int* magic, int len) {
    
}