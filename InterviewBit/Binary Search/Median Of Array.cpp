// Time Complexity: O(log(min(x, y))
// https://www.youtube.com/watch?v=LPFhl65R7ww
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int x = A.size();
    int y = B.size();
    
    if(x > y)
    {
        return findMedianSortedArrays(B, A);
    }
    
    int low = 0, high = x;
    
    while(low <= high)
    {
        int partition_x = low + (high - low) / 2;
        int partition_y = ((x + y + 1) / 2) - partition_x;
        
        int maxLeftX = (partition_x == 0) ? INT_MIN : A[partition_x - 1];
        int maxLeftY = (partition_y == 0) ? INT_MIN : B[partition_y - 1];
        int minRightX = (partition_x == x) ? INT_MAX : A[partition_x];
        int minRightY = (partition_y == y) ? INT_MAX : B[partition_y];
        
        if(maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            if((x + y) % 2 == 0)
            {
                return (double) (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            } else 
            {
                return (double)(max(maxLeftX, maxLeftY));
            }
        } else if(maxLeftX > minRightY)
        {
            high = partition_x - 1;
        } else 
        {
            low = partition_x + 1;
        }
    }
}
