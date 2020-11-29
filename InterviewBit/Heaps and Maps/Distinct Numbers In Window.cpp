vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> res;
    unordered_map<int, int> mp;
    int n = A.size(), count = 0;
    
    if(B > n)
    {
        return res;
    }
    
    for(int i = 0; i < B; i++)
    {
        // If current element was not present in the window, then increase the count
        if(mp[A[i]] == 0)
        {
            count++;
        }
        // Increase the count of occurence of current element
        mp[A[i]]++;
    }
    
    res.push_back(count);
    
    for(int i = B; i < n; i++)
    {
        // The element which is going out of the window has only one occurrence, 
        // then decrease the count of distinct integers.
        if(mp[A[i - B]] == 1)
        {
            count--;
        }
        
        mp[A[i - B]]--;
        // If the current element is not present in the current window,
        // then increase the count of distinct integers.
        if(mp[A[i]] == 0)
        {
            count++;
        }
        
        mp[A[i]]++;
        
        res.push_back(count);
    }
    
    return res;
}
