vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size(), maxlen = 0, start = -1, sum = 0;
    unordered_map<int, int>mp;
    
    for(int i = 0; i < n; i++)
    {
        sum += A[i];
        // If we encounter 0 and maxlen is at this point, then this can be a start point.
		// For example: 1 0 3 (second element will be the start point)
        if(A[i] == 0 &&  maxlen == 0)
        {
            maxlen = 1;
            start = i;
        }
        
		// If sum is zero, then maxlen will be till this point as we are summing from first element.
		// So, the start point will be 0 as well.
        if(sum == 0)
        {
            maxlen = i + 1;
            start = 0;
            continue;
        }
        // if we find any sum that we got before, then the elements after the previous sum to this current element will be 0.
		// Check if the curr len greater than maxlen or not. If greater, then updated the start and maxlen.
		// The start should be next index of the previous same sum index.
        if(mp.find(sum) != mp.end())
        {
            int currlen = i - mp[sum];
            
            if(maxlen < currlen)
            {
                maxlen = currlen;
                start = mp[sum] + 1;
            }
        } // Otherwise add the same in the map.
		else
        {
            mp[sum] = i;
        }
    }
    
    if(maxlen == 0)
    {
        return {};
    } else
    {
        vector<int>res;
        
        for(int i = start; i < (start + maxlen); i++)
        {
            res.push_back(A[i]);
        }
        
        return res;
    }
}
