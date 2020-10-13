long long findChoppedMeters(vector<int> &A, int n, long long mid)
{
    long long sum = 0ll;
    
    for(int i = 0; i < n; i++)
    {
        // Exclude all those trees by which sawblade can not reach because of height
        if(A[i] > mid)
        {
            sum += A[i] - mid;
        }
    }
    
    return sum;
}

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    
    long long low = 0ll, high = INT_MIN, ans = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        high = max(high, (long long) A[i]);
    }
    
    while(low <= high)
    {
        long long mid = low + (high - low) / 2;
        
        long long choppedMeters = findChoppedMeters(A, n, mid);
        
        // If the chopped meters are greater than or equal to B, then we can higher up the sawblade
        if(choppedMeters >= B)
        {
            ans = max(ans, mid);
            low = mid + 1;
        } else 
        {
            high = mid - 1;
        }
    }
    
    return ans;
}
