// https://www.geeksforgeeks.org/number-ways-form-heap-n-distinct-integers/

#define MOD 1000000007
#define MAXN 100

int log2v[MAXN];
long long nck[MAXN][MAXN]; 
long long dp[MAXN];

void precomputelog2v()
{
    int currLog2 = -1, currPow2 = 1;
    
    for(int i = 1; i <= MAXN; i++)
    {
        if(currPow2 == i)
        {
            currLog2++;
            currPow2 = currPow2 * 2;
        }
        
        log2v[i] = currLog2;
    }
}

int getLeft(int n)
{
    if(n == 1)
    {
        return 0;
    }
    
    int l;
    
    int h = log2v[n];
    // max number of elements that can be present in the  hth level of any heap (2^h)
    int m = (1 << h);
    // number of elements that are actually present in last level(hth level) (2^h - 1) 
    int p = (n - ((1 << h) - 1));
    
    // if more than half-filled (2^h - 1)
    // No of elements present till the last level = 2^(h+1) - 1
    // Remove the root from count, then no of elements = 2^(h+1) - 2
    // No of elements only in the left subtree before the last level = (2^(h+1) - 2) / 2 = (2^h - 1) 
    if(p >= m / 2)
    {
        l = m - 1;
    } else
    {
        // no of elements should present in the left subtree - no of elements missing in the last level
        l = (m - 1) - (m / 2 - p);
    }
    
    return l;
}

long long choose(int n, int k)
{
    if(k == 0 || k == n) return 1;
    if(k == 1) return n;
    
    if(nck[n][k] != -1) return nck[n][k];
    
    long long ans = (choose(n - 1, k) + choose(n - 1, k - 1)) % MOD;
    nck[n][k] = ans;
    
    return ans;
}

long long numberOfHeaps(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    
    if(dp[n] != -1)
    {
        return dp[n];
    }
    
    int left = getLeft(n);
    long long comb = choose(n - 1, left) % MOD;
    long long ans = (((comb * numberOfHeaps(left)) % MOD) * numberOfHeaps(n - left - 1)) % MOD;
    dp[n] = ans;
    
    return ans;
}

int Solution::solve(int A) {
    memset(nck, -1, sizeof(nck));
    memset(dp, -1, sizeof(dp));
    precomputelog2v();
    
    return numberOfHeaps(A); 
}
