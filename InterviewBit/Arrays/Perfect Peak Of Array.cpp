int Solution::perfectPeak(vector<int> &A) {
    int n = A.size();
    
    int left_max[n + 1];
    int right_min[n + 1];
    
    left_max[0] = A[0];
    for(int i = 1; i < n; i++)
    {
        left_max[i] = max(A[i], left_max[i - 1]);
    }
    
    right_min[n - 1] = A[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        right_min[i] = min(A[i], right_min[i + 1]);
    }
    
    for(int i = 1; i <= n - 2; i++)
    {
        if(A[i] > left_max[i - 1] && A[i] < right_min[i + 1])
        {
            return 1;
        }
    }
    
    return 0;
    
    
}
