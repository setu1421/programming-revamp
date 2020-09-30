int Solution::reverse(int A) {
    bool isNeg = false;
    int tempA = A;
    
    // Converting to positive number before reversing
    if(A < 0)
    {
        isNeg = true;
        tempA = - A;
    }
    
    long long total = 0;
    
    while(tempA > 0)
    {
        int rem = tempA % 10;
        total = total * 10 + rem;
        
        // If the current total already exceeds INT_MAX limit, then return 0
        if(total > INT_MAX)
        {
            return 0;
        }
        
        tempA = tempA / 10;
    }
    
    // Finally convert the total to negative if originally it was negative number
    if(isNeg)
    {
        total = - total;
    }
    
    return total;
}
