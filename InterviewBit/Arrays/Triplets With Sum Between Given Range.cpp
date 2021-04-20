int Solution::solve(vector<string> &A) {
    int n = A.size();
    
    if(n < 3) return 0;
    
    double a = stod(A[0]), b = stod(A[1]), c = stod(A[2]);
    
    int i = 3;
    
    while(i <= n)
    {
        double sum = a + b + c;
        
        if(sum > 1 && sum < 2)
        {
            return 1;
        } else
        {
            if(i == n)
            {
                return 0;
            }
            
            double new_value = stod(A[i]);
            
            if(sum > 2)
            {
                if(a > b && a > c)
                {
                    a = new_value;
                } else if(b > a && b > c)
                {
                    b = new_value;
                } else
                {
                    c = new_value;
                }
            } else
            {
                if(a < b && a < c)
                {
                    a = new_value;
                } else if(b < a && b < c)
                {
                    b = new_value;
                } else
                {
                    c = new_value;
                }
            }
            
            i++;
        }
    }
    
    return 0;
}
