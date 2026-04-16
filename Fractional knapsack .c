#include <stdio.h>

float knapsack(int n, int weights[], int profits[], int capacity) {
    float ratios[n];
    float tempRatio; // Temporary variable for swapping ratios
    int tempInt; // Temporary variable for swapping weights and profits

    // Calculate profit-to-weight ratios
    for (int i = 0; i < n; i++) {
        ratios[i] = (float)profits[i] / weights[i];
    }



    // Sort by ratio (descending), and keep all arrays aligned
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratios[i] < ratios[j]) {
                // Swap ratios
                tempRatio = ratios[i];
                ratios[i] = ratios[j];
                ratios[j] = tempRatio;

                // Swap weights
                tempInt = weights[i];
                weights[i] = weights[j];
                weights[j] = tempInt;

                // Swap profits
                tempInt = profits[i];
                profits[i] = profits[j];
                profits[j] = tempInt;

            }
        }
    }

    float totalProfit = 0.0;
    int remaining = capacity;


    // Greedy selection
    for (int i = 0; i < n && remaining > 0; i++) {
        if (weights[i] <= remaining) {
            totalProfit += profits[i];
            remaining -= weights[i];
        } else {
            float fraction = (float)remaining / weights[i];
            totalProfit += profits[i] * fraction;
            remaining = 0;
        }
    }



    return totalProfit;
}

int main(void) {
    int n = 7;
    int profits[] = {12, 5, 16, 7, 9, 11, 6};
    int weights[] = {3, 1, 4, 2, 9, 4, 3};
    int capacity = 15;

    float totalProfit = knapsack(n, weights, profits, capacity);
     printf("\nTotal Profit: %.2f\n", totalProfit);

    return 0;
}