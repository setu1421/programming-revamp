// Simple Approach: O(n)
// Worst case it can be O(n) as all the elements can be same in the array.
int Solution::findCount(const vector<int> &A, int B) {
    int n = A.size();
    
    int left = 0, right = n - 1;

    int indx = -1;
    
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if(A[mid] == B)
        {
            indx = mid;
            break;
        } else if(A[mid] < B)
        {
            left = mid + 1;
        } else 
        {
            right = mid - 1;
        }
    }
    
    if(indx == -1)
    {
        return 0;
    } else
    {
        int temp = indx + 1, count = 1;
        while(temp < n && A[temp] == B)
        {
            count++;
            temp++;
        }
        temp = indx - 1;
        while(temp >= 0 && A[temp] == B)
        {
            count++;
            temp--;
        }
        
        return count;
    }
}

// Best Approach: O(log n)
// Binary Search to find the first occurence and then again binary search to find the last occurence

int binary_search(const vector<int> &A, int n, int B, bool isSearchFirst)
{
    int low = 0, high = n - 1, result = -1;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(A[mid] == B)
        {
            result = mid;
            if(isSearchFirst)
            {
                high = mid - 1;
            } else
            {
                low = mid + 1;
            }
        } else if(A[mid] < B)
        {
            low = mid + 1;
        } else
        {
            high = mid - 1;
        }
    }
    
    return result;
}

int Solution::findCount(const vector<int> &A, int B) {
    int n = A.size();
    int firstIndex = binary_search(A, n, B, true);
    if(firstIndex == -1)
    {
        return 0;
    }
    
    int lastIndex = binary_search(A, n, B, false);
    
    return (lastIndex - firstIndex + 1);
}

