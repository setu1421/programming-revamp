// https://www.algostreak.com/post/stringoholics-interviewbit-solution

#define MOD 1000000007

int findSmallestString(string A)
{
    int n = A.length();
    vector<int> lps(n + 1, 0);
    int index = 0, i = 1;
    
    while(i < n)
    {
        if(A[index] == A[i])
        {
            lps[i] = index + 1;
            index++;
            i++;
        } else
        {
            if(index != 0)
            {
                index = lps[index - 1];
            } else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    int t1 = lps[n - 1];
    int t2 = n - t1;
    
    if(t1 < t2 || (t1 % t2 != 0)) return n;
    
    return t2;
}

int Solution::solve(vector<string> &A) {
    int n = A.size();
    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
    {
        long long len = findSmallestString(A[i]);
        long long k = 1;
        while(1)
        {
            long long rotates = (k * (k + 1)) / 2;
            if(rotates % len == 0)
            {
                v[i] = k;
                break;
            }
            k++;
        }
    }
    
    long long ans = 1ll;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n && v[i] != 1; j++)
        {
            v[j] = v[j] / __gcd(v[i], v[j]);
        }
        
        ans = ((ans % MOD) * (v[i] % MOD)) % MOD;
    }
    
    return ans;
}

/*

With respect to a single string, the total number of bits rotated after N operations is 1+2+3+….+N which is (N*(N+1))/2.
We get back the original string only when the total number of rotated bits is a multiple of the length of the string S(LEN).

This can be done in O(N) time for each string (Summation of length of all strings is <= 1e6), by finding all (N(N+1))/2 where N starts from 1 and goes upto (2LEN-1).

But there is a catch, this wont always give you the minimum number of operations.
Its possible that during rotation, you can get the original string before the number of bits rotated is a multiple of LEN.

Example: S=> 100100
Here, in 2 operations, we get the original string back.
This takes place because the string is made up of recurring substrings.

Assume string A to be 100
S => AA
Hence, over here our length S of string is the length of recurring substring A, so N*(N+1)/2 should be a multiple of length of A.

Length of recurring substring can easily be found out using KMP algorithm in O(N) time complexity for each string.

Find the minimum number of operations for each string, and take the LCM of all these values to get the answer.
Handling of overflow for LCM should be handled by breaking the number down into factors, and then taking LCM (Not needed for languages that don’t have integer limit).

Hence total time complexity is O(N).

*/