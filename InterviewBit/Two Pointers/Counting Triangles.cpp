#define MOD 1000000007

int Solution::nTriang(vector<int> &A) {
    int n = A.size();
    long long count = 0;
    
    sort(A.begin(), A.end());
    
    for(int i = n - 1; i >= 0; i--)
    {
        int l = 0, r = i - 1;
        
        while(l < r)
        {
            long long sum = (long long) A[l] + (long long) A[r];
            
            if(sum > A[i])
            {
                // If it is possible with A[l], A[r]
                // and A[i] then it is also possible
                // with A[l+1]..A[r-1], A[r] and A[i] 
                count = (count + (r - l)) % MOD;
                // checking for more possible solutions
                r--;
            } else
            {
                // if not possible check for higher values of A[l] 
                l++;
            }
        }
    }
    
    return count;
}
