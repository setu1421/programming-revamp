// https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
// https://www.youtube.com/watch?v=5E3se3Gm4aQ

int Solution::uniquePaths(int A, int B) {
    int dp[A][B];
    
    for(int j = 0; j < B; j++)
    {
        dp[0][j] = 1;
    }
    
    for(int i = 0; i < A; i++)
    {
        dp[i][0] = 1;
    }
    
    for(int i = 1; i < A; i++)
    {
        for(int j = 1; j < B; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    
    return dp[A - 1][B - 1];
}
