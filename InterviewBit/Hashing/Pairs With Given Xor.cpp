int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    
    unordered_map<int, int>mp;
    int count = 0;
    // The idea is based on the fact that A[i] ^ A[j] is equal to B if and only if A[i] ^ B is equal to A[j].
    for(int i = 0; i < n; i++)
    {
        if(mp.find(B ^ A[i]) != mp.end())
        {
            count++;   
        } else
        {
            mp[A[i]] = 1;
        }
    }
    
    return count;
}
