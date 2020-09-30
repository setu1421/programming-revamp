int Solution::isPower(int A) {
    if(A == 1)
    {
        return true;
    }
    
    for(int x = 2; x <= sqrt(A); x++)
    {
        unsigned long long product = x * x;
        
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

// Another Solution: Using log properties
// https://stackoverflow.com/questions/63658617/power-of-two-integers#63658617

bool isPower(int a) 
{ 
    if (a == 1) 
        return true; 
  
    for (int i = 2; i * i <= a; i++) { 
        double val = log(a) / log(i); 
        if ((val - (int)val) < 0.00000001) 
            return true; 
    } 
  
    return false; 
}
