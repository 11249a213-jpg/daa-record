AIM:
To implement a program to find the nth fibonacci term using recursion

ALGORITHM:
1.read the vaalue of n
2.if n=0,return 0(base condition)
3.if n=1,return 1(base condition)
4.recursively compute: f(n)=f(n-1)+f(n-2)
5.display the returned value as the nth fibonacci term.
PROGRAM:
#include <stdio.h>

/**
 * Function: fib
 * Complexity: O(2^n) - Tree Recursion with overlapping subproblems.
 * @param n: The index of the Fibonacci term to be computed
 * @return: The Fibonacci value at the given index.
 */
int fib(int n)
{
    /* Base Condition: If n is 0 or 1, the term is the value itself [cite: 141]. */
    if (n <= 1)
    {
        return n;
    }

    /* Recursive Step: F(n) = F(n-1) + F(n-2) [cite: 142].
     * Note: This causes the function to branch twice for every call,
     * leading to the exponential time complexity observed in DAA.
     */
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n, result = 0;

    /* Step 1: Read the input n and validate that it is non-negative [cite: 140]. */
    printf("Enter the value of n: ");
    scanf("%d", &n);

    /* Checking if input is a valid integer and non-negative. */
    if (n < 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("\nNth Fibonacci term = %d\n", fib(n));
    return 0;
}
