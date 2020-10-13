int Solution::solve(string A) {
    int n = A.length();
    
    int count = 0;
    
    int i = 0, j = n - 1;
    
    while(i < j)
    {
		// only one removal allowed. So, palindrome not possible if we do two removals.
        if(count > 1)
        {
            return 0;
        }
        
		// If the characters matching, then check with next set of characters
        if(A[i] == A[j])
        {
            i++;
            j--;
        } // Remove A[i] character and check with next character from left to the right character
		else if(A[i + 1] == A[j])
        {
            count++;
            i += 2;
            j--;
        } // Remove A[j] character and check with next character from right to the left character
		else if(A[i] == A[j - 1])
        {
            count++;
            i++;
            j -= 2;
        } // only one removal allowed. So, palindrome not possible if we do two removals.
		else 
        {
            return 0;
        }
    }
    
    if(count > 1)
    {
        return 0;
    } else 
    {
        return 1;
    }
}
