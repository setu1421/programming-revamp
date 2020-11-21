int Solution::solve(vector<int> &A) {
    int n = A.size(), ans = 0, diff = 0;
    
    unordered_map<int, int>mp;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] == 1)
        {
            diff++;
        } else
        {
            diff--;
        }
        
        if(diff == 1)
        {
            ans = i + 1;
        } else if(mp.find(diff) == mp.end())
        {
            mp[diff] = i;
        } 
        // If we can find a index for diff - 1, that means after the index of mp[diff - 1] to the current index,
		// we have seen one more 1's than 0's 
        if(mp.find(diff - 1) != mp.end())
        {
            ans = max(ans, i - mp[diff - 1]);
        }
    }
    
    return ans;
}
