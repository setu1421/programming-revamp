// https://www.youtube.com/watch?v=AuYujVj646Q

// Time Complexity: O(mn)
// Space Complexity: O(mn)
int dp[455][455];

int Solution::minDistance(string A, string B) {
    int m = A.length(), n = B.length();
    
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0)
            {
                dp[0][j] = j;
            }
            
            if(j == 0)
            {
                dp[i][0] = i;
            }
            
            if(i != 0 && j != 0)
            {
                if(A[i - 1] == B[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                } else
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
            }
        }
    }
    
    return dp[m][n];
}
