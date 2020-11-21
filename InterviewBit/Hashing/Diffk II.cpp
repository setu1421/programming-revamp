int Solution::diffPossible(const vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int>mp;
    
    for(int i = 0; i < n; i++)
    {
        if(mp.find(A[i] + B) != mp.end() || mp.find(A[i] - B) != mp.end())
        {
            return 1;
        }
        
        mp[A[i]] = 1;
    }
    
    return 0;
}
