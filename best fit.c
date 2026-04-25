AIM:
To implement the binpacking problem  using bestfit  to place each item into the bin with the smallest remaining capacity that can accommadateit,thereby minimizing the number of bins used.

ALGORITHM:
1.read the number of items n.
2.read the size of each item.
3.read the bincapacity c.
4.initialize an array bin[] of size n with capacity value c
5.set bincount=0
6.for eachitem i=1to n 
  set best index=-1
  set minspace= c+1
  scan all existing bins j=1 to bincount
->if items fits in binj:
  compute remaingspace after placement
  if this remaining space is less than minspace:
      update bestindex =j
      update minspace
after scanning all bins:
->if bestindex noteqeal to -1
   place items in bin bestindex
   update remaining capacity 
-> if the items is not placed in any existing bin
   open a new bin
   place the item in new bin
   update remaining capacity
   increment bincount
7.display the bincapacity
8.display the total number of bins used.
program:
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
