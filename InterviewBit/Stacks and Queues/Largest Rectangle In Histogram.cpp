int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();
    if(n == 1)
    {
        return A[0];
    }
    
    int lb[n], rb[n];
    stack<int>leftSt, rightSt;
    int max_area = INT_MIN;
    
    // The idea is to find the next smaller element to mark the left and right
    // boundary of the current element. We will stop at that smaller element because
    // if we take that bar, then the minimum height will decrease.
    
    // Find the next smaller element in the left side of an element
    // For the first element, the left bound will be -1
    lb[0] = -1;
    leftSt.push(0);
    
    for(int i = 1; i < n; i++)
    {
        // if the current element is <= to the stack top element, then pop until we get
        // smaller element than the current element
        while(!leftSt.empty() && A[i] <= A[leftSt.top()])
        {
            leftSt.pop();
        }
        
        if(leftSt.empty())
        {
            lb[i] = -1;
        } else
        {
            lb[i] = leftSt.top();
        }
        
        leftSt.push(i);
    }
    
    // Find the next smaller element in the right side of an element
    // For the last element, the right bound will be n
    rb[n - 1] = n;
    rightSt.push(n - 1);
    
    for(int i = n - 2; i >= 0; i--)
    {
        while(!rightSt.empty() && A[i] <= A[rightSt.top()])
        {
            rightSt.pop();
        }
        
        if(rightSt.empty())
        {
            rb[i] = n;
        } else
        {
            rb[i] = rightSt.top();
        }
        
        rightSt.push(i);
    }
    
    for(int i = 0; i < n; i++)
    {
        int width = (rb[i] - lb[i] - 1);
        int curr_area = width * A[i];
        max_area = max(max_area, curr_area);
    }
    
    return max_area;
}
