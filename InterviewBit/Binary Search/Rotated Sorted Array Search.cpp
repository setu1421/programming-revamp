// It will not work if duplicates are present. If duplicates are present, it is not possible to find if left part is increasing or right part is increasing.
// For example: 1 1 1 1 2 0 1 1 1(mid) 1 1 1 1 1 1 1 1 
// Here, according to our logic, the left part is strictly increasing which is wrong.
// So, linear search is the only option in case of duplicates in the sorted rotated array.
int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    
    int low = 0, high = n - 1;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(A[mid] == B)
        {
            return mid;
        } // left part is strictly increasing
        else if(A[low] <= A[mid])
        {
            // Check whether searched value present in the left part or not
            if(B >= A[low] && B <= A[mid])
            {
                high = mid - 1;
            } else 
            {
                low = mid + 1;
            }
        } // right part is strictly increasing
        else 
        {
            // Check whether searched value present in the right part or not
            if(B >= A[mid] && B <= A[high])
            {
                low = mid + 1;
            } else
            {
                high = mid - 1;
            }
        }
    }
    
    return -1;
}
