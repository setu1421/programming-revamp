//Time Complexity: O(n)
// The idea is to store the index of actual values in a map, 
// then place the highest number at the first place, then place the second number at the second place.. 
// until we have swapping capabilities
vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int> mp;
    
    for(int i = 0; i < n; i++)
    {
        mp[A[i]] = i;
    }
    
    for(int i = 0; i < n && B > 0; i++)
    {
		// If the value is not the current greater element, then swap 
        if(A[i] != (n - i))
        {
            mp[A[i]] = mp[n - i];
            swap(A[i], A[mp[n - i]]);
            B--;
        }
    }
    
    return A;
}
