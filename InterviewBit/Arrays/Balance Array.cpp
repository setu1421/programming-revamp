int Solution::solve(vector<int> &A) {
    int n = A.size();
    
    // Edge Cases
    if(n == 0)
    {
        return 0;
    } else if(n == 1)
    {
        return 1;
    }
    
    int odd_sum = 0, even_sum = 0, ans = 0;
    
    // Calculate the total sum at even index and odd index
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            even_sum += A[i];
        } else 
        {
            odd_sum += A[i];
        }
    }
    
    // Check whether removing the first element equals the sum or not
    even_sum -= A[0];
    if(even_sum == odd_sum)
    {
        ans++;
    }
    
    // Check whether removing each element equals the sum or not
    for(int i = 1; i < n; i++)
    {
        if(i % 2 == 0)
        {
            even_sum -= A[i];
            even_sum += A[i - 1];
        } else 
        {
            odd_sum -= A[i];
            odd_sum += A[i - 1];
        }
        
        if(even_sum == odd_sum)
        {
            ans++;
        }
    }
    
    return ans;
    
}
