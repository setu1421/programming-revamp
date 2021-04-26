/*
An Efficient Solution can solve this problem in O(n) time using the fact that all numbers are represented using 32 bits (or some fixed number of bits). The idea is to count differences at individual bit positions. We traverse from 0 to 31 and count numbers with i’th bit set. Let this count be ‘count’. There would be “n-count” numbers with i’th bit not set. So count of differences at i’th bit would be “count * (n-count) * 2”, the reason for this formula is as every pair having one element which has set bit at i’th position and second element having unset bit at i’th position contributes exactly 1 to sum, therefore total permutation count will be count*(n-count) and multiply by 2 is due to one more repetition of all this type of pair as per given condition for making pair 1<=i, j<=N.

*/

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
