#define MOD 1000000007

int Solution::maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    if(n <= 3)
    {
        return 0;
    }
    
    stack<int>leftSt, rightSt;
    vector<int>leftSpecial, rightSpecial;
    
    leftSt.push(0);
    rightSt.push(n - 1);
    leftSpecial.push_back(0);
    rightSpecial.push_back(0);
    
	// Check the value greater than A[i] where j is maximum
	// So maintaining a stack with strictly decreasing order
    for(int i = 1; i < n; i++)
    {
		// if the top of stack is less than A[i], then remove that element from stack.
        while(!leftSt.empty() && A[i] >= A[leftSt.top()])
        {
            leftSt.pop();
        }
        // if stack empty after all the pops, then max j will be 0
        if(leftSt.empty())
        {
            leftSpecial.push_back(0);
        } else
        {
            leftSpecial.push_back(leftSt.top());
        }
        
        leftSt.push(i);
    }
    // Check the value greater than A[i] where j is minimum
	// So maintaining a stack with strictly increasing order
    for(int i = n - 2; i >= 0; i--)
    {
        while(!rightSt.empty() && A[i] >= A[rightSt.top()])
        {
            rightSt.pop();
        }
        
        if(rightSt.empty())
        {
            rightSpecial.push_back(0);
        } else
        {
            rightSpecial.push_back(rightSt.top());
        }
        
        rightSt.push(i);
    }
    
    long long res = INT_MIN;
    
    for(int i = 0; i < n; i++)
    {
        long long leftValue = leftSpecial[i];
        long long rightValue = rightSpecial[n - i - 1];
        
        long long temp = (leftValue * rightValue);
        res = max(res, temp);
    }
    
    return res % MOD;
}
