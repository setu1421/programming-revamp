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
