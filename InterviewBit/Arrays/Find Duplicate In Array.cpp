int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    
    // If only one element present in the array,
    // then, no repeated number present
    if(n < 2)
    {
        return -1;
    }
    
    // Detect cycle using Floyd's cycle detection algo
    int slow = A[0];
    int fast = A[A[0]];
    
    while(slow != fast)
    {
        slow = A[slow];
        fast = A[A[fast]];
    }
    
    // Finally find the starting of the loop
    // https://www.youtube.com/watch?v=LUm2ABqAs1w
    fast = 0;
    while(slow != fast)
    {
        slow = A[slow];
        fast = A[fast];
    }
    
    return slow;
}
