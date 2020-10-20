#define MOD 1000000007

int Solution::nTriang(vector<int> &A) {
    int n = A.size();
    long long count = 0;
    
    sort(A.rbegin(), A.rend());
    
    for(int i = 0; i < n - 2; i++)
    {
        int l = i + 1;
        int r = n - 1;
        
        while(l < r)
        {
            long long sum = (long long) A[l] + (long long) A[r];
            
            if(sum > A[i])
            {
                // If it is possible with A[l], A[r] 
                // and a[i] then it is also possible 
                // with a[r], a[r-1], a[r-2]... a[l+1], a[l] and a[i] 
                count = (count + (r - l)) % MOD;
                // checking for more possible solutions
                l++;
            } else
            {
                // if not possible check for higher values of A[r] 
                r--;
            }
        }
    }
    
    return count;
}
