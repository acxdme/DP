/*
Time complexity : O(M*N)
Space complexity : O(M*N)
My approach : if character same then add include+exclude character else just copy from above.
*/

#include <bits/stdc++.h>
using namespace std;

int subscounter(string a, string b)
{
    int r = a.size();
    int c = b.size();
    int dp[r + 1][c + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= c; i++)
        dp[0][i] = 1;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j-1] + dp[i][j - 1];
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[r][c];
}

int main()
{
    string a, b;
    cin >> a >> b;
    int answer = subscounter(a, b);

    cout << answer << endl;

    return 0;
}
