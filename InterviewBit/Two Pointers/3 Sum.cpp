int Solution::threeSumClosest(vector<int> &A, int B) {
    int n = A.size();
    int closestDiff = INT_MAX;
    int closestSum = 0;
    
    sort(A.begin(), A.end());
    
    for(int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1;
        
        while(left < right)
        {
            int sum = A[i] + A[left] + A[right];
            int diff = abs(sum - B);
            // if the diff is 0, then no need to check more.
            if(diff == 0)
            {
                return sum;
            } // if sum is bigger, then we have to truncate sum. 
            // So, use less values from right
            else if(sum > B)
            {
                right--;
            } else
            {
                left++;
            }
            
            // update the closestDiff and closestSum
            if(diff < closestDiff)
            {
                closestDiff = diff;
                closestSum = sum;
            }
        }
    }
    
    return closestSum;
}


/*
Lets sort the array.
When the array is sorted, try to fix the least integer by looping over it.
Lets say the least integer in the solution is arr[i].

Now we need to find a pair of integers j and k, such that arr[j] + arr[k] is closest to (target - arr[i]).
To do that, let us try the 2 pointer approach.
If we fix the two pointers at the end ( that is, i+1 and end of array ), we look at the sum.

1. If the sum is smaller than the sum we need to get to, we increase the first pointer.
2. If the sum is bigger, we decrease the end pointer to reduce the sum.

*/