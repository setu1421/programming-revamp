// https://www.youtube.com/watch?v=uUN8fVPrJn0
// https://www.geeksforgeeks.org/lexicographic-rank-of-a-string/

#define MAX_CHAR 256
#define MOD 1000003
#define MAX_LENGTH 27

long long fact[MAX_LENGTH];

void prepareSmallerCharCount(int *count, string A, int n)
{
    // Give count 1 to respective characters of the string
    for(int i = 0; i < n; i++)
    {
        count[A[i]]++;
    }

    // Count no. of characters less than particular character
    for(int i = 1; i < MAX_CHAR; i++)
    {
        count[i] += count[i - 1];
    }
}

void updateCharacterCount(int *count, char ch)
{
    for(int i = ch; i < MAX_CHAR; i++)
    {
        count[i]--;
    }
}

// Compute the factorial with MOD as it can be bigger
void computeFactorial(int n)
{
    fact[0] = 1; fact[1] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        fact[i] = ((long long) i * fact[i - 1]) % MOD;
    }
}

int Solution::findRank(string A) {
    int n = A.length();
    int count[MAX_CHAR] = {0};
    long long ans = 1;
    
    computeFactorial(n);
    prepareSmallerCharCount(count, A, n);

    for(int i = 0; i < n; i++)
    {
        char c = A[i];
        ans += (fact[n - i - 1] * count[c - 1]) % MOD;
        // Update the character count for greater than and equal to the character
        // as one character will appear only once and we have fixed the position of this
        // particular character
        updateCharacterCount(count, c); // Though the solution says O(N) time complexity. May be thinking the updateCharacterCount functions as amortized O(1) (Not Sure)
    }

    return ans % MOD;

}