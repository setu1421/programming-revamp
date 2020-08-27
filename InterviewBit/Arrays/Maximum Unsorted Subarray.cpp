vector<int> Solution::subUnsort(vector<int> &A) {
    vector<int>res;
    
    int n = A.size();
    int start = -1, end = -1;
    
    // Find the start
    for(int i = 0; i < n - 1; i++)
    {
        if(A[i] > A[i + 1])
        {
            start = i;
            break;
        }
    }
    
    // Find the end
    for(int i = n - 1; i > 0; i--)
    {
        if(A[i] < A[i - 1])
        {
            end = i;
            break;
        }
    }
    
    // if already sorted
    if(start == -1 && end == -1)
    {
        res.push_back(-1);
        return res;
    }
    
    int min_val = INT_MAX, max_val = INT_MIN;
    // Find the min and max between the start and end
    for(int i = start; i <= end; i++)
    {
        min_val = min(min_val, A[i]);
        max_val = max(max_val, A[i]);
    }
    
    // Adjust the start if any greater element present before the start
    for(int i = 0; i < start; i++)
    {
        if(A[i] > min_val)
        {
            start = i;
        }
    }
    
    // Adjust the end if any smalller element present after the end
    for(int i = end + 1; i < n; i++)
    {
        if(A[i] < max_val)
        {
            end = i;
        }
    }
    
    res.push_back(start);
    res.push_back(end);
    
    return res;
}
