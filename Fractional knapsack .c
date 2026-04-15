#include <stdio.h>

struct Item {
    int value;
    int weight;
};

void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double r1 = (double)arr[j].value / arr[j].weight;
            double r2 = (double)arr[j + 1].value / arr[j + 1].weight;
            if (r1 < r2) {
                struct Item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



double fractionalKnapsack(int W, struct Item arr[], int n) {
    sortItems(arr, n);
    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int n, W;

//    // METHOD 1: STATIC DECLARATION
//    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
//    n = sizeof(arr) / sizeof(arr[0]);
//    W = 50;

    // METHOD 2: USER INPUT
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);


    double maxValue = fractionalKnapsack(W, arr, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
