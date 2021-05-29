void combineSumUtil(set<vector<int> > &ans, vector<int> &A, int B, vector<int> subset, int index, int sum)
{
    if(sum == B)
    {
        ans.insert(subset);
        return;
    }
    
    if(sum > B || index == A.size())
    {
        return;
    }
    // Not taking the element
    combineSumUtil(ans, A, B, subset, index + 1, sum);
	// Taking the element
    subset.push_back(A[index]);
    combineSumUtil(ans, A, B, subset, index + 1, sum + A[index]);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
	// unordered_set can't be used as unordered_set of vector does not work.
	// To make it work, we have to provide own hash functions. https://stackoverflow.com/questions/29855908/c-unordered-set-of-vectors
    set<vector<int> > ans;
    vector<int> subset;
    
    combineSumUtil(ans, A, B, subset, 0, 0);
    
    vector<vector<int> > final_res;
    final_res.assign(ans.begin(), ans.end());
    
    return final_res;
}
