int Solution::solve(vector<int> &A) {
    int n = A.size();
    
    unordered_map<int, int>mp, repeat_mp;
    
    for(int i = 0; i < n; i++)
    {
        if(mp.find(A[i]) != mp.end())
        {
            repeat_mp.insert(make_pair(A[i], mp[A[i]]));
        } else
        {
            mp[A[i]] = i;
        }
    }
    
    int min_index = INT_MAX, ans;
    for(auto v: repeat_mp)
    {
        if(v.second < min_index)
        {
            ans = v.first;
            min_index = v.second;
        }
    }
    
    if(min_index == INT_MAX)
    {
        return -1;
    } else
    {
        return ans;
    }
}

// Another Solution without using two maps.
int Solution::solve(vector<int> &A) {
    int n = A.size(), res = -1;
    
    unordered_map<int, int>mp;
    
    for(int i = n - 1; i >= 0; i--)
    {
        if(mp.find(A[i]) != mp.end())
        {
            res = A[i];
        }
        
       mp.insert(make_pair(A[i], 1));
    }
    
    return res;
}
