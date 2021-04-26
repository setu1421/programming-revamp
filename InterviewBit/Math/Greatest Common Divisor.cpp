int Solution::gcd(int A, int B) {
    if(B == 0)
    {
        return A;
    }
    
    return gcd(B, A % B);
}

// Using Subtraction Method
// May throw time limit error
int Solution::gcd(int A, int B)  
{    
    while(A != B)  
    {  
        if(A > B)  
        {  
            A = A - B;  
        }  
        else  
        {  
            B = B - A;  
        }  
    }  
  
    return A;  
} 