// Time Complexity: O(n) -> n is the number of bits (32)
int Solution::numSetBits(unsigned int A) {
    int count = 0;
    
    for(int i = 0; i <= 31; i++)
    {
        if(A & (1 << i))
        {
            count++;
        }
    }
    
    return count;
}

// Efficient Approach: Using Brian Kernighan's Algorithm
// Time Complexity: O(no. of set bits in the number)
// https://medium.com/@sanchit3b/brian-kernighans-algorithm-9e0ca5989148
int Solution::numSetBits(unsigned int A) {
    int count = 0;
    
    while(A != 0)
    {
        A = A & (A - 1);
        count++;
    }
    
    return count;
}