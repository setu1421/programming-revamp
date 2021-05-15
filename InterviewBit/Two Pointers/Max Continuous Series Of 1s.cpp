vector<int> Solution::maxone(vector<int> &A, int B) {
    int n = A.size();
    int wL = 0, wR = 0, countOfZero = 0, maxDiff = INT_MIN;
    int bestwL = 0, bestwR = 0;
    
    while(wR < n)
    {
        // If count of zero is less than or equal to B, then slide the window to the right
        if(countOfZero <= B)
        {
            if(A[wR] == 0)
            {
                countOfZero++;
            }
            
            wR++;
        }
        
        // If count of zero is greater than B, then slide the window from left untill the number of zero is equal to B in the window
        while(countOfZero > B)
        {
            // if the start element of the window is 0, then decrement count of zero
            if(A[wL] == 0)
            {
                countOfZero--;
            }
            
            wL++;
        }
        
        int tempDiff = wR - wL;
        
        // Only update when current difference is greater and count of zero <= B
        if(tempDiff > maxDiff && countOfZero <= B)
        {
            maxDiff = tempDiff;
            bestwL = wL;
            bestwR = wR;
        }
    }
    
    vector<int> res;
    for(int i = bestwL; i < bestwR; i++)
    {
        res.push_back(i);
    }
    
    return res;
}

//

vector<int> Solution::maxone(vector<int> &A, int B) {
    int n = A.size(), i = -1, count = 0;
    int best_start = 0, best_len = 0;
    
    for(int j = 0; j < n; j++)
    {
        if(A[j] == 0) count++;
        
        while(count > B)
        {
            i++;
            if(A[i] == 0)
            {
                count--;
            }
        }
        
        int curr_len = j - i;
        if(curr_len > best_len)
        {
            best_len = curr_len;
            best_start = i + 1;
        }
    }
    
    vector<int> res;
    
    for(int i = best_start; i < best_start + best_len; i++)
    {
        res.push_back(i);
    }
    
    return res;
}
