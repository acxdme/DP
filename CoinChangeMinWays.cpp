/*
Time complexity :
Space complexity :

*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n= coins.size();
        int dp[n+1][amount+1];
        memset(dp,0,sizeof(dp));
        for(int j=0;j<amount+1;j++)
            dp[0][j] = 1e6;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(coins[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                {
                    
                    dp[i][j] = min(dp[i-1][j], 1+ dp[i][j-coins[i-1]]);

                }
            }
        }
        
        if(dp[n][amount]==1e6)
            return -1;
        return dp[n][amount];
    }
};
