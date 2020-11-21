int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), count = 0, ans = 0;
    
    unordered_map<int, int> mp;
    
    for(int i = 0; i < n; i++)
    {
		// if current number is odd, then increment the count.
        if(A[i] & 1)
        {
            count++;
        }
        // if the count of odd number is equal to B, 
		// then increment the ans as this is a valid subarray.
        if(count == B)
        {
            ans++;
        }
        // if we find (count - B) number of odd numbers before, then increment the ans with the value of that mp[count - B]
        // as subarray after that value will have exactly B odd numbers.		
        if(mp.find(count - B) != mp.end())
        {
            ans += mp[count - B];
        }
        // Add the count in the map.
        mp[count]++;
    }
    
    return ans;
}
