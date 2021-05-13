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

/*
It's hard to reverse all 32 bits (assuming this as size of int) in one go using lookup table (” because it’s infeasible to create lookup table of size 2^32-1 “). So we break 32 bits into 8 bits of chunks( lookup table of size 2^8-1 “0-255”).

Lookup Table:
in lookup tale we will store reverse of every number that are in a range( 0-255)

LookupTable[0] = 0 | binary 00000000 Reverse 00000000
LookupTable[1] = 128 | binary 00000001 reverse 10000000
LookupTable[2] = 64 | binary 00000010 reverse 01000000
LookupTanle[3] = 192 | binary 00000011 reverse 11000000
LookupTable[4] = 32 | binary 00000100 reverse 00100000
and so on… upto lookuptable[255].

Let’s take an Example How lookup table work.
let number = 12456
in Binary = 00000000000000000011000010101000

Split it into 8 bits chunks  :  00000000 | 00000000 | 00110000 | 10101000
         in decimal          :     0          0          48       168
reverse each chunks using lookup table :
Lookuptable[ 0 ] = 0  | in binary 00000000
Lookuptable[48 ] = 12 | in binary 00001100
Lookuptable[168] = 21 | in binary 00010101
 
Now Binary :  
00000000 | 00000000 | 00001100 | 00010101

Binary chunks after rearrangement : 
00010101 | 00001100 | 00000000 | 00000000   
  
Reverse of 12456 is 353107968

*/



