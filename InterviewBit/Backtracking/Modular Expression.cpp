long long power(int A, int B, int C)
{
    if(B == 0) return 1;
    
    long long temp = power(A, B / 2, C);
    temp = (temp * temp) % C;
    
    if(B & 1)
    {
        temp = (temp * A) % C;
    }
    
    return temp;
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
