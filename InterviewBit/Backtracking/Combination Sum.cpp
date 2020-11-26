void subsetUtil(set<vector<int> > &ans, vector<int> &A, int B, vector<int> subset, int index, int sum)
{
    if(sum == B)
    {
        sort(subset.begin(), subset.end());
        ans.insert(subset);
        return;
    }

    if(sum > B || index == A.size())
    {
        return;
    }
    // Not taking the element
    subsetUtil(ans, A, B, subset, index + 1, sum);
    // Taking the element
    subset.push_back(A[index]);
    // Taking the element as much as we can. 
    // That's why we are not moving the index to take next element.
    subsetUtil(ans, A, B, subset, index, sum + A[index]);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    
    set<vector<int> > ans;
    vector<int> subset;
    
    subsetUtil(ans, A, B, subset, 0, 0);
    
    vector<vector<int> > final_res;
    final_res.assign(ans.begin(), ans.end());
    sort(final_res.begin(), final_res.end());
    
    return final_res;
}
