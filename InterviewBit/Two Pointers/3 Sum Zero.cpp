vector<vector<int> > Solution::threeSum(vector<int> &A) {
    int n = A.size();
    vector<vector<int> >res;
    
    sort(A.begin(), A.end());
    
    for(int i = 0; i < n - 2; i++)
    {
        // if A[i] is same as the previous element, 
        // then we have covered the combination already. So, we can skip it to avoid duplicate combination.
        if(i > 0 && A[i] == A[i - 1])
        {
            continue;
        }
        
        int j = i + 1;
        int k = n - 1;
        
        while(j < k)
        {
            // if last element of the triplet is same as the previous last element, 
            // then we have covered the combination already. so, we can skip it to avoid duplicated combination
            if(k < n - 1 && A[k] == A[k + 1])
            {
                k--;
                continue;
            }
            // values can be INT_MAX or INT_MIN. So long long required to tackle overflow
            long long sum = (long long) A[i] + (long long) A[j] + (long long) A[k];
            
            if(sum == 0)
            {
                vector<int> temp{A[i], A[j], A[k]};
                res.push_back(temp);
                j++;
                k--;
            } else if(sum < 0)
            {
                j++;
            } else
            {
                k--;
            }
        }
    }
    
    return res;
}
