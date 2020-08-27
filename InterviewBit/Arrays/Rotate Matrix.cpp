void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();
    
    // Transpose the matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            swap(A[i][j], A[j][i]);
        }
    }
    
    // Swap the columns
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (n / 2); j++)
        {
            swap(A[i][j], A[i][n - 1 - j]);
        }
    }
}
