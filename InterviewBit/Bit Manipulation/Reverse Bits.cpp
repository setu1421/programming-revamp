// Time Complexity: O(log A)
// Bit shifting takes O(1) time
// https://www.youtube.com/watch?v=i4mB2tjeRes
unsigned int Solution::reverse(unsigned int A) {
    unsigned int rev_A = 0;
    
    for(int i = 0; i < 32; i++)
    {
        rev_A |= ((A >> i) & 1) << (32 - i - 1);
    }
    
    return rev_A;
}

// Another Approach using Reverse Cache
// https://www.geeksforgeeks.org/reverse-bits-using-lookup-table-in-o1-time/
// https://www.youtube.com/watch?v=4HFm8kbpkcA
unsigned int reverse_bit(unsigned int A)
{
    unsigned int rev_A = 0;
    
    for(int i = 0; i < 8; i++)
    {
        rev_A |= ((A >> i) & 1) << (8 - i - 1);
    }
    
    return rev_A; 
}

void precompute_Reverse_Cache(unsigned int *rev_cache)
{
    for(int i = 0; i < 256; i++)
    {
        rev_cache[i] = reverse_bit(i);
    }
}

unsigned int Solution::reverse(unsigned int A) {
    unsigned int rev_cache[256];
    precompute_Reverse_Cache(rev_cache);
    
    unsigned int rev_num = 0;
    
    rev_num = (rev_cache[A & 0xff] << 24) |
              (rev_cache[(A >> 8) & 0xff] << 16) |
              (rev_cache[(A >> 16) & 0xff] << 8) |
              (rev_cache[(A >> 24) & 0xff]);
              
    return rev_num;          
}

