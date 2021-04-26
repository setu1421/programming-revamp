// https://www.youtube.com/watch?v=G3n0WAWO3s0 (Multiplicative Modular Inverse)
// https://www.youtube.com/watch?v=L-Wzglnm4dM (Modular exponentiation)
// https://www.geeksforgeeks.org/lexicographic-rank-string-duplicate-characters/


#define MAX_LENGTH 1000003
#define MAX_CHAR 256
#define MOD 1000003

void computeFactorial(int *fact, int n)
{
    fact[0] = 1; fact[1] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        fact[i] = ((long long) (i * fact[i - 1])) % MOD;
    }
}

void calculateSmallestCharCount(string A, int *count, int *dup_count, int n)
{
    for(int i = 0; i < n; i++)
    {
        count[A[i]]++;
        dup_count[A[i]]++;
    }
    
    for(int i = 1; i < MAX_CHAR; i++)
    {
        count[i] += count[i - 1];
    }
}

void updateCount(int *count, int *dup_count, char ch)
{
    for(int i = ch; i < MAX_CHAR; i++)
    {
        count[i]--;
    }
    
    dup_count[ch]--;
}

long long modPow(long long a, int p)
{
    if(p == 0)
    {
        return 1;
    } else if(p % 2 == 0)
    {
        long long y = modPow(a, p / 2);
        return (y * y) % MOD;
    } else
    {
        return ((a % MOD) * modPow(a, p - 1) % MOD) % MOD;
    }
}

int Solution::findRank(string A) {
    long long rank = 1;
    int n = strlen(A.c_str());
    int fact[MAX_LENGTH];
    int count[MAX_CHAR] = {0};
    int dup_count[MAX_CHAR] = {0};
    
    computeFactorial(fact, n);
    calculateSmallestCharCount(A, count, dup_count, n);
    
    for(int i = 0; i < n; i++)
    {
        long long repeat = 1;
        long long temp;

        for(int i = 0; i < MAX_CHAR; i++)
        {
            if(dup_count[i] >= 2)
            {
                repeat = (repeat * fact[dup_count[i]]) % MOD;
            }
        }
        
        // Applying modular multiplicative inverse as MOD can't be applied to division
        // Taking Modular Inverse using Fermat's little Theorem.
        // If Mod is not prime then use Extended Euclidean Theorem to calculate Modular Inverse
        repeat = modPow(repeat, MOD - 2) % MOD;
        
        temp = (count[A[i] - 1] * fact[n - i - 1]) % MOD;
        temp = (temp * repeat) % MOD;

        rank = (rank + temp) % MOD;

        updateCount(count, dup_count, A[i]);
    }
    
    return rank;
}
