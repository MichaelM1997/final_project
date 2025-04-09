#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int n, int* t, int T) {
    int* dp = (int*)calloc((T + 1), sizeof(int));

    for (int i = 1; i <= n; i++) {
        for (int j = T; j >= t[i - 1]; j--) {
            dp[j] = max(dp[j], dp[j - t[i - 1]] + 1);
        }
    }

    int maxProfit = dp[T];
    free(dp);
    return maxProfit;
}

int main() {
    int n = 4;
    int t[] = {3, 2, 1, 4};
    int T = 5;

    int maxProfit = knapsack(n, t, T);
    printf("Maximum profit: %d\n", maxProfit);

    return 0;
}


