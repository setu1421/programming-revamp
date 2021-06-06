vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size(), maxlen = 0, start = INT_MAX, sum = 0;
    unordered_map<int, int>mp;
    
    for(int i = 0; i < n; i++)
    {
        sum += A[i];
        
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
    
    vector<int>res;
    
    for(int i = start; i < (start + maxlen); i++)
    {
        res.push_back(A[i]);
    }
    
    return res;
}

// Another Solution: Using prefix sum and if we get the same sum again, then the middle part is zero.
vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size(), best_len = INT_MIN, best_start = INT_MAX;
    unordered_map<int, int> mp;
    
    int prefix_sum[n];
    prefix_sum[0] = A[0];
    
    for(int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        if(prefix_sum[i] == 0)
        {
            best_len = i + 1;
            best_start = 0;
        } else if(mp.find(prefix_sum[i]) != mp.end())
        {
            int curr_len = i - mp[prefix_sum[i]];
            
            if(curr_len > best_len || curr_len == best_len && best_start > mp[prefix_sum[i]])
            {
                best_len = curr_len;
                best_start = mp[prefix_sum[i]] + 1;
            }
        } else
        {
            mp[prefix_sum[i]] = i;
        }
    }

    vector<int> res;
    for(int i = best_start; i < best_start + best_len; i++)
    {
        res.push_back(A[i]);
    }
    
    return res;
}

