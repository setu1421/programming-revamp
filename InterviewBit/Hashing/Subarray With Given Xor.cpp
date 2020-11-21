// https://www.youtube.com/watch?v=lO9R5CaGRPY&t=712s

int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), count = 0;
    unordered_map<int, int>mp;
    
    // Computing the prefix array for xor.
    for(int i = 1; i < n; i++)
    {
        A[i] = A[i - 1] ^ A[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        // Find XOR of current prefix with B.
        int value = A[i] ^ B;
        // If above XOR exists in map, then there
        // is another previous prefix with same
        // XOR, i.e., there is a subarray ending
        // at i with XOR equal to B.
        if(mp.find(value) != mp.end())
        {
            count += mp[value];
        }
        // If this subarray has XOR equal to B itself.
        if(A[i] == B)
        {
            count++;
        }
        // Add the XOR of this subarray to the map
        mp[A[i]]++;
    }
    
    return count;
}
