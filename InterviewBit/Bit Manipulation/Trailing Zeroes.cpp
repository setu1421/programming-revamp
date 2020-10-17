// Time Complexity : O(Log n)

int Solution::solve(int A) {
    int counter = 0;
    
    for(int i = 0; i < 31; i++)
    {
        if((A >> i) & 1)
        {
            break;
        } else
        {
            counter++;
        }
    }
    
    return counter;
}