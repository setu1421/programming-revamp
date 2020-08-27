int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    
    int result = 0;
    
    for(int i = 0; i < B; i++)
    {
        result += A[i];
    }
    
    int sum = result;
    // Remove from the end of one part and add from the start of another part.
	// Finally check if it is the maximum sum or not.
    for(int i = 0; i < B; i++)
    {
        sum -= A[B - 1 - i];
        sum += A[n - 1- i];
        
        result = max(result, sum);
    }
    
    return result;
}
