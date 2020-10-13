vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = A.size();
    vector<int>v{-1, -1};
    
    int low = 0, high = n - 1;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        // If we got B, then save the mid as possible answer and search in the left part
        if(A[mid] == B)
        {
            v[0] = mid;
            high = mid - 1;
        } else if(A[mid] > B)
        {
            high = mid - 1;
        } else 
        {
            low = mid + 1;
        }
    }
    
    if(v[0] == -1)
    {
        return v;
    }
    
    low = v[0]; high = n - 1;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        // If we got B, then save the mid as possible answer and search in the right part
        if(A[mid] == B)
        {
            v[1] = mid;
            low = mid + 1;
        } else if(A[mid] > B)
        {
            high = mid - 1;
        } else 
        {
            low = mid + 1;
        }
    }
    
    return v;
}
