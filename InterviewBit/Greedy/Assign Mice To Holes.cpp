int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int n = A.size();
    
    if(n < 1)
    {
        return 0;
    }
    
    int res = INT_MIN;
    
    for(int i = 0; i < n; i++)
    {
        res = max(res, abs(A[i] - B[i]));
    }
    
    return res;
}
