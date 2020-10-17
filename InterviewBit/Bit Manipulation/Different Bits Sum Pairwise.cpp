// Hamming Distance

#define MOD 1000000007

int Solution::cntBits(vector<int> &A) {
    int n = A.size();
    long long counter = 0;
    
    for(int i = 0; i < 32; i++)
    {
        long long countOne = 0;
        
        for(int j = 0; j < n; j++)
        {
            if(A[j] & (1 << i))
            {
                countOne = (countOne + 1) % MOD;
            }
        }
        
        counter = (counter + ((2 * countOne * (n - countOne) % MOD))) % MOD;
    }
    
    return counter;
}
