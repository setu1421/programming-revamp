// Using one map only.
vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    map<int, pair<int, bool> >mp;
    
    for(int i = 0; i < A.size(); i++)
    {
        mp.insert(make_pair(A[i], make_pair(1, false)));
    }
    
    for(int i = 0; i < B.size(); i++)
    {
        if(mp.find(B[i]) != mp.end() && mp[B[i]].second != true)
        {
            mp[B[i]] = make_pair(mp[B[i]].first + 1, true);
        } else
        {
            mp.insert(make_pair(B[i], make_pair(1, true)));
        }
    }
    
    for(auto &v: mp)
    {
        v.second.second = false;
    }
    
    for(int i = 0; i < C.size(); i++)
    {
        if(mp.find(C[i]) != mp.end() && mp[C[i]].second != true)
        {
            mp[C[i]] = make_pair(mp[C[i]].first + 1, true);
        } else
        {
            mp.insert(make_pair(C[i], make_pair(1, true)));
        }
    }
    
    vector<int>res;
    
    for(auto v: mp)
    {
        if(v.second.first >= 2)
        {
            res.push_back(v.first);
        }
    }
    
    return res;
}

// Using two maps
vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_map<int, int> count_mp, vis_mp;
    vector<int> res;
    
    for(int i = 0; i < A.size(); i++)
    {
        if(vis_mp[A[i]] == 0)
        {
            count_mp[A[i]]++;
            vis_mp[A[i]]++;
        }
    }
    
    vis_mp.clear();
    
    for(int i = 0; i < B.size(); i++)
    {
        if(vis_mp[B[i]] == 0)
        {
            count_mp[B[i]]++;
            vis_mp[B[i]]++;
        }
    }
    
    vis_mp.clear();
    
    for(int i = 0; i < C.size(); i++)
    {
        if(vis_mp[C[i]] == 0)
        {
            count_mp[C[i]]++;
            vis_mp[C[i]]++;
        }
    }
    
    for(auto v: count_mp)
    {
        if(v.second >= 2)
        {
            res.push_back(v.first);
        }
    }
    
    sort(res.begin(), res.end());
    
    return res;
}

