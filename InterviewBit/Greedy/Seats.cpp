// https://www.youtube.com/watch?v=SK2ypa7poKg&t=131s

#define MOD 10000003

int Solution::seats(string A) {
    vector<int> v;
    
    for(int i = 0; i < A.length(); i++)
    {
        if(A[i] == 'x')
        {
            v.push_back(i);
        }
    }
    
    int n = v.size();
    int mid = n / 2;
    long long count = 0;
    
    for(int i = 0; i < n; i++)
    {
        int start = v[i];
        int end = v[mid] - mid + i;
        
        count = (count + abs(start - end)) % MOD; 
    }
    
    return count;
}
