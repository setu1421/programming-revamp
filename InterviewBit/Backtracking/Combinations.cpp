void combineUtil(vector<vector<int> > &ans, vector<int>subset, int A, int B, int index, int counter)
{
    // If already found B elements, then push to answer and return
    if(counter == B)
    {
        ans.push_back(subset);
        return;
    }
    // If we have finished all the elements from 1 to A, then return.
    if(index == A)
    {
        return;
    }
    // Not taking the element.
    combineUtil(ans, subset, A, B, index + 1, counter);
    // Taking the element.
    subset.push_back(index + 1);
    combineUtil(ans, subset, A, B, index + 1, counter + 1);
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int> > ans;
    vector<int> subset;
    
    combineUtil(ans, subset, A, B, 0, 0);
    // Sorting all the entries
    sort(ans.begin(), ans.end());
    
    return ans;
}
