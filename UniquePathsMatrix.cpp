/*
Time complexity : O(N*M)
Space complexity : O(N*M)
My approach :  Here dp is of the same size as the matrix, the first row and column have value 1,
               each cell is equal to sum of above row  cell and left adjacent cell .
               return the bottom right cell's value as answer.
*/

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++)
            dp[i][0]=1;
        for(int j=0;j<n;j++)
            dp[0][j]=1;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        for(int i=0;i<m;i++)
        { for(int j=0;j<n;j++)
                 cout<<dp[i][j]<<" ";
         cout<<endl;
        }
           
        
        return dp[m-1][n-1];
    }
};
