// Time Complexity: O(logn)
// https://www.youtube.com/watch?v=4qjprDkJrjY&feature=emb_err_woyt
int Solution::findMin(const vector<int> &A) {
    int n = A.size();
    
    int low = 0, high = n - 1;
    int ans = -1;
    
    while(low <= high)
    {
        // Case 1: If already sorted
        if(A[low] <= A[high])
        {
            ans = low;
            break;
        } else
        {
            int mid = low + (high - low) / 2;
            // module n because the mid element can be the last element or first element.
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;
            
            // Case 2: if mid element is the smallest element
            if(A[mid] <= A[next] && A[mid] <= A[prev])
            {
                ans = mid;
                break;
            } // Case 3: if the right part is already sorted
            else if(A[mid] <= A[high])
            {
                high = mid - 1;
            } // Case 4: if the left part is already sorted 
            else
            {
                low = mid + 1;
            }
        }
    }
    
    return A[ans];
}
