#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(m+n)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        unordered_multiset<int> s1, s2;
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
           for(int i = 0; i < n1; i++)
           {
               if(s2.find(nums1[i]) != s2.end())
               {
                    res.push_back(nums1[i]);
                    // Tricky Part (We have to remove one duplicate element)
                    // Otherwise will fail for this input [3,1,2] [1,1]
                    const auto it = s2.find(nums1[i]);
                    s2.erase(it);
               }
           }
        } else
        {
           for(int i = 0; i < n2; i++)
           {
               if(s1.find(nums2[i]) != s1.end())
               {
                    res.push_back(nums2[i]);
                    const auto it = s1.find(nums2[i]);
                    s1.erase(it);
               }
           }
        }

        return res;
    }
};
