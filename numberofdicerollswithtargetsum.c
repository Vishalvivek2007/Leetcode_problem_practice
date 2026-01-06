#define MOD 1000000007

int getcount(int** memo, int n, int k, int target) {
    if (n == 0 && target == 0) return 1;
    if (n == 0 || target <= 0) return 0;

    if (memo[n][target] != -1) {
        return memo[n][target];
    }

    long long ways = 0;
    for (int i = 1; i <= k; i++) {
        ways = (ways + getcount(memo, n - 1, k, target - i)) % MOD;
    }

    return memo[n][target] = (int)ways;
}

int numRollsToTarget(int n, int k, int target) {
    int** memo = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        memo[i] = (int*)malloc((target + 1) * sizeof(int));
        memset(memo[i], -1, (target + 1) * sizeof(int));
    }

    int result = getcount(memo, n, k, target);

    for (int i = 0; i <= n; i++) free(memo[i]);
    free(memo);

    return result;
}

