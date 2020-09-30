vector<int> Solution::primesum(int A) {
    bool isprime[A + 1];
    vector<int> ans;
    
    memset(isprime, true, sizeof(isprime));
    
    isprime[0] = false, isprime[1] = false, isprime[2] = true;
    
    for(int i = 2; i <= sqrt(A); i++)
    {
        if(isprime[i])
        {
            for(int j = i * i; j <= A; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    
    for(int i = 2; i <= A; i++)
    {
        if(isprime[i] && isprime[A - i])
        {
            ans.push_back(i);
            ans.push_back(A - i);
            break;
        }
    }
    
    return ans;
}
