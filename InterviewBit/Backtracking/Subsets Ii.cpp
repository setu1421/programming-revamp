// Time Complexity: O(2 ^ n)
// Space Complexity: O(n)

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

// Another approach: Without using set for duplicates
void helper(int index,vector<int> &A,vector<int> tempAns,vector<vector<int> > &ans)
{
    for(int i=index;i<A.size();i++)
    {
        tempAns.push_back(A[i]);
        ans.push_back(tempAns);
        helper(i+1,A,tempAns,ans);
		// don't take the duplicate elements
        while(i<A.size()-1 && A[i] == A[i+1])
            i++;
        tempAns.pop_back();
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> tempAns;
    ans.push_back(tempAns);
    if(A.size() == 0)
        return ans;
    sort(A.begin(),A.end());
    helper(0,A,tempAns,ans);
    return ans;
}

// Another approach: Using power set.
// https://www.techiedelight.com/print-distinct-subsets-given-set/
// Time Complexity: O(n * 2^n)
set<vector<int> > generateAllSubsets(vector<int> A)
{
    set<vector<int> > ans;
    int n = A.size();
    int total_subset = pow(2, n);
    
    for(int i = 0; i < total_subset; i++)
    {
        vector<int> subset;
        
        for(int j = 0; j < n; j++)
        {
            if(i & (1 << j))
            {
                subset.push_back(A[j]);
            }
        }
        
        ans.insert(subset);
    }
    
    return ans;
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());
    
    set<vector<int> > ans = generateAllSubsets(A);
    vector<vector<int> > final_res;
    final_res.assign(ans.begin(), ans.end());
    sort(final_res.begin(), final_res.end());
    
    return final_res;
}
