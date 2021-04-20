// https://www.youtube.com/watch?v=ZqG89Z-dKpI

int lcs[105][105];

void precompute_modified_lcs(string A, int n)
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
            if(A[i - 1] == A[j - 1] && i != j)
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
}

int Solution::anytwo(string A) {
    int n = A.length();
    
    if(n == 0 || n == 1) return 0;
    
    precompute_modified_lcs(A, n);
    
    if(lcs[n][n] > 1)
    {
        return 1;
    } else
    {
        return 0;
    }
}
