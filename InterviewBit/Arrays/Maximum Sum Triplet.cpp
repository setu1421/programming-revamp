/*
Best and efficient approach is use the concept of maximum suffix-array and binary search.

For finding maximum number greater than given number beyond it, we can maintain a maximum suffix-array array such that for any number(suffix[i]) it would contain maximum number from index i, i+1, … N-1. Suffix array can be calculated in O(N) time.

For finding maximum number smaller than the given number preceding it, we can maintain a sorted list of numbers before a given number such we can simply perform a binary search to find a number which is just smaller than the given number. In C++ language, we can perform this by using set associative container of STL library.

Time complexity: O(NlogN)
Auxiliary space: O(N)

*/

int getLower(set<int> &s, int value)
{
    auto it = s.lower_bound(value);
    
    --it;
    
    return (*it);
}

void preComputeSuffixMax(int suffixMax[], vector<int> &A, int n)
{
    suffixMax[n - 1] = A[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], A[i]);
    }
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int suffixMax[n + 1];
    int ans = 0;
    
    // Compute the maximum element at the right to add as third element
    preComputeSuffixMax(suffixMax, A, n);
    
    // Use set to find out immediate lower element of a value
    set<int> s;
    // Insert minimum value for first comparison in the set 
    s.insert(INT_MIN);
    s.insert(A[0]);
    
    for(int i = 1; i < n - 1; i++)
    {
		// Check if the next max number is greater than current number or not. 
        if(suffixMax[i + 1] > A[i])
        {
            ans = max(ans, getLower(s, A[i]) + A[i] + suffixMax[i + 1]);
            
        }
        
        s.insert(A[i]);
    }
    
    return ans;
}
