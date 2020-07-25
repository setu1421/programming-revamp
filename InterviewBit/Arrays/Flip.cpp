#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::flip(string A) {
    
    int n = A.length();
    vector<int>ret;
    
    bool oneZeroFound = false;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] == '0')
        {
            oneZeroFound = true;
            break;
        }
    }
    
    // If all are one's in the string
    if(!oneZeroFound)
    {
        return vector<int>();
    }
    
    int local_count = 0, max_count = INT_MIN;
    int left = 0, right = 0, left_temp = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] == '0')
        {
            local_count++;
        } else 
        {
            local_count--;
        }
        
        if(local_count > max_count)
        {
            left = left_temp;
            right = i;
            max_count = local_count;
        }
        
        if(local_count < 0)
        {
            local_count = 0;
            left_temp = i + 1;
        }
    }
    
    // Push the indices in the return vector
    ret.push_back(left + 1);
    ret.push_back(right + 1);
    
    return ret;
}
