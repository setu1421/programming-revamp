int findPeakElement(vector<int> &A, int low, int high)
{
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
        {
            return mid;
        } // The left part is stictly increasing, so the peak will be in the right part
		else if(A[mid] > A[mid - 1])
        {
            low = mid + 1;
        } else
        {
            high = mid - 1;
        }
    }
}

int ascending_binary_search(vector<int> &A, int n, int low, int high, int B)
{
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(A[mid] == B)
        {
            return mid;
        } else if(A[mid] > B)
        {
            high = mid - 1;
        } else 
        {
            low = mid + 1;
        }
    }
    
    return -1;
}

int descending_binary_search(vector<int> &A, int n, int low, int high, int B)
{
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(A[mid] == B)
        {
            return mid;
        } else if(A[mid] > B)
        {
            low = mid + 1;
        } else 
        {
            high = mid - 1;
        }
    }
    
    return -1;
}

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    
    int peak_index = findPeakElement(A, 0, n - 1);
    
    // If the searched element is greater than the peak element
    // So, the searched element won't present in the bitonic array 
    if(B > A[peak_index])
    {
        return -1;
    } else if(B == A[peak_index])
    {
        return peak_index;
    } else 
    {
        int temp = ascending_binary_search(A, n, 0, peak_index - 1, B);
        
        if(temp != -1)
        {
            return temp;
        }
        
        temp = descending_binary_search(A, n, peak_index + 1, n - 1, B);
        
        if(temp != -1)
        {
            return temp;
        }
    }
    
    return -1;
}
