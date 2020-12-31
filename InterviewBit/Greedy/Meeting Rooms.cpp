// The idea is to sort based on starting time and then push the end times in a priority_queue
// If the starting time of next meeting is less than the smallest end time, then we will need new room.
// Otherwise, we will pop the finished meetings from priority_queue and place the new meeting end time.
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if(n < 0)
    {
        return 0;
    }
    
    int max_room_needed = 1;
    priority_queue<int, vector<int>, greater<int> > pq; // min heap
    
    sort(A.begin(), A.end());
    
    pq.push(A[0][1]);
    
    for(int i = 1; i < n; i++)
    {
        while(!pq.empty() && A[i][0] >= pq.top())
        {
            pq.pop();
        }
        
        pq.push(A[i][1]);
        
        max_room_needed = max(max_room_needed, (int) pq.size());
    }
    
    return max_room_needed;
}
