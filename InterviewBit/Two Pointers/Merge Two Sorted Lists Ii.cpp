void Solution::merge(vector<int> &A, vector<int> &B) {
    int m = A.size(), n = B.size();
	// resize A with total element
    A.resize(m + n);
    // Fill from backwards
    for(int idx = m + n - 1; idx >= 0; idx--)
    {
		// If all the elements of A have been taken, then take only elements from B
        if(m <= 0)
        {
            A[idx] = B[n - 1];
            n--;
        } // If all the elements of B have been taken, then break as all elements of A are already present in A.
		else if(n <= 0)
        {
            break;
        }
        else if(A[m - 1] < B[n - 1])
        {
            A[idx] = B[n - 1];
            n--;
        } else
        {
            A[idx] = A[m - 1];
            m--;
        }
    }
}
