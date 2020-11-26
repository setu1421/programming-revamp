void subsetsUtil(set<vector<int> > &ans, vector<int> &A, vector<int> subset, int index)
{
    if(index == A.size())
    {
        ans.insert(subset);
        return;
    }
    
    subsetsUtil(ans, A, subset, index + 1);
    subset.push_back(A[index]);
    subsetsUtil(ans, A, subset, index + 1);
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    set<vector<int> > ans;
    vector<int> subset;
    
    sort(A.begin(), A.end());
    subsetsUtil(ans, A, subset, 0);
    
    vector<vector<int> > final_res;
    final_res.assign(ans.begin(), ans.end());
    sort(final_res.begin(), final_res.end());
    
    return final_res;
}
