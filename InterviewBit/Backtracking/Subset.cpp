void subsetUtil(set<vector<int> > &ans, vector<int> A, vector<int> subset, int index)
{
	// If we have taken all the elements combinations, then add the subset to result.
    if(index == A.size())
    {
        ans.insert(subset);
        return;
    }
    // Not taking the current number and recurse for other numbers.
    subsetUtil(ans, A, subset, index + 1);
	// Taking the current number and recurse for other numbers.
    subset.emplace_back(A[index]);
    subsetUtil(ans, A, subset, index + 1);
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    
    set<vector<int> > ans;
    vector<int> subset;
    subsetUtil(ans, A, subset, 0);
    // copy the set of vector into a vector of vector. 
    vector<vector<int> > final_res;
    final_res.assign(ans.begin(), ans.end());

    return final_res;
}
