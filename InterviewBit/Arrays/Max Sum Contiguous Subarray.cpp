#include <bits/stdc++.h>
using namespace std;

int Solution::maxSubArray( const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int global_max = INT_MIN, local_max = 0;
    
    for(int i = 0; i < A.size(); i++)
    {
        local_max = max(A[i], local_max + A[i]);
        global_max = max(local_max, global_max);
    }
    
    return global_max;
}