// https://www.youtube.com/watch?v=OZ2jghS0t24
int Solution::findMinXor(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    int minXor = INT_MAX;
    for(int i = 1; i < n; i++)
    {
        minXor = min(minXor, A[i - 1] ^ A[i]);
    }
    
    return minXor;
}
