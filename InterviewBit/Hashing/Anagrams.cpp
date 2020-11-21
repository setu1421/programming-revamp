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
