#include <stdio.h>
int main()
{
    int n;
    int a = 0, b = 1, c;

    printf("Enter the number of terms (n): ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }
    printf("Fibonacci Series: ");

    // Handle 1st term
    if (n >= 1)
        printf("%d ", a);

    // Handle 2nd term
    if (n >= 2)
        printf("%d", b);

    // Iterative computation from 3rd term onwards
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }

    /* Logic Fix: If n is 1, the nth term is 'a' (0).
       Otherwise, the nth term is 'b'. */
    if (n == 1)
        printf("\nFibonacci term %d = %d\n", n, a);
    else
        printf("\nFibonacci term %d = %d\n", n, b);

    return 0;
}
