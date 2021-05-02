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

/* For having duplicate Entries, we have to use linear search

Binary search works because we are able to identify that there are essentially “two sorted portions” in our array. E.g. : 5 6 7 1 2 3 4 , here 5 6 7 and 1 2 3 4 are the two portions.

However in case of duplicates we would not be able to identify the portions.
E.g. 2 2 2 1 2 2 2.
Here if we land on an index with value 2, we won’t be able to tell whether it is on left side of 1 or right side of 1.
*/