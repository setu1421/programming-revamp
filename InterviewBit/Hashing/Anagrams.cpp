// Time Complexity: O(n * klogk)
// sorting takes O(klogk) time and we have to do the sorting n times.

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    int n = A.size();
    
    unordered_map<string, vector<int> > mp;
    vector<vector<int> > ans;
    // Idea is to sort every string so that if anagrams present 
	// then it will fall into that sorted string key.
    for(int i = 0; i < n; i++)
    {
        string sorted_str = A[i];
        sort(sorted_str.begin(), sorted_str.end());
        // sort the string and save the the index with the key.
        mp[sorted_str].push_back(i + 1);
    }
    
    for(auto temp: mp)
    {
        ans.push_back(temp.second); 
    }
    
    return ans;
}


// Optimized Solution: Without sorting each string.
// Time Complexity: O(n * k)
// The idea is to create another map and use it as a key.
// https://www.youtube.com/watch?v=0I6IL3TnIZs  

vector<vector<int> > Solution::anagrams(const vector<string> &A)
{
    vector<vector<int> > ans;
    map<map<char, int>, vector<int> > mp;

    for(int i = 0; i < A.size(); i++)
    {
        map<char, int> key;

        for(int j = 0; j < A[i].size(); j++)
        {
            key[A[i][j]]++;
        }

        mp[key].push_back(i + 1);
    }
    
    for(auto c: mp)
    {
       ans.push_back(c.second); 
    }
        
    return ans;

}

// Another Solution: Using unordered_map. 
// If you want to use unordered_map of unordered_map, then we have to provide custom hash function for unordered_map

struct hash_unordered_map
{
    template <class T1, class T2>
    size_t operator()(const unordered_map<T1, T2> &p) const
    {
        auto final_hash = 0;

        for(auto c: p)
        {
            auto hash1 = hash<T1>{}(c.first);
            auto hash2 = hash<T2>{}(c.second);
            final_hash ^= hash1 ^ hash2;
        }

        return final_hash;
    }
};

vector<vector<int> > Solution::anagrams(const vector<string> &A)
{
    vector<vector<int> > ans;
    unordered_map<unordered_map<char, int>, vector<int>, hash_unordered_map> mp;

    for(int i = 0; i < A.size(); i++)
    {
        unordered_map<char, int> key;

        for(int j = 0; j < A[i].size(); j++)
        {
            key[A[i][j]]++;
        }

        mp[key].push_back(i + 1);
    }

    for(auto c: mp)
    {
       ans.push_back(c.second);
    }

    return ans;

}