#include <stdio.h> 
 #define MAXN 15 
  
 // Used to initialize minCost to a very large value. 
 // Since all travel costs are non-negative, any valid cost 
 // will be less than INF and replace it. 
 #define INF 999999 
  
  int n; 
 int d[MAXN][MAXN]; 
 // Bitwise AND checks whether that city's bit is set in S. 
 // S will have 2n possible combinations of cities, so the sizofit should be 
 int dp[MAXN][1 << MAXN]; 
  
 // g(i,S) 
 // Returns the minimum cost of visiting all cities in setstarting from city i 
 int g(int i, int S) 
 { 
 
     // Base case: If S is empty, return the cost to return tthestarting city 

     if (S == 0) 
         return d[i][0]; //g(i,{}) = d[i][0] - Cost to returntstarting city A 
  
     //If the g(i,S) has already been computed, return thstoredvalue 
     if (dp[i][S] != -1)  
         return dp[i][S]; 
     int minCost = INF;
   for (int k = 0; k < n; k++) 
     { 
         // (1 << k) creates a mask for city k. 
         // Bitwise AND checks whether that city's bit is set iS. 
         // If the result is non-zero, it means city k iincludedin S. 
         if (S & (1 << k)) 
         { 
             // g(i, S) = d(i,k) + g(k, S & ~(1 << k)) 
             int cost = d[i][k] + g(k, S & ~(1 << k)); 
  
             //If the calculated cost is less than thecurrenminimum cost, 
             if (cost < minCost) 
             { 
                 minCost = cost; 
             } 
         } 
     } 
     // Store the computed final minimum cost in dp[i][S]focurrent city i to 
     return dp[i][S] = minCost; 
 } 
  
 int main() 
 { 
     printf("Enter number of cities: "); 
     scanf("%d", &n); 
  
     printf("Enter cost matrix:\n"); 
     for (int i = 0; i < n; i++) 
         for (int j = 0; j < n; j++) 
             scanf("%d", &d[i][j]); 
  
     // -1 - Indicates that the value has not been computed yet 
     // Since all valid TSP costs are non-negative, -1safelindicates 
     for (int i = 0; i < n; i++) 
         for (int mask = 0; mask < (1 << n); mask++) 
         { 
             dp[i][mask] = -1; 
         }
   int S = 0; 
     for (int i = 1; i < n; i++) 
         S |= (1 << i); 
  
     int result = g(0, S); 
  
     printf("Given Cost Matrix\n"); 
     for (int i = 0; i < n; i++) 
     { 
          
         printf("|"); 
         for (int j = 0; j < n; j++) 
             printf(" %d ", d[i][j]); 
         printf("|\n"); 
     } 
     printf("Minimum travelling cost: %d\n", result); 
  
     return 0; 
 }
