int Solution::solve(string A) {
    unordered_map<char, int> mp;
    int n = A.length();
    
    for(int i = 0; i < n; i++)
    {
        mp[A[i]]++;
    }
    
    int non_pair_count = 0;
    
    for(auto c: mp)
    {
        if(c.second & 1)
        {
            non_pair_count++;
        }
    }
    
    // if string is odd length and non pair count is 1 (aab) 
    // or string length is even and non pair count is zero (aabb),
    // then, we can rearrange to palindrome 
    if(((n & 1) && non_pair_count == 1) || (((n & 1) != 1) && non_pair_count == 0))
    {
        return 1;
    }
    
    return 0;
}
