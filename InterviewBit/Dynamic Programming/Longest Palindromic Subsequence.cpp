int lcs[1010][1010];

void precompute_lcs(string A, string B, int n)
{
    for(int i = 0; i <= n; i++)
    {
        lcs[i][0] = 0;
    }
    
    for(int j = 0; j <= n; j++)
    {
        lcs[0][j] = 0;
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(A[i - 1] == B[j - 1])
            {
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            } else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
}

int Solution::solve(string A) {
    int n = A.length();
    
    string B = A;
    reverse(A.begin(), A.end());
    
    precompute_lcs(A, B, n);
    
    return lcs[n][n];
}
