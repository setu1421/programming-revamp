int Solution::bulbs(vector<int> &A) {
    int n = A.size();
    
    int count = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] == 0 && (count % 2 == 0))
        {
            count++;
        } else if(A[i] == 1 && (count % 2 != 0))
        {
            count++;
        }
    }
    
    return count;
}
