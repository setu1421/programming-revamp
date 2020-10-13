string Solution::solve(string A, int B) {
    int n = A.length();
    string res = "";
    
    for(int i = 0; i < n; i++)
    {
        int count = 0, start_index = i;
        char ch = A[i];
        
        while(i < n && A[i] == ch)
        {
            count++;
            i++;
        }
        
        if(count == B)
        {
            i--;
        } else
        {
            for(int k = start_index; k < i; k++)
            {
                res += A[k]; 
            }
            
            i--;
        }
    }
    
    return res;
}
