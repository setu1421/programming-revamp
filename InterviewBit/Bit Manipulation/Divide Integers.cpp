// https://www.youtube.com/watch?v=htX69j1jf5U&t=347s
int Solution::divide(int A, int B) {
    // overflow case A = -2^31 , B = -1
    if(A == INT_MIN && B == -1)
    {
        return INT_MAX;
    } else if(A == INT_MIN && B == 1)
    {
        return INT_MIN;
    }
    
    bool isNegative = (A < 0) ^ (B < 0);
    
    long long dividend = abs((long long) A), divisor = abs((long long) B), quotient = 0;
    
    // Some Corner Cases
    if(dividend == INT_MAX && divisor == 1)
    {
        return (isNegative) ? -dividend : dividend;
    }
    
    
    while(dividend - divisor >= 0)
    {
        int x = 0;
        
        while(dividend - (divisor << (1 << x)) >= 0)
        {
            x++;
        }
        // 3 << x = 3 * 2^x = 3 * (1 << x)
        quotient += (1 << x);
        dividend -= (divisor << x);
    }
    
    return (isNegative) ? -quotient : quotient;
}
