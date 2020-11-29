/* An efficient solution is to use heap data structure. The time complexity of heap based solution is O(N Log k). where N is count of all elements

1. Create an output array.
2. Create a min heap of size k and insert 1st element in all the arrays into the heap
3. Repeat following steps while priority queue is not empty.
	1. Remove minimum element from heap (minimum is always at root) and store it in output array.
	2. Insert next element from the array from which the element is extracted. If the array doesn’t have any more elements, then do nothing.
*/

typedef pair<int, pair<int, int> > T;

vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> res;
    priority_queue<T, vector<T>, greater<T> > pq;
    
    int k = A.size(), n = A[0].size();
    
    for(int j = 0; j < k; j++)
    {
        pq.push(make_pair(A[0][j], make_pair(0, j)));
    }
    
    while(!pq.empty())
    {
        T top = pq.top();
        pq.pop();
        res.push_back(top.first);
        
        pair<int, int> index = top.second;
        int i = index.first, j = index.second;
        
        if(j + 1 < n)
        {
            pq.push(make_pair(A[i][j + 1], make_pair(i, j + 1)));
        }
    }
    
    return res;
}

// Simple Approach
vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> res;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    int k = A.size(), n = A[0].size();
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            pq.push(A[i][j]);
        }
    }
    
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    
    return res;
}
