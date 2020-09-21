/*
Time complexity : o(N)
Space complexity : O(N)
Algo : intialize dp[0]=0 and rest of dp[n+1] is initialized with -1
       iterate over dp if dp[i]==-1 skip
       else if([i+x/y/z] <=n) dp[i+x/y/z]= max(dp[i+x/y/z],1+dp[i])
*/

//Maximum number of segments of lengths a, b and c
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x, y, z;
        cin >> x >> y >> z;
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < n + 1; i++)
        {
            if (dp[i] != -1)
            {
                if (i + x <= n)
                    dp[i + x] = max(dp[i + x], dp[i] + 1);
                if (i + y <= n)
                    dp[i + y] = max(dp[i + y], dp[i] + 1);
                if (i + z <= n)
                    dp[i + z] = max(dp[i + z], dp[i] + 1);
            }
        }

        cout << dp[n] << endl;
    }
    return 0;
}
