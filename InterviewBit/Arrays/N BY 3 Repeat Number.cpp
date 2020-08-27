// Proof: https://neolzs.wordpress.com/2016/02/01/boyer-moore-majority-vote-algorithm-a-simple-proof/
int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    
    int count1 = 0, count2 = 0;
    int firstME = INT_MAX, secondME = INT_MAX;
    
    for(int i = 0; i < n; i++)
    {
        if(firstME == A[i])
        {
            count1++;
        } else if(secondME == A[i])
        {
            count2++;
        } else if(count1 == 0)
        {
            count1 = 1;
            firstME = A[i];
        } else if(count2 == 0)
        {
            count2 = 1;
            secondME = A[i];
        } else 
        {
            count1--;
            count2--;
        }
    }
    
    count1 = 0, count2 = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(firstME == A[i])
        {
            count1++;
        } else if(secondME == A[i])
        {
            count2++;
        }
    }
    
    if(count1 > (n / 3))
    {
        return firstME;
    } else if(count2 > (n / 2))
    {
        return secondME;
    } else 
    {
        return -1;
    }
}
