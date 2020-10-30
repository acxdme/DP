/*
 The task is to find if two paritions of equal sum exist or not!
 Time complexity O(N*M)
 Space complexity O(N*M)
 Algo :  Calculate the sum of the array if the total sum turns out to be odd then return false
         else call subset sum (arr,N,sum/2);
         the value returned by the helper function is then returned as answer.
         
NOTE : Equal sum partition problem uses subset sum approach as subroutine.
*/

class Solution{
public:

 bool subset_sum(int N,int arr[],int sum)
 {
     bool dp[N+1][sum+1];
     memset(dp,false,sizeof(dp));
     for(int i=0;i<N+1;i++)
      dp[i][0]=true;
      for(int i=1;i<=N;i++)
      {
          for(int j=1;j<=sum;j++)
          {
              if(arr[i-1] > j) dp[i][j]= dp[i-1][j];
              else
              {
                  dp[i][j]= (dp[i-1][j] || dp[i-1][j-arr[i-1]]);   // OR operation of cell just above with remaining sum(j-arr[i-1]) column  of above row.
              }
          }
      }
      return dp[N][sum];
 }
 
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++) sum+= arr[i];
        if(sum%2!=0) return 0;

        return subset_sum(N,arr,sum/2);
    }
};
