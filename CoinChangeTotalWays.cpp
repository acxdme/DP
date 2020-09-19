/*
Time complexity : O(N*M)    where n is the given amount and m is the size of the coins array
Space complexity : O(N*M)
Algo   : create a 2d array of m+1 rows and n+1 columns with all values as 0 except the 1st column with values as 1,
         traverse the 2d array now for each cell if coins values S[i-1] is greater than j the current amount then copy value from above(dp[i][j]= dp[i-1][j],
         else dp[i][j] will be the sum of values excluding the coin and including the coin  so dp[i][j]= dp[i-1][j] + dp[i][j-S[i-1];
         return dp[m][n] as answer.
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
     int m= 4;
     int n= 10;
     int S[m]={2,5,3,6};
     int dp[m+1][n+1] ;
       memset(dp,0,sizeof(dp));
       for(int i=0;i<m+1;i++)
        dp[i][0]=1;
       for( int i=1;i<m+1;i++)
       {
           for( int j=1;j<n+1;j++)
           {
               if(S[i-1] > j )
                dp[i][j]= dp[i-1][j];
               else
                dp[i][j]= dp[i-1][j]+ dp[i][j-S[i-1]];
           }
       }
       
       cout<< dp[m][n]<<endl;

    return 0;

}
