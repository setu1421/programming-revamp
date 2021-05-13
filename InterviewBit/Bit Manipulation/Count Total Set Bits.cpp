// https://www.youtube.com/watch?v=g6OxU-hRGtY

#define MOD 1000000007

// Find the highest number of twos power less than A
int findHighestNoUsingTwosPower(int A)
{
    int x = 0;
    
    while((1 << x) <= A)
    {
        x++;
    }
    
    return x - 1;
}

int Solution::solve(int A) {
    long long counter = 0ll;
    
    while(A > 0)
    {
        int x = findHighestNoUsingTwosPower(A);
        
        long long temp = ((pow(2, x - 1)) * x) + (A - pow(2, x) + 1);
        
        counter = (counter + temp) % MOD;
        
        A = A - pow(2, x);
    }
    
    return counter;
}

// Another Approach: if A is less than 10^6 so that we will not get memory limit exceed error.
// x/2 = y : the number of bits in y is same as x for even number but 1 addition for odd number
// no of bits of x = no of bits of y (even number)
// no of bits of x = no of bits of y + 1 (odd number)
#define MOD 1000000007

int Solution::solve(int A) {
    long long lookup[A];
    
    lookup[0] = 0;
    long long counter = 0ll;
    
    for(int i = 1; i <= A; i++)
    {
        long long temp = (lookup[i / 2] + ((i & 1) ? 1 : 0));
        counter = (counter + temp) % MOD;
        lookup[i] = temp;
    }
    
    return counter;
}
