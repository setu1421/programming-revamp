#define MOD 1000000007

void buildMaxHeap(priority_queue<int> &pq, vector<int> &B)
{
    int n = B.size();
    
    for(int i = 0; i < n; i++)
    {
        pq.push(B[i]);
    }
}

int Solution::nchoc(int A, vector<int> &B) {
    long long ans = 0l;
    
    priority_queue<int> pq;
    buildMaxHeap(pq, B);
    
    for(int i = 0; i < A; i++)
    {
        int chocolates = pq.top();
        pq.pop();
        ans = (ans + chocolates) % MOD;
        pq.push(floor(chocolates / 2));
    }
    
    return ans;
}
