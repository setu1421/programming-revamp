int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    
    int Lmin[n], Rmax[n];
    
    // Find the minimum at each step
    Lmin[0] = A[0];
    for(int i = 1; i < n; i++)
    {
        Lmin[i] = min(Lmin[i - 1], A[i]);
    }
    
    // Find the maximum at each step
    Rmax[n - 1] = A[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        Rmax[i] = max(Rmax[i + 1], A[i]);
    }
    
    // Calculate the max_diff
    int i = 0, j = 0, max_diff = 0;
    
    while(i < n && j < n)
    {
        if(Lmin[i] <= Rmax[j])
        {
            max_diff = max(max_diff, j - i);
            j++;
        } else 
        {
            i++;
        }
    }
    
    return max_diff;
}
