vector<int> Solution::sieve(int A) {
    bool prime[A+1];
    vector<int>sol;
    
    memset(prime,true,sizeof(prime));
    
    
    for(int i=2;i<=sqrt(A);i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=A;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    
    for(int i=2;i<=A;i++)
    {
        if(prime[i])
           sol.push_back(i);
    }
    
    return sol;
}
