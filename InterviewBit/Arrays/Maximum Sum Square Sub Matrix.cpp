#define maxN 1002

void preComputeSum(vector<vector<int> > &A, int stripSum[][maxN], int n, int B)
{
    for(int j = 0; j < n; j++)
    {
        int sum = 0;
        
        for(int i = 0; i < B; i++)
        {
            sum += A[i][j];
        }
        
        stripSum[0][j] = sum;
        
        for(int i = 1; i < n - B + 1; i++)
        {
            sum += A[i + B - 1][j] - A[i - 1][j];
            stripSum[i][j] = sum;
        }
    }
}

int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    int stripSum[n - B + 1][n];
    int ans = INT_MIN;
    
    preComputeSum(A, stripSum, n, B);
    
    for(int i = 0; i < n - B + 1; i++)
    {
        int sum = 0;
        
        for(int j = 0; j < B; j++)
        {
            sum += stripSum[i][j];
        }
        
        ans = max(ans, sum);
        
        for(int j = 1; j < n - B + 1; j++)
        {
            sum += stripSum[i][j + B - 1] - stripSum[i][j - 1];
            ans = max(ans, sum);
        }
    }
    
    return ans;
}
