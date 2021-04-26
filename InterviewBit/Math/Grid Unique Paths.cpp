// https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
// https://www.youtube.com/watch?v=5E3se3Gm4aQ

// Time Complexity: O(AxB)
// Space Complexity: O(AxB)
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


// Another Solution: Using O(n) space;
// Time Complexity: O(AxB)
int Solution::uniquePaths(int A, int B) {
    // Create a 1D array to store results of subproblems
    int dp[B] = { 1 };
    dp[0] = 1;
 
    for (int i = 0; i < A; i++) {
        for (int j = 1; j < B; j++) {
            dp[j] += dp[j - 1];
        }
    }
 
    return dp[n - 1];
}

// Another Solution: Using Combinatorics  (https://www.youtube.com/watch?v=t_f0nwwdg5o)
// Time Complexity: O(B-1) or O(A - 1)
// Space Complexity: O(1)

int Solution::uniquePaths(int A, int B) {
    int N = A + B - 2;
    int R = B - 1;
    int ans = 1;
    
    for(int i = 1; i <= R; i++)
    {
		// We have A + B - 2 positions to go and we have to choose A - 1 or B - 1 to fill among the positions. (A + B - 2) C (B - 1)  
        ans = ans * (N - R + i) / i;  
    }
    
    return ans;
}