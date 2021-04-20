// Aproach 1: Selecting two elements at one time.
// No. of Comparisons: 3n/2 + 2
// https://www.youtube.com/watch?v=txd3UKiSD5Q

int Solution::solve(vector<int> &A) {
    int minValue = INT_MAX, maxValue = INT_MIN, i = 0;
    
    int n = A.size();
    
    if(n % 2 == 0)
    {
        if(A[0] > A[1])
        {
            maxValue = A[0];
            minValue = A[1];
        } else 
        {
            maxValue = A[1];
            minValue = A[0];
        }
        
        i = 2;
    } else 
    {
        maxValue = minValue = A[0];
        i = 1;
    }
    
    while(i < n - 1)
    {
        if(A[i] > A[i + 1])
        {
            maxValue = max(maxValue, A[i]);
            minValue = min(minValue, A[i + 1]);
        } else 
        {
            maxValue = max(maxValue, A[i + 1]);
            minValue = min(minValue, A[i]);
        }
        
        i += 2;
    }
    
    return maxValue + minValue;
}

// Aproach 2: Using divide & conquer approach
// Space Complexity: O(logn)
// No. of Comparisons: 3n/2 - 2
/*
T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2  
  T(2) = 1
  T(1) = 0
If n is a power of 2, then we can write T(n) as:
   T(n) = 2T(n/2) + 2 
After solving above recursion, we get

  T(n)  = 3n/2 -2 
Thus, the approach does 3n/2 -2 comparisons if n is a power of 2. And it does more than 3n/2 -2 comparisons if n is not a power of 2.
*/

int[] findMinMax(int A[], int start, int end)
{
    int max;
    int min;
    if ( start == end )
    {
        max = A[start]
        min = A[start]
    }
    else if ( start + 1 == end )
    {
        if ( A[start] < A[end] )
        {
            max = A[end]
            min = A[start]
        }
        else
        {
            max = A[start]
            min = A[end]
        }
    }
    else
    {
        int mid = start + (end - start)/2
        int left[] = findMinMax(A, start, mid)
        int right[] = findMinMax(A, mid+1, end)
        if ( left[0] > right[0] )
            max = left[0]
        else
            max = right[0]
        if ( left[1] < right[1] )
            min = left[1]
        else
            min = right[1]
    }
    // By convention, we assume ans[0] as max and ans[1] as min
    int ans[2] = {max, min}
   return ans
}
