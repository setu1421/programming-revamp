int Solution::solve(vector<int> &A) {
    int n = A.size();
    
    sort(A.begin(), A.end());
    
    for(int i = 0; i < n; i++)
    {
        int p = A[i];
        
		// Check for duplicate and negative numbers
        if(p < 0 || ((i + 1) < n && A[i + 1] == p))
        {
            continue;
        }
        
        if((n - i - 1) == p)
        {
            return 1;
        }
    }
    
    return -1;
}
