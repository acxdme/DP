/*
Time complexity  : O(N^2) more specifically O(MaxWeightsAllowed*NumberOfWeights)
Space complexity : O(N^2) more specifically O(MaxWeightsAllowed*NumberOfWeights).
My approach : initialize the 2d matrix and set 1st row and column as 0, now iterate over the matrix
              if the current weight of item is more than the capacity we take the above  value from the table.
              else take the max of ( current value+ value excluding the current weight or above value from table)   
              return the bottom right value as answer.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,w;
	    cin>>n>>w;
	    int values[n],weights[n];
	    for(int i=0;i<n;i++)
	     cin>>values[i];
	    for(int j=0;j<n;j++)
	     cin>>weights[j];
	    int dp[n+1][w+1];
	    memset(dp,0,sizeof(dp));
	    for(int i=1;i<n+1;i++)
	    {
	        for(int j=1;j<w+1;j++)
	        {
	            if(weights[i-1] > j)
	             dp[i][j]= dp[i-1][j];
	            else
	            dp[i][j] = max (dp[i-1][j-weights[i-1]]+values[i-1],dp[i-1][j]);
	        }
	    }
	    cout<<dp[n][w]<<endl;
	    
	    
	    
	}
	return 0;
}
