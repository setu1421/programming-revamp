/*
Now, first try to think if you were already given the minimum value MIN and maximum value MAX in the array of size N, under what circumstances would the max gap be minimum and maximum ?

Obviously, maximum gap will be maximum when all elements are either MIN or MAX making maxgap = MAX - MIN.

Maximum gap will be minimum when all the elements are equally spaced apart between MIN and MAX. Lets say the spacing between them is gap.

So, they are arranged as

MIN, MIN + gap, MIN + 2*gap, MIN + 3*gap, ... MIN + (N-1)*gap 
where

MIN + (N-1)*gap = MAX 
=> gap = (MAX - MIN) / (N - 1). 
So, we know now that our answer will lie in the range [gap, MAX - MIN].
Now, if we know the answer is more than gap, what we do is create buckets of size gap for ranges

  [MIN, MIN + gap), [Min + gap, `MIN` + 2* gap) ... and so on
There will only be (N-1) such buckets. We place the numbers in these buckets based on their value.

If you pick any 2 numbers from a single bucket, their difference will be less than gap, and hence they would never contribute to maxgap ( Remember maxgap >= gap ). We only need to store the largest number and the smallest number in each bucket, and we only look at the numbers across bucket.

Now, we just need to go through the bucket sequentially ( they are already sorted by value ), and get the difference of min_value with max_value of previous bucket with at least one value. We take maximum of all such values.

*/

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
