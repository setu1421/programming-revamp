// https://math.stackexchange.com/questions/2877565/greatest-number-that-divides-x-and-is-coprime-with-y
// Time: O(log A * log B)
int findGCD(int A, int B)
{
    if(B == 0)
    {
        return A;
    }
    
    return findGCD(B, A % B);
}

int Solution::cpFact(int A, int B) {
    int gcd_A_B;
    
    while(1)
    {
        gcd_A_B = findGCD(A, B);
        
        if(gcd_A_B == 1)
        {
            break;
        }
        
        A = A / gcd_A_B;
    }
    
    return A;
}
