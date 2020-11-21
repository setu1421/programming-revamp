vector<int> Solution::equal(vector<int> &A) {
    int n = A.size();
    // we are not saving a vector of pairs as it is enough to check only with first pair
    // since we need only the smallest solution.
    // Go though all the vector of pairs and check with combinations will give TLE.
    unordered_map<int, pair<int, int> > mp;
    vector<vector<int> > ans;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int sum = A[i] + A[j];
            // if we have found (C + D), 
            // then check if this pair is valid for all the conditions or not.
            if(mp.find(sum) != mp.end())
            {
                pair<int, int> value = mp[sum];
                
                if(value.first < i && value.second != j && value.second != i)
                {
                    vector<int> temp;
                    temp.push_back(value.first);
                    temp.push_back(value.second);
                    temp.push_back(i);
                    temp.push_back(j);
                    
                    ans.push_back(temp);
                }
            } else
            {
                // store the indices with the sum key (A + B)
                mp[sum] = make_pair(i, j);
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    
    if(ans.size() > 0)
    {
        return ans[0];
    } else
    {
        return {};
    }
}
