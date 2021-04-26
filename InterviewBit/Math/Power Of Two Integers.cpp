int Solution::isPower(int A) {
    if(A == 1)
    {
        return true;
    }
    
    for(int x = 2; x <= sqrt(A); x++)
    {
        unsigned long long product = x * x;
        // product > 0 is to avoid the overflow
        while(product <= A && product > 0)
        {
            if(product == A)
            {
                return true;
            }
            
            product = product * x;
        }
    }
    
    return false;
}

// Another approach: Using division
// https://www.youtube.com/watch?v=ixnSfyXhOfE
int Solution::isPower(int A) {
    if(A == 1)
    {
        return true;
    }
    
    for(int x = 2; x <= sqrt(A); x++)
    {
        int temp = A;
        while(temp > 1)
        {
            if(temp % x != 0)
            {
                break;
            }
            
            temp = temp / x;
        }
        
        if(temp == 1)
        {
            return true;
        }
    }
    
    return false;
}


// Another Solution: Using log properties
// https://stackoverflow.com/questions/63658617/power-of-two-integers#63658617
/*
9=3^2
Log 9 = log 3^2... Adding log at both side
Log 9 = 2 * log 3...using log property
2 = log 9 / log 3
*/
bool isPower(int a) 
{ 
    if (a == 1) 
        return true; 
  
    for (int i = 2; i <= sqrt(a); i++) { 
        double val = log(a) / log(i); 
        if ((val - (int)val) < 0.00000001) 
            return true; 
    } 
  
    return false; 
}
