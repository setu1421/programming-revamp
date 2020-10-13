// https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/
/*
	Time Complexity: O(32 * r * log(c)). The upper bound function will take log(c) time and is performed for each row. And since the numbers will be max of 32 bit, so binary search of numbers from min to max will be performed in at most 32 ( log2(2^32) = 32 ) operations.
	Auxiliary Space : O(1)
*/
int Solution::findMedian(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    
	// Find the desired count of numbers
    int desired = ((r * c) + 1) / 2;
    
    int min_elem = INT_MAX, max_elem = INT_MIN;
    
    for(int i = 0; i < r; i++)
    {
        min_elem = min(min_elem, A[i][0]);
        max_elem = max(max_elem, A[i][c - 1]);
    }
    
    while(min_elem < max_elem)
    {
        int mid = min_elem + (max_elem - min_elem) / 2;
        int count = 0;
        
        // Count the number of elements less than or equal to mid
        for(int i = 0; i < r; i++)
        {
            count += upper_bound(&A[i][0], &A[i][c], mid) - &A[i][0];
        }
        
        if(count < desired)
        {
            min_elem = mid + 1;
        } else
        {
            // We are not doing mid - 1 because mid can also be a candidate for median
            max_elem = mid;
        }
    }
    
    return min_elem;
}
