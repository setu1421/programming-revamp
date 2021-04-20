// https://www.youtube.com/watch?v=Oop18EH4T28
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        bool canLit = false;
        for(int j = (i + B - 1); j >= 0 && j >= (i - B + 1); j--)
        {
            if(A[j] == 1)
            {
                ans++;
                canLit = true;
                i = j + B - 1;
                break;
            }
        }
        
        if(!canLit)
        {
            return -1;
        }
    }
    
    return ans;
}
