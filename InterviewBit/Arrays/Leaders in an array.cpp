vector<int> Solution::solve(vector<int> &A) {
    vector<int> res;
    
    int n = A.size();
    // Need to keep track of the maximum element value found so far
    int max_found_so_far = A[n - 1];
    // The rightmost element is always a leader.
    res.push_back(max_found_so_far);
    
    for(int i = n - 2; i >=0; i--)
    {
        if(A[i] > max_found_so_far)
        {
            res.push_back(A[i]);
            max_found_so_far = A[i];
        }
    }
    
    return res;
}
