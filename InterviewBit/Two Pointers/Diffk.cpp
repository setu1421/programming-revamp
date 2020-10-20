// Follow up problem: https://www.youtube.com/watch?v=pkgNgMSPV4o&feature=youtu.be (Counting all distinct pairs with sum k)
int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size();
    int i = 0, j = 1;
    
    // sliding window apprach with two pointer
    while(i < n && j < n)
    {
        if(i == j)
        {
            j++;
        } else if((A[j] - A[i]) == B)
        {
            return 1;
        } else if((A[j] - A[i]) < B)
        {
            j++;
        } else
        {
            i++;
        }
    }
    
    return 0;
}
