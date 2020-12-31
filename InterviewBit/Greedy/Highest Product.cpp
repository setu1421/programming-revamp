// We can also find out largest three numbers and smallest two numbers in one pass and 
// do the solution in O(n) time complexity and O(1) space complexity
int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    
    if(n < 3)
    {
        return 0;
    }
    
    sort(A.begin(), A.end());
    
    int a = A[n - 1] * A[n - 2] * A[n - 3];
    int b = A[0] * A[1] * A[n - 1];
    
    return max(a, b);
}
