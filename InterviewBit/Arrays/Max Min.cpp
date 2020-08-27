// Using less comparisons
int Solution::solve(vector<int> &A) {
    int minValue = INT_MAX, maxValue = INT_MIN, i = 0;
    
    int n = A.size();
    
    if(n % 2 == 0)
    {
        if(A[0] > A[1])
        {
            maxValue = A[0];
            minValue = A[1];
        } else 
        {
            maxValue = A[1];
            minValue = A[0];
        }
        
        i = 2;
    } else 
    {
        maxValue = minValue = A[0];
        i = 1;
    }
    
    while(i < n - 1)
    {
        if(A[i] > A[i + 1])
        {
            maxValue = max(maxValue, A[i]);
            minValue = min(minValue, A[i + 1]);
        } else 
        {
            maxValue = max(maxValue, A[i + 1]);
            minValue = min(minValue, A[i]);
        }
        
        i += 2;
    }
    
    return maxValue + minValue;
}
