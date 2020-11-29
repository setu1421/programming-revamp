/*
Method 1 (Use Max Heap)
	1. Build a Max Heap tree in O(n)
	2. Use Extract Max k times to get k maximum elements from the Max Heap O(klogn)
*/

vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int> res;
    priority_queue<int> pq;
    
    for(int i = 0; i < A.size(); i++)
    {
        pq.push(A[i]);
    }
    
    while(B > 0)
    {
        res.push_back(pq.top());
        pq.pop();
        B--;
    }
    
    return res;
}

/* Method 2 (Use Min Heap) (Efficient)

	1. Build a Min Heap MH of the first k elements (A[0] to A[k-1]) of the given array. O(k)
	2. For each element, after the kth element (arr[k] to arr[n-1]), compare it with root of MH.
	   1. If the element is greater than the root then make it root and call heapify for MH
	   2. Else ignore it.
	   3. The step 2 is O((n-k)*logk)
	3. Finally, MH has k largest elements and root of the MH is the kth largest element.
	
Time Complexity: O(k + (n-k)Logk) without sorted output. If sorted output is needed then O(k + (n-k)Logk + kLogk)
*/

vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int> res;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for(int i = 0; i < B; i++)
    {
        pq.push(A[i]);
    }
    
    for(int i = B; i < A.size(); i++)
    {
        if(A[i] > pq.top())
        {
            pq.pop();
            pq.push(A[i]);
        }
    }
    
    while(pq.size() > 0)
    {
        res.push_back(pq.top());
        pq.pop();
    }
    
    return res;
}
