string Solution::solve(string A) {
    int n = A.length();
    unordered_map<char, int> mp;
    queue<char>q;
    string res = "";
    
    for(int i = 0; i < n; i++)
    {
        q.push(A[i]);
        mp[A[i]]++;
        // pop all the characters from the front which are repeating
        while(!q.empty() && mp[q.front()] > 1)
        {
            q.pop();
        }
        
        res += (q.empty()) ? '#' : q.front();
    }
    
    return res;
}
