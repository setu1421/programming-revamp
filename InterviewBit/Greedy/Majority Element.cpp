int Solution::majorityElement(const vector<int> &A) {
    int n = A.size();
    int target = floor(n / 2);
    unordered_map<int, int> mp;
    
    for(int i = 0; i < n; i++)
    {
        mp[A[i]]++;
    }
    
    for(auto p: mp)
    {
        if(p.second > target)
        {
            return p.first;
        }
    }
    
    return 0;
}

// Another approach: Without using any extra memory
/*
If we cancel out each occurrence of an element e with all the other elements that are different from e then e will exist till end if it is a majority element. Loop through each element and maintains a count of the element that has the potential of being the majority element. If next element is same then increments the count, otherwise decrements the count. If the count reaches 0 then update the potential index to the current element and reset count to 1.
*/

int Solution::majorityElement(const vector<int> &A) {
    int n = A.size();
    int maj_num = A[0], count = 1;
    
    for(int i = 1; i < n; i++)
    {
        if(A[i] == maj_num)
        {
            count++;
        } else
        {
            count--;
        }
        
        if(count == 0)
        {
            maj_num = A[i];
            count = 1;
        }
    }
    
    return maj_num;
}
