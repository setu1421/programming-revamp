int Solution::solve(vector<int> &A, int B, int C) {
    int n = A.size(), diff = 0, ans = 0;
    
    unordered_map<int, int>mp;
	// setting 1 for zero difference
	// For example: Suppose B = 1, C = 2, and current element is 4, then diff is 0. So, we need to increment ans by 1.
	// The count of difference 0 will change wherever we will get diff 0.
    mp[0] = 1;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] == B)
        {
            diff++;
        } else if(A[i] == C)
        {
            diff--;
        }
        // if the difference is zero or the difference we have seen before on some positions,
		// after those positions, the subarray to the current index contains same number of occurences of B & C
        ans += mp[diff];
		// Updating count of particular diff occurences
        mp[diff]++;
    }
    
    return ans;
}
