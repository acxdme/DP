/*
Time complexity: O(N*M)
Space complexity : O(N*M) , can also be done without taking any extra space.
My approach : The robot can only move either down or right. Hence any cell in the first row can only be reached from the cell left to it.
              And, any cell in the first column can only be reached from the cell above it,For any other cell in the grid,
              we can reach it either from the cell to left of it or the cell above it.
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n= obstacleGrid.size();
        if(n==0)
            return 0;
        int m= obstacleGrid[0].size();
        
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        if(obstacleGrid[0][0] == 1) return 0;
        dp[0][0]=1;
        for(int i=1;i<m;i++)
        {
            if(obstacleGrid[0][i]==1)  dp[0][i]=0;
            else  dp[0][i]= dp[0][i-1]; 
        }
        
        for(int i=1;i<n;i++)
        {
            if(obstacleGrid[i][0]==1) dp[i][0]=0;
            else  dp[i][0] = dp[i-1][0];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(obstacleGrid[i][j]==1) 
                    dp[i][j]=0;
                else
                    dp[i][j]= dp[i-1][j]+dp[i][j-1];
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //          cout<<dp[i][j]<<" ";
        //  cout<<endl;
        // }
        
        return dp[n-1][m-1];
        
    }
};
