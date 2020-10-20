int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    int i = 0, j = 1, count = 1;
    
    while(i < n && j < n)
    {
		// If the same element appears then increment the count and check if it is less than 2.
        if(A[i] == A[j])
        {
            count++;
			// If less than 2, then increment the next element position and swap the elements to place at that position.
            if(count <= 2)
            {
                i++;
                swap(A[i], A[j]);
            }
            j++;
        } else
        {
            i++;
            swap(A[i], A[j]);
            j++;
			// Reset the count to 1 as different element found
            count = 1;
        }
    }
    
    return (i + 1);
}
