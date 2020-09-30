// Explanation: https://www.youtube.com/watch?v=wkvVdggCSeo
int Solution::trailingZeroes(int A) {
    
    if(A < 5)
    {
        return 0;
    }
    
    int countOfZero = 0;
    
	// We are dividing by 5 as on each multiple of 5 position we will get 5. And 
	// There are special cases for 25, 125 etc..
    while(A >= 5)
    {
        countOfZero += (A / 5);
		// Dividing A to handle special cases of 25, 125 etc.
        A = A / 5;
    }
    
    return countOfZero;
}
