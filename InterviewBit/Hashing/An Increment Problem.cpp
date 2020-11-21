vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> res;
    unordered_map<int, int>mp;
    
    for(int i = 0; i < n; i++)
    {
        res.push_back(A[i]);
        // if the same element present before, then increment the value at that index.
        if(mp.find(A[i]) != mp.end())
        {
            int index = mp[A[i]];
            res[index]++;
            // Update the mapping of value with that index.
			// For example: 1 1 1. Output will be: 2 2 1. So once we increment a value, then we need to update the mapping.
            mp[res[index]] = index;
        }
        // Insert the current value with current index.
        mp[A[i]] = i;
    }
    
    return res;
}
