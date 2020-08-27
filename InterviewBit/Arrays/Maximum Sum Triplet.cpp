int getLower(set<int> &s, int value)
{
    auto it = s.lower_bound(value);
    
    --it;
    
    return (*it);
}

void preComputeSuffixMax(int suffixMax[], vector<int> &A, int n)
{
    suffixMax[n - 1] = A[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], A[i]);
    }
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int suffixMax[n + 1];
    int ans = 0;
    
    // Compute the maximum element at the right to add as third element
    preComputeSuffixMax(suffixMax, A, n);
    
    // Use set to find out immediate lower element of a value
    set<int> s;
    // Insert minimum value for first comparison in the set 
    s.insert(INT_MIN);
    s.insert(A[0]);
    
    for(int i = 1; i < n - 1; i++)
    {
        if(suffixMax[i + 1] > A[i])
        {
            ans = max(ans, getLower(s, A[i]) + A[i] + suffixMax[i + 1]);
            
        }
        
        s.insert(A[i]);
    }
    
    return ans;
}
