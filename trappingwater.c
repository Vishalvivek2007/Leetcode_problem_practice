int trap(int* arr, int len) {
    if (len <= 2) return 0;

    int l = 0;
    int r = len - 1;

    int leftMax = 0;
    int rightMax = 0;

    int sum = 0;

    while (l < r) {

        if (arr[l] <= arr[r]) {

            if (arr[l] >= leftMax) {
                leftMax = arr[l];
            } else {
                sum += leftMax - arr[l];
            }

            l++;

        } else {

            if (arr[r] >= rightMax) {
                rightMax = arr[r];
            } else {
                sum += rightMax - arr[r];
            }

            r--;
        }
    }

    return sum;
}
