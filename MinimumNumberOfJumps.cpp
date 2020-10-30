/*
Time complexity : O(N^2)

Space complexity : O(N)

My approach : If the value at 0th index is zero than it's not possible to reach the end,
              intialize a 1d dp array with dp[0] as 0 and rest as infinity(INT_MAX)
              iterate over for i=1 to n and for each i start j=0 to i and check if (a[j]+j >=i ,which means reachable from there)
              update dp[i] as min( 1+dp[j], dp[i]).
              finally return dp[n-1] as output is dp[n-1]== infinity we conclude we are unable to reach.
              
we can also keep track of the actual jumps taken using another arrays which stores the jump sequence , so that later when required we can track from this array.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    int dp[n];
	    for(int i=1;i<n;i++)
	     dp[i]= INT_MAX;
	    dp[0]=0;
	    if(a[0]==0)
	     cout<<-1<<endl;
	    else
	    {
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(j+a[j] >= i)
	             dp[i]= min(1+dp[j],dp[i]);
	        }
	    }
	     if(dp[n-1]==INT_MAX)
	      cout<<"-1"<<endl;
	     else
	     cout<<dp[n-1]<<endl;
	    }
	}
	return 0;
}

//Greedy Approach 
/*
 Time complexity : O(N)
 Space complexity : O(1)
 */

class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        int jumps =0;
        int currMax =0 ;
        int maxReach =0;
        
        for(int i=0; i < n-1; i++)
        {
             if( i + nums[i] > currMax )
             {
                 currMax = i + nums[i];
             }
            if( i == maxReach )
            {
                jumps++;
                maxReach = currMax;
            }
                
        }
        
        return jumps;
        
    }
};
