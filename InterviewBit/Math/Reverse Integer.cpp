/*
Here are some good questions to ask before coding.

If the integer’s last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
*/

int Solution::reverse(int A) {
	// This is overflow.
	if(A == INT_MIN) return 0;
	
    bool isNeg = false;
    long long tempA = A;
	
    
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
