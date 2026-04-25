AIM:
To implement tower of hanoi using recursion to move n disks from sourse to destination rod

ALGORITHM:
1. check the  Base Condition. 
2. Move Top (n−1) Disks from Source to Auxiliary
3. Move the largest disk (nth disk) to destination
4. Move (n−1) Disks from Auxiliary  to destination
5. Repeat Recursively until base condition satisfied.


PROGRAM


#include <stdio.h>
 /**
 * Function to solve Tower of Hanoi problem
 * @param diskNumber: Number of disks to move
 * @param source: Starting rod
 * @param destination: Target rod
 * @param auxiliary: Intermediate rod
 */
 void towerOfHanoi(int diskNumber, char source, char destination, char auxiliary)
 {
 /* Base Condition: Only one disk to move */
 if (diskNumber == 1) {
 printf("Move disk 1 from %c to %c\n", source, destination);
 return;
 }

 /* Step 1: Move n-1 disks from source to auxiliary */
 towerOfHanoi(diskNumber - 1, source, auxiliary, destination);

 /* Step 2: Move the nth disk from source to destination */
 printf("Move disk %d from %c to %c\n", diskNumber, source, destination);
 /* Step 3: Move n-1 disks from auxiliary to destination */
 towerOfHanoi(diskNumber - 1, auxiliary, destination, source);
 }

 int main() {
 int n;

 printf("Enter number of disks: ");
 if (scanf("%d", &n) != 1 || n <= 0) {
 printf("Please enter a valid positive integer.\n");
 return 1;
 }

 printf("\nRequired moves:\n");
 towerOfHanoi(n, 'S', 'D', 'A');

 return 0;
 }
