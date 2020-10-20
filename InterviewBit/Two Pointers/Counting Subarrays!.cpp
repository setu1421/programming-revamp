// Time Complexity: O(n^2)
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        int total = 0;
        for(int j = i; j < n; j++)
        {
            total += A[j];
            
            if(total < B)
            {
                ans++;
            } else
            {
                break;
            }
        }
    }
    
    return ans;
}

// Sliding Window Approach: O(n)
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int i = 0, j = 0, sum = A[0], ans = 0;
    
    while(i < n & j < n)
    {
        if(sum < B)
        {
            ans += (j - i + 1);
            j++;
            sum += A[j];
        }
        
        if(sum >= B)
        {
            sum -= A[i];
            i++;
        }
    }
    
    return ans;
}