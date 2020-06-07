#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m+n)
class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        unordered_set<int>s1, s2;
        vector<int>res;

        for(int i = 0; i < n1; i++)
        {
            s1.insert(nums1[i]);
        }
        for(int i = 0; i < n2; i++)
        {
            s2.insert(nums2[i]);
        }

        if(n1 <= n2)
        {
            for(auto it : s1)
            {
                if(s2.find(it) != s2.end())
                {
                    res.push_back(it);
                }
            }
        } else
        {
            for(auto it : s2)
            {
                if(s1.find(it) != s1.end())
                {
                    res.push_back(it);
                }
            }
        }

        return res;
    }
};
