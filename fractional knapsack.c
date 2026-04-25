AIM:
To implement fractionalknapsack problem using greedymethod to obtain maximum profit by selecting items based on value_to_weight_ratio

ALGORITHM:
1.read the number of items.
2.read weight and value of each item.
3.compute value to weight ratio:
   ratio=value/weight
4.sort items in descending order of ratio
5.initialize totalprofit=0
6.for each item:
  if itemweight<=remaingcapacity
  take full item
  subract weight from capacity
  add full value to totalprofit
  else:
  take fractionalpart
  add proportional value
  ratio* ramain ing capacity
  break the loop
7.display the totalprofit
PROGRAM:
#include <stdio.h>

struct Item
{
    int weight;
    int value;
    float ppw; // profit per weight ratio
};

/* Function to sort items by ratio in descending order */
void sort(struct Item items[], int n)
{
    struct Item temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ppw < items[j + 1].ppw)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    float capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    if (n <= 0)
        return 1;

    struct Item items[n];

    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ppw = (float)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    /* Sort items by value/weight ratio */
    sort(items, n);

    float totalProfit = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            totalProfit += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            totalProfit += items[i].ppw * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);
    return 0;
}
