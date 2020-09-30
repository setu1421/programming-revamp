int M = 1000000007;

int Solution::hammingDistance(const vector<int> &A) {
    long long int n = A.size();
    long long int ans = 0;
    
    for(int i = 0; i < 32; i++)
    {
        int oneCount = 0;
        for(int j = 0; j < n; j++)
        {
            if (A[j] & (1 << i))
            {
                oneCount++;
            }
        }
        
        ans += (2 * oneCount * (n - oneCount)) % M;
    }
    
    return ans % M;
}
