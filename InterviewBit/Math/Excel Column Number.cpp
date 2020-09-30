int Solution::titleToNumber(string A) {
    int n = A.length();
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        ans += pow(26, i) * (A[n - i - 1] - 'A' + 1);
    }
    
    return ans;
}
