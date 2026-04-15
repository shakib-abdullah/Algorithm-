#include <stdio.h>

int main() {
    int n, W;
    float value[20], weight[20], ratio[20], temp;
    float totalValue = 0;

    // METHOD 1: STATIC DECLARATION
    n = 3;
    W = 50;
    float v[] = {60, 100, 120};
    float w[] = {10, 20, 30};
    for(int i=0; i<n; i++) {
        value[i] = v[i];
        weight[i] = w[i];
    }

    // METHOD 2: USER INPUT
    printf("Item koyta? ");
    scanf("%d", &n);
    printf("Bag er capacity koto? ");
    scanf("%d", &W);
    for (int i = 0; i < n; i++) {
        printf("Item %d er Value ar Weight dao: ", i + 1);
        scanf("%f %f", &value[i], &weight[i]);
    }


    // 1. Proti kg er dam (Ratio) ber kora
    for (int i = 0; i < n; i++) {
        ratio[i] = value[i] / weight[i];
    }

    // 2. Ratio onujayi boro theke choto shajano (Sorting)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Ratio swap
                temp = ratio[j]; ratio[j] = ratio[i]; ratio[i] = temp;
                // Sathe sathe weight o swap
                temp = weight[j]; weight[j] = weight[i]; weight[i] = temp;
                // Sathe sathe value o swap
                temp = value[j]; value[j] = value[i]; value[i] = temp;
            }
        }
    }

    // 3. Bag e bhora shuru
    for (int i = 0; i < n; i++) {
        if (weight[i] <= W) {
            // Purota neya jabe
            totalValue += value[i];
            W -= weight[i];
        } else {
            // Shudu kichu ongsho neya jabe
            totalValue += value[i] * ((float)W / weight[i]);
            break;
        }
    }

    printf("Maximum labh hobe: %.2f\n", totalValue);

    return 0;
}
