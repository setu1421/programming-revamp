int Solution::isPalindrome(int A) {
    int n = A;
    int total = 0;
    
	// Getting the last digit using mod and building the sum from front
    while(n > 0)
    {
        int rem = n % 10;
        total = total * 10 + rem;   
        n = n / 10;
    }
    
	// Finally Checking if it correct or not
    if(total == A)
    {
        return 1;
    } else 
    {
        return 0;
    }
}
