int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    // If only one element present in the array
    if(n < 2)
    {
        return 0;
    }
    
    int minVal = *min_element(A.begin(), A.end());
    int maxVal = *max_element(A.begin(), A.end());
    
    float gap = (float) (maxVal - minVal) / (float) (n - 1);
    
    int minBucket[n - 1];
    int maxBucket[n - 1];
    
    fill_n(maxBucket, n - 1, INT_MIN); 
    fill_n(minBucket, n - 1, INT_MAX);
    
    for(int i = 0; i < n; i++)
    {
        // If the value is the minimum and maximum value, 
        // then no need to place this in the bucket
        if(A[i] == minVal || A[i] == maxVal)
        {
            continue;
        }
        // Calculate the index of bucket where the value will fall.
        int idx = (A[i] - minVal) / gap;
        // Update the bucket's min and max value
        minBucket[idx] = min(minBucket[idx], A[i]);
        maxBucket[idx] = max(maxBucket[idx], A[i]);
        
    }
    
    int prev_val = minVal, max_gap = 0;
    
    for(int i = 0; i < n - 1; i++)
    {
        // Check whether any values is been placed in that bucket or not.
        // If not, we should skip that bucket.
        if(minBucket[i] == INT_MAX)
        {
            continue;
        }
        
        max_gap = max(max_gap, minBucket[i] - prev_val);
        // Update the max value of the bucket as previous value  
        prev_val = maxBucket[i];
    }
    // Check with maximum value finally
    max_gap = max(max_gap, maxVal - prev_val);
    
    return max_gap;
}
