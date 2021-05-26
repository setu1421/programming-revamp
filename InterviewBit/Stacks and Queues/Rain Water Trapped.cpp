/* Basic Insight: 
An element of the array can store water if there are higher bars on left and right. The amount of water to be stored in every element can be found out by finding the heights of bars on the left and right sides. The idea is to compute the amount of water that can be stored in every element of the array. 
*/

// Two Pointer Approach
// https://www.geeksforgeeks.org/trapping-rain-water/
int Solution::trap(const vector<int> &A) {
    int n = A.size();
    int leftMax = 0, rightMax = 0, low = 0, high = n - 1, res = 0;
    
	// Water can reside if the current bar is surronded by one bigger bar from left and right.
    while(low < high)
    {
		// If current bar is <= right bar, then water amount can be based on left max bar and current bar.
        if(A[low] <= A[high])
        {
			// If the current bar is greater than left max bar, then update the left max and water can't reside on that bar.
            if(A[low] > leftMax)
            {
                leftMax = A[low];
            } else
            {
                res += (leftMax - A[low]);
            }
            
			// move to the next bar from left
            low++;
        } else
        {
            if(A[high] > rightMax)
            {
                rightMax = A[high];
            } else
            {
                res += (rightMax - A[high]);
            }
            
            high--;
        }
    }
    
    return res;
}
// Using Stack
int Solution::trap(const vector<int> &A) {
    int n = A.size(), res = 0;
    stack<int>st;
    
    for(int i = 0; i < n; i++)
    {
		// Remove bars from the stack
        while(!st.empty() && A[st.top()] < A[i])
        {
			// Store the height of the top and pop it.
            int pop_height = A[st.top()];
            st.pop();
            // If the stack does not have any bars or the popped bar has no left boundary
            if(st.empty())
            {
                break;
            }
            // Get the distance between the left and right boundary of popped bar
            int distance = i - st.top() - 1;
			// Calculate the water amount
            int water_amount = distance * (min(A[st.top()], A[i]) - pop_height);
            res += water_amount;
        }
         // If the stack is either empty or height of the current bar is less than or equal to the top bar of stack 
        st.push(i);
    }
    
    return res;
}

