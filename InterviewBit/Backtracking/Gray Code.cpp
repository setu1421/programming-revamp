// Time Complexity: O(2^N)
// Space Complexity: O(2^N)

/* we have 2 choices for each of the n bits either we  
   can include i.e invert the bit or we can exclude the  
   bit i.e we can leave the number as it is. */
   
void grayCodeUtil(vector<int> &res, int n, int &num)
{
    // base case when we run out bits to process 
    // we simply include it in gray code sequence.
    if(n == 0)
    {
        res.push_back(num);
        return;
    }
    // ignore the bit. 
    grayCodeUtil(res, n - 1, num);
    // invert the bit. 
    num = num ^ (1 << (n - 1));
    grayCodeUtil(res, n - 1, num);
}

vector<int> Solution::grayCode(int A) {
    vector<int> res;
    int num = 0;
    
    grayCodeUtil(res, A, num);
    
    return res;
}


// Using string concatenation recursively
// https://www.youtube.com/watch?v=KOD2BFauQbA
// Time Complexity: O(2^N)
// Space Complexity: O(2^N)

#include<bits/stdc++.h>

vector<string> grayCodeUtil(int n)
{
    if(n == 1)
    {
        vector<string> v;
        v.push_back("0");
        v.push_back("1");
        
        return v;
    }
    
    vector<string> rres = grayCodeUtil(n - 1);
    
    vector<string> mres;
    
    for(int i = 0; i < rres.size(); i++)
    {
        mres.push_back("0" + rres[i]);
    }
    
    for(int i = rres.size() - 1; i >= 0; i--)
    {
        mres.push_back("1" + rres[i]);
    }
    
    return mres;
}

vector<int> Solution::grayCode(int A) {
    vector<string> ans;
    ans = grayCodeUtil(A);
    
    vector<int> final_res;
    
    for(int i = 0; i < ans.size(); i++)
    {
        int value = (int) bitset<32>(ans[i]).to_ulong();
        final_res.push_back(value);
    }
    
    return final_res;
}


// Iterative approach: https://www.youtube.com/watch?v=NOhPycZeVpw

vector<int> Solution::grayCode(int A) {
    vector<int> res;
    
    for(int i = 0; i < (1 << A); i++)
    {
        int val = i ^ (i >> 1); // we can use xor by right shifting i one place to check adjacent bits to produce gray code.
        
        res.push_back(val);
    }
    
    return res;
}