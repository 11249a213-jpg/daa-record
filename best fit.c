#include <stdio.h>

void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];
    int binCount = 0;

    // Initialize bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    // Process each item
    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;
        int minSpace = capacity + 1;

        // Find bin with least remaining space after placement
        for (int j = 0; j < binCount; j++)
        {
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace)
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // Identified the best bin for the current item
        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i];
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        }
        else // New bin needed
        {
            bin[binCount] -= items[i];
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++;
        }
    }
    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n];

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
        int itemSize;
        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        if (itemSize <= capacity)
        {
            items[i] = itemSize;
        }
        else
        {
            printf("Item size exceeds bin capacity. Please enter a valid size.\n");
            i--;
        }
    }

    bestFit(items, n, capacity);

    return 0;
}
