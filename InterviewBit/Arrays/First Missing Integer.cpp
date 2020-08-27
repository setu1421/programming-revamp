
int Solution::firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    bool containsOne = false;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] == 1)
        {
            containsOne = true;
        } else if(A[i] <= 0 || A[i] > n)
        {
            A[i] = 1;
        }
    }
    
    // Case 1: when the missing no. will be one and we don't have one in the original array
    if(containsOne == false)
    {
        return 1;
    }
    
    
    for(int i = 0; i < n; i++)
    {
        int markValue = abs(A[i]);
        
        if(A[markValue - 1] > 0)
        {
            A[markValue - 1] = - A[markValue - 1];
        }
    }
    
    // Case 2: When we find missing no. in range of 1 to n
    for(int i = 1; i < n; i++)
    {
        if(A[i] > 0)
        {
            return i + 1;
        }
    }
    
    // Case 3: When there is no missing no. in range of 1 to n.    
   return n + 1;
}
