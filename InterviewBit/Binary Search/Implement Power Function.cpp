int modPow(int x, int n, int d)
{
    if(n == 1)
    {
        return x % d;
    }
    
    long long y = modPow(x, n / 2, d) % d;
    long long ans = (y * y) % d;
    
    if(n & 1)
    {
        ans = (ans * x) % d;
    }
    
    return ans;
}
int Solution::pow(int x, int n, int d) {
    if(x == 0)
    {
        return 0;
    }
    
    if(n == 0)
    {
        return 1;
    }
    
    long long ans = modPow(x, n, d);
    
    // Make negative remainder to positive remainder
    if(ans < 0)
    {
        ans = (ans + d) % d;
    }
    
    return ans;
}
