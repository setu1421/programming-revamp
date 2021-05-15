// https://www.youtube.com/watch?v=QPfalDbqa4A
int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), j = -1, count = 0, best_len = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] == 0)
        {
            count++;
        }
        
        while(count > B)
        {
            j++;
            if(A[j] == 0)
            {
                count--;
            }
        }
        
        int curr_len = i - j;
        best_len = max(best_len, curr_len);
    }
    
    return best_len;
}
