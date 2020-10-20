vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int m = A.size(), n = B.size();
    int i = 0, j = 0;
    vector<int>res;
    
    while(i < m && j < n)
    {
        if(A[i] == B[j])
        {
            res.push_back(A[i]);
            i++;
            j++;
        } else if(A[i] > B[j])
        {
            j++;
        } else
        {
            i++;
        }
    }
    
    return res;
}
