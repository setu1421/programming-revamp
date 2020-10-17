// https://www.youtube.com/watch?v=QYoWR8hDCyQ
int findForRev(int n)
{
    int rev = 0;
    
    while(n > 0)
    {
        int lsb = (n & 1);
        rev |= lsb;
        rev <<= 1;
        n >>= 1;
    }
    rev >>= 1;
    
    return rev;
}

int Solution::solve(int A) {
    // Base cases
    if(A == 1) return 1;
    if(A == 2) return 3;
    
    int count = 1, len = 1;
    
    while(count < A)
    {
        len++;
        count += (1 << (len - 1) / 2);
    }
    
    count -= (1 << (len - 1) / 2);
    int offset = (A - count - 1);
    
    int ans = (1 << (len - 1));
    offset <<= (len / 2);
    ans |= offset;
    
    int forRev = (ans >> (len / 2));
    int rev = findForRev(forRev);
    ans |= rev;
    
    return ans;
}
