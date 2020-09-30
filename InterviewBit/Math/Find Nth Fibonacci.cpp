// Time Complexity: O(logn)
// Space Complexity: O(logn)
// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

#define MOD 1000000007

void multiply(long long F[2][2], long long M[2][2])
{
    long long x = ((F[0][0] * M[0][0]) % MOD + (F[0][1] * M[1][0]) % MOD) % MOD;
	long long y = ((F[0][0] * M[0][1]) % MOD + (F[0][1] * M[1][1]) % MOD) % MOD;
	long long z = ((F[1][0] * M[0][0]) % MOD + (F[1][1] * M[1][0]) % MOD) % MOD;
	long long w = ((F[1][0] * M[0][1]) % MOD + (F[1][1] * M[1][1]) % MOD) % MOD;
	
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(long long F[2][2], int n)
{
    //Base Case
    if(n == 0 | n == 1)
    {
        return;
    }
    
    power(F, n / 2);
    multiply(F, F);
    
    if(n & 1)
    {
        long long M[2][2] = {{1, 1}, {1, 0}};
        multiply(F, M);
    }
}


int Solution::solve(int A) {
   if(A == 0)
   {
       return 0;
   }
   
   long long F[2][2] = {{1, 1}, {1, 0}};
   
   power(F, A - 1);
   
   return F[0][0];
}
