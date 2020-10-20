void Solution::sortColors(vector<int> &A) {
    int n = A.size();
    int l = 0, m = 0, h = n - 1;
    
    while(m <= h)
    {
        // If 0, then move the element to the available slot in the left
        if(A[m] == 0)
        {
            swap(A[l], A[m]);
            l++;
            m++;
        } // If 2, then move the element to the available slot in the right 
        else if(A[m] == 2)
        {
            swap(A[m], A[h]);
            h--;
        } // If 1, leave 1 in the middle
        else
        {
            m++;
        }
    }
}
