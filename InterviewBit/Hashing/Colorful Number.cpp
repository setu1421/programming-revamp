int Solution::colorful(int A) {
    string str = to_string(A);
    int n = str.length();
    unordered_map<long long, int>mp;
    
    for(int i = 0; i < n; i++)
    {
        long long prod = 1;
        for(int j = i; j < n; j++)
        {
            prod = prod * (str[j] - '0');
            
            if(mp.find(prod) == mp.end())
            {
                mp[prod] = 1;
            } else
            {
                return 0;
            }
        }
    }
    
    return 1;
}
