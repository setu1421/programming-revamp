vector<int> Solution::getRow(int A) {
    vector<int> result;
    
    // Firs element will be always 1. (NC0)
    int prev = 1;
    result.push_back(prev);
    
    // NCr = (NCr-1 * (N- r + 1)) / r
    for(int i = 1; i < A; i++)
    {
        prev = (prev * (A - i + 1)) / i;
        result.push_back(prev);
    }
    
    // Last element will be always 1
    result.push_back(1);
    
    return result;
}
