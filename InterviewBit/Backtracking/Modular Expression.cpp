long long power(int A, int B, int C)
{
    if(B == 0) return 1;
    
    if(B % 2 == 0)
    {
        return (power(A, B / 2, C) * power(A, B / 2, C)) % C;
    } else
    {
        return (power(A, B - 1, C) * A) % C;
    }
}

int Solution::Mod(int A, int B, int C) {
    // Make it positive for negative numbers.
    if(A < 0)
    {
        A = (A + C);
    }
    if(A == 0) return 0;
    
    return power(A, B, C);
}
