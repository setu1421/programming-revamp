int Solution::singleNumber(const vector<int> &A) {
    int n = A.size();
    int res = A[0];
    
    for(int i = 1; i < n; i++)
    {
        res = res ^ A[i];
    }
    
    return res;
}